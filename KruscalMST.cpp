/*
	Kruscal Algorithm
	https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
*/

#include <bits/stdc++.h>
using namespace std;

int find(int node, vector<int>& p) {
	int tmp = node;
	while (node != p[node]) {
		node = p[tmp];
		tmp = node;
	}
	return node;
}
	
void merge(int node_x, int node_y, vector<int>& p, vector<int>& rank){
	int rep_x = find(node_x, p);
	int rep_y = find(node_y, p);
	if (rank[rep_x] > rank[rep_y])
		p[rep_y] = rep_x;
	else {
		p[rep_x] = rep_y;
		if (rank[rep_x] == rank[rep_y])
			rank[rep_y]++;
	}
}	

struct edge {
    int a, b;
    long long w;
    int index;
};

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int v, e;
	cin >> v >> e;
	vector<edge> edges(e);
	for (int i = 0; i < e; i++) {
		cin >> edges[i].a;
		cin >> edges[i].b;
		--edges[i].a;
		--edges[i].b;
		
		cin >> edges[i].w;
		edges[i].index = i;
	}

	sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) { return a.w < b.w;
	});
	
	vector<int> p(v);
	vector<int> rank(v);
	for (int i = 0; i < v; i++) {
		p[i] = i;
	}
	
	int selected = 0;
	long long int sum = 0;
	for (auto& e : edges) {
		if (find(e.a, p) != find(e.b, p))	{
			sum += e.w;
			selected++;
			merge(e.a, e.b, p, rank);
		}
		if (selected == v - 1) {
			break;
		}
	}
	
	cout << sum;
}
