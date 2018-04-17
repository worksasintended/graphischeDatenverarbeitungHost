/*****************************************************************/
/* lines.h                                                       */
/*****************************************************************/

/* Header für Linie zeichnen */



#ifndef __LINES_H__
#define __LINES_H__

//#define rint(X) floor((X)+0.5)

//void SetPoint(int x, int y, float i);


/*
 * kompletter Bresenham-Algorithmus
 */

void Bresenham_lineCoord (int x0, int y0, int x1, int y1);

/*****************************************************************/

#endif