#pragma once

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef int SLDataType;//��������
typedef struct SequenceList {
	SLDataType* a;
	int size;
	int capacity;//��̬����
}SL;
//��ʼ�����ٺʹ�ӡ
void InitSL(SL* ps);
void DestroySL(SL* ps);
void PrintSL(SL* ps);
//�������͸��ֲ���
void CheckCapacity(SL* ps);
void PushBackSL(SL* ps,SLDataType x);
void PushFrontSL(SL* ps,SLDataType x);
void InsertSL(SL* ps, SLDataType x,int pos);
//ɾ��
void PopBackSL(SL* ps);
void PopFrontSL(SL* ps);
void EraseSL(SL* ps, int pos);
//���Һ��޸�
int FindSL(SL* ps, SLDataType x);
void ModifySL(SL* ps, int pos, SLDataType x);
