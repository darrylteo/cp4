#include <bits/stdc++.h>

using namespace std;

// almost did simulation but this guy got elegant solution
// ref: https://github.com/isanchez-aguilar/UVa-Solutions/blob/master/11130%20-%20Billiard%20bounces.cpp

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, v, A, s;
    while (cin >> a >> b >> v >> A >> s, a || b || v || A || s) {
        // Distances covered in x and y along the s seconds plus the half of table.
        int distanceY = (v * s * sin(A * PI / 180.0) + b) / 2;
        int distanceX = (v * s * cos(A * PI / 180.0) + a) / 2;
        // Times it traversed in x and y the vertical and horizontal distance.
        cout << distanceX / a << " " << distanceY / b << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

