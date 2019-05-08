#include <GL/gl.h>
#include <GL/glut.h>

GLubyte rasters[203] = {0x3f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x40, 0x1c, 0x00, 0x38, 0x06, 0x07, 0x06,
						0x80, 0x07, 0x00, 0x1c, 0x09, 0x84, 0xc0,
						0xb0, 0x01, 0xc0, 0x0e, 0x0c, 0x66, 0x20,
						0x70, 0x00, 0x60, 0x07, 0x06, 0x33, 0x10,
						0x00, 0x00, 0x30, 0x03, 0xc3, 0x09, 0x0c,
						0x00, 0x00, 0x1c, 0x01, 0xa1, 0xc5, 0x82,
						0x00, 0x00, 0x0e, 0x04, 0xd8, 0xc2, 0xc1,
						0x00, 0x00, 0x07, 0x02, 0x64, 0x61, 0xe0,
						0x00, 0x00, 0x03, 0x81, 0x33, 0x20, 0x70,
						0x00, 0x00, 0x03, 0x80, 0x98, 0xc0, 0x38,
						0x00, 0x00, 0x01, 0xc0, 0x60, 0x00, 0x00,
						0x00, 0x0f, 0xc0, 0xc0, 0x16, 0x00, 0x00,
						0x00, 0x10, 0x30, 0x60, 0x0b, 0x00, 0x00,
						0x00, 0x20, 0x0c, 0x60, 0x05, 0x80, 0x03,
						0x00, 0x20, 0x02, 0x31, 0x83, 0xc0, 0x03,
						0x00, 0x10, 0x01, 0x19, 0x61, 0xe0, 0x00,
						0x00, 0x10, 0x00, 0x9a, 0x18, 0x70, 0x00,
						0x00, 0x00, 0x00, 0x4d, 0x0c, 0x38, 0x00,
						0x00, 0x08, 0x00, 0x47, 0x84, 0x1c, 0x00,
						0x00, 0x04, 0x00, 0x22, 0x64, 0x06, 0x00,
						0x00, 0x02, 0x00, 0x11, 0x32, 0x07, 0x00,
						0x00, 0x01, 0x00, 0x10, 0x82, 0x03, 0x00,
						0x00, 0x00, 0x80, 0x00, 0x62, 0x01, 0x80,
						0x00, 0x00, 0x40, 0x08, 0x32, 0x00, 0x00,
						0x00, 0x00, 0x30, 0x00, 0x1c, 0x00, 0x00,
						0x00, 0x00, 0x0c, 0x00, 0x04, 0x00, 0x00,
						0x00, 0x00, 0x03, 0x01, 0xb0, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x7f, 0xd0, 0xc0, 0x00
};

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
		glBitmap(56, 29, 0.0, 0.0, 57.0, 0.0, rasters);
	glEnd();
	glFlush ();
}
void init (void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Phi");
	init ();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

