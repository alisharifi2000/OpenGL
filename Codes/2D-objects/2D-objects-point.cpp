#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

int Height=1000, Width=1000;
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 1.0, 0.5);
glPointSize(10.0);
/*glEnable(GL_POINT_SMOOTH);*/
glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

//Rectangle
glBegin(GL_POLYGON);
glVertex2f(0.25 , 0.0);
glVertex2f(0.25 , 0.25);
glVertex2f(0.75 , 0.25);
glVertex2f(0.75 , 0.0);
glEnd();

//Square
glBegin(GL_POLYGON);
glVertex2f(0.25 , 0.5);
glVertex2f(0.25 , 0.75);
glVertex2f(0.5, 0.75);
glVertex2f(0.5 , 0.5);
glEnd();

//Triangle
glBegin(GL_POLYGON);
glVertex2f(0.75 , 0.5);
glVertex2f(0.75 , 0.75);
glVertex2f(1.00, 0.5);
glEnd();

//Octagon
glBegin(GL_POLYGON);
glVertex2f(-0.25 , 0.0);
glVertex2f(-0.5 , 0.0);
glVertex2f(-0.75, 0.25);
glVertex2f(-0.75 , 0.5);
glVertex2f(-0.5 , 0.75);
glVertex2f(-0.25, 0.75);
glVertex2f(0.0 , 0.5);
glVertex2f(0.0 , 0.25);
glEnd();

//Trapezoid
glBegin(GL_POLYGON);
glVertex2f(0.85 , 0.0);
glVertex2f(1.0 , 0.0);
glVertex2f(1.0 , 0.4);
glVertex2f(0.85 , 0.25);
glEnd();
glutSwapBuffers();
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE);
glutInitWindowSize(Width, Height);
glutCreateWindow("5 geometric shapes in one page");
glutDisplayFunc(display);
glutMainLoop();
}
