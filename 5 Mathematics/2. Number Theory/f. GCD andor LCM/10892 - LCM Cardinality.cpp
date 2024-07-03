#include <bits/stdc++.h>
#include <numeric>

using namespace std;

// get all divisors. can use formula from previous chap we see the max no. of divisors for up to 2^31 is approx 2^10
// no. of pairs 1024C2 = 523776 (OK)

inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        // get all divisors
        vector<int> divisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n / i) { // so the same divisor is not added twice
                    divisors.push_back(n / i);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < divisors.size(); i++) {
            for (int j = i; j < divisors.size(); j++) {
                if (lcm(divisors[i], divisors[j]) == n) {
                    cnt++;
                }
            }
        }
        cout << n << " " << cnt << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}