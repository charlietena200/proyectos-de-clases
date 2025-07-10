#include <winbgim.h>
main(int argc, char *argv[]){
	initwindow(300,500);
	moveto(0,0);
	setcolor(15);
	rectangle(100,20,200,270);
	setfillstyle(1,4);
	delay(2000);
	fillellipse(150,65,40,40);
	outtextxy(130,58,"Alto");
	delay(2000);
	setfillstyle(1,0);
	fillellipse(150,65,40,40);
	setcolor(0);
	circle(150,65,40);
	delay(2000);
	circle(150,145,40);
	setfillstyle(1,14);
	fillellipse(150,145,40,40);
	setcolor(15);
	outtextxy(123,138,"Go slow");
	delay(2000);
	setcolor(15);
	setfillstyle(1,0);
	fillellipse(150,145,40,40);
	setcolor(0);
	circle(150,145,40);
	delay(2000);
	circle(150,225,40);
	setfillstyle(1,2);
	fillellipse(150,225,40,40);
	setcolor(15);
	outtextxy(130,218,"Avanza");
	setcolor(0);
	while(!kbhit())delay(1);
	closegraph();
}
