/*****************************************************************/
/* backface.cpp                                                  */
/* hidden surface-Darstellung des teapot                         */
/*****************************************************************/

#include "teapot.h"


/*****************************************************************/
/* Ergaenzen Sie hier Ihren Algorithmus zum backface culling     */
/*																 */
/*		Rueckgabewert fuer sichtbar:							 */
/*		Sichtbar		- "1", wenn 0 <= cos_alpha <= 1			 */
/*		Nicht sichtbar	- "-1", wenn -1 <= cos_alpha < 0		 */
/*		* cos_alpha		- Wert, fuer Flatshading als Grauwert	 */
/*																 */
/*****************************************************************/

int Backface(Triangle3dType Triangle3d, ObjectPoint Eye, float *cos_alpha)
{
    
    Vector Vector1, Vector2, Normal, EyeDir;

	// Berechne, ob Dreieck sichtbar
	// Fuer die Vektor- und Matrizenberechnungen benutzen Sie die implementierten Funktionen
	// in "math3d.cpp" (siehe auch math3d.h)

	
//	.........	
	
	//Kreuzprodukt v1*v2 zur Normalenbestimmung 
	//TODO: wie prüfen, ob er nach außen zeigt??
	MakeVector(Triangle3d.p1, Triangle3d.p2, &Vector1);
	MakeVector(Triangle3d.p1, Triangle3d.p3, &Vector2);
	MakeVector(Triangle3d.p1, Eye, &EyeDir);
	CrossProd(Vector1, Vector2, &Normal);
	Normalize(&Normal);
	Normalize(&EyeDir);
      	
	*cos_alpha = SkalProd(Normal, EyeDir); // cos-alpha bestimmen

	// Sichtbarkeit entscheiden
	if ( *cos_alpha>=0) 
	{
		return 1; // sichtbar
    }
	
	*cos_alpha = 0;
	return -1;	// nicht sichtbar
}

