#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

void Swap(int* a, int* b);
//�����㷨
void AdjustDown(int* a, int n, int parent);
void AdjustUp(int* a, int child);
//������
void HeapSort(int* a,int size);
//���ϵ�������
void InitHeapUp(int* a,int size);
//���µ�������
void InitHeapDown(int* a, int size);
void Print(int* a,int size);
