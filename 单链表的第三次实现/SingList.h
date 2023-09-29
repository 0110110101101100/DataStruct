#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;
struct SLNode {
	struct SLNode* next;
	SLDataType data;
};//����������Ľṹ

SLNode* BuyNode(SLDataType x);//�������
//����
void PushBack(SLNode** pplist, SLDataType x);//β��
void PushFront(SLNode** pplist, SLDataType x);//ͷ��
void InsertBeforePos(SLNode** pplist,SLDataType x, SLNode* pos);//��ָ��λ��֮ǰ������
void InsertAfterPos(SLDataType x, SLNode* pos);//��ָ��λ��֮�������
//ɾ��
void PopBack(SLNode** pplist);//βɾ
void PopFront(SLNode** pplist);//ͷɾ
void PopPos(SLNode** pplist, SLDataType x, SLNode* pos);//��ָ��λ��֮ǰɾ�����
void PopAfterPos(SLDataType x, SLNode* pos);//��ָ��λ��֮��ɾ�����
//�п�
bool EmptySL(SLNode** pplist);
//�ж���ЧԪ�صĸ���
int SizeSL(SLNode** pplist);
//��ӡ
void PrintSL(SLNode** pplist);