#define _CRT_SECURE_NO_WARNINGS 1 
#include"BinaryTree.h"
void test() {
	BTNode* node = CreatBinaryTree();
	printf("ǰ�������");
	PrevOrder(node);
	printf("\n");

	printf("���������");
	InOrder(node);
	printf("\n");

	printf("���������");
	PostOrder(node);
	printf("\n");

	printf("��������� ");
	LevelOrder(node);
	printf("\n");

	printf("���ܽ�������%d ", TreeSize(node));
	printf("\n");

	printf("Ҷ�ӽ��ĸ�����%d ", TreeLeafSize(node));
	printf("\n");

	printf("��%d����ĸ���Ϊ:%d ", 3, TreeLevelSize(node, 3));
	printf("\n");

	printf("�����������Ϊ��%d ", BinaryTreeMaxDepth(node));
	printf("\n");


}
int main() {
	test();
	return 0;
}