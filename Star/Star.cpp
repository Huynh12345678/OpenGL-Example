#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

# define pi           3.14159265358979323846  /* pi */
void HinhS(float x, float y, int diem){
	float step =  pi / diem; // (2 * pi) / (2 * diem)
	for(int i = 0; i < (diem * 2); i++){
		float r = (i % 2 == 0) ? 0.5 : 1;
		float angle = i * step;
		glVertex3f(r * cos(angle) + x, r * sin(angle) + y, 0);
	}
}
static GLfloat spin = 0.0;
void spinDisplay(void)
{
spin = spin + 2.0;
if (spin > 360.0)
spin = spin - 360.0;
glutPostRedisplay();
}

void Draw(){
	glPushMatrix();
	
	glRotatef(spin, 0.0, 0.0, 1.0);
	glRectf(-1.0, -1.0, 1.0, 1.0);
	glRotatef(45, 0.0, 0.0, 1.0);
	glRectf(-1.0, -1.0, 1.0, 1.0);
	
	glPopMatrix();
}

void mouse(int button, int state, int x, int y)
{switch (button) {
case GLUT_LEFT_BUTTON:
if (state == GLUT_DOWN)
glutIdleFunc(spinDisplay);
break;
case GLUT_MIDDLE_BUTTON:
if (state == GLUT_DOWN)
glutIdleFunc(NULL);
break;
default:
break;
}}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity ();
	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	Draw();
	
	glFlush ();
}
void reshape (int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-1, 1, -1, 1, 1.5, 20.0);
	glMatrixMode (GL_MODELVIEW);
}

void init(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

