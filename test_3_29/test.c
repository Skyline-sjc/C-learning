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
		printf("请输入你的选择\n");
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
			printf("请输入要输入的数\n");
			scanf("%d", &x);
			SeqListPushBack(&a, x);
			break;
		case 5:
			printf("请输入要输入的数\n");
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
			printf("请输入要输入的数\n");
			scanf("%d", &x);
			printf("位置在：%d", SeqListFind(&a, x));
			printf("\n");
			break;
		case 9:
			printf("请输入位置：\n");
			scanf("%d", &pos);
			printf("请输入要输入的数\n");
			scanf("%d", &x);
			SeqListInsert(&a, pos, x);
			break;
		case 10:
			printf("请输入位置：\n");
			scanf("%d", &pos);
			SeqListErase(&a, pos);
			break;
		}
	} while (input);
	return 0;
}