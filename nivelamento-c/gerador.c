#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[] )
{
  int i;
  if(argc > 1 )
    srand(atoi(argv[1]));
  for (i = 0; i < 50; i++)
  {
    printf("%d ", rand() % 100);
  }

  return 0;
}
