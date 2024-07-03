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

    int n;
    while (cin >> n >> ws) {
        string buf;
        getline(cin, buf);
        int insCnt = pow(2, n) - 1; // number of backslashes to insert
        string toInsert(insCnt, '\\');
        for (char c: buf) {
            if ((c >= '!' && c <= '*') || (c >= '[' && c <= ']')) {
                cout << toInsert << c;
            } else {
                cout << c;
            }
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

