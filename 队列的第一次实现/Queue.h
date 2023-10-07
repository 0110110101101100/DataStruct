#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int QueueDataType;//������������
//��㶨��
typedef struct QueueNode
{
	struct QueueNode* next;
	QueueDataType data;
}QNode;
//���ж���
typedef struct MyQueue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void InitQueue(Queue* pq);//��ʼ��
void DestoryQueue(Queue* pq);//����
void PushQueue(Queue* pq,QueueDataType x);//����
void PopQueue(Queue* pq);//ɾ��
void PrintQueue(Queue* pq);//��ӡ
QueueDataType FrontQueue(Queue* pq);//ȡ����ͷ����
QueueDataType BackQueue(Queue* pq);//ȡ����β����
bool EmptyQueue(Queue* pq);//�п�
int SizeQueue(Queue* pq);//��Ч���ݸ���
