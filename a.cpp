#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

class UnionFind {
public:
	vector<int> parent;
	vector<int> numChild;

	UnionFind(int size) {
		parent.resize(size + 1);
		numChild.resize(size + 1);
		for (int i = 0; i <= size; i++) {
			parent[i] = i;
			numChild[i] = 1;
		}
	}

	int find(int p) {
		if (parent[p] != p) {
			parent[p] = find(parent[p]);
		}
		return parent[p];
	}
	
	bool unionSets(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);

		if (rootP == rootQ) {
			return false;
		}
		else {
			/* if (numChild[rootP] >= numChild[rootQ]) {
				numChild[rootP] += numChild[rootQ];
				parent[q] = rootP;
			}
			else {
				numChild[rootQ] += numChild[rootP];
				parent[p] = rootQ;
			} */
			parent[rootQ] = rootP;
			return true;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;

	vector<vector<int>> G;
	for (int i = 0; i < E; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		vector<int> temp = {w, a, b};
		G.push_back(temp);
	}
	
	sort(G.begin(), G.end());
	
	UnionFind uf(E);

	int numEdges = 0;
	int weightSum = 0;

	for (int i = 0; i < E; i++) {
		int w, a, b;
		w = G[i][0];
		a = G[i][1];
		b = G[i][2];

		if (uf.unionSets(a, b)) {
			numEdges++;
			weightSum += w;
		}
		if (numEdges == E - 1) break;
	}
	cout << weightSum << endl;
	return 0;
}