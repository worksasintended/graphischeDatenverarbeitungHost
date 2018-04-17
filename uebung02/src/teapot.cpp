/*****************************************************************/
/* teapot.cpp		                                             */
/*****************************************************************/


#include <stdio.h> 
#include <math.h>
#include <string.h>

#include "glut.h"


#include "teapot.h"

#define WINDOW_SIZE     400 // Fenstergroesse

float *pixels;
int option = 0;



// Mit dieser Funktion wird ein Pixel im Frambuffer mit einem Grauwert gesetzt.
// Wertebereich des Grauwertes: 0 <= i <= 1
void SetPoint(int x, int y, float i)
{
	float *help = pixels;
	help+= (y * 3 * WINDOW_SIZE) + (3 * x);
	*help++ = i; 
	*help++ = i;
	*help++ = i;
}


void display(void) 
{
	glClear( GL_COLOR_BUFFER_BIT); 

	// Lese Framebuffer des Fensters aus.
	glReadPixels(0,0,WINDOW_SIZE,WINDOW_SIZE,GL_RGB,GL_FLOAT,pixels);
	// Mit den folgenden Funktionen werden einzelne Pixel im Frambuffer gesetzt.
    
	
	Triangle3dType Triangle3d;
    Triangle2dType Triangle2d;
    int sichtbar = 0;
	float gray = 0;
	ObjectPoint Eye = GetEye();


	// Lichtquelle setzen für Gouraudshading
	switch(option)
	{
		case 5:		// Lichtposition (10, 100, 200)
			SetLight(10, 100, 200);
			break;
		case 6:		// Lichtposition (10, -100, 200)
			SetLight(10, -100, 200);
			break;
		case 7:		// Lichtposition (100, 100, 200)
			SetLight(100, 100, 200);
			break;
	}


	// Alle Dreiecke des Datenmodel der Teekanne durchlaufen
    for (int i=0; i < NumTriangle; i++)
    {
		Triangle3d = teapot3d[i];
		switch(option)
		{
			case 0:		// Wireframe
			case 1:		// Wireframe
				/* Projektionsberechnung */
				Project_Triangle(Triangle3d, & Triangle2d);
				/* Drahtgitter des Dreiecks zeichnen */
				Wireframe(Triangle2d);
				break;
			case 2:		// Backface Culling
				// Sichtbarkeit berechnen
				if ( (sichtbar = Backface(Triangle3d, Eye, &gray)) == 1)
				{
					/* Projektionsberechnung */
					Project_Triangle(Triangle3d, & Triangle2d);
					/* Drahtgitter des Dreiecks zeichnen */
					Wireframe(Triangle2d);
				}
				break;
			case 3:		// Flatshading
				// Sichtbarkeit berechnen
				if ( (sichtbar = Backface(Triangle3d, Eye, &gray)) == 1)
				{
					//printf("Grauwert=%d\n", sichtbar);
					/* Projektionsberechnung */
					Project_Triangle(Triangle3d, & Triangle2d);
					/* Flaeche des Dreiecks zeichnen mit Flatshading */
					Flatshading(Triangle2d, gray);
				}
				break;
			case 4:
				Trifill();
				// NUR einmal Zeichnen
				// Schreiben Framebuffer des Fensters.
				glDrawPixels(WINDOW_SIZE,WINDOW_SIZE,GL_RGB,GL_FLOAT,pixels);
				glFlush();
				return;
				break;
			case 5:		// Gouraudshading
			case 6:		// Gouraudshading
			case 7:		// Gouraudshading
				// Sichtbarkeit berechnen
				if ( (sichtbar = Backface(Triangle3d, Eye, &gray)) == 1)
				{
					/* Projektionsberechnung */
					Project_Triangle(Triangle3d, &Triangle2d);

					/* Flaeche des Dreiecks zeichnen mit Gouraudshading */
					Gouraudshading(Triangle3d, Triangle2d);
				}
				break;
		}
	}

/////////////////////////////////////////////////////////////////////////////
	// Schreiben Framebuffer des Fensters.
	glDrawPixels(WINDOW_SIZE,WINDOW_SIZE,GL_RGB,GL_FLOAT,pixels);
	
	// Ausgeben
	glFlush();
}

// Menuefunktion
void ProcessMenu(int value)
{
	option = value;
	glutPostRedisplay(); // Anzeige aktualisieren
}


int main(int argc, char **argv) 
{ 
	printf("- Visibilitaet und Schattierung -\n\n"); 
	printf("Menue arbeitet mit rechter Maustaste im Display-Fenster.\n\n"); 
	glutInit(&argc, argv); 
	glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 

	glutInitWindowPosition(300,300); 
	glutInitWindowSize(WINDOW_SIZE,WINDOW_SIZE); 
	glutCreateWindow ("Teapot"); 

	pixels = new float[3*WINDOW_SIZE*WINDOW_SIZE];

	glClearColor(0.0, 0.0, 0.0, 0.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0); 

	DefineProjection();

	glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Wireframe", 1);
	glutAddMenuEntry("Backface", 2);
	glutAddMenuEntry("Flatshading", 3);
	glutAddMenuEntry("Trifill", 4);
	glutAddMenuEntry("Gouraudshading Lichtposition (10, 100, 200)", 5);
	glutAddMenuEntry("Gouraudshading Lichtposition (10, -100, 200)", 6);
	glutAddMenuEntry("Gouraudshading Lichtposition (100, 100, 200)", 7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
 
	glutDisplayFunc(display); 
	glutMainLoop(); 

	delete pixels;
	return 0; 
}

