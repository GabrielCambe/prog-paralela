#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // int x,y,z;

    // x = 10;
    // y = 6;
    // z = 4;

    // while(z > 0)
    //     while(y > 1)
    //     {
    //         x = x + 1;
    //         y = y - 2;
    //         while(x<10)
    //         {
    //             y = y + z;
    //             x = x - 1;
    //         }
    //         if(y > 0)
    //             z = z - 2;
    //         else
    //             z = z - 1;
    //         x++;
    //     }
    // printf("x = %d, y = %d, z = %d", x,y,z);    

    // int x,y,z;
    // x = 10;
    // y = 3;
    // z = 2; 

    // while(z > 0)
    //     while(y > 1)
    //     {
    //     x = x + 1;
    //     y = y - 1;
    //     while(x<10)
    //     {
    //         y = y + z;
    //         x = x - 1;
    //     }
    //     if(y > 0)
    //         z = z - 1;
    //     }
    // printf("x = %d, y = %d, z = %d", x,y,z);


    // int x = 0;
    // int a = 0;
    // int y;
    // while (x < 5)
    // {
    // if (x % 2 == 0)
    //     y = x + 1;
    // else
    //     y = x + 2;

    // while (y % 3 != 0)
    // {
    //     a = a + 2;
    //     y++;
    // }

    // x++;
    // }
    // printf("%d",a);

    // int x,y,z;
    // x = 4;
    // y = 3;
    // do
    // {
    //     for(z = 1; z < 3; z++)
    //     {
    //         printf("*");
    //         y = y + z;
    //         if((y % 7) == 0)
    //         {
    //             printf("*");
    //             y = 0;
    //             break;
    //         }
    //     }
    // }while(y > 3);

    // int x,y,z;
    // x = 4;
    // y = 3;

    // do
    // {
    //     for(z = 1; z < 4; z++)
    //     {
    //         y = y + (x % z);
    //         if(y > 6)
    //             y = 0;
    //     }
    //     printf("*");
    // }while(y > 3);

    // printf("*");

    // int x,y;

    // x = 2;
    // y = 2;
    // do
    // {
    // while(x > 0)
    // {
    //     y = y + x;
    //     x = x-1;
    //     }
    //     printf("*");
    //     y = y - x - 1;

    // }while(y > 0);
    // if(x == y)
    // printf("*");

    // int n=10, a=2, i=1;
    // float s=0;
    // while ((i <= n) && (s<a))
    // {
    //     s = s + 1.0/i;
    //     if (s > a)
    //         printf("Numero de termos = %d para se obter a série \n \t com valor %f maior que %d dado", i, s, a);
    //     i++;
    // }

//     int i=1, j=1, k=0, p=0;

// while (i != 13)

// {

//           k = i;

//           i = i + j;

//           j = k;

//           p++;

// }

// printf("%d", p);


    // int x = 1;
    // int y;
    // while (x < 3)
    // {
    // y = x;
    // while (y != 0)
    //     y=y-1;
    // x=x+1;
    // }
    // printf("%d",y);

    // int y, x = 0;
    // for (y = 0; y < 10; y = y+1)
    // {
    // if (y % 2 == 1)
    //     x += y;
    // }
    // printf("%d", x);
    
    // int x;
    // for (x = 1; x != 0 && x <= 28; x = x+2)
    // {
    // if (x % 5 == 0)
    //     printf("%d, ", x);
    // }

    // int M1, N1;
    // int sd1;
    // float s1 = 0;
    // int c = 0;
    // int i,D;
    // M1 = 4;
    // N1 = 7;

    // for (i=M1;i<=N1;i++)
    // {
    // sd1=0;
    // for (D=2;D<=i/2;D++)
    //     if (i % D == 0)
    //     sd1=sd1+D;
    //     if ((i > 1) && (sd1 == 0))
    //     {
    //     s1=s1+i;
    //     c=c+1;
    //     }
    // }
    // printf("\n%.1f",s1/c);

    // int M3 = 1;
    // int N3 = 30;

    // int i,D;
    // for (i = M3; i<=N3;i++)
    // for (D=1; D<=i/2; D++)
    //     if (i == D*(D+1)*(D+2))
    //         printf("%d, ", i);

    int M7, N7;
    int D, i;
    int sd7;
    int s7 = 0;
    int counter7 = 0;

    M7 = 3;
    N7 = 29;
    for (i = M7; i<=N7;i++) {
    sd7 = 1;
    for (D=2;D<=i/2;D++)
        if (i % D == 0)
            sd7= sd7 + D;
    
        if ((i > 1) && (sd7 == i)){
            s7=s7+i;
            counter7++; 
        } 
    } 

    printf("\n%.1f", (float)s7/counter7);
    return 0;
}

