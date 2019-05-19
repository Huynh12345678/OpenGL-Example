#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float angleA = 0;
float angleB = 0;
void spinDisplayA(void){
	angleA += 0.2;
	if(angleA > 360)angleA -= 360;
	glutPostRedisplay();
}
void spinDisplayB(void){
	angleB += 0.2;
	if(angleB > 360)angleB -= 360;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
	if(key == 'a'){
		glutIdleFunc(spinDisplayA);
	}
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		glutIdleFunc(spinDisplayB);
	}	
}

void Draw(){
	glPushMatrix();
		glTranslatef(-1.5, 0.0, 0.0);
		glRotatef(angleB, 0.0, 1.0, 0.0);
	
		glPushMatrix();
		
			glRotatef(angleA, 1.0, 0.0, 0.0);
			glTranslatef(3, 0.0, 0.0);	
			glutWireSphere(1.0, 18, 18);
		
		glPopMatrix();
	
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-1.5, 0.0, 0.0);
		glutWireSphere(1.0, 18, 18);
	
	glPopMatrix();
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity ();
	gluLookAt (0.0, 0.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
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
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

