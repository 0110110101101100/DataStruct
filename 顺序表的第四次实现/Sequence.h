#pragma once

#include<stdlib.h>
#include<assert.h>
#include<stdio.h>


typedef int SDataType;
typedef struct Sequence {
	int size;
	int capacity;
	int* a;
}Sequence;

void InitSequence(Sequence* ps);//��ʼ��
void DestroySequence(Sequence* ps);//����
void Print(Sequence* ps);//��ӡ

void CheckCapacity(Sequence* ps);
void PushFront(Sequence* ps,SDataType x);//ͷ��
void PushBack(Sequence* ps, SDataType x);//β��
void Insert(Sequence* ps, SDataType x, int pos);//posλ�ò���

void PopFront(Sequence* ps);//ͷɾ
void PopBack(Sequence* ps);//βɾ
void Erase(Sequence* ps,int pos);//����λ��ɾ��

bool Empty(Sequence* ps);//�п�
int Size(Sequence* ps);//��ЧԪ�ظ���
