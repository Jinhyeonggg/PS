#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll M = 200000;
ll N;
vector<ll> A;
vector<pair<ll, ll>> tree;
ll treeSize = 1;
ll startIdx;
set<ll> s;
ll Q = 1000000007;

void buildTree() {
    while (treeSize < M) {
        treeSize *= 2;
    }
    treeSize *= 2;
    tree.assign(treeSize, {0, 0});
    startIdx = treeSize / 2;
}

void insertTree(ll n) {
    ll curIdx = startIdx + n;
    while (curIdx != 0) {
        tree[curIdx].first += n;
        tree[curIdx].second += 1;
        curIdx /= 2;
    }
}

// return how much I should add to the answer
ll rangeIn(ll l, ll r, ll cur, ll x, ll y) {
    if (l == x && r == y) return tree[cur].second;
    if (l == r) return tree[cur].second;
    ll mid = (l + r) / 2;
    if (x > mid) {
        return rangeIn(mid + 1, r, 2 * cur + 1, x, y);
    }
    else if (y <= mid) {
        return rangeIn(l, mid, 2 * cur, x, y);
    }
    else {
        ll a = rangeIn(l, mid, 2 * cur, x, mid);
        ll b = rangeIn(mid + 1, r, 2 * cur + 1, mid + 1, y);
        return a + b;
    }
}

ll offset(ll key) {
    ll a = rangeIn(0, treeSize / 2 - 1, 1, 0, key - 1);
    ll b = rangeIn(0, treeSize / 2 - 1, 1, key + 1, treeSize / 2 - 1);
    return (a - b) * key;
}

// l is alway 0, r is always M in the beginning
// flag 2 means not decided yet
ll getSum(ll l, ll r, ll cur, ll key, ll flag) {

    if (flag == 1 || flag == -1) {
        return flag * tree[cur].first;
    }
    if (l == r && flag == 2) return 0;

    ll ans = 0;
    ll mid = (l + r) / 2;
    if (key <= mid) {
        ans += getSum(mid + 1, r, 2 * cur + 1, key, 1);
        ans += getSum(l, mid, 2 * cur, key, flag);
    }
    else {
        ans += getSum(l, mid, 2 * cur, key, -1);
        ans += getSum(mid + 1, r, 2 * cur + 1, key, flag);
    }
    return ans;
}

ll solve() {
    buildTree();
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        if (i == 0) insertTree(A[0]);
        else {
            int n = A[i];
            ll a = getSum(0, treeSize / 2 - 1, 1, n, 2);
            ll b = offset(n);
            // cout << i << ": " << endl;
            // cout << a << endl;
            // cout << b << endl;
            // cout << a + b << endl;
            ans = (ans * ((a + b) % Q)) % Q;
            insertTree(n);
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (ll i = 0; i < N; i++) {
        ll a; cin >> a;
        A.push_back(a);
    }

    cout << solve() << endl;
    return 0;
}