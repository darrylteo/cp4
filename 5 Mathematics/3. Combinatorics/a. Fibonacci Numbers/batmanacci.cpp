#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<ull> fibs(90 + 5);
    fibs[0] = 0;
    fibs[1] = 1;
    for (int i = 2; i <= 90; i++) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }

    ull N, K;
    cin >> N >> K;
    while (N > 2) {
        if (N > 92 || K <= fibs[N - 2]) { // K is always smaller than fibs[88].. anyway this branch means check left "half"
            N -= 2;
        } else { // check right "half"
            K -= fibs[N - 2];
            N--;
        }
    }
    if (N == 1) cout << "N\n";
    else cout << "A\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


