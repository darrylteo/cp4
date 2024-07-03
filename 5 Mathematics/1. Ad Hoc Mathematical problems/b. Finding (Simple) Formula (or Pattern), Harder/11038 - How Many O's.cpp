#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll countZeroes(ll n) {
    if (n < 0) return 0;
    ll counter = 1, self = 0, sum = 1;
    while (n) {
        if (n % 10) sum += n / 10 * counter;
        else sum += (n / 10 - 1) * counter + self + 1;
        self += n % 10 * counter;
        counter *= 10;
        n /= 10;
    }
    return sum;
}

// ref: https://github.com/morris821028/UVa/blob/master/volume110/11038%20-%20How%20Many%20O's.cpp
// explanation of above method: https://algorithmist.com/wiki/UVa_11038_-_How_Many_O%27s%3F

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n, m;
    while (cin >> n >> m) {
        if (n < 0) break;
        cout << countZeroes(m) - countZeroes(n - 1) << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


