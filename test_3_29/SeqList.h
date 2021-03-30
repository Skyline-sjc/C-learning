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
// 顺序表查找
int SeqListFind(SeqList* p, SeqListType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* p, size_t pos, SeqListType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* p, size_t pos);
