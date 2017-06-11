#include <stdio.h>
#include <stdlib.h>

typedef int elem_t;

/**
 * @struct
 * @brief �������ڵ�.
 */
typedef struct bt_node_t {
	elem_t elem;
	struct bt_node_t *left;
	struct bt_node_t *right;
};

/**
 * @brief ʹ��Morrris�㷨�����������.
 * @param[in] root ���ڵ�
 * @param[in] visit ���ʺ���
 */
void 
in_order_mirrors(bt_node_t *root, int(*visit)(bt_node_t *))
{
	bt_node_t *cur;
	cur = root;
	while (cur != NULL) {
		if (cur->left == NULL) {
			visit(cur);
			cur = cur->right;	/* ���Һ�����Ϊ��ǰ�ڵ� */
		}
		else {
			/* ����cur�ڵ��ǰ���ڵ� */
			bt_node_t *node = cur->left;
			while (node->right != NULL && node->right != cur)
				node = node->right;

			if (node->right == NULL) { /* ��û������������������ */
				node->right = cur;
				cur = cur->left;
			}
			else { /* ����Ѿ��������ˣ�����ʽڵ㣬��ɾ������ */
				visit(cur);
				node->right = NULL;
				cur = cur->right;
			}
		}
	}
}

/**
 * @brief ʹ��Morrris�㷨�������
 * @param[in] root ���ڵ�
 * @param[in] visit ���ʺ���
 */
void
pre_order_morris(bt_node_t *root, int(*visit)(bt_node_t *))
{
	bt_node_t *cur;

	cur = root;
	while (cur != NULL) {
		if (cur->left == NULL) {
			visit(cur);
			cur = cur->right;
		}
		else {
			/* ����ǰ�� */
			bt_node_t *node = cur->left;
			while (node->right != NULL && node->right != cur)
				node = node->right;

			if (node->right == NULL) {
				visit(cur);
				node->right = cur;
				cur = cur->left;
			}
			else { /* �Ѿ��������ˣ���ɾ������ */
				node->right = NULL;
				cur = cur->right;
			}
		}
	}
}

/**
 * @brief ��ָ�뷴ת
 * @param[in] from ��ת·�������.
 * @param[in] to ��ת·�����յ㡣
 */
static void 
reverse(bt_node_t *from, bt_node_t *to) 
{
	bt_node_t *x = from, *y = from->right, *z;
	if (from == to) return;
	/* ��Ҫע�����,���ﲢ������ȫ��·����ת,�������������㹻��.��������ֻ��һ���ֲ�����. */
	while (x != to) {
		z = y->right;
		y->right = x;
		x = y;
		y = z;
	}
}

/**
 * @brief ������ת���·���ϵ����нڵ�.
 * @param[in] from ��Ҫ����·�������,Ҳ����Ӧ�����һ�����ʵĽڵ�.
 * @param[in] to ��Ҫ����·�����յ�,Ҳ�ǵ�һ��Ӧ�ñ����ʵĽڵ�.
 */
static void
visit_reverse(bt_node_t* from, bt_node_t *to, int (*visit)(bt_node_t *))
{
	bt_node_t *p = to;
	reverse(from, to);
	while (1) {
		visit(p);
		if (p == from)
			break;
		p = p->right;
	}
	reverse(to, from);
}

/**
 * @brief ʹ��Morrris�㷨���к������.
 * @param[in] root ���ڵ�
 * @param[in] visit ���ʺ���
 */
void
post_order_morris(bt_node_t *root, int(*visit)(bt_node_t *))
{
	bt_node_t dummy = { 0, NULL, NULL };
	bt_node_t *cur, *prev = NULL;

	dummy.left = root;
	cur = &dummy;
	while (cur != NULL) {
		if (cur->left == NULL) {
			prev = cur;
			cur = cur->right;
		}
		else {
			bt_node_t *node = cur->left;
			while (node->right != NULL && node->right != cur)
				node = node->right;

			if (node->right == NULL) { /* ��δ������,���������� */
				node->right = cur;
				prev = cur;
				cur = cur->left;
			}
			else {
				/* visit_reverse��ʵ��һ��С����,�Ǿ���prev->right�ڷ��ʵ�ʱ�����޸� */
				visit_reverse(cur->left, prev, visit); 
				prev->right = NULL;
				prev = cur;
				cur = cur->right;
			}
		}
	}
}

/**
 * @breif ����һ���½ڵ�.
 * @param[in] e �½ڵ������
 */
bt_node_t* new_node(int e)
{
	bt_node_t* node = (bt_node_t *)malloc(sizeof(bt_node_t));
	node->elem = e;
	node->left = NULL;
	node->right = NULL;
	return node;
}

static int
print(bt_node_t *node)
{
	printf(" %d", node->elem);
	return 0;
}

void 
test_01()
{
	bt_node_t n1, n2, n3, n4;
	n1.elem = 1, n1.left = NULL, n1.right = &n2;
	n2.elem = 2, n2.left = NULL, n2.right = &n3;
	n3.elem = 3, n3.left = NULL, n3.right = &n4;
	n4.elem = 4, n4.left = NULL, n4.right = NULL;
	reverse(&n1, &n4);
	reverse(&n4, &n1);
}

int main()
{
	bt_node_t *n1 = new_node(1);
	bt_node_t *n2 = new_node(2);
	bt_node_t *n3 = new_node(3);
	bt_node_t *n4 = new_node(4);
	bt_node_t *n5 = new_node(5);
	bt_node_t *n6 = new_node(6);
	bt_node_t *n7 = new_node(7);
	bt_node_t *n8 = new_node(8);
	bt_node_t *n9 = new_node(9);

	n6->left = n2; n6->right = n7;
	n2->left = n1; n2->right = n4;
	n1->left = NULL; n1->right = NULL;
	n4->left = n3; n4->right = n5;
	n3->left = n3->right = NULL;
	n5->left = n5->right = NULL;
	n7->left = NULL; n7->right = n9;
	n9->left = n8; n9->right = NULL;
	n8->left = n8->right = NULL;
	
	pre_order_morris(n6, print);
	printf("\n");
	
	in_order_mirrors(n6, print);
	printf("\n");
	
	post_order_morris(n6, print);
	printf("\n");
	getchar();
}