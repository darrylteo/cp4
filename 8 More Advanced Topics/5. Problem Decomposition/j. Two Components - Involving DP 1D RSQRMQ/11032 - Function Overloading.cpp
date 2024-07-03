#include <bits/stdc++.h>

using namespace std;

int sod[10000001]{};
int jSodj[10000001]{}, jSodjCum[10000001]{};

inline int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
        if (sod[n] != 0) {
            sum += sod[n];
            break;
        }
    }
    return sum;
}

// max(sod) = 9*7 = 63
int fun(int a) {
    for (int i = max(1, a - 64); i <= a; i++) {
        if (i + sod[i] == a) {
            return i;
        }
    }
    return -1;
}

// since they ++ans when cnt==0
int fun(int a, int b) {
    return (b - a + 1) - (jSodjCum[b] - jSodjCum[a - 1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 10000000; i++) sod[i] = sumOfDigits(i);
    for (int i = 1; i <= 10000000; i++) {
        int ok = i + sod[i];
        if (ok <= 10000000) jSodj[ok] = 1;
    }
    for (int i = 1; i <= 10000000; i++) jSodjCum[i] = jSodjCum[i - 1] + jSodj[i];

    int T;
    cin >> T >> ws;
    for (int cases = 1; cases <= T; cases++) {
        cout << "Case " << cases << ": ";
        string buf;
        getline(cin, buf);
        int hasSpace = 0;
        for (char c: buf) {
            if (c == ' ') {
                hasSpace = 1;
                break;
            }
        }
        if (hasSpace) {
            stringstream ss(buf);
            int a, b;
            ss >> a >> b;
            cout << fun(a, b) << endl;
        } else {
            int a = stoi(buf);
            cout << fun(a) << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

