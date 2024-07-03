#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Case " << i << ": ";
        string s = "-";
        string tmp;
        cin >> tmp;
        s += tmp + "--"; // you can safely check last tile +2
        int burger = 0;
        for (int j = 1; j <= tmp.size(); j++) {
            if (s[j] == '-' && s[j - 1] != 'S' && s[j + 1] != 'S' && s[j + 1] != 'B' && s[j + 2] != 'B') {
                burger++;
            }
        }
        cout << burger << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




