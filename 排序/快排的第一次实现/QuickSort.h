#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stack>
using namespace std;

void Swap(int* a, int* b);
void QuickSort1(int* a, int begin,int end);//Hoare��
void QuickSort2(int* a, int begin, int end);//�ڿӷ�
void QuickSort3(int* a, int begin, int end);//˫ָ�뷨

//�Ż�
//����ȡ��
int GetMidIndex(int* a, int left, int right);
//С�����������
void InsertSort(int* a, int sz);
//�ǵݹ�
int Part1(int* a, int begin, int end);
void QuickSortNonR(int* a, int left, int right);


