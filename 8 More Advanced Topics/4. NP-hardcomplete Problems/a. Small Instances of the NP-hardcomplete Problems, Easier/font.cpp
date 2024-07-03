#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

int N, full = (1 << 26) - 1, cnt = 0;
vector<int> v;

void dfs(int mask, int idx) {
    if (mask == full) { // some optimization
        cnt += 1 << (N - idx); // the remaining (N-idx) can either include or exclude (2^(N-idx) possibilities)
        return;
    }
    if (idx == N) {
        return;
    }
    dfs(mask | v[idx], idx + 1);
    dfs(mask, idx + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> N;
    v.resize(N);
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        int bit = 0;
        for (char c: s) bit |= 1 << (c - 'a');
        v[i] = bit;
    }
    dfs(0, 0);
    cout << cnt << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}