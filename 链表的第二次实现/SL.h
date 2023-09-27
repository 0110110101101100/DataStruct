#pragma once

//1 �Ƿ���Ҫ����ͷָ��
//һ���漰��ָ��λ�õ� ֻ����ָ��λ��֮��Ĳ��� ����Ҫ����ͷָ��
//2 prev����Ҫ������Ϊͷ����������п���

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;//��������
struct SLNode
{
	struct SLNode* next;//������һ������λ��
	SLDataType data;//��������
};

//�������
SLNode* BuyNode(SLDataType x);
//����
void PushBack(SLNode** pplist, SLDataType x);//β��
void PushFront(SLNode** pplist, SLDataType x);//ͷ��
void InsertAfterPos(SLNode** pplist, SLNode* pos, SLDataType x);//��ָ��λ��֮�����
void InsertBeforePos(SLNode** pplist, SLNode* pos, SLDataType x);//��ָ��λ��֮ǰ����
//ɾ��
void PopBack(SLNode** pplist);//βɾ
void PopFront(SLNode** pplist);//ͷɾ
void ErasePos(SLNode** pplist, SLNode* pos);//ɾ��ָ��λ�õ�ֵ
void EraseAfterPos(SLNode* pos);//ɾ��ָ��λ��֮���ֵ
//����
SLNode* FindNode(SLNode** pplist, SLDataType x);//����ָ��λ��ֵ
//�޸�ָ��λ�õ�ֵ
void ModifyNode(SLNode* pos, SLDataType x);//�޸�ָ��λ�õ�ֵ
