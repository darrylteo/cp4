#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int getNimSum(const vi &pile) {
    int nim = 0;
    for (auto &p: pile)
        nim ^= p;
    return nim;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int R, C, r, c;
        cin >> R >> C >> r >> c;
        vi pile;
        pile.push_back(r);
        pile.push_back(c);
        pile.push_back(R - r - 1);
        pile.push_back(C - c - 1);
        int nim = getNimSum(pile);
        if (nim == 0) cout << "Hansel" << endl;
        else cout << "Gretel" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
