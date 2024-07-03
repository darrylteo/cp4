#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000000;

bool prime[MAXN + 5];
vector<int> p; // primes

void sieve() {
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= sqrt(MAXN); i++) {
        if (prime[i]) {
            p.push_back(i);
            for (int j = i * i; j <= MAXN; j += i) prime[j] = false;
        }
    }
}

// RSQ problem since 5! is 5x4!

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    vector<int> ans(MAXN + 5, 0); // count of prime factors for i!
    for (int i = 2; i <= MAXN; i++) {
        ans[i] = ans[i - 1];
        int x = i, idx = 0;
        while (!prime[x]) {
            if (x % p[idx] == 0) {
                ans[i]++;
                x /= p[idx];
            } else idx++;
        }
        ans[i]++;
    }

    int q, cases = 1;
    while (cin >> q) {
        if (q < 0) break;
        int idx = lower_bound(ans.begin(), ans.end(), q) - ans.begin();
        cout << "Case " << cases++ << ": ";
        if (ans[idx] == q) cout << idx << "!\n";
        else cout << "Not possible.\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
