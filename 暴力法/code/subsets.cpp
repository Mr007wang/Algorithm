#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * λ������.
 *	 �ٶ�set��Ԫ�ظ���Ϊn,��ô��һ������Ϊn��bool������ģ��λ����,����ĵ�i��Ԫ��Ϊtrue,��ʾѡ��set
 *	 �ĵ�i��Ԫ��, �����ʾ��ѡ��.�ٶ����ǴӶ����Ƶ� 000....00 (n��0) ��ʼ����, һֱ���� 111...11
 *	 (n��1)�Ļ�, ���ǻᷢ����������ÿһ����,����Ӧ��set��һ���Ӽ�.�������,���Ժܿ��д���Ӽ�Ѱ���㷨.
 *	 �ٸ�����,�ٶ�setΪ[1, 2, 3], λ����001��ʾѡ���3��Ԫ��,��[3]��set��һ���Ӽ�.
 *	 λ����111��ʾ[1, 2, 3]Ϊset��һ���Ӽ�.
 */

/**
 * @brief Ѱ�����е��Ӽ�
 * @param[in] set ����
 * @param[in] mask λ���
 * @param[in] pos ��ǰ�Ѿ������˵�pos��λ����.
 * @param[in, out] subsets ���ڼ�¼���������.
 */
void findSubSets(vector<int>& set, bool mask[], int pos, vector<vector<int>>& subsets)
{
	if (pos == set.size()) { /* �ݹ���ֹ���� */
		vector<int> subset;
		for (int i = 0; i < set.size(); i++) {
			if (mask[i]) subset.push_back(set[i]);
		}
		subsets.push_back(subset);
		return;
	}
	mask[pos] = true;
	findSubSets(set, mask, pos + 1, subsets);
	mask[pos] = false;
	findSubSets(set, mask, pos + 1, subsets);
}

/**
 * @brief Ѱ��set�������Ӽ�.
 * @param[in] set ����������Ԫ�صļ���
 * @return �����Ӽ����ɵ�����
 */
vector<vector<int>> subSets(vector<int>& set)
{
	bool mask[1024];
	vector<vector<int>> subsets;  /* ���ڼ�¼���е��Ӽ� */
	findSubSets(set, mask, 0, subsets);
	return subsets;
}

int main()
{
	vector<int> nums = { 1, 2, 3 };
	auto subsets = subSets(nums);
	for (auto &subset : subsets) {
		for (auto elem : subset) {
			cout << elem << " ";
		}
		cout << endl;
	}
	getchar();
}