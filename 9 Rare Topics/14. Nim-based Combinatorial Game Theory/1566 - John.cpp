#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int getNimSum(const vi &pile) {
    int nim = 0;
    for (auto &p: pile) nim ^= p;
    return nim;
}

string whoWinNimGame(const vi &pile) {
    return (getNimSum(pile) != 0) ? "John" : "Brother";
}

string whoWinMisereNimGame(const vi& pile) {
    int n_more = 0, n_one = 0;
    for (int i: pile) {
        if (i > 1) ++n_more;
        if (i == 1) ++n_one;
    }
    if (n_more >= 1) return whoWinNimGame(pile);
    else return (n_one % 2 == 0) ? "John" : "Brother";
}

// code from book

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi pile(n);
        for (auto &p: pile) cin >> p;
        cout << whoWinMisereNimGame(pile) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

