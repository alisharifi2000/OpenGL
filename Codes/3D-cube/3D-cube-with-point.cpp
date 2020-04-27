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
glRotatef(45,3,0.1,5);
	// Back Side
	glBegin(GL_POLYGON);
	glColor3f(1 ,0 ,0);
	glVertex3f(0.0 , 0.0 , 1);
	glVertex3f(1 , 0.0 , 1);
	glVertex3f(1 , 1 , 1);
	glVertex3f(0.0 , 1 , 1);
	glNormal3d(0 , 0 , 1);
	glEnd();


	//Down side
	glBegin(GL_POLYGON);
	glColor3f(0 , 1 , 0);
	glVertex3f(0 , 0 , 0);
	glVertex3f(0 , 0 , 1);
	glVertex3f(1 , 0 , 1);
	glVertex3f(1 , 0 , 0);
	glNormal3d(0 , -1 , 0);
	glEnd();

	// Left side
	glBegin(GL_POLYGON);
	glColor3f(0 , 0 , 1);
	glVertex3f(0 , 0 , 0);
	glVertex3f(0 , 1 , 0);
	glVertex3f(0 , 1 , 1);
	glVertex3f(0 , 0 , 1);
	glNormal3d(-1 , 0 , 0);
	glEnd();

	// Right side
	glBegin(GL_POLYGON);
	glColor3f(1 , 1, 0);
	glVertex3f(1.0 , 0.0 , 0);
	glVertex3f(1 , 1 , 0);
	glVertex3f(1 , 1 , 1);
	glVertex3f(1 , 0 , 1);
	glNormal3d(1 , 0 , 0);
	glEnd();

	//Front side
	glBegin(GL_POLYGON);
	glColor3f(1 ,0 ,1);
	glVertex3f(0.0 , 0.0 , 0.0);
	glVertex3f(1.0 , 0.0 , 0.0);
	glVertex3f(1.0 , 1.0 , 0.0);
	glVertex3f(0.0 , 1.0 , 0.0);
	glNormal3d(0 , 0 , -1);
	glEnd();

	//Top side
	glBegin(GL_POLYGON);
	glColor3f(0 , 1 , 1);
	glVertex3f(0.0 , 1.0 , 0.0);
	glVertex3f(0 , 1.0 , 1);
	glVertex3f(1 , 1 , 1);
	glVertex3f(1 , 1 , 0);
	glNormal3d(0 , 1 , 0);
	glEnd();

    //add points
	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glColor3f(1, 1, 1);
    glPointSize(10.0);
    glEnable(GL_POINT_SMOOTH);

	glBegin(GL_POLYGON);
	glVertex3f(0.0 , 0.0 , 1);
	glVertex3f(1 , 0.0 , 1);
	glVertex3f(1 , 1 , 1);
	glVertex3f(0.0 , 1 , 1);
	glNormal3d(0 , 0 , 1);
	glEnd();


	//Down side
	glBegin(GL_POLYGON);
	glVertex3f(0 , 0 , 0);
	glVertex3f(0 , 0 , 1);
	glVertex3f(1 , 0 , 1);
	glVertex3f(1 , 0 , 0);
	glNormal3d(0 , -1 , 0);
	glEnd();

	// Left side
	glBegin(GL_POLYGON);
	glVertex3f(0 , 0 , 0);
	glVertex3f(0 , 1 , 0);
	glVertex3f(0 , 1 , 1);
	glVertex3f(0 , 0 , 1);
	glNormal3d(-1 , 0 , 0);
	glEnd();

	// Right side
	glBegin(GL_POLYGON);
	glVertex3f(1.0 , 0.0 , 0);
	glVertex3f(1 , 1 , 0);
	glVertex3f(1 , 1 , 1);
	glVertex3f(1 , 0 , 1);
	glNormal3d(1 , 0 , 0);
	glEnd();

	//Front side
	glBegin(GL_POLYGON);
	glVertex3f(0.0 , 0.0 , 0.0);
	glVertex3f(1.0 , 0.0 , 0.0);
	glVertex3f(1.0 , 1.0 , 0.0);
	glVertex3f(0.0 , 1.0 , 0.0);
	glNormal3d(0 , 0 , -1);
	glEnd();

	//Top side
	glBegin(GL_POLYGON);
	glVertex3f(0.0 , 1.0 , 0.0);
	glVertex3f(0 , 1.0 , 1);
	glVertex3f(1 , 1 , 1);
	glVertex3f(1 , 1 , 0);
	glNormal3d(0 , 1 , 0);
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
