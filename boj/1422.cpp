#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int K, N;
map<string, int> m;
vector<pair<string, int>> v;

bool cmpByLen(string s1, string s2) {
    if (s1.size() == s2.size()) {
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            if (s1[i] != s2[i]) {
                return s1[i] < s2[i];   
            }
        }
        return true;
    }
    return s1.size() < s2.size();
}

bool cmp(string s1, string s2) {
    for (int i = 0; i < min(s1.size(), s2.size()); i++) {
        
    }
}

int solve() {
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> K >> N;
    string sMax;
    for (int i = 0; i < K; i++) {
        string s; cin >> s;
        sMax = s;
        if (m.find(s) == m.end()) {
            m[s] = 1;
        }
        else m[s]++;
    }

    for (pair<string, int> p: m) {
        if (cmpByLen(sMax, p.first)) {
            sMax = p.first;
        }
    }
    m[sMax] += N - K;

    for (pair<string, int> p: m) {
        v.push_back(p);
    }
    sort(v.begin(), v.end(), [](pair<string, int> p1, pair<string, int> p2) {
        return !cmpByLen(p1.first, p2.first);
    });
    // cout << solve() << endl;
    return 0;
}