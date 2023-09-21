#define _CRT_SECURE_NO_WARNINGS 1 

#include"Stack.h"

void test() {
	st s;
	InitStack(&s);
	PushStack(&s, 1);
	PushStack(&s, 2);
	PushStack(&s, 3);
	PushStack(&s, 4);
	PushStack(&s, 5);
	PrintStack(&s);

	PopStack(&s);
	PopStack(&s);
	PopStack(&s);
	PrintStack(&s);

	printf("ջ��Ԫ���ǣ�%d \n",TopStack(&s));
	printf("ջ��Ԫ�ظ����У�%d ��\n", SizeStack(&s));
	
	if (EmptyStack(&s)) printf("ջ��Ϊ��\n");
	else printf("ջΪ��\n");

	DestroyStack(&s);
}

int main() {
	test();
	return 0;
}