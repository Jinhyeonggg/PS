#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> p = {0, 1, 2, 3, 4, 5};
    int i = 5;
    while (i == p[i]) {
        i--;
    }
    for (int v: p) {
        cout << v << endl;
    }
    return 0;
}