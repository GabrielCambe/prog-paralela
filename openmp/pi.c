#include <stdio.h>
#include <likwid.h>

int main(){
    TimerData tempo;
    const TimerData *tempo_ptr = &tempo;
    timer_init();
    timer_start( &tempo );

    static long num_steps = 10000000;
    double step;
    int i; double x, pi, sum = 0.0;
    step = 1.0/(double) num_steps;
    for (i=0; i< num_steps; i++){
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x*x);
    }
    pi = step * sum;
    timer_stop( &tempo );
    printf("%lf\n",  timer_print( tempo_ptr ));

    printf("res: %.5lf\n", pi);
}