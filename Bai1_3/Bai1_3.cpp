#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

using namespace std;
vector<int> arrX;
vector<int> arrY;
bool check = true;

void breTQ(int x1, int y1, int x2, int y2){
	int dx, dy, x, y, d;
	x = x1;
	y = y1;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1; 
	int sy = (y1 < y2) ? 1 : -1;
	d = dx - 2*dy;
	
	bool p = (dx > dy) ? true : false;
	
	if(p)
		while(true){
			if(x > x2 && x1 < x2) return;
			if(x < x2 && x1 > x2) return;
			glVertex2f(x,y);
			if(d > 0)d = d - 2*dy;
			else {
				d = d + 2*dx - 2*dy;
				y += sy;
			}
			x += sx;
		}
	else
		while(true){
			if(y > y2 && y1 < y2) return;
			if(y < y2 && y1 > y2) return;
			glVertex2f(x,y);
			if(d > 0)d = d - 2*dx;
			else {
				d = d + 2*dy - 2*dx;
				x += sx;
			}
			y += sy;
		}
}

void display(void);
void mouse(int button, int state, int x, int y){
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){
				arrX.push_back(x);
				arrY.push_back(y);
				glutPostRedisplay();
				check = !check;
			}
			break;
	}
}
void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
//	glBegin(GL_LINES);		
//		for(int i = 0; i < arrX.size(); i++)
//			glVertex2i(arrX[i],arrY[i]);
//	glEnd();

	glBegin(GL_POINTS);		
		for(int i = 0; i < arrX.size(); i+=2)
			// Error
			if(check)breTQ(arrX[i],arrY[i], arrX[i + 1], arrY[i +1]);
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
