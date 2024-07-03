#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s;
    cin >> s;
    int cnt=0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] != 'P' && i%3 == 0) cnt++;
        if (s[i] != 'E' && i%3 == 1) cnt++;
        if (s[i] != 'R' && i%3 == 2) cnt++;
    }
    cout << cnt << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


