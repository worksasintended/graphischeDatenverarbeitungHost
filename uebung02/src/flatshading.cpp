/*****************************************************************/
/* flatshading.cpp                                               */
/*****************************************************************/


#include <math.h>
#include "teapot.h"


/*****************************************************************/
/* Ergaenzen Sie hier Ihre Algorithmen                           */
/*****************************************************************/

typedef struct {
    float x, dx;      /* x-Wert und Offset */
} FlatScanPoint ;

/*
 * Vertauschen von 2 ScanPoints
 */

void FlatSwapPoints (ImagePoint *p1, ImagePoint *p2)
{
    ImagePoint Temp;

    Temp = *p2;
    *p2 = *p1;
    *p1 = Temp;
}

/*
 * Zeichnen einer Scanzeile 
 */
void FlatDrawScanLine (int xl, int xr, int y, float i)
{
    int x;
    
    /* Vertausche linken und rechten Punkt, falls xl > xr */
    if (xl > xr) {
		x = xl;  xl = xr;  xr = x;
    }
    // alle Punkte auf der Scanzeile setzen
    if (xl != xr)
		for (x = xl; x <= xr; x++)
			SetPoint(x, y, i);
    else
		SetPoint(xl, y, i);
}

/*
 * Scanconvertierungsroutine mit bilinarer Interpolation der Eckpunkte 
 */
void FlatScanConvertTriangle(ImagePoint P1, ImagePoint P2, ImagePoint P3, float gray)
{
    FlatScanPoint Start, Ende;
    int ScanLine;

	/* Sortiere Eckpunkte in y-Richtung --> P1.y <= P2.y <= P3.y */
	if  (P1.y > P2.y)  FlatSwapPoints ( &P1, &P2 ) ;
	if  (P1.y > P3.y)  FlatSwapPoints ( &P1, &P3 ) ;
	if  (P2.y > P3.y)  FlatSwapPoints ( &P2, &P3 ) ;

	/* Der ScanPoint `Start' interpoliert zunaechst einmal zwischen `P1'
	  und `P2'. Berechne den Anfangwert fuer Start */
	Start.x  =  (float)P1.x ;
	Start.dx = 0;
	if (P2.y > P1.y) {
		Start.dx  =  (float)( P2.x - P1.x ) / (float)( P2.y - P1.y ) ;
	}

	/* Der ScanPoint `Ende' interpoliert zwischen `P1' und `P3'. 
	  Berechne den Anfangswert fuer Ende */
	Ende.x  =  (float)P1.x ;
	Ende.dx = 0 ;
	if (P3.y > P1.y) {
		Ende.dx  =  (float)( P3.x - P1.x ) / (float)( P3.y - P1.y ) ;
	}

	// Fuelle Sub-Dreick zwischen P1.y und P2.y 
	for (ScanLine=(int)P1.y; ScanLine<=(int)P2.y; ScanLine++ ) {
	  
	  // Fuelle ScanLine von Start.x bis Ende.x mit gray
	  FlatDrawScanLine(Start.x, Ende.x, ScanLine, gray);
		
	  // Berechne Start.x und Ende.x fuer naechste ScanLine
	    Start.x += Start.dx;
	    Ende.x += Ende.dx;
	}

	if  (P3.y > P2.y) { 
		// Der ScanPoint `Start' soll jetzt zwischen `P2' und `P3' interpolieren.
		// Berechne Start.x fuer die naechste ScanLine sowie Start.dx. 
		Start.dx  =  (float)( P3.x - P2.x ) / (float)( P3.y - P2.y ) ;
		Start.x = (float)P2.x+Start.dx;
		// Ende.dx ändert sich nicht
		// P1.y entspricht der y-Koordinate des neuen Punktes
		//Ende.dx = (float)(P3.x - Ende.x) / float( P3.y - P1.y  );


		for ( ScanLine = (int)P2.y+1; ScanLine<=(int)P3.y; ScanLine++) {
		  // Fuelle ScanLine von Start.x bis Ende.x mit gray
		  FlatDrawScanLine(Start.x, Ende.x, ScanLine, gray);
	 
		  // Berechne Start.x und Ende.x fuer naechste ScanLine
		  Start.x += Start.dx;
		  Ende.x += Ende.dx;	  
		}
	}
}

void Flatshading(Triangle2dType Triangle2d, float gray)
{
	/* Zeichne ausgefuelltes Dreieck */
	FlatScanConvertTriangle(Triangle2d.p1, Triangle2d.p2, Triangle2d.p3, gray);
}

