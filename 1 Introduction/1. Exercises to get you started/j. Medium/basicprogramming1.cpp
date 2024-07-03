#include <bits/stdc++.h>

using namespace std;

int N, t;
vector<int> A;
long long a = 0; // THIS WASTE 1H OF MY TIME!!! C++ INT MUST CAREFUL!!!

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> N >> t;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    switch (t) {
        case 1:
            cout << "7";
            break;
        case 2:
            if (A[0] > A[1]) {
                cout << "Bigger";
            } else if (A[0] == A[1]) {
                cout << "Equal";
            } else {
                cout << "Smaller";
            }
            break;
        case 3:
            sort(A.begin(), A.begin() + 3);
            cout << A[1];
            break;
        case 4:
            for (int i = 0; i < N; i++) {
                a += A[i];
            }
            cout << a;
            break;
        case 5:
            for (int i = 0; i < N; i++) {
                if (A[i] % 2 == 0) {
                    a += A[i];
                }
            }
            cout << a;
            break;
        case 6:
            for (int i = 0; i < A.size(); i++) {
                cout << (char) (A[i] % 26 + 97);
            }
            break;
        case 7:
            int i = 0;
            while (true) {
                if (i < 0 || i >= N) {
                    cout << "Out";
                    break;
                } else if (i == N - 1) {
                    cout << "Done";
                    break;
                } else if (A[i] == 0) {
                    cout << "Cyclic";
                    break;
                } else {
                    int temp = i;
                    i = A[i];
                    A[temp] = 0;
                }
            }
            break;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}