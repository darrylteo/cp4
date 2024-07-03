#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        // get data
        int n;
        cin >> n;
        cout << n << ' ';
        string s;
        cin >> s;
        istringstream ss(s);
        int p, q;
        getline(ss, s, '/');
        p = stoi(s);
        getline(ss, s, '/');
        q = stoi(s);
        // pattern on next line
        if (q == 1) {
            cout << "1/" << p + 1 << '\n';
            continue;
        }
        // is a left number, print right number
        if (p < q) {
            cout << q << '/' << q - p << '\n';
            continue;
        }
        // is a right number, need go until a left node, go right once, then left all the way
        // check until p < q i.e. p - n * q < q. p/q - 1 < n. dunnid minus 1 since relative prime auto round down.
        int upCount = p / q;
        p -= upCount * q;
        // go to right node
        int tmpP = p;
        p = q;
        q -= tmpP;
        // go down left all the way
        q += p * upCount;
        cout << p << '/' << q << '\n';

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

