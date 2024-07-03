#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    int n;
    cin >> n;
    long long ans = 0;
    while (n--) {
        cin >> s;
        int a = s[s.size()-1] - '0';
        s.pop_back();
        int b = stoi(s);
        ans += pow(b, a);
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}