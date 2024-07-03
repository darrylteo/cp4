#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// ref: https://dmoj.ca/problem/naq16g/editorial

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    if (s == "1") {
        cout << 1 << endl;
    } else if (s == "2") {
        cout << 2 << endl;
    } else if (s == "6") {
        cout << 3 << endl;
    } else if (s == "24") {
        cout << 4 << endl;
    } else if (s == "120") {
        cout << 5 << endl;
    } else if (s == "720") {
        cout << 6 << endl;
    } else if (s == "5040") {
        cout << 7 << endl;
    } else if (s == "40320") {
        cout << 8 << endl;
    } else if (s == "362880") {
        cout << 9 << endl;
    } else {
        int len = s.length();
        vector<double> L(1000001, 0);
        L[1] = log10(1);
        for (int i = 2; i <= 1000000; i++) {
            L[i] = L[i - 1] + log10(i);
        }
        int pos = lower_bound(L.begin(), L.end(), len) - L.begin();
        cout << pos - 1 << endl;
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}