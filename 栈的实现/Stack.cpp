#define _CRT_SECURE_NO_WARNINGS 1 
#include"Stack.h"

void InitStack(Stack* ps) {
	assert(ps);//ָ������ò��� ����п�

	ps->a = NULL;
	//top��ʶԪ�ص���һ��λ���൱��˳����е�size
	ps->top = ps->capacity = 0;
}
void DestroyStack(Stack* ps) {
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
void PushStack(Stack* ps, StackDataType x)
{
	assert(ps);
	//�������
	if (ps->top == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		StackDataType* tmp = (StackDataType*)realloc(ps->a, sizeof(StackDataType) * newCapacity);
		assert(tmp);

		ps->capacity = newCapacity;
		ps->a = tmp;
		printf("���ݳɹ�\n");
	}

	ps->a[ps->top] = x;
	ps->top++;
}
void PopStack(Stack* ps) {
	assert(ps);
	assert(ps->top > 0);//��Ϊ�ղ��ܳ�ջ

	ps->top--;
}
StackDataType TopStack(Stack* ps) {
	assert(ps);
	assert(ps->top > 0);

	int pos = ps->top - 1;
	return ps->a[pos];
}
bool EmptyStack(Stack* ps) {
	assert(ps);

	return ps->top == 0;//Ϊ0��� ����true ����false
}
int SizeStack(Stack* ps){
	assert(ps);

	return ps->top;
}