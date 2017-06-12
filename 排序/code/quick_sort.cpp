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
 * @brief ��array�����left��right�Ĳ���ѡ��һ������Ϊ�з���,�������иò���,ʹ���з���
 * ������ȫ��С�ڵ����з���,�зֵ��Ҳ����ȫ�����ڵ����з���.
 * @param[in] array ���зֵ�����
 * @param[in] left, right �����±�,�豣֤left < right
 * @return ���к��з������±�
 **/
int
partition(elem_t array[], int left, int right)
{
	int pivot_idx = (left + right) / 2;
	int pivot = array[pivot_idx];	/* ѡ�����ĵ�Ԫ����Ϊpivot */
	int lidx = left, ridx = right - 1;


	swap(array, pivot_idx, right);
	for (; ;) {
		while (array[lidx] < pivot && lidx < right) lidx++;
		while (array[ridx] > pivot && ridx > lidx) ridx--;
		if (lidx < ridx) 
			swap(array, lidx, ridx);
		else break;
	}
	swap(array, right, lidx);
	return lidx;
}

/**
* @brief partition������һ��ʵ�ְ汾.
* @param[in] array ���зֵ�����
* @param[in] left, right �����±�,�豣֤left < right
* @return ���к��з������±�
**/
int
partition_ex(elem_t array[], int left, int right)
{
	int pivot_idx = right;
	int pivot = array[right]; /* ֱ��ѡ�����һ��Ԫ����Ϊpivot */
	int lidx = left, ridx = right - 1;

	for (; ;) {
		while (array[lidx] < pivot && lidx < right) lidx++;
		while (array[ridx] > pivot && ridx > lidx) ridx--;
		if (lidx < ridx)
			swap(array, lidx, ridx);
		else break;
	}
	swap(array, right, lidx);
	return lidx;
}


/**
 * @brief ��array�����left��right���ֽ�������
 * @param[in] array �����������
 * @param[in] left, right ������±�
 * @return ��
 **/
void
sort(elem_t array[], int left, int right)
{
	if (left > right) return;
	int pivot_idx = partition_ex(array, left, right);
	sort(array, left, pivot_idx - 1);
	sort(array, pivot_idx + 1, right);
}

/**
 * @brief ��������
 * @param[in] array �����������
 * @param[in] len ����Ĵ�С
 * @return ��
 */
void
quick_sort(elem_t array[], int len)
{
	sort(array, 0, len - 1);
}

int main()
{
	elem_t array[] = { 1, 2, 4, 99, 100, 120, 34, 48, 47, 36, 3, 1000, 45, 2, 3 };
	int size = sizeof(array) / sizeof(elem_t);
	quick_sort(array, size);
	for (int i = 0; i < size; ++i) {
		cout << array[i] << endl;
	}
	getchar();
}