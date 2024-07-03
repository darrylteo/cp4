#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int MAX_N = 14000;
// numDiffPFarr[i] stores the number of different prime factors of i
int numDiffPFarr[MAX_N + 10] = {0};
// memoSubs[i] stores the number of different prime factors for the subset i
// memoAns[i] stores the best answer for the subset i
int memoAns[70000], memoSubs[70000], vals[15];

// e.g. n = 110001. we return subsets = {000000, 000001, 010000, 010001, 100000, 100001, 110000, 110001}
vi genSubsets(int n) {
    vi subsets = {0};
    for (int i = 1; i <= n; i <<= 1) {
        if (i&n) {
            int currSize = subsets.size();
            for (int j = 0; j < currSize; ++j) {
                subsets.push_back(subsets[j] | i);
            }
        }
    }
    return subsets;
}

int numDiffPFSubset(int subset) {
    if (memoSubs[subset] != -1) {
        return memoSubs[subset];
    }
    int sum = 0;
    for (int i = 0; i < 15; ++i) {
        if (subset & (1 << i)) {
            sum += vals[i];
        }
    }
    return memoSubs[subset] = numDiffPFarr[sum];
}

int dfs(int subset) {
    if (memoAns[subset] != -1) {
        return memoAns[subset];
    }

    int best = 0;
    vi subsets = genSubsets(subset);
    for (int i: subsets) {
        if (i == 0) continue;
        best = max(best, dfs(subset - i) + numDiffPFSubset(i)); // curr guy use i.
    }
    return memoAns[subset] = best;
}

// yay. dp practice

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 2; i <= MAX_N; ++i) {
        if (numDiffPFarr[i] == 0) {// i is a prime number
            for (int j = i; j <= MAX_N; j += i) {
                ++numDiffPFarr[j]; // j is a multiple of i
            }
        }
    }

    memset(memoSubs, -1, sizeof(memoSubs));
    memset(memoAns, -1, sizeof(memoAns));

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> vals[i];
    cout << dfs((1 << n) - 1) << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}