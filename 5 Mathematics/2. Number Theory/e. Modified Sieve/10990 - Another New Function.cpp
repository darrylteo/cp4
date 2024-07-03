#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2000005;
int EulerPhi[MAX_N], depth[MAX_N], cumDepth[MAX_N], maxDepth;

inline void updateDepth(int n, int d) {
    maxDepth = max(maxDepth, d);
    if (n == 1) return;
    if (depth[EulerPhi[n]] == -1) {
        updateDepth(EulerPhi[n], d+1);
        depth[n] = maxDepth - d;
    } else {
        depth[n] = depth[EulerPhi[n]] + 1;
    }
}

// non dp also works just update 1 number at a time. 0.190s for non dp, 0.060s for dp.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 1; i < MAX_N; ++i) EulerPhi[i] = i;
    for (int i = 2; i < MAX_N; ++i)
        if (EulerPhi[i] == i) // i is a prime number
            for (int j = i; j < MAX_N; j += i)
                EulerPhi[j] = (EulerPhi[j]/i) * (i-1);


    memset(depth, -1, sizeof(depth));
    updateDepth(13, 0);
    for (int i = 2; i < MAX_N; ++i) {
        maxDepth = 0;
        updateDepth(i, 0);
    }

    for (int i = 1; i < MAX_N; ++i) {
        cumDepth[i] = cumDepth[i-1] + depth[i];
    }

    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        cout << cumDepth[r] - cumDepth[l-1] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}