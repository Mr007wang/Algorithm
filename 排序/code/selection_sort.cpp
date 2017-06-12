#include <iostream>
using namespace std;

typedef int elem_t;

/**
 * @breif ��������������Ԫ�ص�λ��
 * @param[in] array ������׵�ַ
 * @param[in] left �±�
 * @param[in] right �±�
 * @return ��
 */
inline void
swap(elem_t array[], int i, int j)
{
	elem_t tmp = array[j];
	array[j] = array[i];
	array[i] = tmp;
}

/**
 * @brief ��������
 * @param[in] array �����������
 * @param[in] len ����ĳ���
 * @return ��
 */
void
selection_sort(elem_t array[], int len)
{
	int min_idx;
	elem_t min_val;
	for (int i = 0; i < len; ++i) {
		min_idx = i;
		min_val = array[i];
		for (int j = i + 1; j < len; ++j) {
			if (array[j] < min_val) {
				min_val = array[j];
				min_idx = j;
			}
		}
		/* ɨ����֮�󽻻�λ�� */
		swap(array, i, min_idx);
	}
}

int main()
{
	elem_t array[] = { 1, 2, 4, 99, 100, 120, 34, 48, 47, 36, 3, 1000, 45, 2, 3 };
	int size = sizeof(array) / sizeof(elem_t);
	selection_sort(array, size);
	for (int i = 0; i < size; ++i) {
		cout << array[i] << endl;
	}
	getchar();
}