#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

// just follow book for min, and flip for max

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, C;
    cin >> N >> M >> C; // M will be size of sliding window
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    deque<pii> window;
    vector<int> mins(N - M + 1, 0), maxs(N - M + 1, 0);
    for (int i = 0; i < N; ++i) {
        while (!window.empty() && window.back().first >= v[i]) window.pop_back();
        window.emplace_back(v[i], i);
        while (window.front().second <= i - M) window.pop_front();
        if (i - M + 1 >= 0) mins[i - M + 1] = window.front().first;
    }
    window.clear();
    for (int i = 0; i < N; ++i) {
        while (!window.empty() && window.back().first <= v[i]) window.pop_back();
        window.emplace_back(v[i], i);
        while (window.front().second <= i - M) window.pop_front();
        if (i - M + 1 >= 0) maxs[i - M + 1] = window.front().first;
    }
    int found = 0;
    for (int i = 0; i < N - M + 1; ++i) {
        if (maxs[i] - mins[i] <= C) {
            cout << i + 1 << '\n';
            found = 1;
        }
    }
    if (!found) cout << "NONE\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}