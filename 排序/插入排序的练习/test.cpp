#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"

void test() {
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = 10;
	//ֱ�Ӳ�������
	Print(a, sz);
	InsertSort1(a, sz);
	Print(a, sz);
	//ϣ������
	int b[10] = { 10,9,8,7,6,5,4,3,2,1 };
	Print(b, sz);
	ShellSort1(b, sz);
	Print(b, sz);
	
}

int main() {
	test();
	return 0;
}