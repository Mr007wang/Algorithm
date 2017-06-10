#include <iostream>
using namespace std;

typedef int elem_t;

/**
 * @brief ���������������±��ֵ
 * @param[in] array ����ĵ�ַ
 * @param[in] idx1 ��һ���±�
 * @param[in] idx2 �ڶ����±�
 */
void
swap(elem_t array[], int idx1, int idx2)
{
	elem_t temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}

/**
 * @brief ������idx�±꿪ʼ�ĵط�,ά�ֺ����ѵ�����
 * @param[in] array ����ĵ�ַ
 * @param[in] idx �±�
 * @param[in] size �ѵĴ�С
 */
void 
max_heaplify(elem_t array[], int idx, int size)
{
	int greater_val_idx = idx; /* greater_val_idx��¼���ӽڵ��нϴ�ֵ���±� */
	int lchild_idx = 2 * idx + 1, rchild_idx = 2 * idx + 2; /* ���Ӻ��Һ��ӵ��±� */

	if (lchild_idx < size && array[idx] < array[lchild_idx]) {
		greater_val_idx = lchild_idx;
	}

	if (rchild_idx < size && array[greater_val_idx] < array[rchild_idx]) {
		greater_val_idx = rchild_idx;
	}

	if (greater_val_idx != idx) {
		swap(array, greater_val_idx, idx);
		max_heaplify(array, greater_val_idx, size);
	}
}


/**
* @brief max_heaplify�����ķǵݹ�汾
* @param[in] array ����ĵ�ַ
* @param[in] idx �±�
* @param[in] size �ѵĴ�С
*/
void max_heaplify_non_recursive(elem_t array[], int idx, int size)
{
	int greater_val_idx, lchild_idx, rchild_idx;
	while (true) {
		greater_val_idx = idx;
		lchild_idx = 2 * idx + 1;	/* ���ӵ��±� */
		rchild_idx = 2 * idx + 2;	/* �Һ��ӵ��±� */

		if (lchild_idx < size && array[idx] < array[lchild_idx]) {
			greater_val_idx = lchild_idx;
		}

		if (rchild_idx < size && array[greater_val_idx] < array[rchild_idx]) {
			greater_val_idx = rchild_idx;
		}

		if (greater_val_idx != idx) {
			swap(array, greater_val_idx, idx);
			idx = greater_val_idx;
		}
		else break;
	}
}

/**
 * @brief ��������
 * @param[in] array ����
 * @param[in] size ����Ĵ�С
 */
void 
build_max_heap(elem_t array[], int size) {
	int parent_idx = (int)floor((size - 1) / 2);
	for (int i = parent_idx; i >= 0; i--) {
		max_heaplify(array, i, size);
	}
}

/**
 * @brief ������
 * @param[in] array �����������
 * @param[in] size ����Ĵ�С
 */
void
heap_sort(elem_t array[8], int size)
{
	build_max_heap(array, size); /* �������� */
	for (int i = size - 1; i > 0; i--) {
		swap(array, 0, i);
		max_heaplify(array, 0, i);
	}
}

int main()
{
	elem_t array[] = { 1, 5, 6, 10, 8, 7, 99, 35 };
	int size = sizeof(array) / sizeof(elem_t);
	heap_sort(array, size);
	for (int i = 0; i < size; i++) {
		cout << array[i] << endl;
	}
	getchar();
}

