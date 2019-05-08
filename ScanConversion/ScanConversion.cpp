#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

# define pi           3.14159265358979323846  /* pi */
void HCN(int x0, int y0, int width, int height){
	for(int x = x0; x <= x0 + width; x++)
		for(int y = y0; y <= y0 + height; y++)
			glVertex2i(x,y);
}

void Tron(int x, int y, int r){
	for(int angle = 0; angle < 360; angle++){
		glVertex2i(x,y);
		glVertex2f(r * cos(angle) + x, r * sin(angle) + y);
	}
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);	
	glBegin(GL_POINTS);
		glColor3f (0.0, 1.0, 0.0);
		HCN(20, 20, 100, 100);
	glEnd();
	
	glBegin(GL_LINES);
		glColor3f (1.0, 1.0, 1.0);
		Tron(200, 200, 40);
	glEnd();
	glFlush ();
}
void init (void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 800.0, 0.0, 800.0, -1.0, 1.0);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Scan Conversion");
	init ();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
