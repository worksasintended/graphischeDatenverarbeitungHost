/*****************************************************************/
/* trifill.h                                                     */
/*****************************************************************/

/* Header für Gouraudshading */



#ifndef __TRIFILL_H__
#define __TRIFILL_H__

void Trifill(void);
void GouraudSwapPoints (GouraudVertex *p1, GouraudVertex *p2);
void GouraudScanConvertTriangle(GouraudVertex P1, GouraudVertex P2, GouraudVertex P3);
void GouraudDrawScanLine (int xl, int xr, int y, float il, float ir);

/*****************************************************************/

#endif