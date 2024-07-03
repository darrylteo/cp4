#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int getNimSum(const vi& pile) {
    int nim = 0;
    for (auto &p : pile) nim ^= p;
    return nim;
}

// code from book

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        vi pile(n);
        for (auto &p : pile) cin >> p;
        int nim = getNimSum(pile);
        if (nim) cout << "Yes\n";
        else cout << "No\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

