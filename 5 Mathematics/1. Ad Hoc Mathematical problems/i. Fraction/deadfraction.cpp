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


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (cin >> s) {
        if (s == "0") break;
        // get the digits aka (int)1000x from our example
        s = s.substr(2, s.size() - 5);
        int n = s.size();
        int original = stoi(s);
        int originalPow = pow(10, n);
        int currN, currD = INT_MAX, bestN, bestD = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int x;
            if (i == 0) x = 0;
            else x = stoi(s.substr(0, i));
            currN = original - x;
            currD = originalPow - pow(10, i);
            int gcd = __gcd(currN, currD);
            currN /= gcd;
            currD /= gcd;
            if (currD < bestD) {
                bestN = currN;
                bestD = currD;
            }
        }
        cout << bestN << "/" << bestD << '\n';


    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

