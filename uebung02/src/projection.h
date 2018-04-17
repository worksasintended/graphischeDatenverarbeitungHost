/* Header für Teapot-Projekte */

#ifndef __MATH3D_H__
#include "math3d.h"
#endif



#ifndef __PROJECTION_H__
#define __PROJECTION_H__

#define rint(X) (int)(floor((X)+0.5))


/******************************************************************
 * die Kamera und die 3D/2D-Transformation/Projektion
 ******************************************************************/


/* 
 * Augpunkt, Position der Kamera
 * default: (10, 100, 200)
 */
//ObjectPoint Eye;
ObjectPoint GetEye(void);

/* 
 * Augpunkt, Position der Kamera setzen
 * 
 */
//ObjectPoint Eye;
void SetEye(double x, double y, double z);

/* 
 * Lichtpunkt, Position der Lichtquelle
 * default: (10, 100, 200)
 */
//ObjectPoint Light;
ObjectPoint GetLight(void);

/* 
 * Lichtpunkt, Position der Lichtquelle
 * 
 */
//ObjectPoint Light;
void SetLight(double x, double y, double z);


/* 
 * Mittelpunkt der Bildebene; (Eye-View) definiert die Richtung
 * default: (0, 0, 0)
 */
//ObjectPoint View;
ObjectPoint GetView(void);


/*
 * definiert, welche Richtung für die Kamera "oben" ist
 * default: (0, 1, 0)  (y-Achse zeigt nach oben)
 */
//Vector ViewUp;
Vector GetViewUp(void);


/*
 * Die Projektionsmatrix wird aus den gegebenen Kamerainformationen
 * und Viewport-Informationen (Fenster 400x400) so berechnet, 
 * das die Teekanne gut in das Fenster paßt.
 */
//extern 
void DefineProjection(void) ;


/*
 * führt die durch die Projektionsmatrix definierte 
 * Projektion/Transformation für alle drei Eckpunkte des Dreiecks durch
 */
//extern 
void Project_Triangle(Triangle3dType Triangle3d, Triangle2dType *Triangle2d) ;

#endif /* __PROJECTION_H__ */
