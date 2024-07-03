#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

// ref: https://codingstrife.wordpress.com/2013/07/28/solution-uva701-pc110503-the-archaeologists-dilemma/
// really need write down formula...

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n;
    while (cin >> n) {
        double a, b, c, d;
        a = log2(n);
        b = log2(10);
        c = log2(n + 1);
        d = log2(10);
        int T = floor(log10(n)) + 2; // make sure more lost digits (e.g. log10(1000) = 3 so we need at least 3+2=5 lost digits)
        while (true) {
            if (ceil(a + T * b) == floor(c + T * d)) {
                cout << (int) ceil(a + T * b) << endl;
                break;
            }
            T++;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

