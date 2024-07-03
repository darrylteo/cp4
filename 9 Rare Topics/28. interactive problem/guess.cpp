#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    int l = 1, r = 1000;
    while (true) {
        int mid = (l + r) / 2;
        cout << mid << endl << flush;
        cin >> s;
        if (s == "correct") break;
        else if (s == "lower") r = mid - 1;
        else l = mid + 1;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
