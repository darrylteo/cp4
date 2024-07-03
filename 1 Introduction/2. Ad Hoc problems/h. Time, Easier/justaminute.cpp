#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int N;
    double M, S, sumM = 0, sumS = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M >> S;
        sumM += M;
        sumS += S;
    }
    double mean = sumS / 60 / sumM;
    if (mean <= 1) cout << "measurement error" << endl;
    else cout << fixed << setprecision(9) << mean << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}