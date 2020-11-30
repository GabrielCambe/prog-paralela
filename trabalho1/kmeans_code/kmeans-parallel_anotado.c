#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 3

#include <likwid.h>
#include <omp.h>
#define NUM_THREADS 2

int main(void) {
	TimerData tempo;
    const TimerData *tempo_ptr = &tempo;
    timer_init();
    timer_start( &tempo );

	// Inicialização
	int i, j, k, n, c;
	double dmin, dx;
	double *x, *mean, *sum;
	int *cluster, *count, color;
	int flips;
	// k == número de centroides, n == número de pontos
	(void)scanf("%d", &k);
	scanf("%d", &n);
	// x == vetor de pontos, mean == vetor de centróides
	x = (double *)malloc(sizeof(double)*DIM*n);
	mean = (double *)malloc(sizeof(double)*DIM*k);
	// sum == vetor que posteriormente guardará a soma ponto à ponto, de cada coordenada dos pontos presentes em um cluster,
	// para o cálculo das centróides
	sum= (double *)malloc(sizeof(double)*DIM*k);
	// cluster == vetor que indica à qual cluser o ponto correspontente está associado
	cluster = (int *)malloc(sizeof(int)*n);
	// count == vetor com a quantidade de pontos em cada cluster, para o cálculo das novas centróides
	count = (int *)malloc(sizeof(int)*k);

	for (i = 0; i<n; i++)
		cluster[i] = 0;
	for (i = 0; i<k; i++)
		scanf("%lf %lf %lf", mean+i*DIM, mean+i*DIM+1, mean+i*DIM+2);
	for (i = 0; i<n; i++)
		scanf("%lf %lf %lf", x+i*DIM, x+i*DIM+1, x+i*DIM+2);
	
	// flips == guarda a ocorrência de uma mudança de cluster por um ponto
	flips = n;
	while (flips>0) {
		flips = 0;
		for (j = 0; j < k; j++) {
			count[j] = 0;
			for (i = 0; i < DIM; i++)
				sum[j*DIM+i] = 0.0;
		}

		#pragma omp parallel num_threads(NUM_THREADS) private(i, j, c, dmin, dx, color)
		{
			#pragma omp for schedule(static)
			for (i = 0; i < n; i++) {
				// dmin == menor distância entre o ponto X_i e as centróides
				// color == centróide à qual o ponto X_i está associado
				dmin = -1; color = cluster[i];
				for (c = 0; c < k; c++) {
					dx = 0.0;
					// Calcula a distância do ponto X_i à centróide MEAN_c
					for (j = 0; j < DIM; j++)
						dx +=  (x[i*DIM+j] - mean[c*DIM+j]) * (x[i*DIM+j] - mean[c*DIM+j]);
					// Atualiza dmin e a centróide associada ao ponto, se necessário
					if (dx < dmin || dmin == -1) {
						color = c;
						dmin = dx;
					}
				}
				// Sinaliza que o ponto mudou de centróide e armazena a nova centróide a qual ele está associado 
				if (cluster[i] != color) {
					#pragma omp atomic
					flips++;
					cluster[i] = color;
				}
			}			
		}

		// Cálculo das novas centróides
		for (i = 0; i < n; i++) {
			count[cluster[i]]++;
			for (j = 0; j < DIM; j++)
				sum[cluster[i]*DIM+j] += x[i*DIM+j];
		}
		for (i = 0; i < k; i++) {
			for (j = 0; j < DIM; j++) {
				mean[i*DIM+j] = sum[i*DIM+j]/count[i];
			}
		}
	}

	// Impressão do resultado
	for (i = 0; i < k; i++) {
		for (j = 0; j < DIM; j++)
			printf("%5.2f ", mean[i*DIM+j]);
		printf("\n");
	}

	#ifdef DEBUG
	for (i = 0; i < n; i++) {
		for (j = 0; j < DIM; j++)
			printf("%5.2f ", x[i*DIM+j]);
		printf("%d\n", cluster[i]);
	}
	#endif

	timer_stop( &tempo );
    printf("%lf\n",  timer_print( tempo_ptr ));

	return(0);
}
