#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#include "merge_sort.h"

void merge(int *array, int p, int q, int r)
{
  int n1 = 0, n2 = 0, i = 0, j = 0, k = 0;

  n1 = q - p + 1;
  n2 = r - q;

  int L[n1 + 1], R[n2 + 1];

  for (i = 0; i < n1; i++)
  {
    L[i] = array[p + i];
  }
  for (j = 0; j < n2; j++)
  {
    R[j] = array[q + j + 1];
  }

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  i = 0;
  j = 0;

  for (k = p; k <= r; k++)
  {
    if (L[i] <= R[j])
    {
      array[k] = L[i];
      i += 1;
    }
    else
    {
      array[k] = R[j];
      j += 1;
    }
  }
}

void merge_sort(int *array, int p, int r)
{
  if (p < r)
  {
    int q = floor((p + r) / 2);

    merge_sort(array, p, q);
    merge_sort(array, q + 1, r);
    merge(array, p, q, r);
  }
}
