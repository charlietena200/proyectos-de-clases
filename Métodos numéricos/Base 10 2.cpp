//Carlos Alberto Gallegos Tena 420090618 Métodos numéricos
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void basediez();
void basedos();
int main()
{
    int h=0;
    do{
        printf("\tTarea\t\n\n De base 10 a base 2 presiona 1\n\n De base 2 a base 10 presiona 2\n\n Ingresa la opcion que deseas: ");
        scanf("%d", &h);
    }while(h>2 || h<1);
    if(h==1){
        basediez();
    }
    if(h==2){
        basedos();
    }
    return 0;
}
void basediez(){
    int a, deci, b, d, c[40]={0}, i, w, z, t[40]={0};
    i=0;
    w=0;


    printf("Convertir de base 10 a base 2\n\n");
    printf("Ingresa la parte entera:");
    scanf("%d", &a);
    d=a;
    printf("\n Ingresa la parte decimal: ");
    scanf("%d", &deci);


    while (a!=0)
    {
        b=a%2;
        a=a/2;
        c[i]=b;
        i++;
    }
    while (deci!=0)
    {
        z=deci%2;
        deci=deci/2;
        t[w]=z;
        w++;
    }


    printf("Resultado ");
    for(i=i-1; i>=0; i--)
        printf("%d", c[i]);
    printf(" . ");
    for(w=w-1; w>=0; w--)
        printf("%d", t[w]);
}
void basedos(){
    long long n;
    printf("Ingresa la parte entera: ");
    scanf("%lld", &n);
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    long long y;
    printf("Ingresa la parte de los 'decimales': ");
    scanf("%lld", &y);
    int dec2 = 0, i2 = 0, rem2;
    while (y != 0) {
        rem2 = y % 10;
        y /= 10;
        dec2 += rem2 * pow(2, i2);
        ++i2;
    }
    printf("Resultado %d . %d", dec, dec2);
}
