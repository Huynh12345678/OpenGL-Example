#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float spin = 0;

void Draw(){
	glPushMatrix();
	
	glRotatef (spin, 1.0, 0.0, 0.0);
	glutWireCube (1.0);
	
	glPopMatrix();
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity ();
	gluLookAt (0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
	
	Draw();
	
	glFlush ();
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		spin += 2.0;
		if(spin > 360)spin -= 360;
		glutPostRedisplay();
	}
}

void reshape (int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-1.5, 1.5, -1.5, 1.5, 1.5, 20.0);
	glMatrixMode (GL_MODELVIEW);
}

void init(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
