#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

int W, N, area = 0;
    cin >> W >> N;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        area += a * b;
    }
    cout << area / W << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

