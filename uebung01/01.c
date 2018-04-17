#include <stdio.h>
#include <GL/glut.h>


void display(void){
  glClear( GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex3f(1.0, 1.0, 0.0);
  glVertex3f(1.0, 9.0, 0.0);
  glVertex3f(9.0, 1.0, 0.0);
  glEnd();
  glFlush();
}


int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
  glutCreateWindow ("triangle");
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
