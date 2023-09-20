#pragma once

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

typedef int SLDataType;//������������
typedef struct sequenceList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

//���δ�����ϰ��Ҫ�����Insert��Erase������ʵ��ͷ�� ͷɾ��β�� βɾ
void SLInit(SL* ps);//��ʼ��
void SLDestroy(SL* ps);//����
void SLPrint(SL* ps);//��ӡ
void CheckCapacity(SL* ps);//�������
void SLInsert(SL* ps,SLDataType x,int pos);//����
void SLPushBack(SL* ps,SLDataType x);//β��
void SLPushFront(SL* ps, SLDataType x);//ͷ��
void SLErase(SL* ps,int pos);//����λ��ɾ��
void SLPopBack(SL* ps);//βɾ
void SLPopFront(SL* ps);//ͷɾ
