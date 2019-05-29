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