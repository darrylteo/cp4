#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int pieces[6] = {1, 1, 2, 2, 2, 8};
    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        cout << pieces[i] - x << " ";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




