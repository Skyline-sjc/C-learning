#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
void menu() {
	printf("*************************************\n");
	printf("*******1.Init        2.Display*******\n");
	printf("*******3.Destroy     4.PushBack******\n");
	printf("*******5.PushFront   6.DelBack*******\n");
	printf("*******7.DelFront    8.FindPos*******\n");
	printf("*******9.InsertPos   10.Erase********\n");
	printf("*******0.exit        ****************\n");
	printf("*************************************\n");
}
void DisplaySeqList(SeqList* p) {
	int i = 0;
	for (i = 0; i < p->size; i++) {
		printf("%d ", p->array[i]);
	}
	printf("\n");
}
void SeqListInit(SeqList* p) {
	assert(p);
	p->array = NULL;
	p->size =p->capacity= 0;
}
void DestroySeqList(SeqList* p) {
	free(p->array);
	p->array = NULL;
	p->size = p->capacity = 0;
}
void SeqListPushBack(SeqList* p, SeqListType x) {
	if (p->size == p->capacity) {
		int newcapacity = (p->capacity == 0 ? 4 : 2 * p->capacity);
		SeqListType* temp =realloc(p->array, newcapacity * sizeof(SeqListType));
		if (temp == NULL) {
			printf("开辟失败\n");
		}
		else {
			p->array = temp;
			p->capacity = newcapacity;
		}
	}
	p->array[p->size] = x;
	p->size++;
	printf("尾插成功\n");
}
void SeqListPushFront(SeqList* p, SeqListType x) {
	if (p->size == p->capacity) {
		int newcapacity = (p->capacity == 0 ? 4 : 2 * p->capacity);
		SeqListType* temp = (SeqListType*)realloc(p->array, newcapacity * sizeof(SeqListType));
		if (temp == NULL) {
			printf("开辟失败\n");
		}
		else {
			p->array = temp;
			p->capacity = newcapacity;
		}
	}
	int i = 0;
	for (i = p->size; i > 0; i--) {
		p->array[i] = p->array[i-1];
	}
	p->array[i]=x;
	p->size++;
	printf("头插成功\n");
}
void SeqListDelBack(SeqList* p) {
	p->size--;
	printf("尾删成功\n");
}
void SeqListDelFront(SeqList* p) {
	int i = 0;
	
	for (i = 0; i < p->size-1; i++) {
		p->array[i] = p->array[i + 1];
	}
	p->size--;
	printf("头删成功\n");
}
int SeqListFind(SeqList* p, SeqListType x) {
	int i = 0;
	for (i = 0; i < p->size; i++) {
		if (p->array[i] == x) {
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* p, size_t pos, SeqListType x) {
	if (pos >= p->capacity) {
		printf("越界！\n");
		return ;
	}
	if (p->size == p->capacity) {
		int newcapacity = (p->capacity == 0 ? 4 : 2 * p->capacity);
		SeqListType* temp = (SeqListType*)realloc(p->array, newcapacity * sizeof(SeqListType));
		if (temp == NULL) {
			printf("开辟失败\n");
		}
		else {
			p->array = temp;
			p->capacity = newcapacity;
		}
	}
	int i = 0;
	for (i = p->size; i > pos; i--) {
		p->array[i] = p->array[i - 1];
	}
	p->array[pos] = x;
	p->size++;
	printf("插入成功！\n");
}
void SeqListErase(SeqList* p, size_t pos) {
	if (pos >= p->capacity) {
		printf("越界！\n");
		return;
	}
	int i = 0;
	for (i = pos; i < p->size-1; i++) {
		p->array[i] = p->array[i + 1];
	}
	p->size--;
	printf("删除成功!\n");
}

