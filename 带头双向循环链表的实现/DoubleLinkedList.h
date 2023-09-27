#pragma once
//˫��ѭ����ͷ�����ʵ��
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDataType;
struct STNode {
	struct STNode* next;
	struct STNode* prev;
	STDataType data;
};//����˫����Ľṹ

STNode* BuyListNode(STDataType x);//�����½ڵ�
STNode* InitList(STNode* phead);//��ʼ������
void DestoryList(STNode* phead);//��������
void PrintList(STNode* phead);//��ӡ����
//����
void PushFront(STNode* phead, STDataType x);//ͷ��
void PushBack(STNode* phead, STDataType x);//β��
void PushBeforePos(STNode* phead, STDataType x, STNode* pos);//��ָ��λ��֮ǰ����
//ɾ��
void PopFront(STNode* phead);//ͷɾ
void PopBack(STNode* phead);//βɾ
void ErasePos(STNode* phead, STNode* pos);//ɾ��ָ��λ�õĽڵ�
//�п�
bool EmptyList(STNode* phead);//�ж������Ƿ�Ϊ��
int SizeList(STNode* phead);//������ЧԪ�ظ���
