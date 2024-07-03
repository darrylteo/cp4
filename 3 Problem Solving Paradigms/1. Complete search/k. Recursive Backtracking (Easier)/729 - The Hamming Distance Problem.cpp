#include <bits/stdc++.h>

using namespace std;

// recently reading this trick https://graphics.stanford.edu/~seander/bithacks.html#NextBitPermutation
// probably a simple putting 1 and 0 into vector and next_permutation should work too

void printDecToBinary(unsigned int n, int size) {
    string str;
    while (n) {
        if (n & 1) {
            str += '1';
        } else {
            str += '0';
        }
        n >>= 1;
    }
    reverse(str.begin(), str.end());
    for (int i = 0; i < size - str.size(); ++i) {
        cout << '0';
    }
    cout << str << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;

        unsigned int v = 0; // current permutation of bits
        unsigned int w = 0; // next permutation of bits
        unsigned int largest = 0; // largest permutation of bits

        // generate start position
        for (int i = 0; i < y; ++i) {
            v |= 1 << i;
        }
        // generate end position. from example, in bits, v = 11. largest = 1100
        largest = v;
        for (int i = 0; i < x - y; ++i) {
            largest <<= 1;
        }

        if (v == largest) {
            printDecToBinary(v, x);
            if (n) cout << endl;
            continue;
        }

        printDecToBinary(v, x);
        while (w < largest) {
            unsigned int t = v | (v - 1); // t gets v's least significant 0 bits set to 1
            // Next set to 1 the most significant bit to change,
            // set to 0 the least significant ones, and add the necessary 1 bits.
            w = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
            v = w;
            printDecToBinary(w, x);
        }

        if (n) cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

