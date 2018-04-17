/*****************************************************************/
/* trifill.cpp                                                   */
/* Gouraudschattierte Darstellung des teapot                     */
/*****************************************************************/

#include "teapot.h"

// einfaches Dreieck zeichnen
void Trifill(void)
{
	// Dreieckspunkte mit Grauwerten definieren
    GouraudVertex p1 = {200, 10, 0.0f};
    GouraudVertex p2 = {10, 100, 0.5f};
    GouraudVertex p3 = {350, 350, 0.9f};
  
	// Zeichne ausgefuelltes Dreieck 
	// GouraudScanConvertTriangle() in gourandshading.cpp implementieren
	// Einfaches Dreieck dient der Kontrolle des Algorithmus 
    GouraudScanConvertTriangle(p1, p2, p3);
}

/*****************************************************************/
