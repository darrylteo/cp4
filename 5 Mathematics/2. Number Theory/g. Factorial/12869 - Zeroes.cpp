#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// almost got tricked to count trailing zeroes.
// for example 5! = 120, 120 has 1 trailing zero
// but 24! = 620448401733239439360000, 24! has 4 trailing zeroes
// but 25! = 15511210043330985984000000, 25! has 6 trailing zeroes... theres a jump here that we normally include but no need for this qn.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            break;
        }
        ull aCnt = a/5, bCnt = b/5;
        cout << bCnt - aCnt + 1 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}