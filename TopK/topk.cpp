#define _CRT_SECURE_NO_WARNINGS 1 
#include"topk.h"
//ȡ��ǰk������� ��С��
void AdjustDown(int* a, int size, int parent) {
	int child = 2 * parent + 1;
	while (child<size)
	{
		if (child + 1 < size && a[child + 1] < a[child]) {
			child += 1;
		}
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void TopK(int* a, int n, int k)
{
	//����һ������
	int* KMin = (int*)malloc(sizeof(k));
	assert(KMin);
	for (int i = 0; i < k; i++) {
		KMin[i] = a[i];
	}

	//�������齨����С��
	for (int i = (k - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(a,k, 0);
	}

	//��ʣ�µ�Ԫ����Ѷ��Ƚ� �����������Ѳ��ҵ���
	for (int i = k; i < n; i++) {
		if (a[i] > KMin[0]) {
			KMin[0] = a[i];
			AdjustDown(KMin, k, 0);
		}
	}

	//��ӡ�������һ��
	for (int i = 0; i < k; i++) {
		printf("%d ", KMin[i]);
	}
	printf("\n");
}
void Print(int* a, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}