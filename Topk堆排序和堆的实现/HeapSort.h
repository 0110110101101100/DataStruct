#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

typedef int HeapDataType;
struct Heap
{
	HeapDataType* a;
	int size;
	int capacity;
};

void InitHeap(Heap* ph);//��ʼ��
void DestroyHeap(Heap* ph);//����
void PrintHeap(Heap* ph);//��ӡ
void AdjustDown(int* a, int n,int parent);//���µ���
void AdjustUp(int* a, int child);//���ϵ���
void Swap(int* a, int* b);//����
void CheckCapacity(Heap* ph);
void PushHeap(Heap* ph, HeapDataType x);//����
void PopHeap(Heap* ph );//ɾ��
HeapDataType TopHeap(Heap* ph);//�ҵ��Ѷ���
bool EmptyHeap(Heap* ph);//�п�
int SizeHeap(Heap* ph);//����������Ч���ݵĸ���
void HeapSort(int*a,int n);//������
void PrintTopK(int* a, int n, int k);//TopK����
