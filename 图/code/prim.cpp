#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

const int MAX_NV = 100;	/* ��������ֵ */
using weight = int;

/**
 * @struct ͼ,���ڽӾ�������ʾ.
 */
struct Graph {
	int numOfVertexes; /* �������Ŀ */
	int numOfEdges; /* �ߵ���Ŀ */
	weight matrix[MAX_NV][MAX_NV];
};

Graph g;
bool contained[MAX_NV];	/* ���ڱ�Ƕ����Ƿ��Ѿ�������С������ */

/**
 * @struct ��,һ�������ṹ,����������С������.
 */
struct Edge {
	int u;
	int v;
	weight w;
	Edge(int u, int v, int w): u(u), v(v), w(w) {}
	bool operator>(const Edge& rhs) {
		return w > rhs.w;
	}
};


/**
 * @brief prim�㷨����С������
 * @param[in] g ͼ
 */
void prim(const Graph &g) 
{
	priority_queue<Edge, vector<Edge>, greater<Edge>> container;
	/**
	 * ���������ʽ��,vector<Edge>��ʾ���ȶ���ʹ��vector��ʵ��, greater<Edge>��ʾ��С
	 * ��������.
	 */
	int n = g.numOfVertexes; /* �������Ŀ */
	int u = 0; /* ��ʼ�Ķ���ı��Ϊ0 */
	int count = 0; /* �ߵ���Ŀ���� */
	contained[0] = true;
	std::fill(contained, contained + n, false);

	while (count < n - 1) { /* n���������n - 1���� */
		for (int v = 0; v < n; v++) {
			if (!contained[v]) { /* ����vδ������������ */
				Edge e(u, v, g.matrix[u][v]);
				container.push(e);
			}
		}

		while (!container.empty()) {
			Edge e = container.top(); 
			container.pop();
			if (!contained[e.v]) { /* ����vδ������������ */
				u = e.v;
				contained[u] = true;
				count++;
				break;
			}
		}
	}

}