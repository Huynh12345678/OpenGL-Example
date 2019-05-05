#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

# define pi           3.14159265358979323846  /* pi */
void HinhS(float x, float y, int diem){
	float step =  pi / diem; // (2 * pi) / (2 * diem)
	for(int i = 0; i < (diem * 2); i++){
		float r = (i % 2 == 0) ? 5 : 15;
		float angle = i * step;
		glVertex2f(r * cos(angle) + x, r * sin(angle) + y);
	}
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
		HinhS(20, 20, 5);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		HinhS(50, 20, 90);
	glEnd();	
	glFlush ();
}
void init (void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 80.0, 0, 40.0, -1.0, 1.0);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1000, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Bai2_2");
	init ();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
