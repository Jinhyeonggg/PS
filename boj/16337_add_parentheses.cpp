#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int N;
string S;
vector<int> nums;
vector<char> ops;

int operate(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else {
        return a * b;
    }
}

int compute() {
    int ans = nums[0];
    for (int i = 0; i < ops.size(); i++) {
        ans = operate(ans, nums[i + 1], ops[i]);
    }
    return ans;
}

int solve(int idx) {
    if (idx == N) {
        return compute();
    }
    int ans = INT_MIN;
    if (idx % 2 == 0) {
        // 1) push
        nums.push_back(S[idx] - '0');
        ans = max(ans, solve(idx + 1));
        nums.pop_back();

        // 2) compute first
        if (idx + 2 <= S.size()){
            nums.push_back(operate(S[idx] - '0', S[idx + 2] - '0', S[idx + 1]));
            ans = max(ans, solve(idx + 3));
            nums.pop_back();
        }
    }

    else {
        ops.push_back(S[idx]);
        ans = max(ans, solve(idx + 1));
        ops.pop_back();
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> S;
    cout << solve(0) << endl;
    return 0;
}