#include <bits/stdc++.h>

using namespace std;

//    _
//   | |
//   | |
//   |_|_
//     |

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> v(4);
    for (int &i : v) cin >> i;
    sort(v.begin(), v.end());
    cout << v[0] * v[2] << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
