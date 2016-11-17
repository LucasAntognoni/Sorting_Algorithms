#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "heap_sort.h"

HEAP *create_heap(int size, int *array)
{
  HEAP *heap;

  heap = (HEAP*) malloc (sizeof(HEAP));
  heap->array = array;
  heap->size = size - 1;

  return heap;
}

void destroy_heap(HEAP *heap)
{
  free(heap->array);
  heap->array = NULL;

  free(heap);
  heap = NULL;
}

int parent_node(int index)
{
  return floor(index / 2);
}

int left_node(int index)
{
  return 2 * index;
}

int right_node(int index)
{
  return (2 * index) + 1;
}

void swap(int *array, int i, int j)
{
  int aux;

  aux = array[i];
  array[i] = array[j];
  array[j] = aux;
}

void max_heapify(HEAP *heap, int index)
{
  int left, right, largest;

  left = left_node(index);
  right = right_node(index);

  if (left <= heap->size && heap->array[left] > heap->array[index])
  {
    largest = left;
  }
  else
  {
    largest = index;
  }

  if (right <= heap->size && heap->array[right] > heap->array[largest])
  {
    largest = right;
  }

  if (largest != index)
  {
    swap(heap->array, index, largest);
    max_heapify(heap, largest);
  }
}

void build_max_heap(HEAP *heap)
{
  int i = 0;

  for (i = floor((heap->size) / 2); i >= 0; i--)
  {
    max_heapify(heap, i);
  }
}

void heap_sort(HEAP *heap)
{
  int i = 0;

  build_max_heap(heap);

  for (i = heap->size; i >= 1; i--)
  {
    swap(heap->array, 0, i);
    heap->size -= 1;
    max_heapify(heap, 0);
  }
}
