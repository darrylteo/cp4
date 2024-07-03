#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--) {
        set<string> s;
        int x;
        cin >> x;
        while (x--) {
            string str;
            cin >> str;
            s.insert(str);
        }
        cout << s.size() << endl;
    }




    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
