#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    long long sqrtn = sqrt(n);
    set<long long> divisors;
    for (long long i = 1; i <= sqrtn; i++) {
        if (n % i == 0) {
            divisors.insert(i - 1);
            divisors.insert(n / i - 1);
        }
    }
    for (auto &i : divisors) {
        cout << i << " ";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
