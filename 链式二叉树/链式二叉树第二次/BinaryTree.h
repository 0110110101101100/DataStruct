#pragma once
#include"Queue.h"

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTree
{
	BTDataType data;
	BinaryTree* left;
	BinaryTree* right;
}BTNode;

BTNode* BuyNode(BTDataType x);
BTNode* CreatBinaryTree();
//����
void PrevOrder(BTNode* node);//ǰ�����
void InOrder(BTNode* node);//�������
void PostOrder(BTNode* node);//��������
void LevelOrder(BTNode* node);//������� 
int TreeSize(BTNode* node);//�ܽ������
int TreeLeafSize(BTNode* node);//Ҷ�ӽ�������
int TreeLevelSize(BTNode* node,int k);//��k���������
BTNode* Findnode(BTNode* root, BTDataType x);//����ֵΪx�Ľ��
int Max(int a, int b);//�����ֵ
int BinaryTreeMaxDepth(BTNode* root);//�����