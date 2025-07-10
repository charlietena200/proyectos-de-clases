#include <stdio.h>
//declaramos los procedimientos
void encripta(char *mensaje, char clave, int tam);
void desencripta(char *mensaje, char clave, int tam);
void muestra_mensaje(char *mensaje, int tam);
int cuenta(char *mensaje);
main(void){
	char mascara = 45;
	char texto[15];
	int c=0;
	//Pedimos el texto
	printf("dame un texto \n");
	gets(texto);
	printf("Mensaje original: %s\n", texto);
	printf("En bytes: ");
	//Mandamos a llamar a los procedimientos y funciones
	c=cuenta(texto);
	printf("total %d : \n", c);
	muestra_mensaje(texto, c);
	
	encripta(texto,mascara,c);
	printf("Encriptado: %s\n", texto);
	printf("Encriptado en bytes: ");
	muestra_mensaje(texto, c);
	
	desencripta(texto,mascara,c);
	printf("Desencriptado: %s\n", texto);
	printf("Desencriptado en bytes: ");
	muestra_mensaje(texto,c);
	
}
int cuenta(char *mensaje){
	//Ésta función nos dice cuantas letras contiene nuestro texto
	int i=0;
		while(mensaje[i]!='\0')//compara a los caracteres del texto con la nulidad
			i++;
		return i;//devuelve el tamaño de nuestro texto
}
void encripta(char *mensaje, char clave, int tam){//mandamos "*mensaje" como un apuntador para que se cambie en tiempo de ejecución
	int i;
	for(i=0; i<tam; i++)
		mensaje[i]^=clave;//El operador ^= es un Or exclusivo de asignación de bits. Guarda ese resultado en mensaje[i]. 
		/*Lo convierte en un valor que se despues se va a traducir a código asscii. Por ejemplo, 45 vale 101101 en bits, si la letra con la que la 
		comparamos es h (que vale 104 en asscii y 1101000 en binario), el resultado de ese or excluyente será 1000101 ó 69 en decimal, el cual equivale al 
		caracter E en asscii.*/
}
void desencripta(char *mensaje, char clave, int tam){
	encripta(mensaje,clave,tam);//Para volver a obtener el mensaje, volvemos a hacer el procedimiento de encripta
}
void muestra_mensaje(char *mensaje, int tam){//El procedimiento nos da los valores hexadecimales de los caracteres de nuestro texto
	int i;
	for(i=0;i<tam;i++){
		printf("0x%X ", mensaje[i]);//Aqui nos imprime el valor "0x" y el valor hexadecimal de nuestras letras
	}
	printf("\n");
}
//El progrma maneja varios sistemas numéricos: decimal, binario, hexadecimal y también maneja código asscii
/*El programa nos convierte un texto a hexadecimal y nos dice su valor en bytes. También el programa nos encripta una linea de texto. Es decir,
compara el valor de los caracteres con el valor de "45" y hace una operación (en este caso or excluyente). Luego lo traduce a código asscii y nos muestra el
nuevo texto. es muy útil para ocultar mensajes o por seguridad, porque se necesita saber la operación que se hizo y los valores*/
//Lo que hace ^= lo explico en la linea 42
