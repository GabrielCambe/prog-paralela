#include <stdio.h>

#define N 3
typedef struct {
    int v1;
    int v2;
    float m;
}Estrutura;

void func1(Estrutura* est) {
    int i, j;
    for (i=0;i<N;i++) {
        est[i].m = (float)(est[i].v1+est[i].v2)/2;
        if (est[i].v1 < est[i].v2) {
            j = est[i].v1;
            est[i].v1 = est[i].v2;
            est[i].v2 = j;
        }
    }
}
int main(int argc, char const *argv[])
{
    // int M8 = 4;
    // int N8 = 28;
    // for (int i = M8; i<=N8;i++)
    //     for (int D=1;D<=i/2;D++)
    //         if (i == D*(D+1)*(D+2)) printf("%d, ", i);
    
//     int M6, N6;
// int sd6;
// int s6 = 0;
// int counter6 = 0;

// M6 = 9;
// N6 = 16;
// for (int i = M6; i<=N6;i++){
// sd6 = 0;
// for (int D=2;D<=i/2;D++)
// if (i % D == 0) sd6 += D;
// if ((i > 1) && (sd6 == 0)){
// s6+=i;
// counter6++;
// }
// }
// printf("\n%.2f", (float)s6/counter6);

// int V3[13];
// int Tn = 13;
// V3[0] = 1;
// V3[1] = 1;
// for (int i = 2; i<11; i++) V3[i] = V3[i-1] + V3[i-2];
// for (int n = 0; n<11;n++)
// if (V3[n] == Tn) printf("\n%d", n+1);
Estrutura est[N];
int i;
est[0].v1 = 3;
est[0].v2 = 3;

est[1].v1 = 1;
est[1].v2 = 3;

est[2].v1 = 4;
est[2].v2 = 2;

func1(est);

    for (i=0;i<N;i++) {
        printf("%d, %d, %1.2f\n", est[i].v1, est[i].v2, est[i].m);
    }
    return 0;
}
