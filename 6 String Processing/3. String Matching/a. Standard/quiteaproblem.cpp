#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 85;

string T, P;
int n, m, b[MAX_N];         // n = |T|, m = |P| b = back table

void kmpPreprocess() {                                // call this first
    int i = 0, j = -1; b[0] = -1;                     // starting values
    while (i < m) {                                   // pre-process P
        while ((j >= 0) && (P[i] != P[j])) j = b[j];  // different, reset j
        ++i; ++j;                                     // same, advance both
        b[i] = j;
    }
}

int kmpSearch() {                                       // similar as above
    int freq = 0;
    int i = 0, j = 0;                                   // starting values
    while (i < n) {                                     // search through T
        while ((j >= 0) && (T[i] != P[j])) j = b[j];    // if different, reset j
        ++i; ++j;                                       // if same, advance both
        if (j == m) {                                   // a match is found
            ++freq;
            // printf("P is found at index %d in T\n", i-j);
            j = b[j];                                   // prepare j for the next
        }
    }
    return freq;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    P = "problem";
    while (getline(cin, T)) {
        transform(T.begin(), T.end(), T.begin(), ::tolower);
        n = T.size();
        m = P.size();
        kmpPreprocess();
        if (kmpSearch()) cout << "yes\n";
        else cout << "no\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


