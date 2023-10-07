#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"

void InitQueue(Queue* pq) {
	assert(pq);

	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void DestroyQueue(Queue* pq) {
	assert(pq);

	QNode* cur = pq->head;
	while (cur) {
		pq->head = cur->next;
		free(cur);
		cur = NULL;
	}
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
void PushQueue(Queue* pq, QueueDataType x) {
	assert(pq);
	//�����½ڵ�
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail==NULL) {
		pq->tail = pq->head = newnode;
	}
	//�����������
	else {
	pq->tail->next = newnode;
	pq->tail = newnode;
	}
	pq->size++;
}
void PopQueue(Queue* pq) {
	assert(pq);
	//1 Ϊ�յ�����²���ɾ��
	assert(!EmptyQueue(pq));
	//2 ֻ��һ���ڵ�������Ұָ������
	if(pq->head->next==NULL){
		free(pq->tail);
		pq->head = pq->tail = NULL;
	}
	//3 ���������ɾ��
	else{
		QNode* cur = pq->head;
		pq->head = cur->next;
		free(cur);
		cur = NULL;
	}
	pq->size--;
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
	return pq->tail==NULL;
}
int SizeQueue(Queue* pq) {
	assert(pq);
	return pq->size;
}