#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 10000;
int prime[MAXN+5];
vector<int> p;

void sieve() {
    for (int i = 0; i <= MAXN; i++) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (prime[i] == 1) {
            for (int j = i * i; j <= MAXN; j += i) {
                prime[j] = 0;
            }
        }
    }
}

bool isPrime(ll N) { // good enough prime test
    if (N < MAXN) return prime[N]; // O(1) for small primes
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        if (N%p[i] == 0)
            return false;
    return true; // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

int ans = 0;
set<int> st;
string s;

inline void dfs(int curr, int mask) {
    if (st.find(curr) != st.end()) return;
    st.insert(curr);
    if (isPrime(curr)) {
        ans++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (mask & (1 << i)) {
            int next = curr * 10 + s[i] - '0';
            dfs(next, mask ^ (1 << i));
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    for (int i = 2; i <= MAXN; i++) {
        if (prime[i]) p.push_back(i);
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        ans = 0;
        st.clear();
        dfs(0, (1 << (s.size())) - 1);
        cout << ans << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
