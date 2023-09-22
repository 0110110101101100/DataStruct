#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int HeapDataType;
struct Heap
{
	HeapDataType* a;
	int size;
	int capacity;
};

void InitHeap(Heap* ph);//��ʼ��
void Destroy(Heap* ph);//����
void PrintHeap(Heap* ph);//��ӡ
void Swap(HeapDataType* a, HeapDataType* b);//����
void CheckCapacity(Heap* ph);//�������
void AdjustUp(HeapDataType* a, int child);//���ϵ����㷨
void AdjustDown(HeapDataType* a, int size, int parent);//���µ����㷨
void PushHeap(Heap* ph, HeapDataType x);//����
void PopHeap(Heap* ph);//ɾ��Ԫ��
HeapDataType TopHeap(Heap* ph);//��ȡ�Ѷ�Ԫ��
bool EmptyHeap(Heap* ph);//�п�
int SizeHeap(Heap* ph);//������Ч���ݸ���


