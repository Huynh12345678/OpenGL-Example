#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;
void bre(int x1, int y1, int x2, int y2, int dashed, int thick){
	int dx, dy, x, y, d;
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	d = dx - 2*dy;
	int dem = 0;
	while(x <= x2){		
		if(dem < dashed){						
			for(int i = -(int)(thick/2); i < thick - (int)(thick/2) ; i++)
				glVertex2f(x,y + i);
			//cout<<x<<endl;
		}
		if(d > 0)d = d - 2*dy;
		else {
			d = d + 2*dx - 2*dy;
			y++;
		}
		x++;
		dem++;	
		if(dem == 20)dem = 0;	
	}
}

void breTK(int x1, int y1, int x2, int y2){
	unsigned long long pattern =0xFFC00FFC00;
	unsigned long long mask =0x8000000000;
	int dx, dy, x, y, d;
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	d = dx - 2*dy;
	while(x <= x2){
		if (pattern&mask){
			//cout<<x<<endl;
			glVertex2f(x,y);
		}
		mask>>=1;
		if(d > 0)d = d - 2*dy;
		else {
			d = d + 2*dx - 2*dy;
			y++;
		}
		x++;
		mask=mask? mask : 0x8000000000;
	}
}

void breTQ(int x1, int y1, int x2, int y2){
	int dx, dy, x, y, d;
	x = x1;
	y = y1;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1; 
	int sy = (y1 < y2) ? 1 : -1;
	d = dx - 2*dy;
	
	bool p = (dx > dy) ? true : false;
	
	if(p)
		while(true){
			if(x > x2 && x1 < x2) return;
			if(x < x2 && x1 > x2) return;
			glVertex2f(x,y);
			cout<<"\t"<<x<<"\t"<<y<<"\t"<<d<<endl;
			if(d > 0)d = d - 2*dy;
			else {
				d = d + 2*dx - 2*dy;
				y += sy;
			}
			x += sx;
		}
	else
		while(true){
			if(y > y2 && y1 < y2) return;
			if(y < y2 && y1 > y2) return;
			glVertex2f(x,y);
			cout<<"\t"<<x<<"\t"<<y<<"\t"<<d<<endl;
			if(d > 0)d = d - 2*dx;
			else {
				d = d + 2*dy - 2*dx;
				x += sx;
			}
			y += sy;
		}
}

//void breTQ1(int x1, int y1, int x2, int y2){
//	int dx, dy, x, y, d;
//	x = x1;
//	y = y1;
//	dx = abs(x2 - x1);
//	dy = abs(y2 - y1);
//	int sx = (x1 < x2) ? 1 : -1; 
//	int sy = (y1 < y2) ? 1 : -1;
//	d = dx - 2*dy;
//	while(true){
//		if(x > x2 && x1 < x2) return;
//		if(x < x2 && x1 > x2) return;
//		glVertex2f(x,y);
//		if(d > 0)d = d - 2*dy;
//		else {
//			d = d + 2*dx - 2*dy;
//			y += sy;
//		}
//		x += sx;
//	}
//}
//
//void breTQ2(int x1, int y1, int x2, int y2){
//	int dx, dy, x, y, d;
//	x = x1;
//	y = y1;
//	dx = abs(x2 - x1);
//	dy = abs(y2 - y1);
//	int sx = (x1 < x2) ? 1 : -1; 
//	int sy = (y1 < y2) ? 1 : -1;
//	d = dx - 2*dy;
//	while(true){
//		if(y > y2 && y1 < y2) return;
//		if(y < y2 && y1 > y2) return;
//		glVertex2f(x,y);
//		if(d > 0)d = d - 2*dx;
//		else {
//			d = d + 2*dy - 2*dx;
//			x += sx;
//		}
//		y += sy;
//	}
//}

void bre1(int x1, int y1, int x2, int y2){
	int dx, dy, x, y, d;
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	d = dx - 2*dy;
	while(x <= x2){
		glVertex2f(x,y);
		cout<<"\t"<<x<<"\t"<<y<<"\t"<<d<<endl;
		if(d > 0)d = d - 2*dy;
		else {
			d = d + 2*dx - 2*dy;
			y++;
		}
		x++;
	}
}

