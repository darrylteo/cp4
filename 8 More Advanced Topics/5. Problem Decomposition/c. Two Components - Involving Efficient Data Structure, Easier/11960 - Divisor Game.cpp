#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> numdiv(1000001, 1);
    for (int i = 2; i <= 1000000; ++i) {
        for (int j = i; j <= 1000000; j += i) {
            numdiv[j]++;
        }
    }
    vector<int> ans(1000001, 0);
    int best = 0, bestIdx = 0;
    for (int i = 1; i <= 1000000; ++i) {
        if (numdiv[i] >= best) {
            best = numdiv[i];
            bestIdx = i;
        }
        ans[i] = bestIdx;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
