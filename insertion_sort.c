#include <stdio.h>

#include "insertion_sort.h"

void insertion_sort(int *vector, int size)
{
  int i = 0, j = 0, key = 0;

  for (j = 1; j < size; j++)
  {
    key = vector[j];

    i = j - 1;

    while (i >= 0 && vector[i] > key)
    {
      vector[i + 1] = vector[i];
      i = i - 1;
    }

    vector[i + 1] = key;

    print_vector(vector, size);
  }
}
