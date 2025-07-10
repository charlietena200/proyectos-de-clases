#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int opcion1();
int Lagrange(int n);
int FormulaNewton(int n);
int spline(int n);
int trapezoidal(float a, float b);
int simpson(float a, float b);

void ResuelveGauss(int Dim, float Sist[10][10]);

int main(){
	int op, bandera, n;
	do{
	
		op=opcion1();
	
		switch(op){
			case 1:
				
				printf("\n\n Numero de datos a ingresar: ");
    			scanf("%d",&n);
    			Lagrange(n);
    			break;
    		
			case 2:
				printf("\n\n Numero de datos a ingresar: ");
    			scanf("%d", &n);
    			FormulaNewton(n);
				break;
				
			case 3:
				printf("\n\n Numero de datos a ingresar: ");
    			scanf("%d", &n);
    			spline(n);
				break;
				
			case 4:
				float a,b;
				printf("\n Ingrese el valor de a: ");
				scanf("%f", &a);
				printf("\n Ingrese el valor de b: ");
				scanf("%f", &b);
				trapezoidal(a,b);
				break;
			case 5:
				float a1,b1;
				do{
					printf("\n Valor de a: ");
					scanf("%f", &a1);
					printf("\n Valor de b: ");
					scanf("%f", &b1);
				}while(b1<a1);
				simpson(a1,b1);
				break;
		}
		printf("Deseas volver a operar cualquier metodo\n1.si\t2.no\n");
		printf("opcion: ");
		scanf("%d",&bandera);	
	}while(bandera==1);
	return 0;
}

int opcion1(){
	int c, d;
	do{
	printf("que metodo deseas utilizar?\n");
	printf("1.Formula de Lagrange\n2.Formula de Newton\n");
	printf("3.Con Splines Cubico\n4.Regla Trapezoidal\n5.Regla de Simpson 1/3\n");
	printf("opcion: ");
	scanf("%d",&c);
	if(c<1 || c>5){
		printf("opcion incorrecta\n");
		d=1;
	}
	
}while(d==1);
return c;
}

int Lagrange(int n){
	
	float x[100],y[100],a,s=1,t=1,k=0;
    int i,j,d=1;
	
	printf("\n\n Ingrese los valorees de x y y: \n");
    for(i=0; i<n; i++)
    {
        scanf ("%f",&x[i]);
        scanf("%f",&y[i]);
    }
    printf("\n\n La tabla que ingresó es la siguiente :\n\n");
    for(i=0; i<n; i++){
        printf("%0.6f\t%0.6f",x[i],y[i]);
        printf("\n");
    }
    while(d==1){
        printf(" \n\n\n Ingrese el valor de x para encontrar el valor respectivo de y\n\n\n");
        scanf("%f",&a);
        for(i=0; i<n; i++){
            s=1;
            t=1;
            for(j=0; j<n; j++){
                if(j!=i){
                   
                    s=s*(a-x[j]);
                    t=t*(x[i]-x[j]);
                    
                }
            }
            k=k+((s/t)*y[i]);
        }
        printf("\n\n El valor respectivo de la variable y es: %0.6f",k);
        printf("\n\n Desea volver a operar metodo de Lagrenge\n 1.si o preciona cualquier tecla\n");
        printf("opcion: ");
        scanf("%d",&d);
    }
}



int FormulaNewton(int n){
	float x[100],fx[100],aux[100], aux1[100];
    int i,j, dd=1, ap;
	float ac, total;
	
	printf("\n\n Ingrese los valorees de x y y: \n");
    for(i=0; i<n; i++)
    {
        scanf("%f",&x[i]);
        scanf("%f",&fx[i]);
    }
    printf("\n\n La tabla que ingreso es la siguiente :\n\n");
    for(i=0; i<n; i++){
        printf("%0.6f\t%0.6f",x[i],fx[i]);
        printf("\n");
    }
	while(dd==1){
		for(i=0;i<n; i++){
			aux[i];
			for(j=0; j<n; j++){
				aux1[j]=(fx[j+1] - fx[j]) / (x[j+i+1] - x[j]);
			}
		}
		printf("\n\nNumero a aproximar: ");
		scanf("%d",&ap);
		
		//FORMULA FALTA 
		
		printf("\n\n El valor respectivo de la variable y es: %0.6f",total);
		
		printf("\n\n Desea volver a operar metodo de Lagrange\n 1.si o preciona cualquier tecla\n");
        printf("opcion: ");
        scanf("%d",&dd);
		
	}		
}

