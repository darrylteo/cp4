#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<double> plots(N), circles(M), squares(K);
    for (double &i: plots) cin >> i;
    for (double &i: circles) cin >> i;
    for (double &i: squares) cin >> i;
    for (double d: squares) {
        circles.push_back(sqrt(d * d / 2)); // diagonal "radius"
    }
    sort(plots.begin(), plots.end());
    sort(circles.begin(), circles.end());
    // for each circle, find the smallest plot it can fit into
    int ans = 0, pIdx = 0;
    for (double circle: circles) {
        while (pIdx < N && plots[pIdx] <= circle) {
            pIdx++;
        }
        if (pIdx == N) break;
        pIdx++;
        ans++;
    }
    cout << ans << '\n';




    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

