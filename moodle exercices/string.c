#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // char c = 0;
    // if ( c >= '0' || c <= 9 ){
    // printf("1");
    // c= '0';
    // }
    // if(c >= '0' && c <= '9')
    // printf("2");
    // else
    // printf("0");

    // char primeiroNome[20];
    // char segundoNome[20];
    // scanf("%s", primeiroNome); 
    // scanf("%s", segundoNome); 
    // printf("%s e %s", primeiroNome, segundoNome);

    // char st [ 80 ];
    // st [ 0 ] = 'o';
    // st [ 1 ] = 'l';
    // st [ 2 ] = 'a';
    // st [ 3 ] = '\0';
    // printf ( "%s \n" , st );

    char frase[13] = "tabela ascii";
    for(int i =0; i< 13; i++){
        if(frase[i] >= 97 && frase[i]<= 122){
            frase[i] -= 32;
        }
    }
    printf("%s\n", frase);

    return 0;
}
