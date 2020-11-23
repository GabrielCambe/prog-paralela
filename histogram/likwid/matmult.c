#include <stdio.h>
#include <stdlib.h>    /* exit, malloc, calloc, etc. */
#include <string.h>
#include <getopt.h>    /* getopt */

#include <likwid.h>

// #include "matriz.h"

/**
 * Exibe mensagem de erro indicando forma de uso do programa e termina
 * o programa.
 */

static void usage(char *progname)
{
  fprintf(stderr, "Forma de uso: %s [ -n <ordem> ] \n", progname);
  exit(1);
}



/**
 * Programa principal
 * Forma de uso: matmult [ -n <ordem> ]
 * -n <ordem>: ordem da matriz quadrada e dos vetores
 *
 */

int main (int argc, char *argv[]) 
{
  LIKWID_MARKER_INIT;
  // int c, n=DEF_SIZE;
  double norma;
  
  // MatPtr mPtr;
  // MatRow mRow;
  // MatCol mCol;
  // Vetor vet, resPtr, resRow, resCol;
  
  /* =============== TRATAMENTO DE LINHA DE COMAANDO =============== */

  char *opts = "n:";
  // c = getopt (argc, argv, opts);
  
  // while ( c != -1 ) {
  //   switch (c) {
  //   case 'n':  n = atoi(optarg);              break;
  //   default:   usage(argv[0]);
  //   }
      
  //   c = getopt (argc, argv, opts);
  // }
  
  /* ================ FIM DO TRATAMENTO DE LINHA DE COMANDO ========= */
 
  // resPtr = (double *) malloc (n * sizeof(double));
  // resRow = (double *) malloc (n * sizeof(double));
  // resCol = (double *) malloc (n * sizeof(double)); 
  
  srand(20191);
      
  // mPtr = geraMatPtr (n, n);
  // mRow = geraMatRow (n, n);
  // mCol = geraMatCol (n, n);
  // vet = geraVetor (n);
    
#ifdef DEBUG
    prnMatPtr (mPtr, n, n);
    prnMatRow (mRow, n, n);
    prnMatCol (mCol, n, n);
    prnVetor (vet, n);
    printf ("=================================\n\n");
#endif /* DEBUG */
  TimerData tempo;
  const TimerData *tempo_ptr = &tempo;
  timer_init();
  
  LIKWID_MARKER_START("multMatPtrVet");
  timer_start( &tempo );
  // multMatPtrVet (mPtr, vet, n, n, resPtr);
  timer_stop( &tempo );
  LIKWID_MARKER_STOP("multMatPtrVet");
  printf("tempo multMatPtrVet: %lfs\n",  timer_print( tempo_ptr ));
  
  LIKWID_MARKER_START("multMatRowVet");  
  timer_reset( &tempo );
  timer_start( &tempo );
  // multMatRowVet (mRow, vet, n, n, resRow);
  timer_stop( &tempo );
  LIKWID_MARKER_STOP("multMatRowVet");
  printf("tempo multMatPtrVet: %lfs\n",  timer_print( tempo_ptr ));
  
  LIKWID_MARKER_START("multMatColVet");
  timer_reset( &tempo );
  timer_start( &tempo );
  // multMatColVet (mCol, vet, n, n, resCol);
  timer_stop( &tempo );
  LIKWID_MARKER_STOP("multMatColVet");
  printf("tempo multMatColVet: %lfs\n",  timer_print( tempo_ptr ));
  

  // norma = normaMax(resRow, resPtr, n);

  // norma = normaEucl(resCol, n);

#ifdef DEBUG
    prnVetor (resPtr, n);
    prnVetor (resRow, n);
    prnVetor (resCol, n);
#endif /* DEBUG */

  // liberaMatPtr (mPtr, n);
  // liberaVetor ((void*)mRow);
  // liberaVetor ((void*)mCol);
  // liberaVetor ((void*)vet);
    
  // free(resCol);
  // free(resRow);
  // free(resPtr);

  LIKWID_MARKER_CLOSE;
  return 0;
}

