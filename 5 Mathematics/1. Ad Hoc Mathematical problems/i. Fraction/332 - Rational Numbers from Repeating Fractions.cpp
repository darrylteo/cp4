#include <bits/stdc++.h>

using namespace std;

// -_- need special math formulas to solve this problem

// last 3 digits are repeating
// x = 0.345345345
// 1000x = 345.345345345
// 1000x - x = 345.345345345 - 0.345345345 = 345
// 999x = 345
// x = 345 / 999 = 115 / 333

// last 2 digits are repeating
// x = 0.345454545
// 1000x = 345.454545
// 10x = 3.4545454545
// 1000x - 10x = 345.454545 - 3.4545454545 = 342
// 990x = 342
// x = 342 / 990 = 57 / 165

// last 1 digit is repeating
// x = 0.3455555555555
// 1000x = 345.5555555555
// 100x = 34.55555555555
// 1000x - 100x = 345.5555555555 - 34.55555555555 = 311
// 900x = 311
// x = 311 / 900

// similar to kattis deadfraction so i just leave the above for reference

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k, cases = 1;
    string s;
    while (cin >> k) {
        if (k == -1) break;
        cin >> s;
        // get the digits aka (int)1000x from our example
        s = s.substr(2);
        int n = s.size();
        int original = stoi(s);
        int originalPow = pow(10, n);
        // there are cases where k == 0
        if (k == 0) {
            int gcd = __gcd(original, originalPow);
            original /= gcd;
            originalPow /= gcd;
            cout << "Case " << cases++ << ": " << original << "/" << originalPow << '\n';
            continue;
        }
        // normal case
        int N, D;
        k = n - k;
        int x;
        if (k == 0) x = 0;
        else x = stoi(s.substr(0, k));
        N = original - x;
        D = originalPow - pow(10, k);
        int gcd = __gcd(N, D);
        N /= gcd;
        D /= gcd;
        cout << "Case " << cases++ << ": " << N << "/" << D << '\n';

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

