#include <stdio.h>

int main(){
    double tempo_antigo = 0.0;
    double tempo_novo = 0.0;
    scanf("%lf\n", &tempo_antigo);
    scanf("%lf\n", &tempo_novo);
    printf("%.6lf\n", tempo_antigo/tempo_novo);
    return 0;
}