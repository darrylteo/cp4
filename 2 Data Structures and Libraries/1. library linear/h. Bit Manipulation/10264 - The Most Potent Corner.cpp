#include <bits/stdc++.h>

using namespace std;

// we will use some standard code from https://github.com/stevenhalim/cpbook-code/blob/master/ch2/lineards/bit_manipulation.cpp

#define isOn(S, j) (S & (1<<j))
#define setBit(S, j) (S |= (1<<j))
#define clearBit(S, j) (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1<<n)-1)

#define modulo(S, N) ((S) & (N-1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S-1)))
#define nearestPowerOfTwo(S) (1<<lround(log2(S)))
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
#define turnOffLastConsecutiveBits(S) ((S) & (S+1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S-1))

long long binToDeci(const string &n) {
    string num = n;
    int dec_value = 0;
    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base <<= 1;
    }
    return dec_value;
}

string deciToBin(long long num) {
    string str;
    while (num) {
        if (num & 1) // 1
            str += '1';
        else // 0
            str += '0';
        num >>= 1; // Right Shift by 1
    }
    reverse(str.begin(), str.end());
    return str;
}

// start here
// similar to grey codes, using the "at most" 1 bit shift trick
// for each corner index, e.g. 100, we get all neighbours as:
// 001 ^ 100 = 101
// 010 ^ 100 = 110
// 100 ^ 100 = 000

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    while (cin >> n) {
        int size = 1 << n;
        vector<int> v(size);
        for(int i = 0; i < size; i++) {
            int x;
            cin >> x;
            v[i] = x;
        }
        vector<int> edgeScore(size);
        for (int i = 0; i < v.size(); i++) {
            int score = 0;
            for (int j = 0; j < n; j++) {
                int neighbour = i ^ (1 << j);
                score += v[neighbour];
            }
            edgeScore[i] = score;
        }
        int maxScore = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < n; j++) {
                int neighbour = i ^ (1 << j);
                maxScore = max(maxScore, edgeScore[i] + edgeScore[neighbour]);
            }
        }
        cout << maxScore << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
