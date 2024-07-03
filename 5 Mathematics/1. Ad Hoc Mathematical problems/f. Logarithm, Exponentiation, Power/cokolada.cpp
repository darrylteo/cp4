#include <bits/stdc++.h>

using namespace std;
#define LSOne(S) (S & (-S))

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

// thinking in terms of bits, to get a size 6 choco, we start from size 8, get 4, 2, 2. don't need break further since 6 = 110 (base 2)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, originalSize, smallestSize;
    cin >> n;
    originalSize = pow(2, ceil(log2(n)));
    cout << originalSize << ' ';
    smallestSize = LSOne(n);
    cout << ceil(log2(n)) - ceil(log2(smallestSize)) << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

