#include<iostream>
#include <vector>
#include <stack>
using namespace std;
#define N 13
struct Edge 
{
	int src;
	int dest;
};
class Graph
{
public:
	vector<int> adjList[N];
	Graph(vector<Edge> edges)
	{
		for (int i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dst = edges[i].dest;
			adjList[src].push_back(dst);
			adjList[dst].push_back(src);
		}
	}
};
void DfS(Graph const &graph, int v, vector<bool> &discovered)
{
	discovered[v] = true;
	cout << v << " ";
	for (int u:graph.adjList[v])
	{
		if (!discovered[u])
		{
			DfS(graph, u, discovered);
		}
	}
}
int iterativedfs(Graph const &graph, int v)
{
	vector<bool> discovered(N);
	stack<int> s;
	s.push(v);
	while (!s.empty())
	{
		v = s.top();
		s.pop();
		if (discovered[v])
			continue;
		discovered[v] = true;
		cout << v << " ";
		for (auto it = graph.adjList[v].rbegin();
			it != graph.adjList[v].rend();it++)
		{
			int u = *it;
			if (!discovered[u])
			{
				s.push(u);
			}
		}
	}

	
}
int main()
{
	vector<Edge> edges =
	{
		{ 1, 2 }, { 1, 7 }, { 1, 8 }, { 2, 3 }, {2,6},
		{ 3, 4 }, { 3, 5 }, {8,9}, { 8, 12 }, { 9, 10 }, { 9, 11 }
	};
	Graph graph(edges);
	vector<bool> discovered(N,false);
	for (int i = 1; i < N;i++)
	{
		if (!discovered[i])
		{
			DfS(graph, i, discovered);
		}
	}
	return 0;
}