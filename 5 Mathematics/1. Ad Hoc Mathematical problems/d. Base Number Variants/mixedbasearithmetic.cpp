#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

// i think this is how numbers are added anyway by carrying forward the remainder (just like baby times)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    int n;
    while (cin >> s >> n) {
        vi bases, val;
        vector<char> types;
        for (char c: s) {
            if (isdigit(c)) {
                bases.push_back(10);
                types.push_back('0');
                val.push_back(c - '0');
            } else if (isupper(c)) {
                bases.push_back(26);
                types.push_back('A');
                val.push_back(c - 'A');
            } else {
                bases.push_back(26);
                types.push_back('a');
                val.push_back(c - 'a');
            }
        }
        int valCarry = n;
        for (int i = val.size() - 1; i >= 0; --i) {
            val[i] += valCarry;
            valCarry = val[i] / bases[i];
            val[i] %= bases[i];
        }
        string ans;
        while (valCarry > 0) {
            if (types[0] == '0') {
                ans += (char) ((valCarry % bases[0]) + types[0]);
                valCarry /= bases[0];
            } else {
                if (valCarry% bases[0] == 0) { // try a9 6751 as a debug case
                    ans += 'z';
                    valCarry--;
                } else {
                    ans += (char) ((valCarry % bases[0]) + types[0] - 1);
                }
                valCarry /= bases[0];
            }
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < val.size(); ++i) {
            ans += (char) (val[i] + types[i]);
        }
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
