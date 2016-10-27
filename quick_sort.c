#include <stdio.h>

#include "quick_sort.h"

void swap(int *vector, int i, int j)
{
  int aux;

  aux = vector[i];
  vector[i] = vector[j];
  vector[j] = aux;
}

int partition(int *array, int p, int r)
{
  int x, i, j;

  x = array[r];
  i = p - 1;

  for(j = p; j < r; j++)
  {
    if (array[j] <= x)
    {
      i = i + 1;
      swap(array, i, j);
    }
  }
  swap(array, i + 1, j);

  return i + 1;
}

void quick_sort(int *array, int p, int r)
{
  int q;

  if (p < r)
  {
    q = partition(array, p, r);
    quick_sort(array, p, q - 1);
    quick_sort(array, q + 1, r);
  }
}
