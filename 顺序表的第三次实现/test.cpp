#define _CRT_SECURE_NO_WARNINGS 1 
#include"sequenceList.h"

void test() {
	SL s;
	SLInit(&s);//��ʼ��
	SLDestroy(&s);//����

	SLInsert(&s, 1, 0);
	SLInsert(&s, 2, 0);
	SLInsert(&s, 3, 0);
	SLInsert(&s, 4, 0);
	SLInsert(&s, 5, 0);
	SLPrint(&s);

	//β����
	SLPushBack(&s, 9);
	SLPushBack(&s, 9);
	SLPushBack(&s, 9);
	SLPushBack(&s, 9);
	SLPushBack(&s, 9);
	SLPushBack(&s, 9);
	SLPushBack(&s, 9);
	SLPrint(&s);

	//ͷ��
	SLPushFront(&s, 8);
	SLPushFront(&s, 8);
	SLPushFront(&s, 8);
	SLPushFront(&s, 8);
	SLPushFront(&s, 8);
	SLPrint(&s);
	//����λ��ɾ��
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLPrint(&s);
	//βɾ
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);
	//ͷɾ
	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);
		
}

int main() {
	test();
	return 0;
}