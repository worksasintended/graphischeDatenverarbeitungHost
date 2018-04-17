/*****************************************************************/
/* math3d.cpp                                                    */
/*****************************************************************/



#include <math.h>
#include <string.h>

#include "teapot.h"

/******************************************************************
 * allgemeine Vektor- und Matrizenfunktionen 
 ******************************************************************/

/*
 * Füllt einen Vektor mit Werten
 */

void SetVector(Vector * v, double f11, double f12, double f13, double f14)
{
    v->x = f11; v->y = f12; v->z = f13; v->w = f14; 
}


/*
 * füllt eine Matrix mit Werten
 */

void SetMatrix(Matrix m, 
    double f11, double f12, double f13, double f14,
    double f21, double f22, double f23, double f24,
    double f31, double f32, double f33, double f34,
    double f41, double f42, double f43, double f44 )
{
    m[0][0] = f11; m[0][1] = f12; m[0][2] = f13; m[0][3] = f14; 
    m[1][0] = f21; m[1][1] = f22; m[1][2] = f23; m[1][3] = f24; 
    m[2][0] = f31; m[2][1] = f32; m[2][2] = f33; m[2][3] = f34; 
    m[3][0] = f41; m[3][1] = f42; m[3][2] = f43; m[3][3] = f44; 
}

/*
 * berechnet vec := p2 - p1 fuer jede Komponente x,y,z und setzt
 * vec.w = 0.0
 */

void MakeVector(ObjectPoint p1, ObjectPoint p2, Vector *vec) 
{
    vec->x  =  p2.x  -  p1.x ;
    vec->y  =  p2.y  -  p1.y ;
    vec->z  =  p2.z  -  p1.z ;
    vec->w  =  0.0;
}


/*
 * berechnet den Vektor cp als Kreuzprodukt der Vektoren u, v. Der
 * Vektor cp steht dann senkrecht auf u und v
 */

void CrossProd (Vector u, Vector v, Vector *cp)
{
   cp->x  =  u.y * v.z - u.z * v.y ;
   cp->y  =  u.z * v.x - u.x * v.z ;
   cp->z  =  u.x * v.y - u.y * v.x ;
   cp->w  =  0.0 ;
}


/*
 * berechnet das Skalarprodukt der Vektoren u, v. 
 * Sind u, v Normaleneinheitsvektoren, so liefert die Prozedur den Kosinus
 * des Winkels zwischen u und v
 */

double SkalProd (Vector u, Vector v)
{
    return  u.x * v.x  +  u.y * v.y  +  u.z * v.z;
}


/*
 * normalisiert vec so, dass Laenge (vec) = 1.0
 */

void Normalize (Vector *vec)
{
    double length;
    
    length = sqrt ( vec->x * vec->x + vec->y * vec->y + vec->z * vec->z ) ;
    if (length > 0.0)
    {
      vec->x  =  vec->x / length ;
      vec->y  =  vec->y / length ;
      vec->z  =  vec->z / length ;
    }
}

float Infinity = 10000.0;

/*
 * formt Vektor vec so um,  daß vec.w = 1.0
 */

void Inhomogenize (Vector *vec)
{
    if (vec->w == 0)
    {
	vec->x = Infinity;
	vec->y = Infinity;
	vec->z = Infinity;
	vec->w = 1.0;
    } else
    {
	vec->x /= vec->w;
	vec->y /= vec->w;
	vec->z /= vec->w;
	vec->w = 1.0;
    };
}


/*
 * Wendet Matrix m auf Vektor u an, d.h. multipliziert Matrix m
 * mit Vektor u und gibt das Ergebnis in Vektor v
 * zurück ( v = m * u )
 */
 
void VectMatrixMult (Vector u, Matrix m, Vector *v)
{
    v->x = m[0][0] * u.x + m[0][1] * u.y + m[0][2] * u.z + m[0][3] * u.w;
    v->y = m[1][0] * u.x + m[1][1] * u.y + m[1][2] * u.z + m[1][3] * u.w;
    v->z = m[2][0] * u.x + m[2][1] * u.y + m[2][2] * u.z + m[2][3] * u.w;
    v->w = m[3][0] * u.x + m[3][1] * u.y + m[3][2] * u.z + m[3][3] * u.w;
}


/*
 * Multiplikation zweier Matritzen out = m1*m2
 */

void MatrixMult (Matrix m1, Matrix m2, Matrix out)
{
    Matrix m;
    int i, j, k;

    for (i=0; i<4; i++)
    {
	for (j=0; j<4; j++)
	{
	    m[i][j] = 0.0;
	    for (k=0; k<4; k++) 
		m[i][j] += m1[i][k] * m2[k][j];
	}
    }
    memcpy(out, m, sizeof(Matrix));
}

