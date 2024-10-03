#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent;

    UnionFind(int size) {
        parent.resize(size + 1);
        for (int i: parent) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (i == 1) {
            if (parent[1] == 0) return 1;
            else return -1;
        }

        if (parent[i] == 0) {
            return i;
        }
        if (i != parent[i]) {
            parent[i] = find(parent[i]);
            return parent[i];
        }
        else return i;
    }

    bool help(int i) {
        if (parent[i] == 0) {
            parent[i] = i;
            return true;
        }
        else {
            int rootI = find(i);
            if (rootI <= 1) return false;
            else {
                while (parent[rootI] != 0) rootI--;
                if (rootI <= 1 && parent[1] == 1) return false;
                int next = find(rootI);
                parent[next] = next;
                parent[rootI] = next;
                parent[i] = next;
                return true;
            }
        }
    }
};

int main() {
    int G, P;
    cin >> G >> P;
    vector<int> gi(P);
    
    for (int i = 0; i < P; i++){
        cin >> gi[i];
    }

    UnionFind uf(G);
    int ans = 0;
    for (int value: gi) {
        if (uf.help(value)) {
            ans++;
        }
        else break;
    }
    cout << ans;
    return 0;
}