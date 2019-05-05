#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

using namespace std;
vector<int> arrX;
vector<int> arrY;
void display(void);
void mouse(int button, int state, int x, int y){
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){
				arrX.push_back(x);
				arrY.push_back(y);
				glutPostRedisplay();
			}
			break;
	}
}
void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glBegin(GL_LINES);		
		for(int i = 0; i < arrX.size(); i++)
			glVertex2i(arrX[i],arrY[i]);
	glEnd();
	glFlush ();
}

void init (void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 600, 600, 0, -1.0, 1.0);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Bai3");	
	init ();
	glutDisplayFunc(display);	
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
