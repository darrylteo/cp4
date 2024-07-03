#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// using nPerms = n! / (n1! * n2! * ... * nk!)
// to remove repeats, divide by the factorial of the number of repeats
// p.second * nPerms / n gives how many times the number p.first will appear

// my example was, with 2 appearing in each pos 3 times. same for 8.
// 2 2 8 8
// 2 8 2 8
// 2 8 8 2
// 8 2 2 8
// 8 2 8 2
// 8 8 2 2
// nPerms = 4! / (2! * 2!) = 6
// m[i]/n is the ratio of appearance. quite high school style permutations and combinations rather than coding.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<ull> facts(13), pows(13);
    facts[0] = 1;
    pows[0] = 1;
    for (int i = 1; i <= 12; i++) {
        facts[i] = facts[i - 1] * i;
        pows[i] = pow(10, i);
    }

    int n;
    while (cin >> n, n) {
        map<ull, ull> m;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            m[x]++;
        }
        ull nPerms = facts[n];
        for (auto &p : m) {
            nPerms /= facts[p.second];
        }

        ull ans = 0;
        for (auto &p : m) {
            for (int i = 0; i < n; i++) {
                ans += p.first * pows[i] * p.second * nPerms / n;
            }
        }

        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}