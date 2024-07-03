#include <bits/stdc++.h>

using namespace std;

int cost[255][255];
int cumFreq[255];

int Sum(int i, int j) {
    return cumFreq[j] - (i ? cumFreq[i - 1] : 0);
}

// added a k so we don't count first layer
inline int optCost_memoized(int freq[], int i, int j, int k) {
    if (j < i) return 0;
    if (j == i && k) return freq[i];
    if (cost[i][j]) return cost[i][j];
    int fsum = Sum(i, j);
    if (!k) fsum = 0;
    int Min = INT_MAX;
    for (int r = i; r <= j; r++) {
        int c = optCost_memoized(freq, i, r - 1, 1) + optCost_memoized(freq, r + 1, j, 1) + fsum;
        if (c < Min) {
            Min = c;
            cost[i][j] = c;
        }
    }
    return cost[i][j];
}

// classic problem? from gfg: https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/
// worked without the recommended Knuth-Yao speed up
// ref: https://github.com/KHvic/uva-online-judge/blob/master/10304-Optimal%20Binary%20Search%20Tree.cpp
// for knuth speed up

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int freq[255]{}, n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> freq[i];
        cumFreq[0] = freq[0];
        for (int i = 1; i < n; i++) cumFreq[i] = cumFreq[i - 1] + freq[i];
        memset(cost, 0, sizeof(cost));
        cout << optCost_memoized(freq, 0, n - 1, 0) << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
