#include <stdio.h>
#include <stdlib.h>
#include "counting_sort.h"

int search_max_element(int *array, int size)
{
  int i = 0, max = array[0];

  for (i = 1; i < size; i++)
  {
    if(max < array[i])
    {
      max = array[i];
    }
  }
  return max;
}

int *counting_sort(int *array, int size)
{
  int i = 0, max = 0;
  int *b, *c;

  b = (int*) malloc (sizeof(int) * size);

  max = search_max_element(array, size);
  c = (int*) malloc (sizeof(int) * (max));

  for (i = 0; i < max; i++)
  {
    c[i] = 0;
  }

  for (i = 0; i < size; i++)
  {
    c[array[i] - 1] += 1;
  }

  for (i = 1; i < max; i++)
  {
    c[i] += c[i - 1];
  }

  for (i = size - 1; i >= 0; i--)
  {
    b[c[array[i] - 1] - 1] = array[i];
    c[array[i] - 1] -= 1;
  }

  return b;
}
