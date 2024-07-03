#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int a, b;
    cin >> a >> b;
    vector<int> sum;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            sum.push_back(i + j);
        }
    }
    vector<int> freq(41);
    for (int i = 0; i < sum.size(); ++i) {
        freq[sum[i]]++;
    }
    int max = *max_element(freq.begin(), freq.end());
    for (int i = 0; i < freq.size(); ++i) {
        if (freq[i] == max) {
            cout << i << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
