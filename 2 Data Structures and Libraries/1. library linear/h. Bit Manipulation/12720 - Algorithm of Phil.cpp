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
    long long dec_value = 0;
    // Initializing base value to 1, i.e 2^0
    long long base = 1;

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

// Function to return the value of (str % k)
// https://www.geeksforgeeks.org/modulo-of-a-large-binary-string/
int getMod(string str, int n, int k) {

    // pwrTwo[i] will store ((2^i) % k)
    // we hypothesize 2^i%k = (2^(i-1)%k * 2 )%k for all i
    // can prove or just check 2 = 2^5%3 = (2^4%3 * 2 )% 3 = 2 ._.
    // 2^6%3 = (2^5%3 * 2 )% 3 = 1
    int pwrTwo[n];
    pwrTwo[0] = 1 % k;
    for (int i = 1; i < n; i++) {
        pwrTwo[i] = (pwrTwo[i - 1] * 2) % k;
    }

    // To store the result
    int res = 0;
    int i = 0, j = n - 1; // nothing special. we always start from the rightmost bit
    while (i < n) {

        // If current bit is 1
        if (str[j] == '1') {

            // Add the current power of 2
            res += (pwrTwo[i]);
            res %= k;
        }
        i++;
        j--;
    }
    return res;
}

// start here

string solve(string s) {
    string ans;
    string a, b;
    a = s.substr(0, s.size() / 2);
    b = s.substr(s.size() / 2);
    reverse(b.begin(), b.end()); // now end of b and a are the "middle" of the string
    while (!a.empty() && !b.empty()) {
        if (a.size() > b.size()) {
            ans += a[a.size() - 1];
            a.pop_back();
        } else if (a.size() < b.size()) {
            ans += b[b.size() - 1];
            b.pop_back();
        } else {
            if (a[a.size() - 1] > b[b.size() - 1]) {
                ans += a[a.size() - 1];
                a.pop_back();
            } else {
                ans += b[b.size() - 1];
                b.pop_back();
            }
        }

    }
    // put last digits
    if (!a.empty()) {
        ans += a[0];
    } else if (!b.empty()) {
        ans += b[0];
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";
        string s;
        cin >> s;
        string ans = solve(s);
        int ansMod = getMod(ans, ans.size(), 1000000007);
        cout << ansMod << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
