#define _CRT_SECURE_NO_WARNINGS 1 
#include"BinaryTree.h"

BTNode* BuyNode(BTDataType x) {
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	assert(newnode);
	newnode->left = newnode->right = NULL;
	newnode->x = x;
	return newnode;
}
BTNode* CreatBinartTree() {
	BTNode* node1 = BuyNode('A');
	BTNode* node2 = BuyNode('B');
	BTNode* node3 = BuyNode('C');
	BTNode* node4 = BuyNode('D');
	BTNode* node5 = BuyNode('E');
	BTNode* node6 = BuyNode('F');
	BTNode* node7 = BuyNode('G');

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->right = node6;
	node5->left = node7;
	return node1;
}
void BinaryPrevOrder(BTNode* root) {
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	//ǰ����������ڵ� ������ ������
	printf("%c ", root->x);
	BinaryPrevOrder(root->left);
	BinaryPrevOrder(root->right);
}
void BinaryInOrder(BTNode* root) {
	if (root == NULL) {
		printf("# ");
		return;
	}
	//��������������� �� ������
	BinaryInOrder(root->left);
	printf("%c ", root->x);
	BinaryInOrder(root->right);
}
void BinaryPostOrder(BTNode* root) {
	if (root == NULL) {
		printf("# ");
		return;
	}
	//��������� ������ ������ �� 
	BinaryPostOrder(root->left);
	BinaryInOrder(root->right);
	printf("%c ", root->x);
}
void BinaryLevelOrder(BTNode* root) {
	//�Ȱѵ�һ��������
	Queue q;
	InitQueue(&q);
	PushQueue(&q, root);
	//���в�Ϊ�յ�ʱ�� ����һ����������Һ��ӽ��
	while (!EmptyQueue(&q)) {
		BTNode* front = FrontQueue(&q);
		printf("%c ", front->x);
		PopQueue(&q);

		if (front->left) {
			PushQueue(&q, front->left);
		}
		if (front->right) {
			PushQueue(&q, front->right);
		}
	}

	DestroyQueue(&q);
}
int BinaryTreeSize(BTNode* root) {
	//�������
	return root == NULL ? 0 :BinaryTreeSize(root->left) + BinaryTreeSize(root->right)+1;
}
int BinartTreeLeafSize(BTNode* root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return 1;
	return BinartTreeLeafSize(root->left) + BinartTreeLeafSize(root->right);
}
int BInaryTreeLevelSize(BTNode* root, int k) {
	if (root == NULL || k < 1) return 0;
	if (k == 1) return 1;
	return BInaryTreeLevelSize(root->left, k - 1) + BInaryTreeLevelSize(root->right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	if (root == NULL) return NULL;
	//ǰ�����
	if (root->x == x) return root;
	BTNode* leftnode = BinaryTreeFind(root->left, x);
	if (leftnode) return leftnode;//�ҵ��˷���
	BTNode* rightnode = BinaryTreeFind(root->right, x);
	if (rightnode) return rightnode;//�ҵ��˷���
}
int Max(int a, int b) {
	return a > b ? a : b;
}
int BinaryTreeMaxDepth(BTNode* root) {
	if (root == NULL) return 0;
	return Max(BinaryTreeMaxDepth(root->left), BinaryTreeMaxDepth(root->right)) + 1;
}