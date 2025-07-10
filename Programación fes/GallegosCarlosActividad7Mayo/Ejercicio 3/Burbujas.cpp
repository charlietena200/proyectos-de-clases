#include<winbgim.h>
#include<stdlib.h>
#include<math.h>
void burbuja(int i, int y);

main(){
	int i=0,n=0;
	int y=200;
	int w[10]={70,5,230,5,270,30,30,30,70,5};
	initwindow(300,300);
	cleardevice();
	rectangle(50,30,250,270);
	drawpoly(5,w);
	for(i=0;i<90;i++){
		setcolor(15);
		burbuja(i,y);
		y--;
		setcolor(15);
		ellipse(80,240,0,360,25,10);
		ellipse(90,260,0,360,25,10);
		ellipse(120,250,0,360,25,10);
		ellipse(140,260,0,360,15,5);
		ellipse(160,240,0,360,25,10);
		ellipse(190,260,0,360,25,10);
		ellipse(200,250,0,360,25,10);
		ellipse(230,260,0,360,15,5);
		delay(50);
		
	}
	while(!kbhit()) delay(1);
	closegraph();
}
void burbuja(int i, int y){
	if(y<190){
		y=y+200;
		if(y>200){
			setcolor(15);
			int t[10]={70+i,150,65+i,130,60+i,150,65+i,170,70+i,150};
			circle(70,y-180-i , 10);
			circle(90+i,150,20);
			circle(95+i,145,2);
			drawpoly(5,t);
			delay(100);
			setcolor(0);
			drawpoly(5,t);
			circle(95+i,145,2);
			circle(90+i,150,20);
			circle(70,y-180-i , 10);
		}
	}
}
