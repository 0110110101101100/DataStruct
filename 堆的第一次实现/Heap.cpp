#define _CRT_SECURE_NO_WARNINGS 1 
#include"Heap.h"
//��С��Ϊ����
void InitHeap(Heap* ph) {
	assert(ph);//�п�

	ph->a = NULL;
	ph->size = ph->capacity = 0;//��ʼ��
}
void Destroy(Heap* ph) {
	assert(ph);

	free(ph->a);
	ph->a = NULL;
	ph->size = ph->capacity = 0;
}
void PrintHeap(Heap* ph) {
	assert(ph);

	for (int i = 0; i < ph->size; i++) {
		printf("%d ", ph->a[i]);
	}
	printf("\n");
}
void Swap(HeapDataType* a, HeapDataType* b) {
	HeapDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void CheckCapacity(Heap* ph) {
	assert(ph);
	if (ph->size == ph->capacity) {
		int newCapacity = ph->capacity == 0 ? 4 : 2 * ph->capacity;
		HeapDataType* tmp = (HeapDataType*)realloc(ph->a, sizeof(HeapDataType) * newCapacity);
		assert(tmp);

		ph->capacity = newCapacity;
		ph->a = tmp;
		printf("���ݳɹ�\n");
	}
}
void AdjustDown(HeapDataType* a, int size, int parent) {
	//�ȼ�����������С��
	int child = 2 * parent + 1;
	while (child < size) {
		//ÿһ��ѭ���ҳ����Һ����н�С�Ľ��
		//��������岢���Һ��ӵ�ֵС������
		if (child + 1 < size && a[child + 1] < a[child]) {
			child += 1;
		}
		//��С�� Ҫ�Ѵ�Ļ������� С�Ļ������棬Ҳ����˵������ױȺ��Ӵ󣬾ͰѺ��ӻ�����
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;//ԭ��child��λ����Ϊ�µ�parent��λ��
			child = 2 * parent + 1;
		}
		else {
			break;
		}

	}


}
void AdjustUp(HeapDataType*a, int child) {
	int parent = (child - 1) / 2;
	//��С�� ���С������������ ������������� ��������С�ڸ� ��Ҫ����
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
//�������Ҫ���ϵ���
//ɾ������Ҫ���µ���
void PushHeap(Heap* ph, HeapDataType x) {
	assert(ph);
	CheckCapacity(ph);
	ph->a[ph->size] = x;
	ph->size++;
	AdjustUp(ph->a, ph->size - 1);
}
void PopHeap(Heap* ph){
	assert(ph);
	//����һ��λ�ú����һ��λ�ý��н�������Ȼ��֤���˵�һ��λ��֮����������Ϊ�ѣ�
	Swap(&ph->a[0], &ph->a[ph->size - 1]);
	//ɾ�����һ��λ�õ�����
	ph->size--;
	AdjustDown(ph->a, ph->size, 0);

}
HeapDataType TopHeap(Heap* ph) {
	assert(ph);

	return ph->a[0];
}
bool EmptyHeap(Heap* ph) {
	assert(ph);
	return ph->size == 0;
}
int SizeHeap(Heap* ph){
	assert(ph);
	return ph->size;