#include <stdio.h>
#include <omp.h>
#include <likwid.h>

static long num_steps = 1000000000;double step;
#define PAD 8 // getconf LEVEL1_DCACHE_LINESIZE yields 64
#define NUM_THREADS 2

int main(){
    TimerData tempo;
    const TimerData *tempo_ptr = &tempo;
    int i, nthreads; double pi, sum[NUM_THREADS][PAD];
    step = 1.0/(double) num_steps;

    timer_init();
    timer_start( &tempo );
    #pragma omp parallel num_threads(NUM_THREADS)
    {
        int i, id, nthrds; double x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if (id == 0) nthreads = nthrds;
        for (i = id; i < num_steps; i += nthrds){
            x = (i + 0.5) * step;
            sum[id][0] += 4.0 / (1.0 + x*x);
        }        
    }
    for(i = 0, pi = 0.0; i < nthreads; i++)
        pi += sum[i][0] * step;
    timer_stop( &tempo );
    printf("tempo: %lfs\n",  timer_print( tempo_ptr ));
    
    printf("Pi == %.5lf\n", pi);
}