#define _CRT_SECURE_NO_WARNINGS 1 
#include"SingList.h"

SLNode* BuyNode(SLDataType x) {
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	assert(newnode);
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}
//����
void PushBack(SLNode** pplist, SLDataType x) {
	SLNode* newnode = BuyNode(x);//����һ�����
	//�������Ϊ�� �������д���
	if (*pplist == NULL) {
		*pplist = newnode;
	}
	else {
		//��β
		SLNode* tail = *pplist;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//�޸����ӹ�ϵ
		tail->next = newnode;
	}
}
void PushFront(SLNode** pplist, SLDataType x) {
	SLNode* newnode = BuyNode(x);//����һ�����
	newnode->next = *pplist;
	*pplist = newnode;
}
void InsertBeforePos(SLNode** pplist,SLDataType x, SLNode* pos) {
	assert(pos);
	SLNode* newnode = BuyNode(x);//����һ���µĽ��
	//ֻ��һ�����������Ҫ�������п���(ͷָ�룩
	if (*pplist==pos) {
		newnode->next = *pplist;
		*pplist = newnode;
	} {
		//�ҵ�posǰ��һ��λ�õĽ��
		SLNode* prev = *pplist;
		while (prev->next != pos) {
			prev = prev->next;
		}
		//�޸����ӹ�ϵ
		newnode->next = prev->next;
		prev->next = newnode;
	}
}
void InsertAfterPos(SLDataType x, SLNode* pos) {
	assert(pos);
	SLNode* newnode = BuyNode(x);//����һ�����
	newnode->next = pos->next;
	pos->next = newnode;
}
void PopBack(SLNode** pplist) {
	assert(!EmptySL(pplist));//����Ϊ��
	if ((*pplist)->next == NULL) {
		free(*pplist);
		*pplist = NULL;//ֻ��һ������൱��ͷɾ
	}
	else {
		SLNode* prev = *pplist;
		SLNode* tail = prev->next;
		while (tail->next!=NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;//�������ڶ�������ָ�����ÿգ�ʹ���Ϊ�µ�β��㣨��ֹֻ��ɾ��һ�ε������
	}
}
void PopFront(SLNode** pplist) {
	assert(!EmptySL(pplist));
	//��¼��һ������λ��
	/*SLNode* next = (*pplist)->next;
	free(*pplist);
	*pplist = next;*/

	SLNode* tmp = *pplist;
	*pplist = (*pplist)->next;
	free(tmp);
	tmp = NULL;
}
void PopPos(SLNode** pplist, SLDataType x, SLNode* pos) {
	assert(pos);
	if (*pplist == pos) {
		*pplist = pos->next;
		free(pos);
		pos = NULL;
	}
	else {
		SLNode* prev = *pplist;
		while (prev->next != NULL) {
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void PopAfterPos(SLDataType x, SLNode* pos){
	assert(pos);//ɾ���Ľڵ㲻Ϊ��
	assert(pos->next != NULL);//��Ϊ���һ������λ��
	SLNode* after = pos->next;
	pos->next = after->next;
	free(after);
	after = NULL;
}
//�п�
bool EmptySL(SLNode** pplist) {
	assert(*pplist);
	return *pplist == NULL;
}
//�ж���ЧԪ�صĸ���
int SizeSL(SLNode** pplist) {
	int count = 0;
	SLNode* cur = *pplist;
	while (cur->next != NULL) {
		count++;
		cur = cur->next;
	}
	return count;
}
void PrintSL(SLNode** pplist) {
	SLNode* cur = *pplist;
	while (cur->next != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}