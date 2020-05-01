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
gluLookAt(10.0, 0,5.0, 0.0, 0.0, 0.0, 0.0, 0, 1.0);
}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
glRotatef(45, 2, -2, 5);
glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

glShadeModel(GL_SMOOTH);
glClearColor(1, 1, 1, 1);

glPushMatrix();
glColor3f(1, 0, 0);
glTranslatef(0,0,0);
glutSolidSphere(1,20,15);
glColor3f(0, 1, 0);
glTranslatef(1.5,1.5,1.5);
glutWireSphere(1,20,15);
glPopMatrix();

glutSwapBuffers();
//rotate_x += 0.01;
}


int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE);
glutInitWindowSize(1000, 1000);
glutInitWindowPosition(100 , 100);
glutCreateWindow("Sphere");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();                 // Enter the infinite event-processing loop
return 0;
}
