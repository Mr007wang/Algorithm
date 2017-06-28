#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <functional>
using namespace std;

/**
 * �����ͼʹ���ڽӾ�������ʾ,��������ڽӱ�Ļ�,���ܻ���Ӽ�һ��.
 */

const int MAX_NV = 100;	/* ��������ֵ */
using weight = int;
const int GRAPH_INF = INT_MAX / 2;

/**
 * @struct ͼ, ���ڽӾ�������ʾͼ.
 */
struct Graph {
	int numOfVertexes; /* �������Ŀ */
	int numOfEdges;	/* �ߵ���Ŀ */
	weight matrix[MAX_NV][MAX_NV];
};

Graph g;
int topological[MAX_NV]; /* ��������Ľ�� */

/**
 * @brief ��ͼ������������
 * @param[in] g ͼ
 * @return �������ɹ�,����ture,���򷵻�false
 */
bool topo_sort(const Graph& g) 
{
	int n = g.numOfVertexes; /* �������Ŀ */
	int degree[MAX_NV];
	int count = 0;
	queue<int> container;

	std::fill(degree, degree + n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g.matrix[i][j] < GRAPH_INF) {
				degree[j]++; /* ����j����ȼ�1 */
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (degree[i] == 0) container.push(i); /* �������i����������,��ô����� */
	}

	while (!container.empty()) {
		int v = container.front(); 
		container.pop();
		topological[count++] = v; /* ����ɹ� */
		for (int i = 0; i < n; i++) {
			if (g.matrix[v][i] < GRAPH_INF) {
				if (--degree[i] == 0) container.push(i); /* ������� */
			}
		}
	}

	return count == n;
	/* ������ڻ��Ļ�,����������ɹ� */
}