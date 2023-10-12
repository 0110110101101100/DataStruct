#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QueueDataType;//������������
typedef struct QueueNode {
	QueueNode* next;
	QueueDataType data;
}QNode;//������
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	int size;
}Queue;

void InitQueue(Queue* pq);//��ʼ��
void DestroyQueue(Queue* pq);//����
void PrintQueue(Queue* pq);//��ӡ
void PushQueue(Queue* pq, QueueDataType x);//���루β�壩
void PopQueue(Queue* pq);//ɾ��
QueueDataType FrontQueue(Queue* pq);//����ͷ������
QueueDataType BackQueue(Queue* pq);//����β������
int SizeQueue(Queue* pq);//������ЧԪ�صĸ���
bool EmptyQueue(Queue* pq);//�п�
