#include <iostream>
using namespace std;


typedef int elem_t;


/**
 * @brief ��array�����left��right���ֽ�������
 * @param[in] array �����������
 * @param[in] left, right ������±�
 * @return ��
 */
void
sort(elem_t array[], int left, int right)
{
	if (right <= left) return; /* �ݹ���ֹ���� */
	int mid = (left + right) / 2;

	sort(array, left, mid); /* ���η� */
	sort(array, mid + 1, right);

	/* array[left, mid]�Լ�array[mid+1, right]���Ѿ����� */
	int l = left, h = mid + 1;
	while (l < h && h <= right) {
		/* lָ��array[left, mid]��һ��, hָ��array[mid+1, right]��һ��,
		 * ��ʼ�ϲ���������.���������˼����,��array[left, mid]�нϴ�Ĳ���
		 * Ǩ�Ƶ��Ҳ�.
		 */
		if (array[l] >= array[h]) {
			elem_t tmp = array[h];
			for (int i = h - 1; i >= l; i--) {
				array[i + 1] = array[i]; 
			}
			array[l] = tmp;
			h++;
		}
		/* ���ܽ������,l��Ҫ��ǰ�ƶ� */
		l++;
	}
}


/**
 * @brief �鲢����
 * @param[in] array �����������
 * @param[in] len ����Ĵ�С
 * @return ��
 */
void
merge_sort(elem_t array[], int len)
{
	sort(array, 0, len - 1);
}

int main()
{
	elem_t array[] = { 1, 2, 4, 99, 100, 120, 34, 48, 47, 36, 3, 1000, 45, 2, 3 };
	int size = sizeof(array) / sizeof(elem_t);
	merge_sort(array, size);
	for (int i = 0; i < size; ++i) {
		cout << array[i] << endl;
	}
	getchar();
}
