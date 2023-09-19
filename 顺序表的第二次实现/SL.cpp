#define _CRT_SECURE_NO_WARNINGS 1 
#include"SL.h"
//��ʼ�����ٺʹ�ӡ
void InitSL(SL* ps) {
	assert(ps);//ָ���п�

	ps->a = NULL;
	ps->size = ps->capacity = 0;//��ʼ��
}
void DestroySL(SL* ps) {
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void PrintSL(SL* ps) {
	assert(ps);
	//����
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void CheckCapacity(SL* ps) {
	assert(ps);
	//���size��capacity���˵�������ٷ���Ԫ���ˣ�Ҳ����˵�����ﵽ������
	if (ps->size == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newCapacity);
		assert(tmp);

		ps->capacity = newCapacity;
		ps->a = tmp;
		printf("���ݳɹ�\n");
	}

	
}
void PushBackSL(SL* ps, SLDataType x) {
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void PushFrontSL(SL* ps, SLDataType x) {
	assert(ps);
	CheckCapacity(ps);
	//�Ӻ���ǰ��ǰһ��λ�õ������ƶ�����һ��λ��
	for (int i = ps->size - 1; i >= 0; i--) {
		ps->a[i+1] = ps->a[i];
	}
	ps->a[0] = x;

	ps->size++;
}
void InsertSL(SL* ps, SLDataType x, int pos) {
	assert(ps);

	CheckCapacity(ps);
	for (int i = ps->size - 1; i >= pos; i--) {
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;

	ps->size++;
}

void PopBackSL(SL* ps) {
	assert(ps);
	assert(ps->size > 0);

	ps->size--;
}
void PopFrontSL(SL* ps) {
	assert(ps);
	assert(ps->size > 0);

	if (ps->size == 1) {
		ps->size--;
	}
	//��ǰ�����ƶ����� ��һ��λ�õ�Ԫ�ظ���ǰһ��λ��
	for (int i = 0; i < ps->size; i++) {
		ps->a[i] = ps->a[i+1];
	}

	ps->size--;
}
void EraseSL(SL* ps, int pos) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size; i++) {
		ps->a[i] = ps->a[i+1];
	}
	
	ps->size--;
}

int FindSL(SL* ps, SLDataType x) {
	assert(ps);

	for (int i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) return i;
	}

	return -1;
}
void ModifySL(SL* ps, int pos, SLDataType x) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	ps->a[pos] = x;

}