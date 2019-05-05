#include "glut.h"

#define NON -1
#define SUN 1
#define PLANET 2
#define BUFSIZE 512
static int year = 0, day = 0;
static int ichosen = NON; 

void init(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel (GL_FLAT);
}

void draw(GLint mode){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor3f (1.0, 0, 0);
	if (mode == GL_SELECT)
		glLoadName(SUN);
	if (ichosen == SUN)
		glutSolidSphere(1.0, 50, 50);
	else
		glutWireSphere(1.0, 20, 16);
		
	glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
	glTranslatef (2.0, 0.0, 0.0);
	glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
	glColor3f (0, 0, 1.0);
	if (mode == GL_SELECT)
		glLoadName(PLANET);
	if (ichosen == PLANET)
		glutSolidSphere(0.2, 30, 30);
	else
		glutWireSphere(0.2, 10, 8);
	glPopMatrix();
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	draw(GL_RENDER);
	glutSwapBuffers();
}

void processHits (GLint hits, GLuint buffer[]){
	unsigned int i, j;
	GLuint *ptr;
	float min_z_min;
	ptr = (GLuint *) buffer;
	ichosen = NON;
	for (i = 0; i < hits; i++) {
		GLuint names = *ptr; ptr++;
		float z_min = (float) *ptr/0x7fffffff; ptr++;
		float z_max = (float) *ptr/0x7fffffff; ptr++;
		GLuint name = *ptr;
		if ( i == 0 || min_z_min > z_min ){
			min_z_min = z_min;
			ichosen = name;
		}
	}
	ptr = (GLuint*) buffer;
}

void pick(int button, int state, int x, int y){
	GLuint selectBuf[BUFSIZE];
	GLint hits;
	GLint viewport[4];
	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
		return;
	glGetIntegerv (GL_VIEWPORT, viewport);
	glSelectBuffer (BUFSIZE, selectBuf);
	(void) glRenderMode (GL_SELECT);
	glInitNames();
	glPushName(0);
	
	glMatrixMode (GL_PROJECTION);
	glPushMatrix ();
	glLoadIdentity ();
	gluPickMatrix ((GLdouble) x, (GLdouble) (viewport[3]- y), 5.0, 5.0,viewport);
	gluPerspective(60.0, viewport[2]/viewport[3], 1.0, 20.0);
	draw(GL_SELECT);
	glMatrixMode (GL_PROJECTION);
	glPopMatrix ();
	glFlush ();
	hits = glRenderMode (GL_RENDER);
	processHits (hits, selectBuf);
	glutPostRedisplay();
}

void reshape (int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // thi?t l?p view
}

void keyboard (unsigned char key, int x, int y){
	switch (key) {
	case 'd':
		day = (day + 10) % 360;
		glutPostRedisplay();
		break;
	case 'D':
		day = (day - 10) % 360;
		glutPostRedisplay();
		break;
	case 'y':
		year = (year + 5) % 360;
		glutPostRedisplay();
	break;
		case 'Y':
		year = (year - 5) % 360;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(pick);
	glutMainLoop();
	return 0;
}
