#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// skipping even n, num pattern - num[i]-num[i-1] - num[i]-3*num[i-1]
//1
//3	    2	0
//11	8	3
//41	30	8
//153	112	30
//571	418	112

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<ull> v(20);
    v[0] = 1;
    v[1] = 3;
    v[2] = 11;
    for (int i = 3; i < 20; i++) {
        v[i] = 4 * v[i - 1] - v[i - 2];
    }

    int n;
    while (cin >> n, n!=-1) {
        if (n%2) {
            cout << 0 << '\n';
        } else {
            cout << v[n/2] << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


