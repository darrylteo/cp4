#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200005;

string T, P;
int n, m, b[MAX_N];         // n = |T|, m = |P| b = back table

void kmpPreprocess() {                                // call this first
    int i = 0, j = -1;
    b[0] = -1;                     // starting values
    while (i < m) {                                   // pre-process P
        while ((j >= 0) && (P[i] != P[j])) j = b[j];  // different, reset j
        ++i;
        ++j;                                     // same, advance both
        b[i] = j;
    }
}

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// kmp pre-process can find out the longest suffix that is also a prefix of the string

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string tmp;
    while (cin >> tmp) {
        if (isPalindrome(tmp)) {
            cout << tmp << endl;
            continue;
        }
        reverse(tmp.begin(), tmp.end());
        P = tmp;
        reverse(tmp.begin(), tmp.end());
        P += tmp;
        m = P.size();
        kmpPreprocess();
        string prefix = tmp.substr(0, m/2 - b[m]);
        cout << prefix;
        string mid = tmp.substr(m/2 - b[m], b[m]);
        cout << mid;
        reverse(prefix.begin(), prefix.end());
        cout << prefix << endl;
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


