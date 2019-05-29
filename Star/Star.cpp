#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

# define pi           3.14159265358979323846  /* pi */

float angleA = 0;
bool a = false;
void HinhS(float x, float y, int diem){
	float step =  pi / diem; // (2 * pi) / (2 * diem)
	for(int i = 0; i < (diem * 2); i++){
		float r = (i % 2 == 1) ? 0.5 : 1;
		float angle = i * step;
		glVertex3f(r * cos(angle) + x, r * sin(angle) + y, 0);
	}
}

void spinDisplayA(void){
	angleA += 0.2;
	if(angleA > 360)angleA -= 360;
	glutPostRedisplay();
}

void Draw(){
	glPushMatrix();
	
	
	if(a)glTranslatef(1,0,0);
	glRotatef(angleA, 0,0,1);
	if(a)glTranslatef(-1,0,0);
	glBegin(GL_LINE_LOOP);
		HinhS(0, 0, 5);
	glEnd();
	
	glPopMatrix();
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		a = false;
		glutIdleFunc(spinDisplayA);
	}	
}

void keyboard(unsigned char key, int x, int y){
	if(key == 'a'){
		a = true;
		glutIdleFunc(spinDisplayA);
	}
}

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
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
