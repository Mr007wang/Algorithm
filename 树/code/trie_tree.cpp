#include <iostream>
using namespace std;

#define MAXN 10000 /** ����ĵ��ʵ������� */
#define CHAR_COUNT 128  /** ASCII���뷶Χ */
#define MAX_CODE_LEN 10  /** ���ʵ���󳤶� */
#define MAX_NODE_COUNT (MAXN * MAX_CODE_LEN + 1)

typedef struct trie_node_t {
	struct trie_node_t* next[CHAR_COUNT];
	bool is_tail;	/** ���ʽ�β��� */
} trie_node_t;

typedef struct trie_tree_t {
	trie_node_t *root; /** ���ĸ��ڵ� */
	int size;	/** ����ʵ�ʳ��ֵĽڵ��� */
	trie_node_t nodes[MAX_NODE_COUNT];
} trie_tree_t;

/**
 * @brief ����һ��Trie��
 * @return ����������ָ��
 */
trie_tree_t *
trie_tree_create(void)
{
	trie_tree_t *tree = (trie_tree_t *)malloc(sizeof(struct trie_tree_t));
	tree->root = &(tree->nodes[0]);
	memset(tree->nodes, 0, sizeof(tree->nodes));
	tree->size = 1;
	return tree;
}

/**
 * @brief ����Trie��
 * @param[in] tree �����ٵ�Trie����ָ��
 * @return ��
 */
void
trie_tree_destroy(trie_tree_t *tree)
{
	free(tree);
	tree = NULL;
}

/**
 * @brief ���Trie���Ľڵ���Ϣ
 * @param[in] tree ����յ�Trie����ָ��
 * @return ��
 */
void
trie_tree_clear(trie_tree_t *tree)
{
	memset(tree->nodes, 0, sizeof(tree->nodes));
	tree->size = 1;
}

/**
 * @brief ��Trie���в��뵥��
 * @param[in] tree Trie����ָ��
 * @param[in] word ������ĵ��ʵ�ָ��
 * @return ����ɹ�,����true,���򷵻�false
 */
bool
trie_tree_insert(trie_tree_t *tree, char *word)
{
	trie_node_t *p = tree->root; /* �Ӹ��ڵ㿪ʼ */
	while (*word) {
		if (p->next[*word] == NULL) {
			p->next[*word] = &(tree->nodes[tree->size++]);
		}
		p = p->next[*word];
		word++; /* ָ������ */
	}
	p->is_tail = true;
	return true;
}

/**
 * @brief ��ѯ�����Ƿ������Trie����
 * @param[in] tree Trie����ָ��
 * @param[in] word ����ѯ�ĵ��ʵ�ָ��
 * @return ����,����true,���򷵻�false
 **/
bool
trie_tree_query(trie_tree_t *tree, char *word)
{
	trie_node_t *p = tree->root;
	while (*word) {
		if (p->next[*word] == NULL) return false;
		p = p->next[*word];
		word++;
	}
	return p->is_tail;
}

int main()
{
	trie_tree_t *tree = trie_tree_create();
	trie_tree_insert(tree, "Hello");
	trie_tree_insert(tree, "world");
	trie_tree_insert(tree, "Trie");
	trie_tree_insert(tree, "Tree");
	trie_tree_insert(tree, "Nice");

	cout << trie_tree_query(tree, "Hello") << endl;
	cout << trie_tree_query(tree, "Yihulee") << endl;
	cout << trie_tree_query(tree, "world") << endl;
	cout << trie_tree_query(tree, "Nice") << endl;
	trie_tree_destroy(tree);
	getchar();
}