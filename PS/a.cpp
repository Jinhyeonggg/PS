#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> G;
vector<int> visited;

void initVisited(int size) {
    visited.assign(size + 1, 0);
}

int dfs(int start, vector<int> &visited, int curDist) {
    visited[start] = 1;
    int maxDist = curDist;
    // cout << "curDist: " << curDist << endl;
    for (pair<int, int> edge: G[start]) {
        int end, d;
        end = edge.first;
        d = edge.second;
        if (!visited[end]) {
            // cout << end << ' ';
            int leftDist = dfs(end, visited, curDist + d);
            if (maxDist < leftDist) maxDist = leftDist;
        }
    }
    // cout << endl;
    return maxDist;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int V;
    cin >> V;
    G.resize(V + 1);
    visited.assign(V, 0);

    for (int i = 0; i < V; i++) {
        int a, b, t; cin >> a;
        while (cin >> t) {
            if (t == -1) break;
            cin >> b;
            G[a].push_back(make_pair(t, b));
        }
    }

    int maxDist = 0;
    for (int i = 1; i < V + 1; i++) {
        initVisited(V);
        int d = dfs(i, visited, 0);
        if (maxDist < d) maxDist = d;
    }
    cout << maxDist;
    return 0;
}
