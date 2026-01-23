#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int V, E;
int idCount = 1;
vector<int> id, low;
vector<vector<int>> graph;
vector<bool> onStack;
vector<vector<int>> scc;
stack<int> stk;

void initSize() {
    graph.resize(V + 1, {});
    id.resize(V + 1, 0);
    low.resize(V + 1, 0);
    onStack.resize(V + 1, false);
}

int dfs(int cur) {
    id[cur] = idCount;
    low[cur] = idCount;
    idCount++;

    stk.push(cur);
    onStack[cur] = true;

    // compute low[cur] 
    for (int next: graph[cur]) {
        if (id[next] == 0) {
            dfs(next);
            low[cur] = min(low[cur], low[next]);
        }
        else if (onStack[next]) {
            low[cur] = min(low[cur], id[next]);
        }
    }

    if (id[cur] == low[cur]) {
        vector<int> v;
        v.push_back(cur);
        while (stk.top() != cur) {
            int s = stk.top();
            v.push_back(s);
            stk.pop();
            onStack[s] = false;
        }
        scc.push_back(v);
        stk.pop();
        onStack[cur] = false;
    }
    return 0;
}

int solve() {
    for (int i = 1; i <= V; i++) {
        if (id[i] == 0) {
            dfs(i);
        }
    }

    for (vector<int> &v: scc) {
        sort(v.begin(), v.end());
    }
    sort(scc.begin(), scc.end(), [](vector<int> a, vector<int> b){
        return a[0] < b[0];
    });

    cout << scc.size() << endl;
    for (vector<int> v: scc) {
        for (int n: v) {
            cout << n << ' ';
        }
        cout << "-1\n";
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> V >> E;
    initSize();

    for (int i = 0; i < E; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    solve();
    return 0;
}