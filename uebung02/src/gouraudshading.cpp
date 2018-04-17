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
//		...
    }
    
    /* Lineare Interpolation der Intensitaeten */
    if (xl != xr)
    {
//		i = ...
//		di = ...

		for (x = xl; x <= xr; x++)
		{
			SetPoint(x, y, i);
//			...
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
//	Start.i = ...
	Start.dx = 0;
//	Start.di = ...
	if  (P2.y > P1.y)
	{
		Start.dx = (float)(P2.x - P1.x)/(float)(P2.y - P1.y); // Offset
//		Start.di = ...
	}

	/* Der ScanPoint `Ende' interpoliert zwischen `P1' und `P3'. 
	  Berechne den Anfangswert fuer Ende (x und i)*/
	Ende.x = (float)P1.x;
//	Ende.i = ...
	Ende.dx = 0;
//	Ende.di = ...
	if  (P3.y > P1.y)
	{
		Ende.dx = (float)(P3.x - P1.x)/(float)(P3.y - P1.y); // Offset
//		Ende.di = ...
	}

/* //Kommentar entfernen
	// Fuelle Sub-Dreick zwischen P1.y und P2.y 
	for (ScanLine ... ) {
		// Fuelle ScanLine von Start.x bis Ende.x
		...
		
        // Berechne Start und Ende fuer naechste ScanLine
		...
	}
*/ // Kommentar entfernen

	if  (P3.y > P2.y)
	{
		/* Der ScanPoint `Start' soll jetzt zwischen `P2' und `P3'
		 interpolieren. Berechne Start.x und Start.i fuer die naechste ScanLine 
		 sowie Start.dx. imd Start.di */
		Start.dx = (float)(P3.x - P2.x)/(float)(P3.y - P2.y) ;
//		Start.x  = ...
//		Start.di = ...
//		Start.i  = ...

/* //Kommentar entfernen
		for (ScanLine ... ) {
			// Fuelle ScanLine von Start.x bis Ende.x
			...
	 
			// Berechne Start und Ende fuer naechste ScanLine
			...
		}
*/ // Kommentar entfernen

	}
}



void Gouraudshading(Triangle3dType Triangle3d, Triangle2dType Triangle2d)
{
    GouraudVertex P1, P2, P3;

	/* Zeichne ausgefuelltes Dreieck */
	P1.x = Triangle2d.p1.x;
	P1.y = Triangle2d.p1.y;
//	P1.i = Intensitaet( ... );
		
	P2.x = Triangle2d.p2.x;
	P2.y = Triangle2d.p2.y;
//	P2.i = Intensitaet( ... );

	P3.x = Triangle2d.p3.x;
	P3.y = Triangle2d.p3.y;
//	P3.i = Intensitaet( ... );
			
	GouraudScanConvertTriangle(P1, P2, P3);

}

/*****************************************************************/

