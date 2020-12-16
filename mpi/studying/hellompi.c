#include <mpi.h>
#include <stdio.h>
#include <string.h>

#define STD_TAG 0

int main(int argc, char *argv[])
{
    int rank, size, i;
    char msg[100];
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank != 0)
    {
        sprintf(msg, "I'm alive!");
        MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, 0, STD_TAG, MPI_COMM_WORLD);
    }
    else
    {
        for (i = 1; i < size; i++)
        {
            MPI_Recv(msg, 100, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            printf("Proc %d/%d: %s\n", status.MPI_SOURCE, size, msg);
        }
    }

    MPI_Finalize();

    return 0;
}