int trapezoidal(float a, float b){
	printf("\n\n Relga trapezoidal ");
	printf("\n Ingrese n ");
	int n=0;
	scanf("%d",&n);
			
	float h=(b-a)/n;
	printf("\n h= %f\n",h);
	int z=n+1;
	float x[z];
	x[0]=a+h;
	
	for(int i=1;i<z;i++){
		x[i]=x[i-1]+h;	
	}
	printf("\nIngrese los valores de f(y)\n");
	float y[n-1];
	float fa,fb;
	printf("\na=%f : ",a);
	scanf("%f",&fa);
	for(int i=0;i<n-1;i++){
		printf("\n x[%d]=%f : ",i+1,x[i]);
		scanf("%f",&y[i]);
	}
	printf("\nb=%f : ",b);
	scanf("%f",&fb);
	float area=0, suma=0;
	
	
	for(int i=0; i<n-1; i++){
		suma+=y[i];
	}
	
	area=(h/2)*((fa+fb)+(2*suma));
	
	printf("\n La operacion que se efectua es: (%f / 2) * (%f+%f)+(2*%f) \n\n",h,fa,fb,suma);
	printf("\n Con los valores indicados, la aproximacion al area es : %f\n\n", area);
	
	return 0;
	
}
int spline(int n){
	int i, j;
	float x[100],y[100], ec1[100];
	printf("\n\n Ingrese los valorees de x y y (primero x seguido de y): \n");
    for(i=0; i<n; i++)
    {
        scanf("%f",&x[i]);
        scanf("%f",&y[i]);
    }
    printf("\n\n La tabla que ingreso es la siguiente :\n\n");
    for(i=0; i<n; i++){
        printf("%0.6f\t%0.6f",x[i],y[i]);
        printf("\n");
    }
    printf("\n Definimos un polinomio cúbico\n");
    for(int i=1; i<n; i++){
    	printf("\na%d x^3 + b%d x^2 + c%d x + d%d si x[%f,%f]\n",i,i,i,i,x[i-1],x[i]);
    	
	}
	float res[8];
	float a[8],b[8],c[8],d[8];
	float a2[8],b2[8],c2[8],d2[8];
	for(int i=0; i<8; i++){
		a[i]=0;
		b[i]=0;
		c[i]=0;
		d[i]=0;
		a2[i]=0;
		b2[i]=0;
		c2[i]=0;
		d2[i]=0;  
		
		res[i]=0;
	}
	
	res[0]=y[0];
	res[1]=y[1];
	res[2]=y[1];
	res[3]=y[2];
	
	for(int i=0; i<=1; i++){
		a[i]=pow(x[i],3);
		b[i]=pow(x[i],2);
		c[i]=x[i];
		d[i]=1;
	}
	for(int i=2; i<=3; i++){
		a2[i]=pow(x[i-1],3);
		b2[i]=pow(x[i-1],2);
		c2[i]=x[i-1];
		d2[i]=1;
	}
	for(int i=4;i<=4;i++){
		a[i]=(3*pow(x[1],2));
		b[i]=(2*x[1]);
		c[i]=1;
		d[i]=0;
		a2[i]=-(3*pow(x[1],2));
		b2[i]=-(2*x[1]);
		c2[i]=-1;
		d2[i]=0;
	}
	
	a[5]=(6*x[1]);
	b[5]=2;
	c[5]=0;
	d[5]=0;
	a2[5]=-(6*x[1]);
	b2[5]=-2;
	c2[5]=0;
	d2[5]=0;
	
	
	
	a[6]=(6*x[0]);
	b[6]=2;
	
	a2[7]=(6*x[2]);
	b2[7]=2;
	
	for(int i=0; i<8; i++){
		printf("\n %f %f %f %f %f %f %f %f = %f\n",a[i],b[i],c[i],d[i],a2[i],b2[i],c2[i],d2[i],res[i]);
	}
	float Sist[10][10];
	int A,B;
	int Dim=8;
	for(A=1;A<=8;A++){
    	if(A==1){
    			Sist[A][1]=a[A-1];
    			Sist[A][2]=b[A-1];
    			Sist[A][3]=c[A-1];
    			Sist[A][4]=d[A-1];
    			Sist[A][5]=a2[A-1];
    			Sist[A][6]=b2[A-1];
    			Sist[A][7]=c2[A-1];
    			Sist[A][8]=d2[A-1];
				Sist[A][9]=res[A-1];}
    	if(A==2){
    			Sist[A][1]=a[A-1];
    			Sist[A][2]=b[A-1];
    			Sist[A][3]=c[A-1];
    			Sist[A][4]=d[A-1];
    			Sist[A][5]=a2[A-1];
    			Sist[A][6]=b2[A-1];
    			Sist[A][7]=c2[A-1];
    			Sist[A][8]=d2[A-1];
				Sist[A][9]=res[A-1];}
		if(A==3){
    			Sist[A][1]=a[A-1];
    			Sist[A][2]=b[A-1];
    			Sist[A][3]=c[A-1];
    			Sist[A][4]=d[A-1];
    			Sist[A][5]=a2[A-1];
    			Sist[A][6]=b2[A-1];
    			Sist[A][7]=c2[A-1];
    			Sist[A][8]=d2[A-1];
				Sist[A][9]=res[A-1];}
		if(A==4){
    			Sist[A][1]=a[A-1];
    			Sist[A][2]=b[A-1];
    			Sist[A][3]=c[A-1];
    			Sist[A][4]=d[A-1];
    			Sist[A][5]=a2[A-1];
    			Sist[A][6]=b2[A-1];
    			Sist[A][7]=c2[A-1];
    			Sist[A][8]=d2[A-1];
				Sist[A][9]=res[A-1];}
		if(A==5){
    			Sist[A][1]=a[A-1];
    			Sist[A][2]=b[A-1];
    			Sist[A][3]=c[A-1];
    			Sist[A][4]=d[A-1];
    			Sist[A][5]=a2[A-1];
    			Sist[A][6]=b2[A-1];
    			Sist[A][7]=c2[A-1];
    			Sist[A][8]=d2[A-1];
				Sist[A][9]=res[A-1];}
		if(A==6){
    			Sist[A][1]=a[A-1];
    			Sist[A][2]=b[A-1];
    			Sist[A][3]=c[A-1];
    			Sist[A][4]=d[A-1];
    			Sist[A][5]=a2[A-1];
    			Sist[A][6]=b2[A-1];
    			Sist[A][7]=c2[A-1];
    			Sist[A][8]=d2[A-1];
				Sist[A][9]=res[A-1];}
		if(A==7){
    			Sist[A][1]=a[A-1];
    			Sist[A][2]=b[A-1];
    			Sist[A][3]=c[A-1];
    			Sist[A][4]=d[A-1];
    			Sist[A][5]=a2[A-1];
    			Sist[A][6]=b2[A-1];
    			Sist[A][7]=c2[A-1];
    			Sist[A][8]=d2[A-1];
				Sist[A][9]=res[A-1];}
		if(A==8){
    			Sist[A][1]=a[A-1];
    			Sist[A][2]=b[A-1];
    			Sist[A][3]=c[A-1];
    			Sist[A][4]=d[A-1];
    			Sist[A][5]=a2[A-1];
    			Sist[A][6]=b2[A-1];
    			Sist[A][7]=c2[A-1];
    			Sist[A][8]=d2[A-1];
				Sist[A][9]=res[A-1];}	
		}
	
    for(A=1;A<=Dim;A++){
        for(B=1;B<=(Dim+1);B++){
            printf("%7.2f",Sist[A][B]);
            if(B==Dim) printf("   |");}
        printf("\n");}
	
	int C,Dimension=8;
    
    ResuelveGauss(Dimension,Sist);
    printf("\n\n\nLas soluciones son:\n");
    for(C=1;C<=Dimension;C++) printf("\n X%d=%f\n",C,Sist[C][Dimension+1]);
   	
   	printf("\n\n Por lo tanto el polinomio nos queda : \n");
   	printf("%fx^3 + %fx^2 + %fx + %f si x[%f,%f]\n",Sist[1][9],Sist[2][9],Sist[3][9],Sist[4][9],x[0],x[1]);
   	printf("%fx^3 + %fx^2 + %fx + %f si x[%f,%f]\n\n\n",Sist[5][9],Sist[6][9],Sist[7][9],Sist[8][9],x[1],x[2]);
    scanf("");
    
	return 0;
	
}
int simpson(float a, float b){
	printf("\n\n Método de simpson con %f %f",a,b);
	printf("\n Ingrese n (debe de ser par): ");
	int n=0;
	do{
		scanf("%d",&n);
		if(n%2!=0){
			printf("\n n no es par \n Ingrese otro: ");
		}
	}while(n%2!=0);
	float h=(b-a)/n;
	printf("\n h= %f\n",h);
	int z=n+1;
	float x[z];
	x[0]=a+h;
	
	for(int i=1;i<z;i++){
		x[i]=x[i-1]+h;	
	}
	printf("\nIngrese los valores de f(y)\n");
	float y[n-1];
	float fa,fb;
	printf("\na=%f : ",a);
	scanf("%f",&fa);
	for(int i=0;i<n-1;i++){
		printf("\n x[%d]=%f : ",i+1,x[i]);
		scanf("%f",&y[i]);
	}
	printf("\nb=%f : ",b);
	scanf("%f",&fb);
	float area=0;
	float pares=0, nones=0;
	for(int i=0; i<n-1; i++){
		if(i%2==0){
			nones+=y[i];
		}
		if(i%2!=0){
			pares+=y[i];
		}
	}
	printf("\npares %f   nones %f \n",pares,nones);
	printf("%f",h/3);
	area=(h/3)*((fa+fb)+(2*pares)+(4*nones));
	printf("\n La operacion que se efectua es: (%f / 3) * (%f+%f +(2*%f)+(4*%f) \n\n",h,fa,fb,pares,nones);
	printf("\n Con los valores indicados, la aproximacion al area es : %f\n\n", area);
}




void ResuelveGauss(int Dim, float Sist[10][10])
{
    int NoCero,Col,C1,C2,A;
    float Pivote,V1;
   
    for(Col=1;Col<=Dim;Col++){
        NoCero=0;A=Col;
        while(NoCero==0){
           if((Sist[A][Col]>0.0000001)||((Sist[A][Col]<-0.0000001))){
                NoCero=1;}
            else A++;}
        Pivote=Sist[A][Col];
        for(C1=1;C1<=(Dim+1);C1++){
            V1=Sist[A][C1];
            Sist[A][C1]=Sist[Col][C1];
            Sist[Col][C1]=V1/Pivote;}
        for(C2=Col+1;C2<=Dim;C2++){
            V1=Sist[C2][Col];
            for(C1=Col;C1<=(Dim+1);C1++){
                Sist[C2][C1]=Sist[C2][C1]-V1*Sist[Col][C1];}
    }}
   
    for(Col=Dim;Col>=1;Col--) for(C1=(Col-1);C1>=1;C1--){
        Sist[C1][Dim+1]=Sist[C1][Dim+1]-Sist[C1][Col]*Sist[Col][Dim+1];
        Sist[C1][Col]=0;
    }
}

