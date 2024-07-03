#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // eg for RSTEEOTCP
    // print index 3 6 9 2 5 8 1 4 7
    // 3*j + i (-1 for 0 index) where 3 is the size of N*N matrix

    int n;
    cin >> n;
    while (n--){
        string s, ans;
        cin >> s;
        int len = sqrt(s.length());
        for (int i = len; i > 0; i--){
            for (int j = 0; j < len; j++){
                ans += s[i + j*len-1];
            }
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


