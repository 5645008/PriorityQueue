#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_ELEMENT 200
#define SIZE 17

typedef struct
{
	int key;
} element;

typedef struct
{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}

// 삽입 함수
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);
	h->heap[h->heap_size] = item;

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		h->heap[i / 2] = item;
		i /= 2;
		
	}
	for (int j = 1; j <= h->heap_size; j++) {
		printf("%d ", h->heap[j].key);
	}
	printf("\n");
	h->heap[i] = item;
}

// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	h->heap[1].key = h->heap[h->heap_size].key;
	temp = h->heap[(h->heap_size)--];
	
	parent = 1;
	child = 2;

	while (child <= h->heap_size)
	{
		
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		h->heap[child] = temp;
		parent = child;
		child *= 2;
		
	}

	h->heap[parent] = temp;
	for (int j = 1; j <= h->heap_size; j++) {
		printf("%d ", h->heap[j].key);
	}
	printf("\n");
	return item;
}


void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
	free(h);
}


int main(void)
{

	element list[SIZE] = { 34, 12, 76, 59, 32, 55, 88, 26, 16, 79, 34, 85, 29, 78, 41, 56, 86 };
	heap_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");
	return 0;
}