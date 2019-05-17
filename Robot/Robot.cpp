#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float spinHand = 10;
float spinCube2 = 20;

void DrawHand(){
	// IHand
	glPushMatrix();
	glTranslatef(-5.0, 0.0, 0.0);
	glRotatef(spinHand, 0.0, 0.0, 1.0);		
		// Hand
		glPushMatrix();
			glTranslatef(2.5, 0.0, 0.0);
			// Cube1
			glPushMatrix();			
			glScalef(5.0, 1.0, 1.0);
			glutWireCube (1.0);			
			glPopMatrix();
			
			// ICube2
			glPushMatrix();
			glTranslatef(2.5, 0.0, 0.0);
			glRotatef(spinCube2, 0.0, 0.0, 1.0);
				
				//Cube2
				glPushMatrix();			
				glTranslatef(2.5, 0.0, 0.0);
				glScalef(5.0, 1.0, 1.0);
				glutWireCube (1.0);
				glPopMatrix();
				
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();	
}

void keyboard (unsigned char key, int x, int y){
	switch(key){
		case 'w':
			spinCube2 += 2.0;
			glutPostRedisplay();
			break;
		case 's':
			spinCube2 -= 2.0;
			glutPostRedisplay();
			break;
		case 'W':
			spinHand += 2.0;
			glutPostRedisplay();
			break;
		case 'S':
			spinHand -= 2.0;
			glutPostRedisplay();
			break;
		default:
			break;
	}
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity ();
	gluLookAt (0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	DrawHand();
	
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
	glutMainLoop();
	return 0;
}

