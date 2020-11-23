#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int main(int argc, char const *argv[])
{
    // int V[10] = {5,2,8,0,12,3,0,6,0,15};
    // int i;
    // for (i = 0; i < 9; i++)
    //     V[i] = V[i] - V[i+1];

    // for (i = 0; i < 10; i++)
    //     printf ("%d,",V[i]);
    
    // int v[6] = {1, 3, 4, 12, -1, 10};
    // int i, condicao;

    // for (i=0; i<6; i++) {
    //     condicao = ((v[i]*(i+1))) % 2;
    //     if (condicao != 0)
    //         printf("%d", v[i]);
    //     else
    //         printf("%d", i);
    // }

    // int V2[11];
    // int i, n;
    // int Tn = 8;


    // V2[0] = 1;
    // V2[1] = 1;

    // for (i = 2; i<11; i++)
    // V2[i] = V2[i-1] + V2[i-2];

    // for (n = 0; n<11;n++)
    // if (V2[n] == Tn)
    //     printf("\n%d", n+1);

    // int i, n;
    // int V3[13];
    // int Tn = 13;
    // V3[0] = 1;
    // V3[1] = 1;

    // for(i = 2; i<11; i++)
    // V3[i] = V3[i-1] + V3[i-2];

    // for(n = 0; n<11;n++)
    // if(V3[n] == Tn)
    //     printf("\n%d", n+1); 
    
    // int a[SIZE][SIZE];
    // int x,y,n, acha=0, t=0;
    // for(x=0; x<SIZE;x++)
    //     for(y=0;y<SIZE;y++) a[x][y] = 2*y-1;
    // printf("Array\n");
    // for(x=0; x<SIZE;x++) {
    //     printf("\n");
    //     for(y=0;y<SIZE;y++) 
    //         printf(" %2d ", a[x][y]); }
    // printf("\nDigite inteiro"); scanf(" %d ", &n);
    // for(x=0; x<SIZE;x++)
    //     for(y=0;y<SIZE;y++)
    //         if (n == a[x][y]) {
    //             acha=1; t++;}
    // if(acha==1) printf("valor %d, ok visto %d",n, t );
    // else printf("n ok");

    int m[4][4] = {
        {12, 7, 6, 4},
        {8, 16, 7, 11},
        {6, 15, 3, 10}
    };

    int s = 0;
    int s2 = 0;
    int i = 0;
    int k;
    for (k=0; k<=3; k=k+1) 
        s = s + m[i][k];
    k = 3;
    for(i=0; i < 3; i = i+1)
        s2 = s2 + m[i][k];
    printf("%d, %d", s, s2);
    return 0;
}
