#define _CRT_SECURE_NO_WARNINGS 1 
#include"SingleList.h"
//һ��ָ���޸��ǴӺ���ǰ�����޸� Ҫ����Щ�޸��˾ͻᵼ���Ҳ�����һ������λ��
//���ܺ���
void PrintSL(SLNode** pplistnode) {
	assert(pplistnode);

	SLNode* cur = *pplistnode;
	while (cur->next != NULL) {
		printf("%d ->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
SLNode* BuyListNode(SLDataType x) {
	SLNode* node =(SLNode*) malloc(sizeof(SLNode));
	assert(node);
	
	node->data = x;
	node->next = NULL;

	return node;
}
//����
void PushFrontSL(SLNode** pplistnode, SLDataType x) {
	assert(pplistnode);

	SLNode* node = BuyListNode(x);//����һ�����
	node->next = *pplistnode;//�ı�ָ�����ӵ��ʼ��λ��
	*pplistnode = node;//�ı�ͷָ��

}
void PushBackSL(SLNode** pplistnode, SLDataType x) {
	assert(pplistnode);
	
	//����һ�����
	SLNode* node = BuyListNode(x);
	//����ǿ����� ����Կ�ָ�������
	if (*pplistnode == NULL) {
		*pplistnode = node;
	}
	else {
		//��β
		SLNode* tail = *pplistnode;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//������������ �����ͷŽ��
		node->next = tail->next;
		tail->next = node;
	}
}
void InsertBeforeNode(SLNode** pplistnode, SLDataType x, SLNode* pos) {
	assert(pplistnode&&pos);
	//�����½��
	SLNode* node=BuyListNode(x);
	//��������λ����ͷ����λ�� ��ô�൱��ͷ�� ��Ϊ����ѭ����������ȥ
	if (pos==*pplistnode) {
		node->next = pos;
		*pplistnode = node;
	}
	else {
		//�ҵ�����λ�õ�ǰһ��λ��
		SLNode* prev = *pplistnode;
		while (prev->next != pos) {
			prev = prev->next;
		}
		node->next = pos;
		prev->next = node;
	}
}
//���ض����֮���֮ǰ�����û�п���������������ж���
void InsertAfterNode(SLNode** pplistnode, SLDataType x, SLNode* pos) {
	assert(pplistnode);
	SLNode* node = BuyListNode(x);//����һ�����
	node->next = pos->next;
	pos->next = node;
}
//ɾ��
void PopFrontSL(SLNode** pplistnode) {
	assert(pplistnode);
	if (*pplistnode == NULL) {
		return;//�սڵ㲻��ɾ��
	}
	else {
		SLNode* tmp = *pplistnode;
		*pplistnode = (*pplistnode)->next;
		free(tmp);
		tmp = NULL;
	}
	
}
void PopBackSL(SLNode** pplistnode) {
	assert(pplistnode);
	//�����漰��prev�Ķ�Ҫ����Ƿ�ֻ��һ��������ͷ���
	//����Ϊ��
	if (*pplistnode == NULL) {
		return;
	}
	//ֻ��һ�����
	else if ((*pplistnode)->next == NULL) {
		free(*pplistnode);
		*pplistnode = NULL;
	}
	else {
		SLNode* prev = *pplistnode;
		SLNode* tail = prev->next;
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		prev->next = tail->next;
		free(tail);
		tail = NULL;
	}
}
void ErasePosSL(SLNode** pplistnode,SLNode* pos){
	assert(pos && pplistnode);//��λ�ò���Ϊ��
	//���ɾ������ͷ���
	if (pos==*pplistnode) {
		*pplistnode = (*pplistnode)->next;
		free(pos);
		pos = NULL;
	}
	else {
		SLNode* prev = *pplistnode;
		while (prev->next != pos) {
			prev = prev->next;	
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void EraseAfterPosSL(SLNode* pos) {
	assert(pos);//��λ�ò���Ϊ�� 
	//��������һ�����Ͳ�ɾ����
	if (pos->next == NULL) {
		return;
	}
	else {
		SLNode* after = pos->next;
		pos->next = after->next;
		free(after);
		after = NULL;
	}

}
//����
SLNode* FindNode(SLNode** pplistnode, SLDataType x) {
	SLNode* cur = *pplistnode;
	while (cur != NULL) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
	
}
//�޸�����
void ModifyNode(SLNode* pos, SLDataType x) {
	assert(pos);
	pos->data = x;
}