#pragma once

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

typedef int QueueDataType;//������������
typedef struct QueueNode
{
	QueueNode* next;
	QueueDataType data;//�������ָ����
}QNode;//��������ʵ�ֶ��У�������

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;//������еĽṹ

void InitQueue(Queue* pq);//��ʼ��
void DestroyQueue(Queue* pq);//����
void PrintQueue(Queue* pq);//��ӡ
void PushQueue(Queue* pq, QueueDataType x);//���루β�壩
void PopQueue(Queue* pq);//ɾ����ͷɾ��
QueueDataType FrontQueue(Queue* pq);//ͷԪ��
QueueDataType BackQueue(Queue* pq);//βԪ��
bool EmptyQueue(Queue* pq);//�п�
int SizeQueue(Queue* pq);//������ЧԪ�صĸ���
