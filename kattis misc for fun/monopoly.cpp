#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    vector<int> v;
    for (int i = 1; i < 7; ++i) {
        for (int j = 1; j < 7 ; ++j) {
            v.push_back(i + j);
        }
    }
    vector<int> sum;
    for (int i = 2; i < 13; ++i) {
        sum.push_back(count(v.begin(), v.end(), i));
    }

    double sumProb = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        sumProb += sum[x - 2] / 36.0; // since we started from 2
    }
    cout << sumProb << endl;



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
