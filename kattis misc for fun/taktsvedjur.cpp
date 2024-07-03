#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, combo = 0, mult = 1, x;
    long long total = 0;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x != 0) {
            combo++;
            if (mult == 1 && combo == 2) {
                mult = 2;
                combo = 0;
            } else if (mult == 2 && combo == 4) {
                mult = 4;
                combo = 0;
            } else if (mult == 4 && combo == 8) {
                mult = 8;
                combo = 0;
            }
            total += mult * x;
        } else {
            mult = max(1, mult / 2);
            combo = 0;
        }
    }
    cout << total << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}