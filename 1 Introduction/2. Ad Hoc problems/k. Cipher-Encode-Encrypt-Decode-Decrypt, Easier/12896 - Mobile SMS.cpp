#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    const char T[][6]={" ",".,?\"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    int t;
    cin >> t;
    while (t--){
        vector<int> keys, times;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            keys.push_back(x);
        }
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            times.push_back(x);
        }

        string ans;
        for (int i = 0; i < n; ++i) {
            ans += T[keys[i]][times[i]-1];
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


