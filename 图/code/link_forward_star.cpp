#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int sz = 1024;
int head[sz];

/**
 * @struct Edge ���ڼ�¼һ����.
 */
struct Edge {
	int to;	
	int weight;
	int next;		/* ���ڼ�¼ͬ������һ���ߵı�� */
};

Edge edges[sz];

/**
 * @brief �ӱ߲���.
 * @param[in] u, v�ֱ�Ϊ��ʼ�ڵ�ı��
 * @param[in] w Ȩ��
 */
void add(int u, int v, int w)
{
	static int cnt = 0;
	edges[cnt].weight = w;
	edges[cnt].to = v;
	edges[cnt].next = head[u];
	head[u] = cnt++;
}

int main()
{
	int numOfEdges, numOfVertexes;
	int from, to, weight;
	memset(head, -1, sizeof(head));
	cin >> numOfEdges >> numOfVertexes;

	for (int i = 1; i <= numOfEdges; i++) {
		cin >> from >> to >> weight;
		add(from, to, weight);
		/*
		edges[i].to = to;
		edges[i].weight = weight;
		edges[i].next = head[from];
		head[from] = i;
		*/
	}

	/* traversal */
	for (int i = 1; i <= numOfVertexes; i++) {
		for (int k = head[i]; k != -1; k = edges[k].next) {
			cout << i << " " << edges[k].to << " " << edges[k].weight << endl;
 		}
	}
	getchar();
}