#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P, curr = 0, best = 0;
    cin >> N >> P;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        curr += x - P;
        if (curr < 0) curr = 0;
        best = max(best, curr);
    }
    cout << best << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
