#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * �������취
 *	���ַ�����λ��������΢Ҫ����һЩ.��ʵ��,�Ҳ����Ƽ����ַ���,����û�б�λ������Ч�ʸ��߻���
 *	���������.
 */

/**
 * @brief Ѱ�����г���ΪsubsetIdx + 1���Ӽ�
 * @param[in] set Ҫ���Ӽ��ļ���
 * @param[in] setIdx ���ڱ�ʾ���ϵ��±��0~setIdx-1��Ԫ�ؼ�ǰsetIdx��Ԫ�������ֵ����в�����ȡ.
 * @param[in] subset �ɼ��ϵ�ǰsetIdxԪ����϶��ɵĳ���ΪsubsetIdx���Ӽ�.
 * @param[in] subsetIdx �Ӽ��ĳ���.
 * @param[in/out] subsets ���ڼ�¼���е��Ӽ�������
 * @return ��
 */
void findSubsets(vector<int>& set, int setIdx, int* subset, int subsetIdx, 
vector<vector<int>>& subsets)
{
	/**
	 * ǰһ���Ӽ�����ΪsubsetIdx,�Ҹ��Ӽ��ɼ��ϵ�ǰsetIdx��Ԫ����϶���,��ξ��ɸ��Ӽ����ɳ���Ϊ
	 * subsetIdx+1���Ӽ���?
	 */	 
	for (int i = setIdx; i < set.size(); i++) {
		/* ��ʱ��subset���ɼ���ǰi��Ԫ�ع��ɵ�һ���Ӽ�,��������ɼ��ϵ�ǰi+1��Ԫ�ع��ɵ��Ӽ���? */
		/* ѡ��set�ĵ�i+1��Ԫ����Ϊsubset��subsetIdxλ���ϵ�Ԫ�� */
		subset[subsetIdx] = set[i];
		/* �������ɵ�,����ΪsubsetIdx+1���Ӽ�����subsets */
		subsets.push_back(vector<int>(subset, subset + subsetIdx + 1));
		/* �����ȡ��i��Ԫ��, ��ôsubset�ĳ���ΪsubsetIdx,���Ѿ���subsets���� */
		/**
		 * ����ǰ������,�����Ѿ�������һ����ǰi+1��Ԫ����϶��ɵ�,����ΪsubsetIdx+1���Ӽ�,
		 * �������ĵݹ�Ҫ������Ѿ����ɵ��Ӽ��Ļ����ϼ�������.i+1��ʾ���ں����λ��˵,set��
		 * 0~iλ�õ�Ԫ�ض�����ȡ��.
		 * subsetIdx+1��ʾ��subsetIdxλ�õ�Ԫ���Ѿ�ȡ��,Ȼ��Ҫ����һ��λ�����Ԫ��.
		 */
		findSubsets(set, i + 1, subset, subsetIdx + 1, subsets);
	}
}

/**
* @brief Ѱ��set�������Ӽ�.
* @param[in] set ����������Ԫ�صļ���
* @return �����Ӽ����ɵ�����
*/
vector<vector<int>> subSets(vector<int>& set) {
	vector<vector<int>> subsets;
	int subset[1024];
	findSubsets(set, 0, subset, 0, subsets);
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