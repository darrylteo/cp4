#include <bits/stdc++.h>

using namespace std;

vector<int> nextVals[10];
set<int> vals;

// n is current digit, pos is current position (check up to 3 digits)
void dfs(string n, int pos) {
    vals.insert(stoi(n));
    if (pos == 3) return;
    if (pos == 2 && n[0] >= '0' + 3) return; // optional stop check at 299
    // check all possible next digits given the last digit, append to n and update pos and recurse
    for (int i: nextVals[n.back() - '0']) {
        dfs(n + to_string(i), pos + 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    nextVals[0] = {0};
    nextVals[1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    nextVals[2] = {2, 3, 5, 6, 8, 9, 0};
    nextVals[3] = {3, 6, 9};
    nextVals[4] = {4, 5, 6, 7, 8, 9, 0};
    nextVals[5] = {5, 6, 8, 9, 0};
    nextVals[6] = {6, 9};
    nextVals[7] = {7, 8, 9, 0};
    nextVals[8] = {8, 0, 9};
    nextVals[9] = {9};

    for (int i = 0; i <= 9; i++) {
        dfs(to_string(i), 1);
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int less = *--vals.lower_bound(n);
        int more = *vals.lower_bound(n);
        if (n - less <= more - n) {
            cout << less << endl;
        } else {
            cout << more << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

