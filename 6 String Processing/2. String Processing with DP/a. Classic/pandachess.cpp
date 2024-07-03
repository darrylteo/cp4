#include <bits/stdc++.h>

using namespace std;

// similar to 12747 - Back to Edit Distance
// but extra topsort to get original order
unordered_map<string, int> vis;
unordered_map<string, unordered_set<string>> AL;
vector<string> originalOrder;
unordered_set<string> pandas;

inline void toposort(const string& s) {
    vis[s] = 1;
    for (const auto& v : AL[s]) {
        if (vis[v] == 0) toposort(v);
    }
    originalOrder.push_back(s);
}

// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_6_String_Processing/String_Processing_with_DP/kattis_pandachess.cpp
// something that got me stuck is i used AL <string, string> rather than <string, unordered_set<string>>. this won't work since one panda may play more than a match
// 345 678
// 678 123
// 345 123
// 123 -> 345 and STUCK

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, D;
    cin >> N >> M >> D;
    string p1, p2;
    for (int i = 0; i < M; ++i) {
        cin >> p1 >> p2;
        AL[p1].insert(p2);
        pandas.insert(p1);
        pandas.insert(p2);
    }
    for (const auto& p : pandas) {
        if (vis[p] == 0) toposort(p);
    }
    reverse(originalOrder.begin(), originalOrder.end());

    // similar LIS stuff as before
    unordered_map<string, int> a;
    vector<int> b;
    for (int i = 0; i < N; i++) {
        a[originalOrder[i]] = i + 1; // a[k] tells the index of k in the array. e.g. a = 2 3 1. a[2] = 0
    }
    for (int i = 0; i < N; i++) {
        string x;
        cin >> x;
        if (a[x] == 0) continue;
        b.push_back(a[x]); // b[i] tells the index of x in the array a. e.g. b = 3 2 1. a[3] = 1, b[0] = 1, b[1] = 0, b[2] = 2
    }
    if (b.empty()) {
        cout << N * 2 << '\n';
        return 0;
    }
    // b is the important matrix. we can ignore a now.
    // we find longest increasing subsequence because if b increasing means it is same order as a
    // the non increasing ones will be removed/inserted
    vector<int> v;
    v.push_back(b[0]);
    for (int i = 1; i < b.size(); i++) {
        int pos = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
        if (pos == v.size()) {
            v.push_back(b[i]);
        } else {
            v[pos] = b[i];
        }
    }
    cout << (N - v.size()) * 2 << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}