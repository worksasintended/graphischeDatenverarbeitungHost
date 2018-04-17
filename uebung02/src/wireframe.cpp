/*****************************************************************/
/* wireframe.cpp                                                 */
/*****************************************************************/

#include "teapot.h"

void Wireframe(Triangle2dType Triangle2d)
{
	
	Bresenham_lineCoord(Triangle2d.p1.x, Triangle2d.p1.y, 
		Triangle2d.p2.x, Triangle2d.p2.y); 
	Bresenham_lineCoord(Triangle2d.p2.x, Triangle2d.p2.y, 
		Triangle2d.p3.x, Triangle2d.p3.y); 
	Bresenham_lineCoord(Triangle2d.p3.x, Triangle2d.p3.y, 
		Triangle2d.p1.x, Triangle2d.p1.y); 
}


/*****************************************************************/
