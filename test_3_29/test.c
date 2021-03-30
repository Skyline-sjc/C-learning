#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include<stdio.h>
int main() {
	int input = 0;
	SeqList a;
	SeqListType x = 0;
	SeqListType pos = 0;
	do {
		menu();
		printf("���������ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			SeqListInit(&a);
			break;
		case 2:
			DisplaySeqList(&a);
			break;
		case 3:
			DestroySeqList(&a);
			break;
		case 4:
			printf("������Ҫ�������\n");
			scanf("%d", &x);
			SeqListPushBack(&a, x);
			break;
		case 5:
			printf("������Ҫ�������\n");
			scanf("%d", &x);
			SeqListPushFront(&a, x);
			break;
		case 6:
			SeqListDelBack(&a);
			break;
		case 7:
			SeqListDelFront(&a);
			break;
		case 8:
			printf("������Ҫ�������\n");
			scanf("%d", &x);
			printf("λ���ڣ�%d", SeqListFind(&a, x));
			printf("\n");
			break;
		case 9:
			printf("������λ�ã�\n");
			scanf("%d", &pos);
			printf("������Ҫ�������\n");
			scanf("%d", &x);
			SeqListInsert(&a, pos, x);
			break;
		case 10:
			printf("������λ�ã�\n");
			scanf("%d", &pos);
			SeqListErase(&a, pos);
			break;
		}
	} while (input);
	return 0;
}