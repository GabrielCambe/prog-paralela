#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 3

#include <likwid.h>
#include <mpi.h>
#define K 0
#define N 1

int main(int argc, char *argv[])
{
	TimerData tempo;
	const TimerData *tempo_ptr = &tempo;
	timer_init();
	timer_start(&tempo);

	int rank, n_procs;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &n_procs);

	int i, j, c;
	int input_param[2]; // k e n
	double dmin, dx;
	double *x, *mean, *sum;
	int *cluster, *count, color;
	int flips;

	if (rank == 0)
	{
		scanf("%d", &input_param[K]);
		scanf("%d", &input_param[N]);
	}
	MPI_Bcast(input_param, 2, MPI_INT, 0, MPI_COMM_WORLD);

	x = (double *)malloc(sizeof(double) * DIM * input_param[N]);
	mean = (double *)malloc(sizeof(double) * DIM * input_param[K]);
	sum = (double *)malloc(sizeof(double) * DIM * input_param[K]);
	cluster = (int *)malloc(sizeof(int) * input_param[N]);
	count = (int *)malloc(sizeof(int) * input_param[K]);

	for (i = 0; i < input_param[N]; i++)
		cluster[i] = 0;
	if (rank == 0)
	{
		for (i = 0; i < input_param[K]; i++)
			scanf("%lf %lf %lf", mean + i * DIM, mean + i * DIM + 1, mean + i * DIM + 2);
		for (i = 0; i < input_param[N]; i++)
			scanf("%lf %lf %lf", x + i * DIM, x + i * DIM + 1, x + i * DIM + 2);
	}

	flips = input_param[N];
	while (flips > 0)
	{
		flips = 0;
		for (j = 0; j < input_param[K]; j++)
		{
			count[j] = 0;
			for (i = 0; i < DIM; i++)
				sum[j * DIM + i] = 0.0;
		}

		// parte que eu decidi paralelizar
		MPI_Bcast(mean, DIM * input_param[K], MPI_DOUBLE, 0, MPI_COMM_WORLD);
		MPI_Scatter(x, (DIM * input_param[N]) / n_procs, MPI_DOUBLE, x, (DIM * input_param[N]) / n_procs, MPI_DOUBLE, 0, MPI_COMM_WORLD);
		MPI_Scatter(cluster, input_param[N] / n_procs, MPI_INT, cluster, input_param[N] / n_procs, MPI_INT, 0, MPI_COMM_WORLD);
		for (i = 0; i < input_param[N] / n_procs; i++)
		{
			dmin = -1;
			color = cluster[i];
			for (c = 0; c < input_param[K]; c++)
			{
				dx = 0.0;
				for (j = 0; j < DIM; j++)
					dx += (x[i * DIM + j] - mean[c * DIM + j]) * (x[i * DIM + j] - mean[c * DIM + j]);
				if (dx < dmin || dmin == -1)
				{
					color = c;
					dmin = dx;
				}
			}
			if (cluster[i] != color)
			{
				flips++;
				cluster[i] = color;
			}
		}
		//
		MPI_Allreduce(&flips, &flips, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
		MPI_Gather(x, (DIM * input_param[N]) / n_procs, MPI_DOUBLE, x, (DIM * input_param[N]) / n_procs, MPI_DOUBLE, 0, MPI_COMM_WORLD);
		MPI_Gather(cluster, (input_param[N] / n_procs), MPI_INT, cluster, (input_param[N] / n_procs), MPI_INT, 0, MPI_COMM_WORLD);

		if (rank == 0)
		{
			for (i = 0; i < input_param[N]; i++)
			{
				count[cluster[i]]++;
				for (j = 0; j < DIM; j++)
					sum[cluster[i] * DIM + j] += x[i * DIM + j];
			}
			for (i = 0; i < input_param[K]; i++)
			{
				for (j = 0; j < DIM; j++)
				{
					mean[i * DIM + j] = sum[i * DIM + j] / count[i];
				}
			}
		}
		MPI_Barrier(MPI_COMM_WORLD);
	}

	if (rank == 0)
	{
		for (i = 0; i < input_param[K]; i++)
		{
			for (j = 0; j < DIM; j++)
				printf("%5.2f ", mean[i * DIM + j]);
			printf("\n");
		}
	}

#ifdef DEBUG
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < DIM; j++)
			printf("%5.2f ", x[i * DIM + j]);
		printf("%d\n", cluster[i]);
	}
#endif

	MPI_Finalize();

	timer_stop(&tempo);
	printf("parallel_time: %lf\n", timer_print(tempo_ptr));

	return (0);
}