void bre2(int x1, int y1, int x2, int y2){
	int dx, dy, x, y, d;
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	d = dy - 2*dx;
	while(y <= y2){
		glVertex2f(x,y);
		if(d > 0)d = d - 2*dx;
		else {
			d = d + 2*dy - 2*dx;
			x++;
		}
		y++;
	}
}

void bre3(int x1, int y1, int x2, int y2){
	int dx, dy, x, y, d;
	x = x1;
	y = y1;
	dx = x1 - x2;
	dy = y2 - y1;
	d = dy - 2*dx;
	while(y <= y2){
		glVertex2f(x,y);
		if(d > 0)d = d - 2*dx;
		else {
			d = d + 2*dy - 2*dx;
			x--;
		}
		y++;
	}
}

void bre4(int x1, int y1, int x2, int y2){
	int dx, dy, x, y, d;
	x = x1;
	y = y1;
	dx = x1 - x2;
	dy = y2 - y1;
	d = dx - 2*dy;
	while(x >= x2){
		glVertex2f(x,y);
		if(d > 0)d = d - 2*dy;
		else {
			d = d + 2*dx - 2*dy;
			y++;
		}
		x--;
	}
}

void bre5(int x1, int y1, int x2, int y2){
	int dx, dy, x, y, d;
	x = x1;
	y = y1;
	dx = x1 - x2;
	dy = y1 - y2;
	d = dx - 2*dy;
	while(x >= x2){
		glVertex2f(x,y);
		if(d > 0)d = d - 2*dy;
		else {
			d = d + 2*dx - 2*dy;
			y--;
		}
		x--;
	}
}

void bre6(int x1, int y1, int x2, int y2){
	int dx, dy, x, y, d;
	x = x1;
	y = y1;
	dx = x1 - x2;
	dy = y1 - y2;
	d = dy - 2*dx;
	while(y >= y2){
		glVertex2f(x,y);
		if(d > 0)d = d - 2*dx;
		else {
			d = d + 2*dy - 2*dx;
			x--;
		}
		y--;
	}
}

void bre7(int x1, int y1, int x2, int y2){
	int dx, dy, x, y, d;
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y1 - y2;
	d = dy - 2*dx;
	while(y >= y2){
		glVertex2f(x,y);
		cout<<"\t"<<x<<"\t"<<y<<"\t"<<d<<endl;
		if(d > 0)d = d - 2*dx;
		else {
			d = d + 2*dy - 2*dx;
			x++;
		}
		y--;
	}
}

void bre8(int x1, int y1, int x2, int y2){
	int dx, dy, x, y, d;
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y1 - y2;
	d = dx - 2*dy;
	while(x <= x2){
		glVertex2f(x,y);
		if(d > 0)d = d - 2*dy;
		else {
			d = d + 2*dx - 2*dy;
			y--;
		}
		x++;
	}
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);	
	glBegin(GL_POINTS);
	// Ve truc
//	glColor3f (1.0, 0.0, 0.0);
//	bre1(-200,0,200,0);
//	bre2(0,-200,0,200);
//	bre1(-180,-180,180,180);
//	bre3(180,-180,-180,180);
//		// Ve duong thang
//		glColor3f (0.0, 1.0, 0.0);
//		//bre1(20,10,150,70);
//		breTQ(20,10,150,70);		
//		//bre2(10,20,70,150);
//		breTQ(10,20,70,150);
//		//bre3(-10,20,-70,150);
//		breTQ(-10,20,-70,150);
//		//bre4(-20,10,-150,70);
//		breTQ(-20,10,-150,70);
//		//bre5(-20,-10,-150,-70);
//		breTQ(-20,-10,-150,-70);
//		//bre6(-10,-20,-70,-150);
//		breTQ(-10,-20,-70,-150);
//		//bre7(10,-20,70,-150);
//		breTQ(10,-20,70,-150);
//		//bre8(20,-10,150,-70);
//		breTQ(20,-10,150,-70);
		
		//bre(70,10,180,30, 10, 7);
		//breTK(70,10,180,30);
		//breTK(70,2,180,22);
		bre7(10, -5, 15, -20);
	glEnd();
	
	//bre1(12,20,22,27);
	
	glFlush();
}
void init (void) {
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200.0, 200.0, -200.0, 200.0, -1.0, 1.0);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Bai 2 ");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

