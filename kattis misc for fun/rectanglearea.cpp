#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double area = abs(x1 - x2) * abs(y1 - y2);
    cout << fixed << setprecision(10) << area << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


