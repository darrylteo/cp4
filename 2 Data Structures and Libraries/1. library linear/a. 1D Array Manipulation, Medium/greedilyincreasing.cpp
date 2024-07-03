#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int N, myMax = 0;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x > myMax) {
            myMax = x;
            A.push_back(x);
        }
    }
    cout << A.size() << endl;
    for (int i = 0; i < A.size() - 1; ++i) {
        cout << A[i] << " ";
    }
    cout << A[A.size() - 1] << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




