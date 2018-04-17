/*****************************************************************/
/* lines.cpp                                                     */
/*****************************************************************/

#include <math.h>


#include "teapot.h"

/*
 * kompletter Bresenham-Algorithmus
 */

void Bresenham_lineCoord (int x0, int y0, int x1, int y1)
{
    int dx, dy, x, y, incO, incNO, d;
    int swap, temp, Ax, Ay;

    if (abs(y1-y0) >= abs(x1-x0))
    {
        temp = x0; x0 = y0; y0 = temp;
        temp = x1; x1 = y1; y1 = temp;
        swap = 1;
    }
    else swap = 0;

    if (x1 > x0) Ax = 1; else Ax = -1;
    if (y1 > y0) Ay = 1; else Ay = -1;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    d = 2 * dy - dx;
    incO = 2 * dy;
    incNO = 2 * dy - 2 * dx;

    x = x0;
    y = y0;
    for (temp = 0; temp <= dx; temp++)
    {
        /* Tausch beim Zeichnen der Punkte: */
        if (swap == 1) SetPoint(y, x, 1);
        else           SetPoint(x, y, 1); 

        x += Ax;

        if (d < 0)  d += incO;
        else      { d += incNO; y += Ay; }
    }

}

/*****************************************************************/
