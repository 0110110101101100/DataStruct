#define _CRT_SECURE_NO_WARNINGS 1 
#include"BinaryTree.h"
void test() {
	BTNode* node=CreatBinartTree();
	printf("ǰ�������");
	BinaryPrevOrder(node);
	printf("\n");

	printf("���������");
	BinaryInOrder(node);
	printf("\n");

	printf("���������");
	BinaryPostOrder(node);
	printf("\n");

	printf("��������� ");
	BinaryLevelOrder(node);
	printf("\n");

	printf("���ܽ�������%d ",BinaryTreeSize(node));
	printf("\n");

	printf("Ҷ�ӽ��ĸ�����%d ", BinartTreeLeafSize(node));
	printf("\n");

	printf("��%d����ĸ���Ϊ:%d ", 3,BInaryTreeLevelSize(node, 3));
	printf("\n");
	
	printf("�����������Ϊ��%d ", BinaryTreeMaxDepth(node));
	printf("\n");

	
}
int main() {
	test();
	return 0;
}