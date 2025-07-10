#include<winbgim.h>
void rellenar();
main(){
	initwindow(600,300);
	setbkcolor(0);
	cleardevice();
	setcolor(12);
	setcolor(4);
	circle(300,150,100);
	setcolor(4);
	setfillstyle(1,5);
	fillellipse(300,150,100,100);
	rellenar;
	setbkcolor(4);
	setcolor(4);
	circle(250,120,20);
	setcolor(4);
	circle(350,120,20);
	moveto(300,150);
	lineto(300,165);
	setcolor(4);
	setfillstyle(1,4);
	fillellipse(350,120,20,20);
	fillellipse(250,120,20,20);
	arc(300,175,180,0,50);
	while(!kbhit())delay(1);
	closegraph();		
}
void rellenar(){
	setcolor(4);
	ellipse(300,150,90,90,100,100);
	setbkcolor(4);
	
}
