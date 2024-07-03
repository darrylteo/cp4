#include <bits/stdc++.h>

using namespace std;

// next time should not calculate the odd until needed.
// just compare the ints directly rather than use struct for speed

struct number {
    int mod, original, odd;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int N, M;
    while (cin >> N >> M, N) {
        vector<number> numbers(N);
        for (int i = 0; i < N; i++) {
            cin >> numbers[i].original;
            numbers[i].mod = numbers[i].original % M;
            numbers[i].odd = abs(numbers[i].original % 2);
        }

        sort(numbers.begin(), numbers.end(), [](number a, number b) {
            if (a.mod != b.mod) return a.mod < b.mod;
            if (a.odd != b.odd) return a.odd > b.odd;
            if (a.odd) return a.original > b.original;
            return a.original < b.original;
        });

        cout << N << " " << M << endl;
        for (int i = 0; i < N; i++) {
            cout << numbers[i].original << endl;
        }
    }
    cout << 0 << " " << 0 << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
