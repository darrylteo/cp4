#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

//1: 2	= 2 x 1
//2: 4	= 2 x 2
//3: 6	= 3 x 2
//4: 9	= 3 x 3
//5: 12	= 4 x 3
//6: 16	= 4 x 4
//7: 20	= 5 x 4
//8: 25	= 5 x 5
//9: 30	= 6 x 5
//10:36 = 6 x 6
//11:42	= 7 x 6
//12:49	= 7 x 7

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n;
    cin >> n;
    if (n == 1) cout << 2 << '\n';
    else if (n % 2 == 0) cout << (n / 2 + 1) * (n / 2 + 1) << '\n';
    else cout << (n / 2 + 1) * (n / 2 + 2) << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


