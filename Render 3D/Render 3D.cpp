#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

GLfloat CangTay;

void SetMaterialColor(GLfloat mat_diffuse[4], GLfloat mat_ambient[4]){
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
}

GLuint MakeTruncatedCone(const float& base_rad, const float & top_rad, const float& length){
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	GLUquadricObj *quadratic_obj;
	quadratic_obj = gluNewQuadric();
	gluCylinder(quadratic_obj, base_rad, top_rad, length, 32, 32);
	glEndList();	
	return dp_list;
}

void SetMaterialColor(GLfloat ambient[4], GLfloat diff_use[4], GLfloat specular[]){
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
}

void Draw(){		
	glPushMatrix();
		
		GLfloat mat_diffuse[] = { 0.8157, 0.57255, 0.411765, 1.0 };
		GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	  	SetMaterialColor(mat_diffuse, mat_ambient);
	  	
		glTranslatef(0.0, -1, 0.0);
		glRotatef(-90, 1.0,0.0,0.0);
		glCallList(CangTay);
	
	glPopMatrix();
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();
	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	Draw();
	
	glFlush ();
}
void reshape (int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-1.5, 1.5, -1.5, 1.5, 1.0, 20);
	glMatrixMode (GL_MODELVIEW);
}

void init(void){	
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);      
	
	CangTay = MakeTruncatedCone(1, 0.75, 2.0);
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
	glutMainLoop();
	return 0;
}

