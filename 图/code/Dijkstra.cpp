#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <functional>
using namespace std;

const int MAX_NV = 100;	/* ��������ֵ */
using weight = int;

/**
 * @struct ͼ, ���ڽӾ�������ʾͼ.
 */
struct Graph {
	int numOfVertexes; /* �������Ŀ */
	int numOfEdges;	/* �ߵ���Ŀ */
	weight matrix[MAX_NV][MAX_NV];
};


/**
 * @struct ����,һ�������ṹ,���ڼ�¼���u������v�ľ���,����˵��ĿǰΪֹ��֪����̾���
 */
struct Dist {
	int v; /* ·�����յ�v,�����u */
	int dist; /* ·��u -> v��ĿǰΪֹ��֪����̾��� */
	Dist(int u,int dist) : v(v), dist(dist) {}
	bool operator>(Dist& rhs) {
		return dist > rhs.dist;
	}
};

Graph g;
int dist[MAX_NV]; /* ��¼��㵽�����������С���� */
int father[MAX_NV]; /* father[i]���ڼ�¼���uͨ�����·�����ﶥ��iʱ�������м䶥��ı�� */

/**
 * @brief dijkstra�㷨�����u�����������������·��.
 * @param[in] g ͼ
 * @param[in] u ���
 */
void dijkstra(const Graph& g, int u)
{
	priority_queue<Dist, vector<Dist>, greater<Dist>> container;
	int n = g.numOfVertexes; /* �������Ŀ */
	std::fill(dist, dist + n, INT_MAX / 2);
	dist[u] = 0; /* ��㵽�Լ�����̾���Ϊ0 */
	
	container.push(Dist(u, 0));
	while (!container.empty()) {
		Dist d = container.top(); 
		container.pop(); 
		for (int i = 0; i < n; ++i) {
			if (dist[d.v] + g.matrix[d.v][i] < dist[i]) {
				dist[i] = dist[d.v] + g.matrix[d.v][i];	/* �Խڵ�v��Ϊ�м�ڵ�,��u��i������� */
				father[i] = d.v; /* �����u����i������vΪ�м�ڵ� */
				container.push(Dist(dist[i], i));
			}
		}
	}
}

