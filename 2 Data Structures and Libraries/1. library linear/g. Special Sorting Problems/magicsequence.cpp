#include <bits/stdc++.h>

using namespace std;

// radix from https://www.geeksforgeeks.org/radix-sort/
// bitwise tricks from https://github.com/stevenhalim/cpbook-code/blob/master/ch2/lineards/bit_manipulation.cpp
// more bitwise https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_2_Data_Structures/Linear_DS_with_Built-in_Libraries/kattis_magic_sequence.cpp
// solved in 1.88s 11 Nov 2023

long long maxVal;
// idx is to save operations
// we can recycle this array (save time since we will update all indexes that will be used)
vector<long long> output(1000000), myIdx(1000000);

// base 2 for fast modulo
int myBaseLog2 = 10;
int myBase = pow(2, myBaseLog2);

void radixsort(vector<long long> &arr, long long n)
{
    for (long long exp = 0; exp < ((log(maxVal))/(log(myBase))); exp++) {
        // Output array
        vector<long long> count(myBase);
        int i;

        for (i = 0; i < n; i++)
            myIdx[i] = (arr[i] >> (exp * myBaseLog2)) & (myBase - 1);
        for (i = 0; i < n; i++)
            count[myIdx[i]]++;
        for (i = 1; i < myBase; i++)
            count[i] += count[i - 1];
        for (i = n - 1; i >= 0; i--) {
            output[count[myIdx[i]] - 1] = arr[i];
            count[myIdx[i]]--;
        }
        arr = output;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        // get data
        long long N, A, B, C, X, Y;
        cin >> N >> A >> B >> C >> X >> Y;
        vector<long long> S(N);
        S[0] = A;
        maxVal = A;
        for (int i = 1; i < N; i++) {
            S[i] = (S[i - 1] * B + A) % C;
            maxVal = max(maxVal, S[i]);
        }
        // sort here
        radixsort(S, N);
        // print hash value V
        long long V = 0;
        for (int i = 0; i < N; i++) {
            V = (V * X + S[i]) % Y;
        }
        cout << V << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
