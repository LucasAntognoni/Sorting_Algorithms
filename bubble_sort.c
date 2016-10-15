#include <stdio.h>

#include "bubble_sort.h"

void bubble_sort(int *vector, int size)
{
  int i = 0, j = 0;

  for (i = 0; i < size - 1; i++)
  {
    for (j = size - 1; j >= i + 1; j--)
    {
      if (vector[j] < vector[j - 1])
      {
        swap(vector, j, j - 1);
      }
    }
  }
}

void swap(int *vector, int i, int j)
{
  int aux;

  aux = vector[i];
  vector[i] = vector[j];
  vector[j] = aux;
}
