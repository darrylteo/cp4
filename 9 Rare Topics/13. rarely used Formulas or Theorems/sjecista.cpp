#include <bits/stdc++.h>

using namespace std;

int nck(int n, int k) {
    if (k == 0) return 1;
    return n * nck(n - 1, k - 1) / k;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    cout << nck(n, 4) << endl; // 4 vertices = 2 edges = 1 intersection

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

