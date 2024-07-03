#include <bits/stdc++.h>

using namespace std;

typedef tuple<double, double, int> ddi;             // (real size, original size, number of cuts)

// feels like the hint is in sample input output
// 2000 3000 4000 need 0.99 means cut 1, cut 2, cut 3 so total 6 cuts then all will be 1000 length
// second input also 1000 cut 1, 1400 cut 2.
// seems that cutting half half half is wrong.. for example size 4 u cut half and each half cut half, is same as 3 cuts. u cant stack them to cut twice only

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double T, minLength = 1e9;
    int N;
    cin >> T >> N;
    priority_queue<ddi> pq;
    for (int i = 0; i < N; i++) {
        double x;
        cin >> x;
        minLength = min(minLength, x);
        pq.emplace(x, x, 0);
    }
    int numCuts = 0;
    while (minLength/get<0>(pq.top()) < T) {
        numCuts++;
        auto [realSize, originalSize, cuts] = pq.top();
        pq.pop();
        pq.emplace(originalSize/(cuts+2), originalSize, cuts+1);
        minLength = min(minLength, originalSize/(cuts+2));
    }
    cout << numCuts << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
