#include <bits/stdc++.h>

using namespace std;

vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n/i) {
                divisors.push_back(n/i);
            }
        }
    }
    divisors.push_back(n);
    return divisors;
}

// clue say differences of 2 numbers.
// a mod M = b mod M = x implies a-b mod M = 0
// so gcd of the differences is M.
// then we can get all divisors, excl 1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int gg = 0; // gcd 0 and any number is the number itself
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            gg = __gcd(gg, abs(A[i] - A[j]));
        }
    }
    vector<int> divisors = getDivisors(gg);
    for (int i : divisors) cout << i << " ";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
