#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int cs, ec;
        long long csTotal = 0, ecTotal = 0;
        cin >> cs >> ec;
        vi csArr(cs), ecArr(ec);
        for (int i = 0; i < cs; i++) {
            cin >> csArr[i];
            csTotal += csArr[i];
        }
        for (int i = 0; i < ec; i++) {
            cin >> ecArr[i];
            ecTotal += ecArr[i];
        }
        double csAvg = (double) csTotal / cs;
        double ecAvg = (double) ecTotal / ec;
        int count = 0;
        for (int i = 0; i < cs; i++) {
            if (csArr[i] < csAvg && csArr[i] > ecAvg) {
                count++;
            }
        }
        cout << count << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


