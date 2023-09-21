#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int StackDataType;
typedef struct Stack {
	StackDataType* a;
	int top;
	int capacity;
}st;

void InitStack(st* ps);//��ʼ��
void DestroyStack(st* ps);//����
void PrintStack(st* ps);//��ӡ
void PushStack(st* ps, StackDataType x);//��ջ
void PopStack(st* ps);//��ջ
StackDataType TopStack(st* ps);//����ջ��Ԫ��
int SizeStack(st* ps);//������ЧԪ�صĸ���
bool EmptyStack(st* ps);//�ж�ջ�Ƿ�Ϊ��
