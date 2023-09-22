#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int StackDataType;
struct Stack {
	StackDataType* a;
	int top;//ֻ����ջ������ ������˳����size
	int capacity;//��������
};

void InitStack(Stack* ps);//��ʼ��
void DestroyStack(Stack* ps);//����
void PushStack(Stack* ps,StackDataType x);//��ջ
void PopStack(Stack* ps);//��ջ
StackDataType TopStack(Stack* ps);//����ջ��Ԫ��
bool EmptyStack(Stack* ps);//�ж��Ƿ�Ϊ��
int SizeStack(Stack* ps);//��ЧԪ�ظ���
