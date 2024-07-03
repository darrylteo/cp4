#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// they are just asking how many pairs... since size 2 spanning tree is the smallest "connected" graph

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, cases = 1;
    while (cin >> n, n) {
        cout << "Case " << cases++ << ": " << n / 2 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


