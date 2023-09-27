#define _CRT_SECURE_NO_WARNINGS 1 
#include"SL.h"

//�������
SLNode* BuyNode(SLDataType x) {
	SLNode* newnode = (SLNode*)malloc(sizeof(SLDataType));
	assert(newnode);
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}
//����
void PushBack(SLNode** pplist, SLDataType x) {
	assert(pplist);
	//����һ���µĽ��
	SLNode* newnode = BuyNode(x);
	//��ֹ�Կ�ָ��Ľ�����
	if(*pplist==NULL){
		//����ǿ�����ֱ�ӽ�������
		*pplist = newnode;
	}
	else {
		//����������ݵ��ҵ�β�ͺ����ӽ�ȥ
		SLNode* tail = *pplist;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newnode->next;
	}
}
void PushFront(SLNode** pplist, SLDataType x) {
	assert(pplist);

	SLNode* newnode = BuyNode(x);//����һ�����
	newnode->next = *pplist;
	*pplist = newnode;
}
void InsertAfterPos(SLNode** pplist, SLNode* pos, SLDataType x) {
	assert(pplist);
	SLNode* newnode = BuyNode(x);//����һ�����
	//���ΪNULL���� ֱ�Ӳ���
	if (*pplist==NULL) {
		*pplist = newnode;
	}
	else {
		newnode->next = pos->next;
		pos->next = newnode;
	}

}
void InsertBeforePos(SLNode** pplist, SLNode* pos, SLDataType x) {
	assert(pos && pplist);

	SLNode* newnode = BuyNode(x);//����һ�����
	
	//�����ͷ��㣨������ֻ��һ����������� ����Կ�ָ��Ľ����� �൱��ͷ��
	if(pos==*pplist){
		newnode->next = *pplist;
		*pplist = newnode;
	}
	else {
		SLNode* prev = *pplist;
		while (prev->next != pos) {
			prev = prev->next;
		}
		newnode->next = prev->next;
		prev->next = newnode;
	}
}
//ɾ��
void PopBack(SLNode** pplist) {
	assert(*pplist);//������Ϊ��
	//���ֻ��һ�����
	if ((*pplist)->next == NULL) {
		free(*pplist);
		*pplist = NULL;
	}
	else {
		SLNode* prev = *pplist;
		SLNode* tail = prev->next;
		//��β
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		prev->next = tail->next;
		free(tail);
		tail = NULL;
	}

}
void PopFront(SLNode** pplist) {
	assert(*pplist);//��������Ϊ��
	//�������Ǹı�ͷ�����Ҳ���֮ǰ��λ�� ��Ϊ�����ַ�����¼
	//1��¼�µ�ͷ
	/*SLNode* newhead = *pplist;
	newhead = (*pplist)->next;
	free(*pplist);
	*pplist = NULL;
	*pplist=newhead;*/

	//2��¼֮ǰ�ͷŵ�λ��
	SLNode* tmp = *pplist;
	*pplist = (*pplist)->next;
	free(tmp);
	tmp = NULL;
}
//Ҫͷָ����ΪҪpos֮ǰ�Ľ��
void ErasePos(SLNode** pplist, SLNode* pos) {
	assert(pos && (*pplist));//��Ϊ�������Ҹ�λ�ò�Ϊ��

	if((*pplist)==pos){
		*pplist = pos->next;//ͷ���¶���
		free(pos);
		pos = NULL;
	}
	else {
		SLNode* prev = *pplist;
		while (prev->next != pos) {
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//����Ҫͷָ�� ��Ϊֻ����pos֮���
void EraseAfterPos(SLNode* pos) {
	assert(pos);//��������Ϊ��
	//ֻ��һ����� ֱ��ɾ���ýڵ�
	if (pos->next == NULL) {
		free(pos);
		pos = NULL;
	}
	else {
		SLNode* next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
	}
}
//����
SLNode* FindNode(SLNode** pplist, SLDataType x) {
	assert(*pplist);

	while (( * pplist)->next != NULL) {
		if ((*pplist)->data == x) {
			return *pplist;
		}
	}
	return NULL;
}
//�޸�ָ��λ�õ�ֵ
//����Ҫͷָ��
void ModifyNode(SLNode* pos, SLDataType x) {
	assert(pos);
	pos->data = x;
}