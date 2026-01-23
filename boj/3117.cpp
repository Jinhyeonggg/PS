#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K, M;

vector<int> start;
vector<vector<int>> parent;

void fillParent() {
    for (int i = 1; i < 50; i++) {
        for (int j = 1; j <= K; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

int helper(int s) {
    int x = M - 1;
    int cur = s;

    while (x != 0) {
        int n = 1;
        int cnt = 0;
        while (n * 2 <= x) {
            n *= 2;
            cnt++;
        }
        if (cnt == 0) cur = parent[cur][0];
        else cur = parent[cur][cnt];
        x = x - n;
    }
    return cur;
}

int solve() {
    fillParent();
    // for (int i = 1; i <= K; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         cout << parent[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    for (int s: start) {
        cout << helper(s) << ' ';
    }
    cout << endl;
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K >> M;
    parent.assign(K + 1, vector<int>(50, -1));
    for (int i = 1; i <= N; i++) {
        int t; cin >> t;
        start.push_back(t);
    }
    // 1 5 3 1 5 3 1 5 3 1 5 3
    for (int i = 1; i <= K; i++) {
        int t; cin >> t;
        parent[i][0] = t;
    }

    solve();
    return 0;
}