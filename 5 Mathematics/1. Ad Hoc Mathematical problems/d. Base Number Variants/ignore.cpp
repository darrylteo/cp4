#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

inline string base10ToN(ll n, int base) {
    string digits = "0125986";
    string result;
    while (n > 0) {
        result += digits[n % base];
        n /= base;
    }
    return result;
}

// just getting the numbers in order, that they are flipped upside down e.g. flip 6 become 9. flip 5 become 5.
// don't reverse since it is upside down

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n;
    while (cin >> n) {
        string ans = base10ToN(n, 7 );
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
