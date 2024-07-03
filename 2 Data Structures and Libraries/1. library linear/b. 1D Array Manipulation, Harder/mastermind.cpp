#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    vector<char> v1(n), v2(n); // v1 is the guess, v2 is the secret
    string tmp;
    cin >> tmp;
    for (int i = 0; i < n; i++) {
        v2[i] = tmp[i];
    }
    cin >> tmp;
    for (int i = 0; i < n; i++) {
        v1[i] = tmp[i];
    }

    int r = 0, s = 0;
    for (int i = 0; i < n; i++) {
        if (v1[i] == v2[i]) {
            v1[i] = '1'; // to avoid counting again
            v2[i] = '0'; // to avoid counting again
            r++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v1[i] == v2[j]) {
                v2[j] = '0'; // to avoid counting again
                s++;
                break;
            }
        }
    }

    cout << r << " " << s << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




