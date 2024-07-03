#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int N;
    while (cin >> N, N) {
        int D, M, Y, C;
        cin >> D >> M >> Y >> C;
        int start = C;
        tm currDay = {0, 0, 0, D, M-1, Y-1900};
        int sum = 0, sumDays = 0;
        for (int i = 1; i < N; i++) {
            cin >> D >> M >> Y >> C;
            tm nextDay = {0, 0, 0, D, M-1, Y-1900};
            int diff = (int) difftime(mktime(&nextDay), mktime(&currDay)) / 86400;
            if (diff == 1) {
                sumDays++;
                sum += C - start;
            }
            start = C;
            currDay = nextDay;
        }
        cout << sumDays << " " << sum << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}