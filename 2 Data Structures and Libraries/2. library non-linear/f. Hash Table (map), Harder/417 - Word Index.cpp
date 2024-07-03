#include <bits/stdc++.h>

using namespace std;

// 1e5 combo, small enough for complete search

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, int> mp;
    int cnt = 1;
    // 1 letter
    for (char i = 'a'; i <= 'z'; i++) {
        string s = "";
        s += i;
        mp[s] = cnt++;
    }
    // 2 letter
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = i + 1; j <= 'z'; j++) {
            string s = "";
            s += i;
            s += j;
            mp[s] = cnt++;
        }
    }
    // 3 letter
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = i + 1; j <= 'z'; j++) {
            for (char k = j + 1; k <= 'z'; k++) {
                string s = "";
                s += i;
                s += j;
                s += k;
                mp[s] = cnt++;
            }
        }
    }
    // 4 letter
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = i + 1; j <= 'z'; j++) {
            for (char k = j + 1; k <= 'z'; k++) {
                for (char l = k + 1; l <= 'z'; l++) {
                    string s = "";
                    s += i;
                    s += j;
                    s += k;
                    s += l;
                    mp[s] = cnt++;
                }
            }
        }
    }
    // 5 letter
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = i + 1; j <= 'z'; j++) {
            for (char k = j + 1; k <= 'z'; k++) {
                for (char l = k + 1; l <= 'z'; l++) {
                    for (char m = l + 1; m <= 'z'; m++) {
                        string s = "";
                        s += i;
                        s += j;
                        s += k;
                        s += l;
                        s += m;
                        mp[s] = cnt++;
                    }
                }
            }
        }
    }

    string s;
    while (cin >> s) {
        cout << mp[s] << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
