#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//������ṹ
typedef int SLDataType;
typedef struct SLNode {
	struct SLNode* next;//��һ������λ��
	SLDataType data;//����
}SLNode;

//���ܺ���
void PrintSL(SLNode** pplistnode);//��ӡ
SLNode* BuyListNode(SLDataType x);//����
//����
void PushFrontSL(SLNode** pplistnode, SLDataType x);//ͷ��
void PushBackSL(SLNode** pplistnode, SLDataType x);//β��
void InsertBeforeNode(SLNode** pplistnode, SLDataType x, SLNode* pos);//��posλ��֮ǰ����
void InsertAfterNode(SLNode** pplistnode, SLDataType x, SLNode* pos);//��posλ��֮ǰ����
//ɾ��
void PopFrontSL(SLNode** pplistnode);//ͷɾ
void PopBackSL(SLNode** pplistnode);//βɾ
void ErasePosSL(SLNode** pplistnodec);//���ض�λ��ɾ��
void EraseAfterPosSL(SLNode* pos);//���ض�λ��֮��ɾ��
//����
SLNode* FindNode(SLNode** pplistnode, SLNode* x);//�����ض�λ�õĽ��
//�޸�
void ModifyNode(SLNode*pos,SLDataType x);//�޸��ض�λ�õĽ��
