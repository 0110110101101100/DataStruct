#define _CRT_SECURE_NO_WARNINGS 1 
#include"DoubleLinkedList.h"

STNode* BuyListNode(STDataType x) {
	STNode* newnode = (STNode*)malloc(sizeof(STDataType));
	assert(newnode);
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;

}
STNode* InitList(STNode* phead) {
	assert(phead);

	STNode* newnode = BuyListNode(-1);//����һ��ͷ���
	newnode->next = newnode;//ͷβָ���Լ�
	newnode->prev = newnode;

	return newnode;
}
void DestoryList(STNode* phead) {
	assert(phead);

	STNode* cur = phead->next;
	STNode* after = cur->next;
	while (cur!= phead) {
		free(cur);
		cur = NULL;
		cur = after;
		after = after->next;
	}
	free(phead);//ͷ���ҲҪ���ͷ�
	phead = NULL;
}
void PrintList(STNode* phead) {
	assert(phead);
	STNode* cur = phead->next;
	while (cur != phead) {
		printf("%d ->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//����
void PushFront(STNode* phead, STDataType x) {
	
	assert(phead);
	STNode* after = phead->next;
	STNode* newnode = BuyListNode(x);
	//�����½ڵ��after�Ĺ�ϵ
	newnode->next = after;
	after->prev = newnode;
	//�����½ڵ��ͷ���Ĺ�ϵ
	phead->next = newnode;
	newnode->prev = phead;
}
void PushBack(STNode* phead, STDataType x) {
	assert(phead);

	STNode* tail = phead->prev;
	STNode* newnode = BuyListNode(x);
	//����newnode��β���Ĺ�ϵ
	tail->next = newnode;
	newnode->prev = tail;
	//����newnode��ͷ���Ĺ�ϵ
	newnode->next = phead;
	phead->prev = newnode;
}
void PushBeforePos(STNode* phead, STDataType x, STNode* pos) {
	assert(phead && pos);

	STNode* prev = pos->prev;
	STNode* newnode = BuyListNode(x);
	//����newnode��prev����ϵ
	prev->next = newnode;
	newnode->prev = prev;
	//����newnode��pos����ϵ
	newnode->next = pos;
	pos->prev = newnode;

}
//ɾ��
void PopFront(STNode* phead) {
	assert(phead);
	assert(!EmptyList(phead));

	STNode* cur = phead->next;
	STNode* after = cur->next;
	//�ı�ָ��
	phead->next = after;
	after->prev = phead;
	//ɾ���ڵ�
	free(cur);
	cur = NULL;
}
void PopBack(STNode* phead) {
	assert(phead);
	assert(!EmptyList(phead));

	STNode* tail = phead->prev;
	STNode* prev = tail->prev;
	//���½������ӹ�ϵ
	prev->next = phead;
	phead->prev = prev;
	//�ͷ�β���
	free(tail);
	tail = NULL;
}
void ErasePos(STNode* phead, STNode* pos) {
	assert(phead && pos);
	assert(!EmptyList(phead));
	
	STNode* prev = pos->prev;
	STNode* next = pos->next;
	//�ı����ӹ�ϵ
	prev->next = next;
	next->prev = prev;
	//�ͷŸ�λ�õĽ��
	free(pos);
	pos = NULL;
}
//�п�
bool EmptyList(STNode* phead) {
	assert(phead);
	return phead->next == phead;
}
int SizeList(STNode* phead) {
	assert(phead);

	int count = 0;
	STNode* cur = phead->next;

	while (cur != phead) {
		cur = cur->next;
		count++;
	}
	return count;
}