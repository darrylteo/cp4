#include <bits/stdc++.h>

using namespace std;

// ref: https://hackmd.io/@txya900619/Uva11147

int n;
vector<int> v, cum;

// find best parent within range l to r
void dfs(int l, int r) {
    if (l == r) {
        cout << v[r];
        return;
    }
    if (l > r) return;

    int myMin = INT_MAX, myLeftMax = INT_MIN, idx = l, leftSum, rightSum, diff;
    for (int i = l; i <= r; ++i) {
        if (i != r && v[i] == v[i + 1]) {
            continue;
        }
        // if v = 1, 3, 1, 5, 2, 2, 1, with  l = 2, r = 6, i = 4, leftSum = 1 + 5 = 6, rightSum = 2 + 1 = 3
        // then cumsum = 0, 1, 4, 5, 10, 12, 14, 15, we take leftSum = cum[4] - cum[2], rightSum = cum[7] - cum[5]
        leftSum = cum[i] - cum[l];
        rightSum = cum[r + 1] - cum[i + 1];
        diff = abs(leftSum - rightSum);
        if (diff < myMin) {
            myMin = diff;
            myLeftMax = leftSum;
            idx = i;
        }
        // we want sum of all values in left tree maximum (after minimizing diff of course)
        if (diff == myMin && leftSum > myLeftMax) {
            myLeftMax = leftSum;
            idx = i;
        }
    }
    cout << v[idx];
    cout << '(';
    dfs(l, idx - 1);
    if (idx != l && idx != r) cout << ',';
    dfs(idx + 1, r);
    cout << ')';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        cin >> n;
        v.resize(n);
        cum.resize(n + 1);
        cum[0] = 0;
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }
        sort(v.begin(), v.end()); // so cumsum works (when there are negative values?)
        for (int j = 1; j <= n; ++j) {
            cum[j] = cum[j - 1] + v[j - 1];
        }
        dfs(0, n - 1);
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


