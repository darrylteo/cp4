#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// build up all 1111 using (ans * 10 + 1) then mod n

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n;
    while (cin >> n) {
        ull power = 1, ans = 1;
        while (ans % n != 0) {
            ans = (ans * 10 + 1) % n;
            power++;
        }
        cout << power << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


