#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"

void InitQueue(Queue* pq) {
	assert(pq);

	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void DestoryQueue(Queue* pq) {
	assert(pq);
	QNode* cur = pq->head;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void PushQueue(Queue* pq, QueueDataType x) {
	assert(pq);
	//�����µĽ��
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	//�����һ������ֹ��ָ��Ľ�����)
	if (pq->head == NULL) {
		pq->head = pq->tail = newnode;
	}
	//�����������
	else {
		//�ı�ָ��
		pq->tail->next = newnode;
		//�ı�β���
		pq->tail = newnode;
	}
	pq->size++;
}
void PopQueue(Queue* pq) {
	assert(pq);
	//1 Ϊ�ղ���ɾ��
	assert(!EmptyQueue(pq));
	//2 �����ֻ��һ����� ��ֹβ��㱻�ͷź�Ľ�����
	if (pq->head->next==NULL) {
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	//3 �������ɾ��
	else {
	QNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	}
	pq->size--;
}
void PrintQueue(Queue* pq) {
	assert(pq);
	QNode* cur = pq->head;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
QueueDataType FrontQueue(Queue* pq) {
	assert(pq);
	return pq->head->data;
}
QueueDataType BackQueue(Queue* pq) {
	assert(pq);
	return pq->tail->data;
}
bool EmptyQueue(Queue* pq) {
	assert(pq);
	return pq->tail == NULL;//head����tailһ��ΪNULL����
}
int SizeQueue(Queue* pq) {
	assert(pq);
	return pq->size;
}