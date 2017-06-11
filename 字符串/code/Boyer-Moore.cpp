#include <iostream>
#include <algorithm>
using namespace std;

/**
* @brief Ԥ��������ģʽ����ÿ���ַ���ҵ�λ�þ���ģʽ��ĩβ�ĳ���.
*
* @param[in] pattern ģʽ��
* @param[in] m ģʽ���ĳ���
* @param[out] bmBc ���ڼ�¼ÿ���ַ���ģʽ������ҵ�λ�þ���ģʽ��ĩβ�ĳ���.
*/
void preBmBc(const char *pattern, int m, int bmBc[])
{
	int i;

	for (i = 0; i < 256; i++) {
		bmBc[i] = m;
	}

	for (i = 0; i < m - 1; i++) {
		bmBc[pattern[i]] = m - 1 - i; /* pattern[i]��ģʽ�ַ����ĵ�i���ַ� */
	}
}
/**
* @brief Ԥ���������ģʽ��λ��i��ʼ���Ӵ����Ӻ���ǰ���ͺ�׺��ƥ�����󳤶�.
*
* @param[in] pattern ģʽ�ַ���
* @param[in] m ģʽ���ĳ���
* @param[out] suff ���ڼ�¼���������
*/
void suffixes(const char *pattern, int m, int *suff)
{
	suff[m - 1] = m;
	for (int i = m - 2; i >= 0; --i) {
		int q = i;
		/* pattern[q]�����Ӵ����֣�pattern[m-1-i+q]���ں�׺���� */
		while (q >= 0 && pattern[q] == pattern[m - 1 - i + q])
			--q;
		suff[i] = i - q;
	}
}

/**
* @brief Ԥ����,�����ú�׺�����.
*
* @param[in] pattern ģʽ��
* @param[in] m ģʽ���ĳ���
* @param[out] bmGs bmGs[i]��ʾ�����ģʽ����iλ��������ƥ��,��ô���úú�׺����,ģʽ��Ӧ��������ı�������ƶ���λ��.
*/
void preBmGs(const char *pattern, int m, int bmGs[])
{
	int i, j;
	int *suff = (int *)malloc(sizeof(int) * (m + 1));
	suffixes(pattern, m, suff);
	for (i = 0; i < m; ++i) /* �����Ӵ�ƥ��ú�׺��Ҳû�����ǰ׺ */
		bmGs[i] = m;
	j = 0;
	for (i = m - 1; i >= 0; --i)
		if (suff[i] == i + 1)
			for (; j < m - 1 - i; ++j)
				if (bmGs[j] == m) /* ��ֻ֤���޸�һ�� */
					bmGs[j] = m - 1 - i;
	for (i = 0; i <= m - 2; ++i) /* �����Ӵ�ƥ��ú�׺ */
		bmGs[m - 1 - suff[i]] = m - 1 - i;
	free(suff);
}

int BM(const char *pattern, const char *text)
{
	int i = 0, j = 0;
	int bmBc[256];
	int n = strlen(text), m = strlen(pattern);
	int *bmGs = (int *)malloc(sizeof(int) * (m + 1));
	/* Preprocessing */
	preBmGs(pattern, m, bmGs);
	preBmBc(pattern, m, bmBc);

	/* Searching */
	while (i <= n - m) {
		for (j = m - 1; j >= 0 && pattern[j] == text[i + j]; --j);
		if (j < 0) {
			j += bmGs[0];
			free(bmGs);
			return i;
		}
		else
			i += max(bmGs[j], bmBc[text[i + j]] - m + 1 + j);
	}
	free(bmGs);
	return -1;
}


int main()
{
	char haystack[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char needle[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	cout << BM(needle, haystack) << endl;
	getchar();
}