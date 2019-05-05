#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

# define pi           3.14159265358979323846  /* pi */
void HinhS(float x, float y, int diem){
	float step =  pi / diem; // (2 * pi) / (2 * diem)
	for(int i = 0; i < (diem * 2); i++){
		float r = (i % 2 == 0) ? 5 : 10;
		float angle = i * step;
		glVertex2f(r * cos(angle) + x, r * sin(angle) + y);
	}
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
		HinhS(0, 7.5, 180);		
	glEnd();
	glBegin(GL_LINE_LOOP);
		HinhS(0, -7.5, 180);		
	glEnd();	
	glFlush ();
}
void init (void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20.0, 20.0, -40.0, 40.0, -1.0, 1.0);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (300, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Bai2_4");
	init ();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
