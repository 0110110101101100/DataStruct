#pragma once

#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

typedef int StackDataType;
typedef struct Stack
{
	int* a;
	int capacity;
	int top;
}Stack;

void InitStack(Stack* ps);//��ʼ��
void DestroyStack(Stack* ps);//����
void Print(Stack* ps);//��ӡ
void CheckCapacity(Stack* ps);//�������
void Push(Stack* ps, StackDataType x);//����
void Pop(Stack* ps);//ɾ��
bool Empty(Stack* ps);//�ж��Ƿ�Ϊ��
int Size(Stack* ps);//�ж���ЧԪ�صĸ���


