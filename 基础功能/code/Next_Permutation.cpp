#include <iostream>
using namespace std;

typedef int elem_t;


/**
 * @brief ��������������Ԫ�ص�λ��
 * @param[in] array �����׵�ַ
 * @param[in] �����±�
 * @param[in] �����±�
 * @return ��
 **/
void
swap(elem_t array[], int i, int j)
{
	elem_t tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * @brief ��ת�����д�firstλ�õ�lastλ��(������lastλ��)��Ԫ��
 * @param[in] array ������׵�ַ
 * @param[in] i �����±�
 * @param[in] j �����±�
 * @return ��
 **/
void reverse(elem_t array[], int first, int last)
{
	last--;
	while (first < last)
		swap(array, first++, last--);
}

/**
 * @brief ������һ������
 * @param[inout] num ��ǰ����
 * @param[in] first ��ʼλ��
 * @param[in] last ����λ��
 * @return �ɹ�����0,ʧ�ܷ���-1
 */
int
next_permutation(elem_t num[], int first, int last)
{
	int i, j;
	i = last - 2; /* PartitionNumber's index */
	while (i >= 0 && num[i] >= num[i + 1]) i--;

	if (i == -1) {
		reverse(num, first, last);
		return -1;
	}

	j = last - 1;
	while (num[j] <= num[i]) --j;
	swap(num, i, j);
	reverse(num, i + 1, last);
	return 0;
}
