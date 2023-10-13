#define _CRT_SECURE_NO_WARNINGS 1 

#include"Sort.h"

void Print(int* a, int sz) {
	for (int i = 0; i < sz; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
//��������Ϊ����
void InsertSort(int* a, int sz) {
	//i<sz-1 ��ʱend���Ϊsz-1(���һ��λ��)-1
	//��ôtmpΪend�ĺ�һ��λ�� �պø�����������
	for (int i = 0; i < sz - 1; i++) {
		int end = i;
		int tmp = a[end + 1];
		//end>=0 end==0��ʱ�� �ŵ�һ��
		while (end >= 0) {
			//������ ǰ������־�����ҪС 
			//������tmpС����Ҫ�Ƶ�ǰ��
			if (tmp<a[end]) {
				//�Ӻ���ǰ�ƶ����֣���λ�ø�����һ��λ��
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
void ShellSort(int* a, int sz) {
	int gap = sz;
	//gap>1 ��Ϊ��ѭ���ڲ����Ա�֤gap==1
	//�����gap>0��ô����gap���һ��ȡ1 �ͻ���ѭ��
	while (gap > 1) {
		gap = gap / 3 + 1;//Ԥ�����ֱ�Ӳ������򣬱�֤���һ��һ����1
		for (int i = 0; i < sz - gap; i++) {
			int end = i;
			int tmp = a[end + 1];
			while (end >= 0) {
				if (tmp < a[end]) {
					a[end+1] = a[end];
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
void InsertSort1(int* a, int sz) {
	for (int i = 0; i < sz - 1; i++) {
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
void ShellSort1(int* a, int sz) {
	int gap = sz;
	while (gap>1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < sz - gap; i++) {
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