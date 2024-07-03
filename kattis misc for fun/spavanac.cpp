#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int hh, mm;
    cin >> hh >> mm;
    if (hh == 0) {
        hh = 24;
    }
    if (mm < 45) {
        mm += 60;
        hh--;
    }
    mm -= 45;
    cout << hh << " " << mm << "\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

