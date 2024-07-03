#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

// n-th diagonal := contains n(n+1)/2 elements inclusive, and sum of a+b=n+1 from a/b

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vi sumAP;
    for (int i = 1; i <= 5000; i++) {
        sumAP.push_back(i * (i + 1) / 2);
    }
    int n;
    while (cin >> n) {
        if (n == 1) {
            cout << "TERM 1 IS 1/1" << endl;
            continue;
        }

        int diagonalIdx = lower_bound(sumAP.begin(), sumAP.end(), n) - sumAP.begin();
        int cntToAdd = n - sumAP[diagonalIdx - 1];
        int aPlusB = diagonalIdx + 2;
        if (diagonalIdx % 2) {
            cout << "TERM " << n << " IS " << cntToAdd << "/" << aPlusB - cntToAdd << endl;
        } else {
            cout << "TERM " << n << " IS " << aPlusB - cntToAdd << "/" << cntToAdd << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

