#include <stdio.h>
#include <omp.h>
#include <likwid.h>
#define NUM_THREADS 2

int main(){
    TimerData tempo;
    const TimerData *tempo_ptr = &tempo;
    timer_init();
    timer_start( &tempo );

    static long num_steps = 10000000;
    double step = 1.0/(double) num_steps;
    double pi = 0.0;
    #pragma omp parallel num_threads(NUM_THREADS)
    {
        double sum = 0.0;
        double x;
        #pragma omp for schedule(static)
        for (int i=0; i< num_steps; i++)
        {
            x = (i + 0.5) * step;
            sum = sum + 4.0 / (1.0 + x*x);
        }
        #pragma omp atomic
        pi += step * sum;
    }
    timer_stop( &tempo );
    printf("%lf\n",  timer_print( tempo_ptr ));

    printf("res: %.5lf\n", pi);
}