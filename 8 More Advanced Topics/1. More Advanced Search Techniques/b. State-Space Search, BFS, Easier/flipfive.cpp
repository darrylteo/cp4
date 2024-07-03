#include <bits/stdc++.h>

using namespace std;

bitset<9> pattern, curr;
vector<bitset<9>> buttons = {
        0b000001011,
        0b000010111,
        0b000100110,
        0b001011001,
        0b010111010,
        0b100110100,
        0b011001000,
        0b111010000,
        0b110100000
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        pattern = 0;
        for (int i = 0; i < 3; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < 3; j++) {
                if (s[j] == '*') {
                    pattern.set(i * 3 + j);
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i < 512; ++i) {
            curr = 0;
            for (int j = 0; j < 9; ++j) {
                if (i & (1 << j)) curr ^= buttons[j];
            }
            if (curr == pattern) {
                ans = min(ans, __builtin_popcount(i));
            }
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}