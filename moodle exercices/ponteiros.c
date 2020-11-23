#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // char *ptr;
    // int i;
    // char vet[2][3] = {
    //     {'a', 'b', 'c'},
    //     {'1', '2', '3'}
    // };

    // ptr = vet[0];
    // for(i=0;i<3;i++){
    //     printf("\nVet[%d] = %c  ptr = %c", i, vet[0][i], *ptr);
    //     ptr++;
    // }
    // ptr = vet[1];
    // for(i=0;i<3;i++){
    //     printf("\nVet[%d] = %c  ptr = %c", i, vet[1][i], *ptr);
    //     ptr++;
    // }

    // int i=2, j=6;
    // int *p, *q;
    // p = &i;
    // q = &j;
    // printf("%d %d\n", *p - *q, 3* - *p/ *q +7);

    // int vet[] = {4, 9, 12};
    // int i,*ptr;
    // ptr=vet;
    // for(i=0;i<3;i++){
    //     printf("%d ", *ptr++);
    // }

    // int i =5, *p = &i;
    // printf("%d %d %d %d", *p+2, **&p, 3**p, **&p+4);

    // char a = 65;
    // char *x = &a;
    // printf("%c", *x);

    char *ptr;
    int i;
    char vet[5] = {'a', 'b', 'c', 'd', 'e'};
    ptr = vet;
    for (i=0; i<5; i++){
        printf("\nVet[%d] = %c  ptr = %c", i, vet[i], *ptr);
        ptr++;
    }
    return 0;
}
