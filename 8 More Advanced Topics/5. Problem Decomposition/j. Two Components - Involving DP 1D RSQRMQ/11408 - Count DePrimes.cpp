#include <bits/stdc++.h>

using namespace std;

int primeSum[5000001]{};

void sieve() {
    for (int i = 2; i <= 5000000; i++) {
        if (!primeSum[i]) {
            for (int j = i + i; j <= 5000000; j += i) primeSum[j] += i;
        }
    }
}

// qn wants prime factors excluding powers.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    vector<int> dePrime(5000001), cumDePrime(5000001);
    for (int i = 2; i <= 5000000; i++) {
        if (!primeSum[i] || !primeSum[primeSum[i]]) dePrime[i] = 1;
        cumDePrime[i] = cumDePrime[i - 1] + dePrime[i];
    }
    int l, r;
    while (cin >> l >> r, l) {
        cout << cumDePrime[r] - cumDePrime[l - 1] << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

