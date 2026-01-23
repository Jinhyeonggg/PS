#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tc, N, W;
vector<vector<int>> A;
vector<vector<int>> dp;

void initSize() {
    // A.clear();
    // dp.clear();
    A.assign(2, vector<int>(N, 0));
    A.resize(2, vector<int>(N, 0));
    dp.assign(N, vector<int>(5, -1));
}

void initDP() {
    // dp.assign(N, vector<int>(5, -1));
    for (int i = 0; i < N; i++) {
        for (int t = 1; t <= 3; t++) {
            dp[i][t] = -1;
        }
    }
}

int helper(int n, int type) {
    if (n == -1 && type == 1) return 0;
    if (n == 0) {
        if (type == 1) {
            if (A[0][0] + A[1][0] <= W) return 1;
            else return 2;   
        }
        else return 1;
    }

    if (dp[n][type] != -1) return dp[n][type];

    vector<int> v;
    int r1 = helper(n - 1, 1), r2 = helper(n - 1, 2), r3 = helper(n - 1, 3);
    if (type == 1) {
        if (A[0][n - 1] + A[0][n] <= W) {
            if (A[1][n - 1] + A[1][n] <= W) {
                v.push_back(helper(n - 2, 1) + 2);
            }   
            v.push_back(r3 + 2);
        }
        if (A[0][n] + A[1][n] <= W) {
            v.push_back(r1 + 1);
        }
        if (A[1][n - 1] + A[1][n] <= W) {
            v.push_back(r2 + 2);
        }
        v.push_back(r1 + 2);
    }
    else if (type == 2) {
        v.push_back(r1 + 1);
        if (A[0][n - 1] + A[0][n] <= W) {
            v.push_back(r3 + 1);
        }
    }
    else if (type == 3) {
        v.push_back(r1 + 1);
        if (A[1][n - 1] + A[1][n] <= W) {
            v.push_back(r2 + 1);
        }
    }

    dp[n][type] = *min_element(v.begin(), v.end());
    return dp[n][type];
}

int solve() {
    if (N == 1) {
        if (A[0][0] + A[1][0] <= W) return 1;
        else return 2;
    }
    int a = A[0][0], b = A[0][N - 1], c = A[1][0], d = A[1][N - 1];
    // a 0 0 b
    // c 0 0 d

    vector<int> v;
    // case 1: 0 0 0 0
    //         0 0 0 0
    v.push_back(helper(N - 1, 1));
    initDP();

    // case 2: 1 0 0 1
    //         0 0 0 0
    if (A[0][0] + A[0][N - 1] <= W) {
        A[0][0] = W + 1, A[0][N - 1] = W + 1;
        v.push_back(helper(N - 1, 1) - 1);
        A[0][0] = a, A[0][N - 1] = b;
        initDP();
    }

    // case 3: 0 0 0 0
    //         1 0 0 1
    if (A[1][0] + A[1][N - 1] <= W) {
        A[1][0] = W + 1, A[1][N - 1] = W + 1;
        v.push_back(helper(N - 1, 1) - 1);
        A[1][0] = c, A[1][N - 1] = d;
        initDP();
    }

    // case 4: 1 0 0 1
    //         1 0 0 1
    if (A[0][0] + A[0][N - 1] <= W && A[1][0] + A[1][N - 1] <= W) {
        A[0][0] = W + 1, A[0][N - 1] = W + 1;
        A[1][0] = W + 1, A[1][N - 1] = W + 1;
        v.push_back(helper(N - 1, 1) - 2);
        A[0][0] = a, A[0][N - 1] = b;
        A[1][0] = c, A[1][N - 1] = d;
        initDP();
    }

    return *min_element(v.begin(), v.end());
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> tc;
    while (tc--) {
        cin >> N >> W;
        initSize();
        for (int i = 0; i < 2; i++) {
            int t;
            for (int j = 0; j < N; j++) {
                cin >> t;
                A[i][j] = t;
            }   
        }
        cout << solve() << endl;
    }
    return 0;
}