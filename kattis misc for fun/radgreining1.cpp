#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, start;
    cin >> n >> m;
    string s(n, '?'), ss;
    for (int i = 0; i < m; i++) {
        cin >> start >> ss;
        start--;
        for (int k = 0; k < ss.size(); k++) {
            if (s[start + k] != '?' && s[start + k] != ss[k]) {
                cout << "Villa\n";
                return 0;
            }
            s[start + k] = ss[k];
        }
    }
    cout << s << endl;
    
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
