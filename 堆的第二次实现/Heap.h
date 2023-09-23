#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//Heap�ṹ
typedef int HeapDataType;
struct Heap {
	HeapDataType* a;
	int size;
	int capacity;
};

void InitHeap(Heap* ph);//��ʼ��
void DestroyHeap(Heap* ph);//����
void PrintHeap(Heap* ph);//��ӡ
void AdjustUp(int* a, int child);//���ϵ����㷨
void AdjustDown(int* a, int size, int parent);//���µ����㷨
void Swap(HeapDataType* a, HeapDataType* b);//����
void CheckCapacity(Heap* ph);//�������
void PushHeap(Heap* ph,HeapDataType x);//����
void PopHeap(Heap* ph);//��ӡ
HeapDataType TopHeap(Heap* ph);//��ӡ����Ԫ��
bool EmptyHeap(Heap* ph);//�п�
int SizeHeap(Heap* ph);//������ЧԪ��

