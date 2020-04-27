#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

int Height=1000, Width=1000;
void reshape(int w , int h)
{
glViewport(0 , 0 ,(GLsizei)w , (GLsizei)h);
gluPerspective(50.0 , (GLfloat)w / (GLfloat)h , 1.0 ,20.0);
gluLookAt(0.0, 0.0,5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void display(void)
{
glRotatef(45,5,-5,-2);
//clear window to the black color
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//define vertices arrays and colors for all faces of a cube
GLfloat verticesFront[]={0,0,0,1,0,0,1,1,0,0,1,0};
GLfloat colorsFront[]={1,0,0,1,0,0,1,0,0,1,1,0};
GLfloat verticesRight[]={1,0,0,1,1,0,1,1,1,1,0,1};
GLfloat colorsRight[]={0,1,0,0,1,0,1,1,1,0,1,0};
GLfloat verticesLeft[]={0,0,0,0,0,1,0,1,1,0,1,0};
GLfloat colorsLeft[]={0,1,0,0,1,1,0,1,1,0,1,0};
GLfloat verticesBack[]={0,0,1,1,0,1,1,1,1,0,1,1};
GLfloat colorsBack[]={0,0,0.5,0,0,0,0.5,1,1,0,1,1,0};
GLfloat verticesTop[]={0,1,0,0,1,1,1,1,1,1,1,0};
GLfloat colorsTop[]={1,0.5,0.5,1,1,0,1,0,1,1,1,0};
GLfloat verticesBottom[]={0,0,0,1,0,0,1,0,1,0,0,1};
GLfloat colorsBottom[]={0,0,1,0,1,0,1,0,0,1,0.4,1};

//drawing font face
glEnableClientState(GL_COLOR_ARRAY);
glEnableClientState(GL_VERTEX_ARRAY);
glColorPointer(3, GL_FLOAT, 0, colorsFront);
glVertexPointer(3, GL_FLOAT, 0, verticesFront);
glBegin(GL_POLYGON);
glArrayElement(0);
glArrayElement(1);
glArrayElement(2);
glArrayElement(3);
glNormal3d(0 , 0 , -1);
glEnd();

//drawing back face
glColorPointer(3, GL_FLOAT, 0, colorsBack);
glVertexPointer(3, GL_FLOAT, 0, verticesBack);
glBegin(GL_QUADS);
glArrayElement(0);
glArrayElement(1);
glArrayElement(2);
glArrayElement(3);
glNormal3d(0 , 0 , 1);
glEnd();

//drawing left face
glColorPointer(3, GL_FLOAT, 0, colorsLeft);
glVertexPointer(3, GL_FLOAT, 0, verticesLeft);
glBegin(GL_QUADS);
glArrayElement(0);
glArrayElement(1);
glArrayElement(2);
glArrayElement(3);
glNormal3d(-1 , 0 , 0);
glEnd();

//drawing top face
glColorPointer(3, GL_FLOAT, 0, colorsTop);
glVertexPointer(3, GL_FLOAT, 0, verticesTop);
glBegin(GL_QUADS);
glArrayElement(0);
glArrayElement(1);
glArrayElement(2);
glArrayElement(3);
glNormal3d(0 , 1 , 0);
glEnd();

//drawing bottom face
glColorPointer(3, GL_FLOAT, 0, colorsBottom);
glVertexPointer(3, GL_FLOAT, 0, verticesBottom);
glBegin(GL_QUADS);
glArrayElement(0);
glArrayElement(1);
glArrayElement(2);
glArrayElement(3);
glNormal3d(0 , -1 , 0);
glEnd();

//drawing right face
glColorPointer(3, GL_FLOAT, 0, colorsRight);
glVertexPointer(3, GL_FLOAT, 0, verticesRight);
glBegin(GL_QUADS);
glArrayElement(0);
glArrayElement(1);
glArrayElement(2);
glArrayElement(3);
glNormal3d(1 , 0 , 0);
glEnd();

glutSwapBuffers();

}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE);
glutInitWindowSize(1000, 1000);
glutInitWindowPosition(100 , 100);
glutCreateWindow("CUBE");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
}
