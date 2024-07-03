#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> recital(n);
    for (string &i: recital) cin >> i;
    vector<int> perm(n); // use int to permute so we can use diff matrix
    iota(perm.begin(), perm.end(), 0); // fill increasing sequence
    vector<vector<int>> diff(n, vector<int>(n));

    // only 10c2 different pairs, so we should save it so don't recompute
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string dancersInPrev = recital[i];
            string dancersInNext = recital[j];
            for (char k : dancersInPrev) {
                // if found in next dance, add quickchange
                if (dancersInNext.find(k) != string::npos) {
                    ++diff[i][j];
                    ++diff[j][i];
                }
            }
        }
    }

    int bestQuickChange = INT_MAX;
    do {
        int quickChange = 0;
        for (int i = 1; i < n; ++i) {
            quickChange += diff[perm[i - 1]][perm[i]];
        }
        bestQuickChange = min(bestQuickChange, quickChange);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << bestQuickChange << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
