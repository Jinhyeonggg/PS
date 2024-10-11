#include <bits/stdc++.h>
using namespace std;

int p[100001];

int find(int i) {
    if (p[i] == i) return i;
    return p[i] = find(p[i]);
}

void uni(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa < pb) p[pb] = pa;
    else p[pa] = pb;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    for (int i = 0; i < 100001; i++) {
        p[i] = i;
    }

    int G, P;
    cin >> G >> P;
    int g, ans = 0;
    for (int i = 0; i < P; i++) {
        cin >> g;
        int pg = find(g);
        if (pg == 0) break;
        else {
            uni(pg, pg - 1);
            ans++;
        }
    }
    cout << ans;
    return 0;
}