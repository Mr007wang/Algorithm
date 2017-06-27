#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int EDGE_MAX = 128;
const int VERTEX_MAX = 128;

typedef int edgeInfo;

/**
 * @struct ��
 */
struct Edge {
	int to; /* �յ��� */
	edgeInfo info;	/* �ߵ���Ϣ,�����Ǳ��,Ȩ�صȵ�. */
	int next; /* ��һ��ͬ���ıߵı�� */
};

Edge edges[EDGE_MAX];
bool visited[EDGE_MAX];
int head[VERTEX_MAX];
queue<edgeInfo> path;


/**
 * @brief �Ӷ���u����,Ѱ��ŷ����·.
 * @param[in] u ����ı�� 
 */
void findEulerCircuit(int u) 
{
	for (int k = head[u]; k != -1; k = edges[k].next) { /* ������u���������б� */
		if (!visited[k]) {
			visited[k] = true;	/* ������Ҫע��,��Ϊģ����������,�����߹�һ����Ҫ������� */
			if (k & 1) visited[k + 1] = true;
			else visited[k - 1] = true;
			findEulerCircuit(edges[k].to);
			path.push(edges[k].info); /* ����ʱ��¼�ߵ���Ϣ */
		}
	}
}

int main()
{
	int numOfEdges, numOfVertexes;
	int from, to;
	edgeInfo info;
	cin >> numOfEdges >> numOfVertexes;

	for (int i = 1; i <= numOfEdges; i++) { /* Ϊ�˷������,0�ŵ�Ԫ���� */
		/* ��Ϊ����ģ���������ͼ,������΢�鷳,���������ͼ,һ�ж����ü򵥺ܶ� */
		cin >> from >> to >> info; /* ��ʼ������,�Լ��ߵ�һЩ��Ϣ,��ߵı�ŵȵ�. */
		edges[2 * i - 1].to = to;
		edges[2 * i - 1].info = info;
		edges[2 * i - 1].next = head[from];
		head[from] = 2 * i - 1;

		edges[2 * i].to = from;
		edges[2 * i].info = info;
		edges[2 * i].next = head[to];
		head[to] = 2 * i;
	}
	memset(visited, false, sizeof(visited));
	findEulerCircuit(1);

	/* ����ߵ���Ϣ */
	while (!path.empty()) {
		cout << path.front() << " ";
		path.pop();
	}
	cout << endl;

	getchar();
}