#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull fastpow(ull base, ull exp) {
    ull result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base);
        }
        base = (base * base);
        exp >>= 1;
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n;
    cin >> n;
    int best = 0;
    for (int i = 1; i <= 130; i++) {
        if (n % fastpow(i, 9) == 0) {
            best = i;
        }
    }
    cout << best << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


