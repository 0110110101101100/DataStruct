#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void AdjustDown(int* a, int size, int parent);//���µ����㷨
void AdjustUp(int* a, int child);//���ϵ����㷨
void Swap(int* a, int* b);//����
void InitHeap(int* a, int size);//����
void HeapSort(int* a, int size);//����
void Print(int* a, int size);//��ӡ

