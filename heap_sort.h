#ifndef HEAP_SORT_H
#define HEAP_SORT_H

typedef struct heap
{
  int size;
  int *array;
}HEAP;

HEAP *create_heap(int size, int *array);

void destroy_heap(HEAP *heap);

int parent_node(int index);

int left_node(int index);

int right_node(int index);

void swap(int *array, int i, int j);

void max_heapify(HEAP *heap, int index);

void build_max_heap(HEAP *heap);

void heap_sort(HEAP *heap);

#endif
