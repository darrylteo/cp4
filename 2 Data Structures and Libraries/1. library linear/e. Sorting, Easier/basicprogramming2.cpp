#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int N, t;
    cin >> N >> t;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    switch (t) {
        case 1: {
            sort(A.begin(), A.end());
            int l = 0, r = N - 1;
            while (l < r) {
                if (A[l] + A[r] == 7777) {
                    cout << "Yes";
                    return 0;
                } else if (A[l] + A[r] < 7777) l++;
                else r--;
            }
            cout << "No";
            return 0;
        }
        case 2:
            sort(A.begin(), A.end());
            for (int i = 0; i < N - 1; i++) {
                if (A[i] == A[i + 1]) {
                    cout << "Contains duplicate";
                    return 0;
                }
            }
            cout << "Unique";
            return 0;
        case 3: {
            sort(A.begin(), A.end());
            int count = 1;
            for (int i = 0; i < N - 1; i++) {
                if (A[i] == A[i + 1]) count++;
                else count = 1;
                if (count > N / 2) {
                    cout << A[i];
                    return 0;
                }
            }
            cout << -1;
            return 0;
        }
        case 4:
            if (N % 2 == 0) {
                nth_element(A.begin(), A.begin() + N / 2, A.end());
                nth_element(A.begin(), A.begin() + N / 2 - 1, A.end());
                cout << A[N / 2 - 1] << " " << A[N / 2];
            } else {
                nth_element(A.begin(), A.begin() + N / 2, A.end());
                cout << A[N / 2];
            }
            return 0;
        case 5:
            sort(A.begin(), A.end());
            for (int i = 0; i < N; i++) {
                if (A[i] >= 100 && A[i] <= 999) cout << A[i] << " ";
            }
            return 0;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




