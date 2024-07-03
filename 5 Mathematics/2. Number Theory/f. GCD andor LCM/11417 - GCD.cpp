#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 505;
unsigned long long EulerPhi[MAX_N], ans[MAX_N], ansCum[MAX_N];

// e.g. GCD for (i,6)
// (1,6) -> 1
// (2,6) -> 2
// (3,6) -> 3
// (4,6) -> 2
// (5,6) -> 1

// SUM_{i=1}^5 GCD(i,6) = 1+2+3+2+1 = 9
// = 1*phi(6) + 2*phi(3) + 3*phi(2) = 1*2 + 2*2 + 3*1 = 9

// e.g. GCD for (i,8)
// (1,8) -> 1
// (2,8) -> 2
// (3,8) -> 1
// (4,8) -> 4
// (5,8) -> 1
// (6,8) -> 2
// (7,8) -> 1

// SUM_{i=1}^7 GCD(i,8) = 1+2+1+4+1+2+1 = 12
// = 1*phi(8) + 2*phi(4) + 4*phi(2) = 1*4 + 2*2 + 4*1 = 12

// phi(4) is the number of times gcd = 2 appears
// generalize this to cnt(gcd == i) = cnt(gcd(x,n)=i) for 1<=x<n = cnt(gcd(x/i,n/i)==1) for 1<=x<n = cnt(numbers that are relatively prime to n/i) = phi(n/i)

// repeat of GCD from previous section

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 1; i < MAX_N; ++i) EulerPhi[i] = i;
    for (int i = 2; i < MAX_N; ++i)
        if (EulerPhi[i] == i) // i is a prime number
            for (int j = i; j < MAX_N; j += i)
                EulerPhi[j] = (EulerPhi[j]/i) * (i-1);

    for (int i = 1; i < MAX_N; ++i) {
        for (int j = i + i; j < MAX_N; j += i) {
            ans[j] += i * EulerPhi[j/i];
        }
    }

    for (int i = 1; i < MAX_N; ++i) ansCum[i] = ansCum[i-1] + ans[i];

    int n;
    while (cin >> n, n) cout << ansCum[n] << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}