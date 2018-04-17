/*****************************************************************/
/* projection.cpp                                                */
/*****************************************************************/


#include <math.h>

#include "teapot.h"

ObjectPoint Eye;
ObjectPoint Light;
ObjectPoint View;
Vector ViewUp;

Matrix ProjectionMatrix;

ObjectPoint GetEye(void)
{
	return Eye;
}

void SetEye(double x, double y, double z)
{
    SetVector(&Eye, x, y, z, 1.0);   
}

ObjectPoint GetLight(void)
{
	return Light;
}

void SetLight(double x, double y, double z)
{
    SetVector(&Light, x, y, z, 1.0);   
}


ObjectPoint GetView(void)
{
	return View;
}

Vector GetViewUp(void)
{
	return ViewUp;
}

/******************************************************************
 * die Kamera und die 3D/2D-Transformation/Projektion 
 ******************************************************************/

/*
 * Legt ProjektionsMatrix fest
 */
 
void DefineProjection() 
{
    SetVector(&Eye, 10.0, 100.0, 200.0, 1.0);   
    SetVector(&Light, 10.0, 100.0, 200.0, 1.0);   
    SetVector(&View, 0.0, 0.0, 0.0, 1.0); 
    SetVector(&ViewUp, 0.0, 1.0, 0.0, 0.0); 
    
    SetMatrix(ProjectionMatrix, 
    59.887,  -0.379,  -3.755, 190.000, 
	-1.362,  53.439, -27.252, 120.000, 
	-2.681, -26.806, -53.612,   0.000, 
	-0.000,  -0.002,  -0.004,   1.000);
}


/*
 * Projiziert einen 3D-Punkt in einen 2D-Bildpunkt mithilfe
 * der aktuellen Projektionsmatrix
 */
 
void Project_Vertex (ObjectPoint op, ImagePoint *ip)
{
    Vector temp;
    VectMatrixMult ( op, ProjectionMatrix, &temp);
    Inhomogenize (&temp);

    ip->x = (int) rint(temp.x); //rint (temp.x);
    ip->y = (int) rint(temp.y); //rint (temp.y);
}


/*
 * Projiziert ein Dreieck in die Bildebene
 */
 
void Project_Triangle(Triangle3dType Triangle3d, Triangle2dType * Triangle2d)
{
    Project_Vertex (Triangle3d.p1, & (Triangle2d->p1));
    Project_Vertex (Triangle3d.p2, & (Triangle2d->p2));
    Project_Vertex (Triangle3d.p3, & (Triangle2d->p3));
}
