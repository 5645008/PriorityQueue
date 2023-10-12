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

//����� �̵�Ƚ���� ���� ����
int node = 0;

// ���� �Լ�
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
	h->heap_size = 0;
}

// ���� �Լ�
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

// ���� �Լ�
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

//Ʈ���� ����
int height(HeapType* h) {
	int start = 1;
	int height = 1;
	while (h->heap_size >= start*2) {
		start = start * 2;
		height++;
	}
	return height;
}

//������ ��Ʈ�������� �������� ���
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

//�Է½� ����� ���� �޾��ֱ�
void Clear(void) {
	while (getchar() != '\n');
}

int main(void)
{

	HeapType* heap;
	heap = create();
	init(heap);

	//Ʈ�� �� �ֱ�
	int a[10] = { 90, 89, 70, 36, 75, 63, 65, 21, 18, 15 };
	for (int i = 0; i < 10; i++) {
		heap->heap[i+1].key = a[i];
	}
	heap->heap_size = 10;


	//�޴�
	printf("�ѤѤѤѤѤѤѤѤѤѤ�\n");
	printf("| i   : ��� �߰�   |\n");
	printf("| d   : ��� ����   |\n");
	printf("| p   : ������ ��� |\n");
	printf("| c   : ����        |\n");
	printf("�ѤѤѤѤѤѤѤѤѤѤ�\n");
	printf("\n\n");

	element number;
	char command;
	do {
		printf("�޴� �Է�: ");
		command = getchar();

		switch (command) {
		//����(i)�Է�
		case 'i':
		{
			printf("�߰��� �� �Է�: ");
			scanf_s("%d", &number);
			Clear();
			insert_max_heap(heap, number);
			printf("��尡 �̵��� Ƚ��: %d\n\n", node);
			node = 0;
			break;
		}
		//����(d)�Է�
		case 'd':
		{
			Clear();
			delete_max_heap(heap);
			printf("��尡 �̵��� Ƚ��: %d\n\n", node);
			node = 0;
			break;
		}
		//������ ���(p)�Է�
		case 'p':
		{
			Clear();
			printf("Ʈ�� ������ ���\n");
			level_print(heap);
			break;
		}
		}
		//c�� �ԷµǸ� do-while�� ����
	} while (command != 'c');

	free(heap);
	return 0;
}