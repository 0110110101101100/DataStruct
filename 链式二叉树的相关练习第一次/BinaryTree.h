#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"Queue.h"

typedef char BTDataType;
typedef struct BTNode
{
	BTDataType x;
	BTNode* left;
	BTNode* right;
}BTNode;
//����
BTNode* BuyNode(BTDataType x);//�������
BTNode* CreatBinartTree();//����������
void BinaryPrevOrder(BTNode* root);//ǰ�����
void BinaryInOrder(BTNode* root);//�������
void BinaryPostOrder(BTNode* root);//�������
void BinaryLevelOrder(BTNode* root);//�������
int BinaryTreeSize(BTNode* root);//�����ܽ�����
int BinartTreeLeafSize(BTNode* root);//Ҷ�ӽ������
int BInaryTreeLevelSize(BTNode* root, int k);//��k����ĸ���
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//��ֵΪk�Ľ��
int Max(int a, int b);//�����ֵ
int BinaryTreeMaxDepth(BTNode* root);//�����
