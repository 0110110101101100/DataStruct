#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"
//��������
//������ĩβ�����ݲ��뵽ǰ��n-1�����ݵ���Ч������
//���ұ�֤ǰn-1�����ݼ����������
//��ô�Ϳ��Ա�֤�����������
//���ѭ����һ���Ƚϵ����������һ��λ����size-1 
//��ô����Ҫ�Ƚ�size-1-1��
void InsertSort(int* a, int size) {
	//������
	//ʱ�临�Ӷ�O(n^2) �ռ临�Ӷ�O(1)
	//i ���ڼ�¼endλ�� ���ѭ���ǱȽ�����
	for (int i = 0; i < size - 1; i++) {
		//��������
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + 1] = a[end];
				end--;
			}
			/*1 �ҵ��˺��ʵ�����ѭ��
			2 ���tmp���������κ�һ�����ݶ�ҪС*/
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//Ԥ����+ֱ�Ӳ�������
//Ԥ�������ʱ�临�Ӷȣ�ʹ����������߽ӽ�����
//���һ��ֱ�Ӳ�������ȷ�������������
//ʱ�临�Ӷ�O(NlogN) �ռ临�Ӷ�O(1)
void ShellSort(int* a, int size) {
	int gap = size;
	while (gap > 1) {
		gap = gap / 3 + 1;//��֤���һ����1
		for (int i = 0; i < size - gap; i++) {
			int end = i;
			int tmp = a[end + 1];
			while (end >= 0) {
				if (tmp < a[end]) {
					a[end + 1] = a[end];
					end--;
				}
				else {
					break;
				}
			}
			a[end + 1] = tmp;
		}
	}
}

void Print(int* a, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}