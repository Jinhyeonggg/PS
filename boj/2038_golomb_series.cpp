#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
map<int, int> m;

int solve() {
    m[1] = 1;
    m[3] = 2;
    m[5] = 3;

    int curIdx = 5;

    while (curIdx < N) {
        int value = m[curIdx] + 1;
        int num = m.lower_bound(value)->second;

        m[curIdx + num] = value;
        curIdx += num;
    }

    auto it = m.lower_bound(N);
    return it->second;

    for (auto i: m) {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    cout << solve() << endl;
    return 0;
}