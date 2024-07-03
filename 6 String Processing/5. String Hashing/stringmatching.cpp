#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000005;

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

int kmpSearch() {                                       // similar as above
    int freq = 0;
    int i = 0, j = 0;                                   // starting values
    while (i < n) {                                     // search through T
        while ((j >= 0) && (T[i] != P[j])) j = b[j];    // if different, reset j
        ++i;
        ++j;                                       // if same, advance both
        if (j == m) {                                   // a match is found
            ++freq;
            cout << i - j << ' ';
            j = b[j];                                   // prepare j for the next
        }
    }
    return freq;
}

// direct application. template code from book

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, P) && getline(cin, T)) {
        m = P.size();
        n = T.size();
        kmpPreprocess();
        kmpSearch();
        cout << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


