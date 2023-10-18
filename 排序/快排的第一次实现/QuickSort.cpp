#define _CRT_SECURE_NO_WARNINGS 1 
#include"QuickSort.h"
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[mid] > a[left])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
			return left;
	}
}
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
			if (tmp < a[end]) {
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
void QuickSort1(int* a, int begin,int end) {
	//������
	if (begin >= end) return;//ֻ��һ�����ݻ���������Ч������
	
	int left = begin;
	int right =end;
	int keyi = begin;
	
	//���Ϊkeyi �ұ����� 
	while (left < right) {
		//��ҪԽ�� �ұ���С
		while (left<right && a[right]>=a[keyi]) {
			right--;
		}
		while (left < right && a[left] <= a[keyi]) {
			left++;
		}
		//keyi��߶���С�� keyi�ұ߶��Ǵ��
		Swap(&a[left], &a[right]);
	}
	
	

	Swap(&a[keyi], &a[left]);//���keyi�ŵ���Ӧ��λ����

	QuickSort1(a, begin,keyi-1);
	QuickSort1(a ,keyi+1,end);
}
void QuickSort2(int* a, int begin, int end) {
	if (begin >= end) return;
	
	int midIndex = GetMidIndex(a, begin, end);//��ȡ��С���е������±�
	Swap(&a[begin], &a[midIndex]);//����������������˵����ݽ���

	int left = begin;
	int right = end;
	int key = a[left];//ֻ��key����Ϊһ��ֵ��ʱ�� �����±��ʱ�� ������������

	if (end - begin + 1 > 20) {
		while (left < right) {
			if (left < right && a[right] >= key) {
				right--;
			}
			a[left] = a[right];

			if (left < right && a[left] <= key) {
				left++;
			}
			a[right] = a[left];
		}

		int meeti = left;
		a[meeti] = key;
		QuickSort2(a, begin, meeti - 1);
		QuickSort2(a, meeti + 1, end);
	}
	else {
		InsertSort(a + begin, end - begin + 1);
	}
}
void QuickSort3(int* a, int begin, int end) {
	if (begin >= end) return;
	
	int prev = begin;
	int cur = prev + 1;
	int keyi = prev;
	while (cur <= end) {
		//������ cur��λ�õ�ֵ��keyС ����prev��cur������������
		if (a[cur] < a[keyi] && ++prev != cur) {
			Swap(&a[prev],& a[cur]);
		}
		cur++;
	}

	Swap(&a[prev], &a[keyi]);
	QuickSort3(a, begin, keyi - 1);
	QuickSort3(a, keyi + 1, end);
}
int Part1(int* a, int begin, int end) {
	//������
	int left = begin;
	int right = end;
	int keyi = begin;

	//���Ϊkeyi �ұ����� 
	while (left < right) {
		//��ҪԽ�� �ұ���С
		while (left < right && a[right] >= a[keyi]) {
			right--;
		}
		while (left < right && a[left] <= a[keyi]) {
			left++;
		}
		//keyi��߶���С�� keyi�ұ߶��Ǵ��
		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyi], &a[left]);//���keyi�ŵ���Ӧ��λ����
	return keyi;

}
void QuickSortNonR(int* a, int left, int right) {
	stack<int>st;
	st.push(left);
	st.push(right);

	while (!st.empty()) {
		int right = st.top();
		st.pop();
		int left = st.top();
		st.pop();
		int keyi = Part1(a, left, right);

		if (left < keyi - 1) {
			st.push(left);
			st.push(keyi - 1);
		}
		if (keyi + 1 < right) {
			st.push(keyi + 1);
			st.push(right);
		}
		
	}

}

