#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int day= 0;
void Draw(){
	glPushMatrix();
		GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
		GLfloat mat_ambient[] = { 0.545, 0.0, 0.0, 1.0 };
	    GLfloat mat_shininess[] = { 50.0 };
	    
	    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	    
		glRotatef(45,0,0,1);
		glScalef(15,0.6,5);
		glutSolidCube(1.0);
	glPopMatrix();
	glPushMatrix();
		GLfloat mat_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_diffuse1[] = { 0.0, 1.0, 0.0, 1.0 };
		GLfloat mat_ambient1[] = { 0.0, 0.545, 0.0, 1.0 };
	    GLfloat mat_shininess1[] = { 50.0 };
	    
	    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
	    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
				
		glTranslatef(5,7,0);
		glTranslatef( (GLfloat) day/40 , (GLfloat) day/40 , 0);
		glRotatef (((GLfloat) day)*(-1), 0, 0, 1);
		glutSolidSphere(1, 20, 15);
	glPopMatrix();
}

void keyboard (unsigned char key, int x, int y){
	switch (key) {
		case '.':
			day = (day + 1)/1.1;
			glutPostRedisplay();
			break;
		case ',':
			day = (day - 1)*1.1;
			glutPostRedisplay();
			break;
		default:
			break;
	}
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();
	gluLookAt (0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
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
    glShadeModel (GL_SMOOTH);
    
    GLfloat light0_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat light0_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);

    glEnable(GL_LIGHTING);    
    	glEnable(GL_LIGHT0);    
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
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


