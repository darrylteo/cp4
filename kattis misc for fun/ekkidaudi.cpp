#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2, ans;
    getline(cin, s1);
    int n1 = s1.find('|');
    getline(cin, s2);
    int n2 = s2.find('|');
    ans += s1.substr(0, n1);
    ans += s2.substr(0, n2);
    ans += ' ';
    ans += s1.substr(n1 + 1);
    ans += s2.substr(n2 + 1);
    cout << ans << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
