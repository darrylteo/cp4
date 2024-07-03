#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// ref: https://github.com/jfrbr/UVa_online_judge/blob/master/1224.cpp

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // if expand by 1, can put a tall block. if expand by 2, can put 2 horizontal blocks or square. don't double count tall blocks. it would be included in the i-1 case already
    vector<ull> dp1(50), dp2(50);
    dp1[0] = 1;
    dp1[1] = 1;
    for (int i = 2; i < 32; i++) {
        dp1[i] = dp1[i - 1] + 2 * dp1[i - 2];
    }

    // counting symmetric cases
    // if expand by 2, tall block at sides. if expand by 4, either square at sides or 2 horizontal blocks at sides
    dp2[0] = 1;
    dp2[1] = 1;
    dp2[2] = 3;
    dp2[3] = 1;
    for (int i = 4; i < 32; i++) {
        dp2[i] = dp2[i - 2] + 2 * dp2[i - 4];
    }

    // need draw diagram for 4 then easier see
    // you should get 5 symmetric cases for n = 4
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << (dp1[n] + dp2[n])/2 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


