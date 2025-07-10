#include <stdio.h>
void despliegaBits(unsigned valor);
main(){
	unsigned numero1;
	unsigned numero2;
	unsigned mascara;
	unsigned estableceBits;
	numero1 = 65535;
	mascara = 1;
	printf("El resultado de combinar los siguietenes valores: \n");
	despliegaBits(numero1);
	despliegaBits(mascara);
	printf("\n con el uso del operado de bits AND (&) es \n");
	despliegaBits(numero1 & mascara);
	numero1 = 15;
	estableceBits=241;
	printf("\n El resultado de combinar los siguientes valores \n");
	despliegaBits(numero1);
	despliegaBits(estableceBits);
	printf("\n con el uso del operador de bits OR incluyente (|) es \n");
	despliegaBits(numero1|estableceBits);
	numero1=139;
	numero2=199;
	printf("\n El resultado de combinar los siguientes valores \n");
	despliegaBits(numero1);
	despliegaBits(numero2);
	printf("\n con el uso de operador de bits OR excluyente(^) es \n");
	despliegaBits(numero1^numero2);
	numero1=21845;
	printf("\n Operador not (comlemento a uno) \n");
	despliegaBits(numero1);
	despliegaBits((~numero1));
	return 0;
}
void despliegaBits(unsigned valor){
	unsigned c;
	unsigned despliegaMascara = 1 << 31;
	printf("%u = ", valor);
	for(c=1; c<=32; c++){
		printf("%c",valor & despliegaMascara ? '1' : '0');
		valor <<= 1;
		if(c %8 ==0){
			printf(" ");
		}
	}printf("\n");
}
