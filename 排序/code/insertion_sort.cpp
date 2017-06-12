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
* @breif ��������
* @param[in] array �����������
* @param[in] n ����Ĵ�С
* @return ��
*/
void
insertion_sort(elem_t array[], int n)
{
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (array[j - 1] > array[j]) swap(array, j - 1, j);
			else break;
		}
	}
}

/**
* @breif ��������
* @param[in] array �����������
* @param[in] n ����Ĵ�С
* @return ��
*/
void
insertion_sort_ex(elem_t array[], int n)
{
	for (int i = 1; i < n; i++) {
		elem_t tmp = array[i];
		for (int j = i; j >= 0; j--) {
			if (array[j - 1] > tmp) {
				array[j] = array[j - 1];
			}
			else {
				array[j] = tmp;
				break;
			}
		}
	}
}


/**
 * @brief Ѱ��target����������array�Ĳ���λ��.
 * @param[in] array ������׵�ַ
 * @param[in] start, end �����±�
 * @param[in] target �������Ԫ��
 * @return �����λ��
 */
int search_insert_pos(elem_t array[], int head, int tail, elem_t target)
{
	int mid;
	/*
	������һ���㣬��Ҫ��һ�£��Ǿ���head �����ܴ���tail����������tail������������������
	mid = (head + tail) / 2,����head == tail������mid�����ܵ���tail��Ȼ��head == tail
	�ǲ�����ͨ��while���ģ������Ƕȣ�mid�ǿ��Ե���head������tail����Сֵ��head - 1
	*/
	while (head < tail) {
		mid = (head + tail) / 2;
		if (array[mid] == target) return mid;
		if (target < array[mid]) tail = mid - 1;
		else head = mid + 1;
	}
	// head == tail
	// tail < head
	if (target > array[head]) return head + 1;
	else return head;
}

/**
* @breif ��������
* @param[in] array �����������
* @param[in] n ����Ĵ�С
* @return ��
*/
void
insertion_sort_3(elem_t array[], int n)
{
	int k;
	for (int i = 1; i < n; ++i) {
		elem_t tmp = array[i];
		if (array[i - 1] <= tmp) k = i;
		else {
			k = search_insert_pos(array, 0, i - 1, tmp);
			for (int j = i; j > k; j--) {
				array[j] = array[j - 1];
			}
		}
		array[k] = tmp;
	}
}

void test()
{
	elem_t array[] = { 1, 2, 4, 9, 12, 12, 12 };
	int size = sizeof(array) / sizeof(elem_t);
	cout << search_insert_pos(array, 0, 5, 10) << endl;
	cout << search_insert_pos(array, 0, 5, 1) << endl;
	cout << search_insert_pos(array, 0, 5, 3) << endl;
	cout << search_insert_pos(array, 0, size - 1, 12) << endl;
}

int main()
{
	elem_t array[] = { 1, 5, 134, 123, 12, 11, 12 };
	int size = sizeof(array) / sizeof(elem_t);
	insertion_sort(array, size);
	for (int i = 0; i < size; ++i) {
		cout << array[i] << endl;
	}
	getchar();
}