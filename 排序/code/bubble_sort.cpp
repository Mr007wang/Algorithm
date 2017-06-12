#include <iostream>
using namespace std;

typedef int elem_t;


/**
 * @breif ��������������Ԫ�ص�λ��
 * @param[in] array ������׵�ַ
 * @param[in] i �±�
 * @param[in] j �±�
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
 * @breif ð������
 * @param[in] array �����������
 * @param[in] n ����Ĵ�С
 * @return ��
 */
void 
bubble_sort(elem_t array[], int n)
{
	for (int i = n - 1; i > 0; --i) {
		for (int j = 0; j < i; j++) {
			if (array[j] > array[j + 1]) {
				swap(array, j, j + 1);
			}
		}
	}
}

int main()
{
	elem_t array[] = { 1, 5, 4, 3, 9, 144, 45, 99, 124 };
	int size = sizeof(array) / sizeof(elem_t);
	bubble_sort(array, size);
	for (int i = 0; i < size; ++i) {
		cout << array[i] << endl;
	}
	getchar();
}