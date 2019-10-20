#include<iostream>
#include<vector>
/*
Chu Ming Sun
10196230
I certify that this submission contains my own work, except as noted.
*/
using namespace std;
struct edge
{
	int src;
	int dest;
	vector<int> depTime;
	vector<int> arvTime;
	edge(int s, int d, int dT, int aT)
	{
		src = s;
		dest = d;
		depTime.push_back(dT);
		arvTime.push_back(aT);
	}


};
void addEdge(vector<edge *> & v, int s, int d, int dT, int aT)
{
	for (int i = 0;i<v.size();i++)
	{
		if (v[i]->src == s && v[i]->dest == d)
		{
			v[i]->depTime.push_back(dT);
			v[i]->arvTime.push_back(aT);
			return;
		}
	}
	v.push_back(new edge(s, d, dT, aT));
}
int minDistance(int dist[],
	bool sptSet[],int V)
{

	// Initialize min value 
	int min = 2147483647, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false &&
			dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
void printPath(int parent[], int j)
{

	// Base Case : If j is source 
	if (parent[j] == -1)
		return;

	printPath(parent, parent[j]);
	cout << "->" << j;
}
void printSolution(int dist[], int n,
	int parent[],int V,int src,int dest)
{
	if (dist[dest] == 2147483647)
	{
		cout << "no path exist.\n";
		return;
	}
	cout << "City " << src << " to City " << dest << " the Route is: "<<src;
	printPath(parent, dest);
	cout << ". And the Arrival time At City " << dest << " is " << dist[dest] << ".\n";
}
int getMax(vector<edge *> v)
{
	int max = -1;
	for (int i = 0;i < v.size();i++)
	{
		if (max < v[i]->dest)
			max = v[i]->dest;
		if (max < v[i]->src)
			max = v[i]->src;
	}
	return max+1;
}
vector<int> getTime(vector<edge*> &v,int prevArivalTime, int src, int dest)
{
	vector<int> ind;
	for (int i = 0;i < v.size();i++)
	{
		if (v[i]->src == src&&v[i]->dest==dest)
		{
			ind.push_back(i);
			int minArivalTime = 2147483647;
			int minInd = 0;
			for (int j = 0;j < v[i]->arvTime.size();j++)
			{
				if (prevArivalTime<v[i]->depTime[j] && minArivalTime>v[i]->arvTime[j])
				{
					minArivalTime = v[i]->arvTime[j];
					minInd = j;
				}
			}
			if (prevArivalTime>=v[i]->depTime[minInd])
			{
				ind.push_back(-1);
				return ind;
			}
			ind.push_back(minInd);
			return ind;
		}
	}
	ind.push_back(-1);
	ind.push_back(-1);
	return ind;
} 
void dijkstra(vector<edge *> & graph, int src,int dest)
{
	//algo
	int Size = getMax(graph);
	int *dist=new int[Size];
	bool * sptSet= new bool[Size];
	int *parent= new int[Size];
	for (int i = 0; i < Size; i++)
	{
		parent[i] = -1;
		dist[i] = 2147483647; // max ints
		sptSet[i] = false;
	}
	dist[src] = 0;
	int prevArivalTime=-1;

	for (int count = 0; count < Size - 1; count++)
	{
		int u = minDistance(dist, sptSet,Size);
		sptSet[u] = true;
		for (int v = 0; v < Size; v++)
		{
			vector<int> ind = getTime(graph, prevArivalTime, u, v);
			if (ind[0] == -1|| ind[1] == -1)
			{
				continue;
			}
			prevArivalTime = graph[ind[0]]->arvTime[ind[1]];
			if (!sptSet[v] &&
				 graph[ind[0]]->arvTime[ind[1]] < dist[v])
			{
				parent[v] = u;
				dist[v] = graph[ind[0]]->arvTime[ind[1]];
			}
		}
	}
	printSolution(dist, Size, parent,Size,src,dest);
}
int main()
{	// test sample
	vector<edge *>graph;
	addEdge(graph, 0, 1, 2, 6); 
	addEdge(graph, 1, 2, 6, 7);
	addEdge(graph, 1, 2, 8, 9);
	addEdge(graph, 2, 0, 8, 10);

	dijkstra(graph, 0,2);
	return 0;
}



