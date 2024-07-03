#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000000

typedef vector<int> vi;
typedef unsigned long long ull;
typedef vector<ull> vull;

bitset<MAXN> primes; // if int array, MLE

// sieve of eratosthenes. primes[i] = 0 if i is prime so i don't need to memset
void sieve() {
    primes[0] = primes[1] = 1;
    for (int i = 2; i * i < MAXN; i++) {
        if (primes[i] == 0) {
            for (int j = i * i; j < MAXN; j += i) {
                primes[j] = 1;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();
    int N, Q;
    cin >> N >> Q;
    int cnt = 0;
    for (int i = 0; i <= N; i++) {
        if (primes[i] == 0) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < Q; i++) {
        int n;
        cin >> n;
        if (primes[n] == 0) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}