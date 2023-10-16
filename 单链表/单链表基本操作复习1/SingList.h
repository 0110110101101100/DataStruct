#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;
typedef struct SingListNode
{
	SingListNode* next;
	SLDataType data;
}SLNode;

SLNode* BuyListNode(SLDataType x);//�������
void InitList(SLNode** pplist);//��ʼ��
void DestroyList(SLNode** pplist);//����
void PushBack(SLNode** pplist, SLDataType x);//β��
void PushFront(SLNode** pplist, SLDataType x);//ͷ��
void InsertAfterPos(SLNode** pplist, SLDataType x, SLNode* pos);//��posλ��֮�����
void InsertBeforePos(SLNode** pplist, SLDataType x, SLNode* pos);//��posλ��֮ǰ����
void PopBack(SLNode** pplist);//βɾ
void PopFront(SLNode** pplist);//ͷɾ
void PopAfterPos(SLNode** pplist, SLNode* pos);//��posλ��֮��ɾ��
void PopPos(SLNode** pplist, SLNode* pos);//ɾ��posλ�õ�ֵ
bool Empty(SLNode** pplist);//�п�
int Size(SLNode** pplist);//�ж���ЧԪ�صĸ���
void Print(SLNode** pplist);//��ӡ


