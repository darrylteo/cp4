#include <bits/stdc++.h>

using namespace std;

int primeFactors(int N, vector<int> &p) { // p is the H-primes
    int cnt = 0;
    for (int i = 0; (i < (int) p.size()) && (p[i] * p[i] <= N); ++i)
        while (N % p[i] == 0) {
            N /= p[i];
            ++cnt;
        }
    if (N != 1) ++cnt;
    return cnt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> H(1000005, 1);
    for (int i = 1; i < 1000005 / 4; ++i) H[4 * i + 1] = 0;
    // when land on a 0 (H-prime), subtract 1 from all its multiples (if it is H number)
    for (int i = 5; i < 1000005; i += 4) {
        if (H[i] == 0) {
            for (int j = 2 * i; j < 1000005; j += i) {
                if (H[j] == 0) H[j] = -1;
            }
        }
    }
    vector<int> H_primes;
    for (int i = 1; i < 1000005; ++i) {
        if (H[i] == 0) H_primes.push_back(i);
    }
    // now we have H[i]==0 for all H-primes and H[i]==-1 for all other H numbers, and H[i]==1 for all non-H numbers
    vector<int> semi_H_primes(1000005, 0), semiCum(1000005, 0);
    for (int i = 1; i < 1000005; ++i) {
        semiCum[i] = semiCum[i - 1];
        if (H[i] != -1) continue;
        if (primeFactors(i, H_primes) == 2) semi_H_primes[i] = 1;
        semiCum[i] += semi_H_primes[i];
    }

    int n;
    while (cin >> n, n) {
        cout << n << " " << semiCum[n] << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

