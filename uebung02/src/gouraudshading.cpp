/*****************************************************************/
/* gouraudshading.cpp                                            */
/* Gouraudschattierte Darstellung des teapot                     */
/*****************************************************************/

#include <math.h>

#include "teapot.h"



/*
 * Gouraud-Beleuchtungsmodell mit einer Lichtquelle und ambienten und 
 * diffusen Intensitaetsanteilen. Die resutierende Intensitaet liegt
 * zwischen 0.0 und 1.0 ( 0.0 <= i <= 1.0)
 */

float Intensitaet(ObjectPoint P, Vector N)
{
    double I_ambient, I_diffuse, CosNL;
    Vector LightDir;
    
    ObjectPoint LightSource = GetLight();       
    
    MakeVector (P, LightSource, &LightDir);
    Normalize (&LightDir);
    CosNL = SkalProd (N, LightDir);
    if (CosNL < 0)  CosNL = 0;
    I_ambient = 0.1;
    I_diffuse = 0.9 * CosNL;
    return  (float) (I_ambient + I_diffuse);
}



/*****************************************************************/
/* ergaenzen Sie hier Ihre Algorithmen                           */
/*****************************************************************/

/*
 * Vertauschen von 2 ScanPoints
 */

void GouraudSwapPoints (GouraudVertex *p1, GouraudVertex *p2)
{
    GouraudVertex Temp;

    Temp = *p2;
    *p2 = *p1;
    *p1 = Temp;
}


/*
 * Zeichnen einer Scanzeile von (xl, y) bis (xr, y)
 * mit einem Intensitätsverlauf von il bis ir
 */
void GouraudDrawScanLine (int xl, int xr, int y, float il, float ir)
{
    float i, di;
    int x;
    
    /* Vertausche linken und rechten Punkt, falls xl > xr */
    if (xl > xr)
    {
		x = xl; xl = xr; xr = x;
		//swap intensities corresponding to the points
		i = il; il=ir; ir= i;
    }
    
    /* Lineare Interpolation der Intensitaeten */
    if (xl != xr)
    {
		//start with intensity from xl, as xl<xr
		i = il;
		// linear intensity interpolation
	 	di = (float)(ir-il)/(float)(xr-xl) ;

		for (x = xl; x <= xr; x++)
		{
			SetPoint(x, y, i);
			// il + (xr - xl) di = ir
			i += di;
		}
    }
    else
    {
		SetPoint(xl, y, il);
    }
}



/*
 * Scanconvertierungsroutine mit bilinarer Interpolation der Eckpunkte 
 * sowie deren Intensitaeten
 */
void GouraudScanConvertTriangle(GouraudVertex P1, GouraudVertex P2, GouraudVertex P3)
{
	GouraudScanPoint Start, Ende;
    int ScanLine;

	/* Sortiere Eckpunkte in y-Richtung --> P1.y <= P2.y <= P3.y */
	if  (P1.y > P2.y)  GouraudSwapPoints ( &P1, &P2 ) ;
	if  (P1.y > P3.y)  GouraudSwapPoints ( &P1, &P3 ) ;
	if  (P2.y > P3.y)  GouraudSwapPoints ( &P2, &P3 ) ;

	/* Der ScanPoint `Start' interpoliert zunaechst einmal zwischen `P1'
	  und `P2'. Berechne den Anfangwert fuer Start (x und i)*/
	Start.x = (float)P1.x;
	Start.i = (float)P1.i; 
	Start.dx = 0;
	Start.di = 0;
	if  (P2.y > P1.y)
	{
		Start.dx = (float)(P2.x - P1.x)/(float)(P2.y - P1.y); // Offset
		Start.di = (float)(P2.i-P1.i)/(float)(P2.y-P1.y);
	}

	/* Der ScanPoint `Ende' interpoliert zwischen `P1' und `P3'. 
	  Berechne den Anfangswert fuer Ende (x und i)*/
	Ende.x = (float)P1.x;
	Ende.i = (float)P1.i;
	Ende.dx = 0;
	Ende.di = 0;
	if  (P3.y > P1.y)
	{
		Ende.dx = (float)(P3.x - P1.x)/(float)(P3.y - P1.y); // Offset
		Ende.di = (float)(P3.i - P1.i)/(float)(P3.y - P1.y);
	}

	// Fuelle Sub-Dreick zwischen P1.y und P2.y 
	for (ScanLine=(int)P1.y; ScanLine<P2.y; ScanLine++) {
		// Fuelle ScanLine von Start.x bis Ende.x
		GouraudDrawScanLine(Start.x, Ende.x, ScanLine,  Start.i, Ende.i);
		
        // Berechne Start und Ende fuer naechste ScanLine
		Start.x += Start.dx;
	        Ende.x += Ende.dx;
		Start.i += Start.di;
		Ende.i += Ende.di;	
	}

	if  (P3.y > P2.y)
	{
		/* Der ScanPoint `Start' soll jetzt zwischen `P2' und `P3'
		 interpolieren. Berechne Start.x und Start.i fuer die naechste ScanLine 
		 sowie Start.dx. imd Start.di */
		Start.dx = (float)(P3.x - P2.x)/(float)(P3.y - P2.y) ;
		Start.x  = P2.x;
		Start.di = (float)(P3.i-P2.i)/(float)(P3.y-P2.y);
		Start.i  = P2.i;

		for (ScanLine = (int)P2.y; ScanLine < P3.y; ScanLine++ ) {
			GouraudDrawScanLine(Start.x, Ende.x, ScanLine, Start.i, Ende.i);
			Start.x += Start.dx;
			Ende.x += Ende.dx;
			Start.i += Start.di;
			Ende.i += Ende.di;
		}

	}
}



void Gouraudshading(Triangle3dType Triangle3d, Triangle2dType Triangle2d)
{
    GouraudVertex P1, P2, P3;

	/* Zeichne ausgefuelltes Dreieck */
	P1.x = Triangle2d.p1.x;
	P1.y = Triangle2d.p1.y;
	P1.i = Intensitaet(Triangle3d.p1, Triangle3d.n1 );
		
	P2.x = Triangle2d.p2.x;
	P2.y = Triangle2d.p2.y;
	P2.i = Intensitaet(Triangle3d.p2, Triangle3d.n2);

	P3.x = Triangle2d.p3.x;
	P3.y = Triangle2d.p3.y;
	P3.i = Intensitaet( Triangle3d.p3, Triangle3d.n3 );
			
	GouraudScanConvertTriangle(P1, P2, P3);

}

/*****************************************************************/

