#include <stdlib.h>

#define LENGTH 10000000

int main()
{
  int * buffer = malloc(LENGTH * sizeof(int));
  free (buffer);
  return 0;
}
