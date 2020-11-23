#include <stdio.h>

int tanana (int x, float y, float z) {
    int i;
    i = 0;
    while(i<x){
        z = z+y;
        y++;
        i++;
    }
    return y;
}
int funcao2(){

    int num1, num2, i,n,aux;

    num1 = 0;
    num2 = 1;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        aux = num1;
        num1 = num1 + num2;
        num2 = aux;
    }
    return num1;
}

int funcao1() {
    int i;
    float a,b,c;
    a = 0;
    b = 0;
    i = 2;
    c = 7;
    while(i<4){
        a++;
        i++;
    }
    b++;
    return (a*b)/c;
}

void funcao () {
    int i =2;
    int j;

    for(j = i; j>0; j--)
        printf("%d", i);
}

int main(int argc, char const *argv[])
{
    // int i;
    // for(i =1; i<4; i++)
    //     funcao ();
    // printf("\n");

    // printf("%d",funcao2());
    
    // printf("%d",funcao1());

    printf("%d",tanana(3,1,2));
    return 0;
}
