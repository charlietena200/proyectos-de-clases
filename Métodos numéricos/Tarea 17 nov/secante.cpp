/*Carlos Alberto Gallegos Tena 420090618 Tarea método de la secante*/
#include<stdio.h>
#include<math.h>


void uno(float xi, float xu){
	#define RAIZ(x)((x*x*x) - (x)-1)
	float  xr, xa, ea;
int iteraciones;

 
iteraciones = 0;
xa = 0.0;
ea = 0;
printf("%12s %10s %10s %10s %10s\n", "Iteraciones", "Xn-1", "Xn", "Xn+1", "Error rel");
 
iteraciones++;
float dif;
float erel;
int w=1;

do{
        dif=xu-xi;
		xr= (xu-(((RAIZ(xu))*(dif))/((RAIZ(xu))-(RAIZ(xi)))));
		erel=(fabs(xu-xr))/(fabs(xr));
        printf("%12d %10f %10f %10f %f\n", w, xi, xu, xr, erel);
        
        xi=xu;
		xu=xr;
        w++;
    }while(erel>(0.00001)&&w<25);
 
printf("\nLa raiz es de f(x) = x^3 -x -1; es: %f\n", xr);
	}
void dos(float xi, float xu){
		#define RAIZdos(x)(-2*(x*x*x) - (4*(x*x)) + (4*x) +4)
	float  xr, xa, ea;
int iteraciones;

 
iteraciones = 0;
xa = 0.0;
ea = 0;

printf("%12s %10s %10s %10s %10s\n", "Iteraciones", "Xn-1", "Xn", "Xn+1", "Error rel");
 

iteraciones++;
float dif;
float erel;
int w=0;
do{
        dif=xu-xi;
		xr= (xu-(((RAIZdos(xu))*(dif))/((RAIZdos(xu))-(RAIZdos(xi)))));
		erel=(fabs(xu-xr))/(fabs(xr));
        printf("%12d %10f %10f %10f %f\n", w, xi, xu, xr, erel);
        
        xi=xu;
		xu=xr;
        w++;
    }while(erel>(0.00001)&&w<25);
 
printf("\nLa raiz es de f(x) = -2x^3 - 4x^2  + 4x  + 4; es: %f\n", xr);
	}
void tres(float xi, float xu){
	#define RAIZtres(x)(x-(2*(1/x)))
	float  xr, xa, ea;
int iteraciones;

 
iteraciones = 0;
xa = 0.0;
ea = 0;
 
printf("%12s %10s %10s %10s %10s\n", "Iteraciones", "Xn-1", "Xn", "Xn+1", "Error rel");
 
iteraciones++;
float dif;
float erel;
int w=0;
do{
        dif=xu-xi;
		xr= (xu-(((RAIZtres(xu))*(dif))/((RAIZtres(xu))-(RAIZtres(xi)))));
		erel=(fabs(xu-xr))/(fabs(xr));
        printf("%12d %10f %10f %10f %f\n", w, xi, xu, xr, erel);
        
        xi=xu;
		xu=xr;
        w++;
    }while(erel>(0.00001)&&w<25);
printf("\nLa raiz es de f(x) = x-2^-x; es: %f\n", xr);
}
void cuatro(float xi, float xu){
	#define RAIZcuatro(x)(exp(x)+ (2/x) + (2*cos(x))- 6)
	float  xr, xa, ea;
int iteraciones;

 
iteraciones = 0;
xa = 0.0;
ea = 0;
printf("%12s %10s %10s %10s %10s\n", "Iteraciones", "Xn-1", "Xn", "Xn+1", "Error rel");
 

iteraciones++;
float dif;
float erel;
int w=0;
do{
        dif=xu-xi;
		xr= (xu-(((RAIZcuatro(xu))*(dif))/((RAIZcuatro(xu))-(RAIZcuatro(xi)))));
		erel=(fabs(xu-xr))/(fabs(xr));
        printf("%12d %10f %10f %10f %f\n", w, xi, xu, xr, erel);
        
        xi=xu;
		xu=xr;
        w++;
    }while(erel>(0.00001)&&w<25);
 
printf("\nLa raiz es de f(x) = e^x  + 2^-x + 2cosx -6; es: %f\n", xr);
}

int main(){
	printf("Método de la secante \n Escoge una opcion:\n");
	printf("1) x^3 - x - 1 \n2)-2x^3 - 4x^2  + 4x  + 4\n");
	printf("3) x-2^-x para 0<x<1 \n4)e^x  + 2^-x + 2cosx -6 para 1<x<2   ");
	float xi, xo;
	int opcion;
	char c;
	while(!(scanf("%i%c",&opcion,&c) == 2 && c=='\n') || (opcion <1 || opcion>4)){
		printf("\n Ingresa opcion valida \n");
		while(getchar() != '\n');
	}
	printf("\nIngresa el valor de x0 : ");
	while(!(scanf("%f%c",&xi,&c) == 2 && c=='\n')){
		printf("\n Ingresa opcion valida \n");
		while(getchar() != '\n');
	}
	printf("\nIngresa el valor de x1 : ");
	while(!(scanf("%f%c",&xo,&c) == 2 && c=='\n')){
		printf("\n Ingresa opcion valida \n");
		while(getchar() != '\n');
	}
	if(opcion==1){
		uno(xi,xo);
	}
	if(opcion==2){
		dos(xi,xo);
	}
	if(opcion==3){
		tres(xi,xo);
	}
	if(opcion==4){
		cuatro(xi,xo);
	}
}
