#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (cin >> s, s != "END") {
        vector<string> board;
        board.push_back(s);
        for (int i = 0; i < 14; ++i) {
            cin >> s;
            board.push_back(s);
        }
        // record rows with # so we only get combinations of these rows
        // we could've just get all 2^15 combinations but this is slightly faster
        vector<int> rows;
        for (int i = 0; i < 15; ++i) {
            bool flag = false;
            for (int j = 0; j < 15; ++j) {
                if (board[i][j] == '#') {
                    flag = true;
                    break;
                }
            }
            if (flag) rows.push_back(i);
        }
        // generate all possible combinations of rows with #
        bitset<15> r, c;
        int ans = 16; // find min rooks
        for (int i = 0; i < 1 << rows.size(); ++i) {
            r = 0;
            for (int j = 0; j < rows.size(); ++j) {
                if (i & 1 << j) r[rows[j]] = true;
            }
            c = 0;
            for (int j = 0; j < 15; ++j) {
                if (!r[j]) { // if this row not chosen, any #s in this row must be eaten by a rook in another row. else the max function will take effect to add rooks in addition to the ones in selected rows
                    for (int k = 0; k < 15; ++k) {
                        if (!c[k] && board[j][k] == '#') c[k] = true;
                    }
                }
            }
            ans = min(ans, (int) max(r.count(), c.count()));
        }
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}