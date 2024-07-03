#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string keyPress[1000];
    keyPress['a'] = "2";
    keyPress['b'] = "22";
    keyPress['c'] = "222";
    keyPress['d'] = "3";
    keyPress['e'] = "33";
    keyPress['f'] = "333";
    keyPress['g'] = "4";
    keyPress['h'] = "44";
    keyPress['i'] = "444";
    keyPress['j'] = "5";
    keyPress['k'] = "55";
    keyPress['l'] = "555";
    keyPress['m'] = "6";
    keyPress['n'] = "66";
    keyPress['o'] = "666";
    keyPress['p'] = "7";
    keyPress['q'] = "77";
    keyPress['r'] = "777";
    keyPress['s'] = "7777";
    keyPress['t'] = "8";
    keyPress['u'] = "88";
    keyPress['v'] = "888";
    keyPress['w'] = "9";
    keyPress['x'] = "99";
    keyPress['y'] = "999";
    keyPress['z'] = "9999";
    keyPress[' '] = "0";


    int n;
    cin >> n;
    string clear2;
    getline(cin, clear2); // best way to clear buffer after cin >> n
    for (int i = 0; i < n; i++) {
        string ans;
        string s;
        getline(cin, s);
        for (int j = 0; j < s.size(); j++) {
            if (j == 0) {
                ans += keyPress[s[j]];
            } else {
                if (keyPress[s[j]][0] == keyPress[s[j - 1]][0]) { // safe to use [0] because all the same
                    ans += " ";
                }
                ans += keyPress[s[j]];
            }
        }

        cout << "Case #" << i + 1 << ": " << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


