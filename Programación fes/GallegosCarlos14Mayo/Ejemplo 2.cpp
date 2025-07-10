#include <stdio.h>
void despliegaBits(unsigned valor);
main(){
	unsigned number=960;
	printf("Resultado de corrimiento a la izquierda : \n");
	despliegaBits(number);
	printf("Corrimiento de posiciones de 8 bits a la izquierda: \n");
	despliegaBits(number<<8);
	printf("Resultado de corrimioento a la dereceha: \n");
	despliegaBits(number);
	printf("Corrimiento posiciones de 8 bits a la derecha: \n");
	despliegaBits(number>>8);
	return 0;
}
void despliegaBits(unsigned valor){
	unsigned c;
	unsigned despliegaMascara = 1 << 15;
	printf("%7u = ", valor);
	for(c=1; c<=16; c++){
		printf("%c",valor & despliegaMascara ? '1' : '0');
		valor <<=1;
		if(c % 8 ==0){
			printf(" ");
		}
	}
	printf("\n");
}
