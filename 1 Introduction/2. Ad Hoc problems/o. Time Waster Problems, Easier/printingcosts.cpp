#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // important to note that the question information is in ASCII order
    vector<int> costs {0, 9, 6, 24,29,22,
                       24,3, 12,12,17,13,
                       7, 7, 4, 10,22,19,
                       22,23,21,27,26,16,
                       23,26,8, 11,10,14,
                       10,15,32,24,29,20,
                       26,26,20,25,25,18,
                       18,21,16,28,25,26,
                       23,31,28,25,16,23,
                       19,26,18,14,22,18,
                       10,18,7, 8, 3, 23,
                       25,17,25,23,18,30,
                       21,15,20,21,16,22,
                       18,20,25,25,13,21,
                       17,17,13,19,13,24,
                       19,18,12,18,9};

    string buf;
    while (getline(cin, buf)){
        int sum = 0;
        for (int i = 0; i < buf.size(); i++){
            sum += costs[buf[i] - 32];
        }
        cout << sum << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}