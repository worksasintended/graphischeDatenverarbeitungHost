/* Header für Teapot-Projekte */

#ifndef __MATH3D_H__
#define __MATH3D_H__

/******************************************************************
 * globale Datenstrukturen
 ******************************************************************/
 
typedef struct 
{
	int x, y;
} ImagePoint ;

typedef struct 
    {
	double x, y, z, w;
    } ObjectPoint ;

typedef ObjectPoint Vector;

typedef double Matrix[4][4];

typedef struct 
    {
	ObjectPoint p1, p2, p3;
	Vector n1, n2, n3;
    } Triangle3dType ;

typedef struct {
	ImagePoint p1, p2, p3;
} Triangle2dType ;

typedef struct {
	float x;			  // x-Wert
    float dx;         // Offset
    float i, di;      // Intensitaet fuer Gouraudshading 
} GouraudScanPoint ;

typedef struct {
    int x, y; 
    float i;          // Intensitaet
} GouraudVertex ;


/******************************************************************
 * allgemeine Vektor- und Matrizenfunktionen
 ******************************************************************/


/*
 * Füllt einen Vektor mit Werten
 */
void SetVector(Vector * v, double f11, double f12, double f13, double f14);


/*
 * füllt eine Matrix mit Werten
 */
void SetMatrix(Matrix m, 
    double f11, double f12, double f13, double f14,
    double f21, double f22, double f23, double f24,
    double f31, double f32, double f33, double f34,
    double f41, double f42, double f43, double f44 );
    

/*
 * berechnet vec := p2 - p1 fuer jede Komponente x,y,z und setzt
 * vec.w = 0.0
 */
//extern 
void MakeVector(ObjectPoint p1, ObjectPoint p2, Vector *vec) ;


/*
 * berechnet den Vektor cp als Kreuzprodukt der Vektoren u, v. Der
 * Vektor cp steht dann senkrecht auf u und v
 */
//extern 
void CrossProd (Vector u, Vector v, Vector *cp) ;


/*
 * berechnet das Skalarprodukt der Vektoren u, v. 
 * Sind u, v Normaleneinheitsvektoren, so liefert die Prozedur den Kosinus
 * des Winkels zwischen u und v
 */
//extern 
double SkalProd (Vector u, Vector v) ;


/*
 * normalisiert vec so, dass Laenge (vec) = 1.0
 */
//extern 
void Normalize (Vector *vec) ;


/*
 * formt Vektor vec so um,  daß vec.w = 1.0
 */
//extern 
void Inhomogenize (Vector *vec) ;


/*
 * Wendet Matrix m auf Vektor u an, d.h. multipliziert Matrix m
 * mit Vektor u und gibt das Ergebnis in Vektor v
 * zurück ( v = m * u )
 */
//extern 
void VectMatrixMult (Vector u, Matrix m, Vector *v) ;


/*
 * Multiplikation zweier Matritzen out = m1*m2
 */
//extern 
void MatrixMult (Matrix m1, Matrix m2, Matrix out) ;

#endif /* __MATH3D_H__ */
