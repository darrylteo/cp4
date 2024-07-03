#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bintoll(const string &s) {
    ll res = 0;
    for (char i: s) {
        res <<= 1;
        res += i - '0';
    }
    return res;
}

string lltobin(ll n) {
    string res;
    while (n > 0) {
        if (n & 1) res.push_back('1');
        else res.push_back('0');
        n >>= 1;
    }
    reverse(res.begin(), res.end());
    if (res.empty()) res.push_back('0');
    return res;
}

// reverse engineering uwu

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string a, b;
    int start = 0;
    while (cin >> a >> b) {
        if (a == "0" && b == "0") break;

        if (start) cout << '\n';
        start = 1;

        string ans = lltobin(bintoll(a) * bintoll(b));
        string aa = a, bb = b;

        ll sz = max(max(a.size(), b.size()), ans.size());
        ll sz1 = max(a.size(), b.size());
        string line(sz1, '-');
        reverse(a.begin(), a.end());
        while (a.size() < sz) a.push_back(' ');
        reverse(a.begin(), a.end());
        cout << a << '\n';
        reverse(b.begin(), b.end());
        while (b.size() < sz) b.push_back(' ');
        reverse(b.begin(), b.end());
        cout << b << '\n';
        while (line.size() < ans.size()) line.push_back(' ');
        reverse(line.begin(), line.end());
        cout << line << '\n';

        reverse(ans.begin(), ans.end());
        while (ans.size() < sz) ans.push_back(' ');
        reverse(ans.begin(), ans.end());

        ll spaces = ans.size() - aa.size();
        for (int i = bb.size() - 1; i >= 0; --i) {
            cout << string(spaces--, ' ');
            spaces = max(spaces, 0LL);
            if (bb[i] == '1') cout << aa;
            else cout << string(aa.size(), '0');
            cout << '\n';
        }

        cout << string(ans.size(), '-') << '\n';
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




