#include <bits/stdc++.h>

using namespace std;

// arithmetic progression
// note in the auto rounding down of int in cpp, but we know AP is always an integer
// so just multiply first

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--) {
        int caseNo, x;
        cin >> caseNo >> x;
        cout << caseNo << " " << (1+x)*x/2+x << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}