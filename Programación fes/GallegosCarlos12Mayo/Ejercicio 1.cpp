#include<stdio.h>
void despliegaBits(unsigned valor);
main(){
	unsigned x;
	printf("Introduzca un entero sin signo: ");
	scanf("%u",&x);
	despliegaBits(x);
	return 0;
}
void despliegaBits(unsigned valor){
	unsigned c;
	unsigned despliegaMascara = 1 << 31;
	printf("%10u = ",valor);
	for(c=1;c<=32;c++){
		printf("%c",valor & despliegaMascara ? '1' : '0');
		valor <<= 1;
		if(c % 8 ==0){
			printf(" ");
		}
	}printf("\n");
}
