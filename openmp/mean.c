#include <stdio.h>

int main(){
    double var = 0.0;
    double sum = 0.0;
    int i = 0;
    while (1) {
        scanf("%lf\n", &var);
        if (var < 0.0) break;
        // printf("%.5lf\n", var);
        sum += var;
        i++;
    }
    printf("%.6lf\n", sum/(double)i);
    return 0;
}