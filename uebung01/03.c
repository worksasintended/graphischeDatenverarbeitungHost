#include <stdio.h>
#include <GL/glut.h>

void display(void){
  glClear( GL_COLOR_BUFFER_BIT);
  glBegin(GL_QUADS);

  glColor3f(0.0, 1.0, .0); //green
  glVertex3f(.0, 1., 0.);

  glColor3f(1.0, 1.0, 0.0); //yellow
  glVertex3f(1., .5, .0);

  glColor3f(1.0, 1.0, 1.0); //white
  glVertex3f(.0, 0., .0);

  glColor3f(0.0, 1.0, 1.0); //cyan
  glVertex3f(-1., .5, 0.);

  ///////////////////////////////////
  glColor3f(1.0, 1.0, 0.0); //yellow
  glVertex3f(1., .5, .0);

  glColor3f(1.0, 1.0, 1.0); //white
  glVertex3f(.0, .0, .0);

  glColor3f(1.0, 0.0, 1.0); //magenta
  glVertex3f(.0, -1., .0);

  glColor3f(1.0, 0.0, 0.0); //red
  glVertex3f(1.0, -.5, .0);

  /////////////////////////////////
  glColor3f(1.0, 1.0, 1.0); //white
  glVertex3f(.0, .0, .0);

  glColor3f(0.0, 1.0, 1.0); //cyan
  glVertex3f(-1., .5, 0.);
 
  glColor3f(0.0, 0.0, 1.0); //blue
  glVertex3f(-1.0, -.5, .0);

  glColor3f(1.0, 0.0, 1.0); //magenta
  glVertex3f(.0, -1., .0);
  

  glEnd();
  glFlush();

  glBegin(GL_LINES);
  glColor3f(0., 0., 0.);

  glVertex3f(0,0,0);
  glVertex3f(0., -1., 0.);

  glVertex3f(.0, .0, .0);
  glVertex3f(-1., .5, .0);
  
  glVertex3f(.0, .0,.0);
  glVertex3f(1.0, .5, .0);

  glEnd();
  glFlush();

}

int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
  glutCreateWindow ("cube");
  glClearColor(.0, .0, .0, .0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.5, 1.5, -1.5 ,1.5, 5.0, -5.0);
  //gluLookAt(-2,-2, -2, 0, 0, 0, 0, 0, 1);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
