#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--) {
        int amplitude, frequency;
        cin >> amplitude >> frequency;
        while (frequency--) {
            for (int i = 1; i <= amplitude; i++) {
                for (int j = 1; j <= i; j++) {
                    cout << i;
                }
                cout << endl;
            }
            for (int i = amplitude - 1; i >= 1; i--) {
                for (int j = 1; j <= i; j++) {
                    cout << i;
                }
                cout << endl;
            }
            // this means no blank line after last test case
            // let code below handle it ...
            if (frequency != 0) {
                cout << endl;
            }
        }
        // to avoid printing extra blank line at the end
        if (n != 0) cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}