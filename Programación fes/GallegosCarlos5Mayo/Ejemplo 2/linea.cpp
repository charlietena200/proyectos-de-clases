#include <winbgim.h>
main(int argc, char *argv[]){
	initwindow(400,300);
	moveto(0,0);
	lineto(50,250);
	setcolor(12);
	moveto(200,0);
	lineto(50,250);
	while(!kbhit()) delay(1);
}
