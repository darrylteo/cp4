#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;
int primes[MAXN + 5];

void sieve() {
    for (int i = 2; i <= MAXN; i++) {
        if (primes[i] == 1) {
            for (int j = 2 * i; j <= MAXN; j += i) {
                primes[j] = 0;
            }
        }
    }
}

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(primes, primes + MAXN + 1, 1);
    primes[0] = primes[1] = 0;
    sieve();
    vector<bool> isDigitPrime(1000005, false);
    for (int i = 2; i <= 1000000; i++) {
        int sum = sumOfDigits(i);
        if (primes[sum] && primes[i]) {
            isDigitPrime[i] = true;
        }
    }
    vector<int> cum(1000005, 0);
    for (int i = 1; i <= 1000000; i++) {
        cum[i] = cum[i - 1] + isDigitPrime[i];
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << cum[R] - cum[L - 1] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

