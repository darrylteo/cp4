#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000005;
int numDiffPFarr[MAX_N+10] = {0};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 2; i <= MAX_N; ++i)
        if (numDiffPFarr[i] == 0) // i is a prime number
            for (int j = i; j <= MAX_N; j += i)
                ++numDiffPFarr[j]; // j is a multiple of i


    int n;
    while (cin >> n, n) {
        cout << n << " : " << numDiffPFarr[n] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}