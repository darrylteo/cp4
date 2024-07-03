#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int v, n;
    cin >> v >> n;
    while (n--) {
        string s;
        int k;
        cin >> s >> k;
        if (k >= v) cout << s << " opin" << endl;
        else cout << s << " lokud" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




