#include <iostream>
using namespace std;

typedef int elem_t;

/**
* @breif ��������������Ԫ�ص�λ��
* @param[in] array ������׵�ַ
* @param[in] start �±�
* @param[in] end �±�
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
 * @brief ϣ������
 * @param[in] array �������������׵�ַ
 * @param[in] len ����ĳ���
 * @return ��
 **/
void 
shell_sort(elem_t array[], int len)
{
	int gap = len / 2;
	while (gap > 0) {
		for (int i = gap; i < len; i++) {
			for (int j = i; 0 < j; j -= gap) {
				if (array[j - gap] > array[j])
					swap(array, j - gap, j);
				else
					break;
			}
		}
		gap = gap / 2;
	}
}

int main()
{
	elem_t array[] = { 1, 2, 4, 5, 100, 120, 34, 48, 47, 36, 3 };
	int size = sizeof(array) / sizeof(elem_t);
	shell_sort(array, size);
	for (int i = 0; i < size; ++i) {
		cout << array[i] << endl;
	}
	getchar();
}