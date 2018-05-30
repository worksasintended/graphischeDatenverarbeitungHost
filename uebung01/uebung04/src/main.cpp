#include <math.h>
#include <stdio.h> 
#include <GL/glut.h> 

void display(void){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1, 0, 0);
  glutSolidSphere(1.0, 50, 50);
  glTranslatef(2,0,0);
  glFlush();
  glColor3f(.5, .5, .5);
  glutSolidSphere(1.0, 50, 50);
  glTranslatef(-2.0, 0, 0);
  glFlush();
}


int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow ("task4");
  glutDisplayFunc(display);
  gluPerspective(45,1,0,20);
  gluLookAt(0,10,0,0,0,0,0,0,1);
  glutMainLoop();
  return 0;
}
