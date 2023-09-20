#define _CRT_SECURE_NO_WARNINGS 1 
#include"sequenceList.h"

void SLInit(SL* ps) {
	assert(ps);//ָ���п�

	ps->a = NULL;
	ps->size = ps->capacity = 0;//��ʼ��
}
void SLDestroy(SL* ps) {
	assert(ps);

	free(ps->a);
	ps->a = NULL;//�����ָ��
	ps->size = ps->capacity = 0;
}
void CheckCapacity(SL* ps) {
	//���size��capacity��ֵ��� ˵�������ﵽ������ ����ٴβ���ͻᳬ��capacity �����Ҫ��������
	if (ps->size == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;//1 �տ�ʼcapacityΪ0���⴦�� 2 ��������
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newCapacity);
		assert(tmp);//����ʧ����ֱ����ֹ û���㹻���ڴ������

		ps->capacity = newCapacity;
		ps->a = tmp;
		printf("���ݳɹ���\n");
	}
}
void SLPrint(SL* ps) {
	assert(ps);

	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}

	printf("\n");
}
void SLInsert(SL* ps, SLDataType x,int pos) {
	assert(ps);

	CheckCapacity(ps);
	//�Ӻ���ǰ�ƶ�Ԫ�� ��Ԫ�������ƶ�����һ��λ��
	for (int i = ps->size - 1; i >= pos; i--) {
		ps->a[i+1] = ps->a[i];
	}
	ps->a[pos] = x;//��������

	ps->size++;
}
void SLPushBack(SL* ps, SLDataType x) {
	
	SLInsert(ps, x, ps->size);
}
void SLPushFront(SL* ps, SLDataType x) {
	SLInsert(ps, x, 0);
}
void SLErase(SL* ps,int pos) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	//��ǰ�����ƶ����� �ú�һ��λ�õ����ݸ���ǰһ��λ��
	for (int i = pos; i < ps->size; i++) {
		ps->a[i] = ps->a[i+1];
	}

	ps->size--;

}
void SLPopBack(SL* ps) {
	SLErase(ps, ps->size - 1);
}
void SLPopFront(SL* ps) {
	SLErase(ps, 0);
}