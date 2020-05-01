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
glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

glClearColor(1, 1, 1, 1);
glRotatef(20, 2, -2, 5);
// light 0
GLfloat light_position[] = {2 , 2 , 1, 1.0 };
glClearColor (0.0, 0.0, 0.0, 0.0);
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
//GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);


//light1
GLfloat light_position1[] = {-3, -4, -3, 1.0 };
glClearColor (0.0, 0.0, 0.0, 0.0);
GLfloat light_diffuse1[] = { 1 , 0 , 1, 1.0 };
//GLfloat light_ambient1[] = { 1 , 0 , 1, 1.0 };
//GLfloat light_specular1[] = { 1 , 0 , 1, 1.0 };
glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
//glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
//glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);;
glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

glEnable(GL_LIGHT0);
glEnable(GL_LIGHT1);
glEnable(GL_LIGHTING);

glShadeModel(GL_FLAT);
//glShadeModel(GL_SMOOTH);

/*
glPointSize ( 10 ) ;
glBegin (GL_POINTS) ;
glColor3f (1 , 1 , 1) ;
glVertex3f (2 , 2 , 1) ;
glEnd ( ) ;

glPointSize ( 10 ) ;
glBegin (GL_POINTS) ;
glColor3f(1 , 0 , 1) ;
glVertex3f (-3, -4, -3) ;
glEnd ( ) ;
*/

glPushMatrix();
glColor3f(1, 0, 0);
glTranslatef(0,0,0);
glutSolidSphere(1,20,15);

glColor3f(0, 1, 0);
glTranslatef(1,1,2);
glutSolidSphere(1,20,15);

glColor3f(0, 0, 1);
glTranslatef(0,-1,1);
glutSolidSphere(1,25,25);
glPopMatrix();


glutSwapBuffers();
}


int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE);
glutInitWindowSize(1000, 1000);
glutInitWindowPosition(100 , 100);
glutCreateWindow("Light");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();                 // Enter the infinite event-processing loop
return 0;
}
