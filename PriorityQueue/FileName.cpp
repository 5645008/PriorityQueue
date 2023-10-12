#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_ELEMENT 200

typedef struct
{
	int key;
} element;

typedef struct
{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

//노드의 이동횟수를 세는 정수
int node = 0;

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
	for (int j = 1; j <= h->heap_size; j++) {
		printf("%d ", h->heap[j].key);
	}
	printf("\n");

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		h->heap[i / 2] = item;
		i /= 2;
		node++;
		for (int j = 1; j <= h->heap_size; j++) {
			printf("%d ", h->heap[j].key);
		}
		printf("\n");
	}
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
	for (int j = 1; j <= h->heap_size; j++) {
		printf("%d ", h->heap[j].key);
	}
	printf("\n");

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
		for (int j = 1; j <= h->heap_size; j++) {
			printf("%d ", h->heap[j].key);
		}
		printf("\n");
		node++;
	}
	h->heap[parent] = temp;
	return item;
}

//트리의 높이
int height(HeapType* h) {
	int start = 1;
	int height = 1;
	while (h->heap_size >= start*2) {
		start = start * 2;
		height++;
	}
	return height;
}

//히프를 루트에서부터 레벨별로 출력
void level_print(HeapType* h)
{
	int j = 1;
	int now = 0;
	for (int i = 1; i <=height(h) ; i++) {
		printf("[%d] ",i);
		now = now + pow(2, i - 1);
		for (; j <= now; j++) {
			if (j > h->heap_size) {
				break;
			}
			printf("%d ", h->heap[j].key);
		}
		printf("\n");
	}
	printf("\n");
	
}

//입력시 생기는 엔터 받아주기
void Clear(void) {
	while (getchar() != '\n');
}

int main(void)
{

	HeapType* heap;
	heap = create();
	init(heap);

	//트리 값 넣기
	int a[10] = { 90, 89, 70, 36, 75, 63, 65, 21, 18, 15 };
	for (int i = 0; i < 10; i++) {
		heap->heap[i+1].key = a[i];
	}
	heap->heap_size = 10;


	//메뉴
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("| i   : 노드 추가   |\n");
	printf("| d   : 노드 삭제   |\n");
	printf("| p   : 레벨별 출력 |\n");
	printf("| c   : 종료        |\n");
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("\n\n");

	element number;
	char command;
	do {
		printf("메뉴 입력: ");
		command = getchar();

		switch (command) {
		//삽입(i)입력
		case 'i':
		{
			printf("추가할 값 입력: ");
			scanf_s("%d", &number);
			Clear();
			insert_max_heap(heap, number);
			printf("노드가 이동된 횟수: %d\n\n", node);
			node = 0;
			break;
		}
		//삭제(d)입력
		case 'd':
		{
			Clear();
			delete_max_heap(heap);
			printf("노드가 이동된 횟수: %d\n\n", node);
			node = 0;
			break;
		}
		//레벨별 출력(p)입력
		case 'p':
		{
			Clear();
			printf("트리 레벨별 출력\n");
			level_print(heap);
			break;
		}
		}
		//c가 입력되면 do-while문 종료
	} while (command != 'c');

	free(heap);
	return 0;
}