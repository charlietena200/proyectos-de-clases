#include<winbgim.h>
#include<stdlib.h>
#include<math.h>
void burbuja(int i, int y);
main(int argc, char *argv[]){
	int i, y=200;
	initwindow(400,550);
	setbkcolor(0);
	cleardevice();
	for(i=0;i<300;i++){
		setcolor(7);
		ellipse(190,480,0,360,20,10);
		ellipse(215,460,0,360,25,10);
		ellipse(240,480,0,360,25,10);
		ellipse(260,465,0,260,15,5);
		delay(50);
		cleardevice();
	}
	while(!kbhit()) delay(1);
	closegraph();
}
void burbuja(int i, int y){
	if(y<100){
	y=y+200;
	if(y>200){
	circle(200,y+100-i,10);
	}
	}else{
		circle(200,y+100-i,10);
	}
}
