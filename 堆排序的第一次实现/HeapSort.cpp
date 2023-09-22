#define _CRT_SECURE_NO_WARNINGS 1 
#include"HeapSort.h"
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustDown(int* a, int n, int parent) {
	//�ȼ���Ϊ����
	int child = 2 * parent + 1;
	//ȡ�����Һ����н�С�Ľ��
	while(child<n){
		if (child + 1 < n && a[child + 1] < a[child]) {
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
void AdjustUp(int* a, int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
void InitHeapUp(int* a,int size) {
	for (int i = 1; i < size; i++) {
		AdjustUp(a, i);
	}
}
void InitHeapDown(int* a, int size) {
	for (int i = (size - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(a, size, i);
	}
}
//�Ž���С��
void HeapSort(int* a,int size) {
	InitHeapDown(a, size);//����

	//�ѶѶ������ݷŵ����һ��λ�� �ź�����
	for (int i = size - 1; i > 0; i--) {
		Swap(&a[0], &a[i]);
		//����ʣ�µ������˳��
		AdjustDown(a, i, 0);
	}

}
void Print(int* a,int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}