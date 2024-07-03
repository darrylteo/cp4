#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int C, n, exit, enter, wait, total = 0;
    cin >> C >> n;
    while (n--){
        cin >> exit >> enter >> wait;
        if (exit > total || total - exit + enter > C){
            cout << "impossible" << endl;
            return 0;
        }
        total = total - exit + enter;
        if (total < C && wait > 0){
            cout << "impossible" << endl;
            return 0;
        }
    }

    // check last station
    if (total > 0){
        cout << "impossible" << endl;
        return 0;
    }
    if (wait > 0){
        cout << "impossible" << endl;
        return 0;
    }

    // ok
    cout << "possible" << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
