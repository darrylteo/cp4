#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int start, end;
    cin >> start >> end;
    int clockwise = 0, anticlockwise = 0;
    if (start < end) {
        clockwise = end - start;
        anticlockwise = start + (360 - end);
    } else if (start > end) {
        clockwise = (360 - start) + end;
        anticlockwise = start - end;
    }
    if (clockwise <= anticlockwise) {
        cout << clockwise << endl;
    } else {
        cout << -anticlockwise << endl;
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
