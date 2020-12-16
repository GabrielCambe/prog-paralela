#include <stdio.h>
#include <omp.h>
#include <likwid.h>
#define NUM_THREADS 2

static long num_steps = 10000000;
double step;
double pi[NUM_THREADS];

int main(){
    int nthreads;
    double res = 0.0;
    TimerData tempo;
    const TimerData *tempo_ptr = &tempo;
    timer_init();

    timer_start( &tempo );
    #pragma omp parallel num_threads(NUM_THREADS)
    {
        int i, nthrds; double x, sum = 0.0;
        int id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if (id == 0) nthreads = nthrds;
        step = 1.0/(double) num_steps;
        for (i=id*(num_steps/nthrds); i < (id+1)*(num_steps/nthrds); i++){
            x = (i + 0.5) * step;
            sum = sum + 4.0 / (1.0 + x*x);
        }
        pi[id] = step * sum;
    }
    for(int i = 0; i < nthreads; i++)
        res += pi[i];

    timer_stop( &tempo );
    printf("%lf\n",  timer_print( tempo_ptr ));
    
    printf("res: %.5lf\n", res);
}