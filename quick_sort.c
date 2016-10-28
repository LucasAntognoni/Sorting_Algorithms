#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quick_sort.h"

void swap(int *array, int i, int j)
{
  int aux;

  aux = array[i];
  array[i] = array[j];
  array[j] = aux;
}

int random_pivot(int *array, int p, int r)
{
  int i;

  i = p + rand() % (r - p + 1);

  swap(array, r, i);

  return partition(array, p, r);
}

int median(int array[])
{
  int i = 0, j = 0;

  for (i = 0; i < 4 - 1; i++)
  {
    for (j = 4 - 1; j >= i + 1; j--)
    {
      if (array[j] < array[j - 1])
      {
        swap(array, j, j - 1);
      }
    }
  }
  return array[1];
}

int median_pivot(int *array, int p, int r)
{
  int m[3];

  m[0] = p + rand() % (r - p + 1);
  m[1] = p + rand() % (r - p + 1);
  m[2] = p + rand() % (r - p + 1);

  swap(array, r, median(m));

  return partition(array, p, r);
}

int middle_pivot(int *array, int p, int r)
{
  int i;

  i = (p + r) / 2;

  swap(array, p, i);

  return partition(array, p, r);
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
  if (p < r)
  {
    int q;

    //srand((unsigned)time(NULL));
    //q = random_partition(array, p, r);
    //q = median_pivot(array, p, r);
    //q = middle_partition(array, p, r);

    q = partition(array, p, r);
    quick_sort(array, p, q - 1);
    quick_sort(array, q + 1, r);
  }
}
