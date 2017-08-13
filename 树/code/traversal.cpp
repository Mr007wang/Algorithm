#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


/*
 * @struct
 * @brief �������ڵ�
 */
struct treeNode {
	treeNode *left;
	treeNode *right;
	int val;  /* �������� */
	treeNode(int x): val(x), left(nullptr), right(nullptr){}
};

/**
 * @brief �������,�ǵݹ�汾
 */
void preOrder(const treeNode *root, void(*visit)(const treeNode*)) {
	const treeNode *p = root;
	stack<const treeNode*> nodes;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	�ݹ�汾���������
	void preOrder(const treeNode *root, void (*visit)(const treeNode *)) {
		if (root == nullptr) return;
		visit(root);
		if (root->left != nullptr) preOrder(root->left);
		if (root->right != nullptr) preOrder(root->right);
	}
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	if (p != nullptr) nodes.push(p);
	/* �ǵݹ�汾����������ǵݹ�汾����ʵģ�� */
	while (!nodes.empty()) {
		p = nodes.top(); nodes.pop();
		visit(p);
		if (p->right != nullptr) nodes.push(p->right);
		if (p->left != nullptr) nodes.push(p->left);
	}
}

/**
 * @brief �������,�ǵݹ�汾
 */
void inOrder(const treeNode *root, void(*visit)(const treeNode*)) {
	const treeNode *p = root;
	stack<const treeNode*> nodes;

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 �ݹ�汾���������
	  void inOrder(treeNode *root, void (*visit)(const treeNode *)) {
		if (root == nullptr) return;
		if (root->left != nullptr) inOrder(root->left);
		visit(root);
		if (root->right != nullptr) inOrder(root->right);
	  }
	 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	while (!nodes.empty() || p != nullptr) {
		if (p != nullptr) { /* �Ƚ���߲�����ջ */
			nodes.push(p);
			p = p->left;
		}
		else {
			p = nodes.top(); nodes.pop();
			visit(p);
			p = p->right; /* ���������� */
		}
	}
}

void inOrder2(const treeNode *root, void(*visit)(const treeNode*)) {
	const treeNode *p = root;
	stack<const treeNode*> nodes;
	
	do {
		while (p != nullptr) { /* ��������ȫ����ջ */
			nodes.push(p);
			p = p->left;
		}

		while (!nodes.empty()) {
			p = nodes.top(); nodes.pop();
			visit(p);
			if (p->right != nullptr) { /* �������Ѿ����ʹ���,��������Ϊ�� */
				p = p->right;
				break;
			}
			/* p������������,��ôҪ��ջ */
		}
	} while (!nodes.empty());
}


/**
 * @brief �������,�ǵݹ�汾
 */
void postOrder(const treeNode* root, void *(*visit)(const treeNode*)) {
	const treeNode *p = root, *q;
	stack<const treeNode*> nodes;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	�ݹ�汾�ĺ�������
	void postOrder(treeNode *root, void (*visit)(const treeNode *)) {
		if (root == nullptr) return;
		postOrder(root->left);
		postOrder(root->right);
		visit(root);
	}
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	do {
		while (p != nullptr) { /* �������� */
			nodes.push(p);
			p = p->left;
		}
		q = nullptr;
		while (!nodes.empty()) {
			p = nodes.top(); nodes.pop();
			/* �Һ��Ӳ����ڻ����Ѿ������ʹ���,���ʸýڵ� */
			if (p->right == q) {
				visit(p);
				q = p;  /* ����շ��ʹ��Ľڵ� */
			}
			else {
				/* ��ǰ�ڵ㲻�ܷ���,��Ҫ�ڶ��ν�ջ */
				nodes.push(p);
				/* �������Ѿ���������,���ݺ����������,�ȴ��������� */
				p = p->right;
				break;
			}
		}
	} while (!nodes.empty());
}

void print(const treeNode* root) {
	cout << root->val << endl;
}

int main() {
	treeNode n1(1), n2(2), n3(3), n4(4), n5(5);
	n1.left = &n2; n2.left = &n3; n3.left = &n4; n3.right = &n5;
	inOrder2(&n1, print);
	getchar();
}