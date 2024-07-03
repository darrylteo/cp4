#include <bits/stdc++.h>

using namespace std;

bool isValid(vector<int> &rungs, int k) {
    int prev = 0;
    for (int i = 0; i < rungs.size(); i++) {
        if (rungs[i] - prev > k) {
            return false;
        }
        if (rungs[i] - prev == k) {
            k--;
        }
        prev = rungs[i];
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int r;
        cin >> r;
        vector<int> rungs(r);
        for (int j = 0; j < r; j++) {
            cin >> rungs[j];
        }
        int low = 0, high = 1e9;
        while (low < high) {
            int mid = (high + low) / 2;
            if (isValid(rungs, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << "Case " << i << ": " << low << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
