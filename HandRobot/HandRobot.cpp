#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float spinIHandRobot = 0; // WS
float spinICube2 = 40; // ws
float spinFingter1 = -45; // ED
float spinICube4 = 55; // ed
float spinFingter2 = 20; // RF
float spinICube6 = -55; // rf

void DrawHand(){
	// IHandRobot
	glPushMatrix();
	glTranslatef(-3.0, 0.0, 0.0);
	glRotatef(20, 0.0, 1.0, 0.0);	
	glRotatef(spinIHandRobot, 0.0, 0.0, 1.0);		
		// Hand
		glPushMatrix();
			glTranslatef(1.5, 0.0, 0.0);
			// Cube1
			glPushMatrix();			
			glScalef(3.0, 1.0, 1.0);
			glutWireCube (1.0);			
			glPopMatrix();
			
			// ICube2
			glPushMatrix();
			glTranslatef(1.5, 0.0, 0.0);
			glRotatef(spinICube2, 0.0, 0.0, 1.0);
				
				//Cube2
				glPushMatrix();			
				glTranslatef(1.5, 0.0, 0.0);
				glScalef(3.0, 1.0, 1.0);
				glutWireCube (1.0);
				glPopMatrix();
				
				// Fingter1
				glPushMatrix();
				glTranslatef(3, -0.35, 0);
				glRotatef(spinFingter1, 0.0, 0.0, 1.0);
					
					// Cube3
					glPushMatrix();
					glTranslatef(0.5, 0.0, 0.0);
					glScalef(1.0, 0.3, 0.25);
					glutWireCube (1.0);
					glPopMatrix();
					
					// ICube4
					glPushMatrix();
					glTranslatef(1, 0.0, 0.0);
					glRotatef(spinICube4, 0.0, 0.0, 1.0);
					
						// Cube4
						glPushMatrix();
						glTranslatef(0.5, 0.0, 0.0);
						glScalef(1.0, 0.3, 0.25);
						glutWireCube (1.0);
						glPopMatrix();
					
					glPopMatrix();
													
				glPopMatrix();
				
				// Fingter2
				glPushMatrix();
				glTranslatef(3, 0.35, 0);
				glRotatef(spinFingter2, 0.0, 0.0, 1.0);
					
					// Cube5
					glPushMatrix();
					glTranslatef(0.5, 0.0, 0.0);
					glScalef(1.0, 0.3, 0.25);
					glutWireCube (1.0);
					glPopMatrix();
					
					// ICube6
					glPushMatrix();
					glTranslatef(1, 0.0, 0.0);
					glRotatef(spinICube6, 0.0, 0.0, 1.0);
					
						// Cube6
						glPushMatrix();
						glTranslatef(0.5, 0.0, 0.0);
						glScalef(1.0, 0.3, 0.25);
						glutWireCube (1.0);
						glPopMatrix();
					
					glPopMatrix();
													
				glPopMatrix();
				
				// Fingter2R
				glPushMatrix();
				glTranslatef(3, 0.35, 0.375);
				glRotatef(spinFingter2, 0.0, 0.0, 1.0);
					
					// Cube5
					glPushMatrix();
					glTranslatef(0.5, 0.0, 0.0);
					glScalef(1.0, 0.3, 0.25);
					glutWireCube (1.0);
					glPopMatrix();
					
					// ICube6
					glPushMatrix();
					glTranslatef(1, 0.0, 0.0);
					glRotatef(spinICube6, 0.0, 0.0, 1.0);
					
						// Cube6
						glPushMatrix();
						glTranslatef(0.5, 0.0, 0.0);
						glScalef(1.0, 0.3, 0.25);
						glutWireCube (1.0);
						glPopMatrix();
					
					glPopMatrix();
													
				glPopMatrix();
				
				// Fingter2L
				glPushMatrix();
				glTranslatef(3, 0.35, -0.375);
				glRotatef(spinFingter2, 0.0, 0.0, 1.0);
					
					// Cube5
					glPushMatrix();
					glTranslatef(0.5, 0.0, 0.0);
					glScalef(1.0, 0.3, 0.25);
					glutWireCube (1.0);
					glPopMatrix();
					
					// ICube6
					glPushMatrix();
					glTranslatef(1, 0.0, 0.0);
					glRotatef(spinICube6, 0.0, 0.0, 1.0);
					
						// Cube6
						glPushMatrix();
						glTranslatef(0.5, 0.0, 0.0);
						glScalef(1.0, 0.3, 0.25);
						glutWireCube (1.0);
						glPopMatrix();
					
					glPopMatrix();
													
				glPopMatrix();
										
			glPopMatrix();						
			
		glPopMatrix();
	glPopMatrix();	
}

void keyboard (unsigned char key, int x, int y){
	switch(key){
		// Cube 2
		case 'w':
			spinICube2 += 2.0;
			glutPostRedisplay();
			break;
		case 's':
			spinICube2 -= 2.0;
			glutPostRedisplay();
			break;

		// Hand
		case 'W':
			spinIHandRobot += 2.0;
			glutPostRedisplay();
			break;
		case 'S':
			spinIHandRobot -= 2.0;
			glutPostRedisplay();
			break;
			
		// Fingter1
		case 'E':
			spinFingter1 += 2.0;
			glutPostRedisplay();
			break;
		case 'D':
			spinFingter1 -= 2.0;
			glutPostRedisplay();
			break;
			
		// Cube4
		case 'e':
			spinICube4 += 2.0;
			glutPostRedisplay();
			break;
		case 'd':
			spinICube4 -= 2.0;
			glutPostRedisplay();
			break;
			
		// Fingter2
		case 'R':
			spinFingter2 += 2.0;
			glutPostRedisplay();
			break;
		case 'F':
			spinFingter2 -= 2.0;
			glutPostRedisplay();
			break;
			
		// Cube6
		case 'r':
			spinICube6 += 2.0;
			glutPostRedisplay();
			break;
		case 'f':
			spinICube6 -= 2.0;
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
	gluLookAt (2.5, 2, 6.0, 0.0, 0.0, 0.0, 0.0, 1, 0.0);
	
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


