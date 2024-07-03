#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int L, D, X;
    cin >> L >> D >> X;
    for (int i = L; i <= D; i++) {
        int sum = 0;
        int temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == X) {
            cout << i << endl;
            break;
        }
    }
    for (int i = D; i >= L; i--) {
        int sum = 0;
        int temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == X) {
            cout << i << endl;
            break;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}