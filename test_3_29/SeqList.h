#pragma once
#include<stdio.h>
typedef int SeqListType;
typedef struct SeqList {
	SeqListType *array;
	size_t size;
	size_t capacity;
}SeqList;
void SeqListPushBack(SeqList* p, SeqListType x);
void SeqListPushFront(SeqList* p, SeqListType x);
void SeqListDelBack(SeqList* p);
void SeqListDelFront(SeqList* p);
void SeqListInit(SeqList* p);
void DisplaySeqList(SeqList* p);
void DestroySeqList(SeqList* p);
// ˳������
int SeqListFind(SeqList* p, SeqListType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* p, size_t pos, SeqListType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* p, size_t pos);
