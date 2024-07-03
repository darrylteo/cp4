#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 105;

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

    string buf;
    while (getline(cin, buf), buf != "0") {
        stringstream ss(buf);
        string patternOriginal;
        ss >> patternOriginal >> T;
        P = patternOriginal;
        n = T.size();
        m = P.size();
        kmpPreprocess();
        cout << kmpSearch() << " ";

        set<string> patternsDeleteOne;
        for (int i = 0; i < m; i++) {
            P = patternOriginal;
            P.erase(P.begin() + i);
            patternsDeleteOne.insert(P);
        }
        int p2 = 0;
        for (const string &pattern : patternsDeleteOne) {
            P = pattern;
            m = P.size();
            kmpPreprocess();
            p2 += kmpSearch();
        }
        cout << p2 << " ";

        set<string> patternsAddOne;
        string nucl = "ACGT";
        for (int i = 0; i <= m + 1; i++) { // plus 1 since previous time we used m was in the loop for deletion
            for (char c : nucl) {
                P = patternOriginal;
                P.insert(P.begin() + i, c);
                patternsAddOne.insert(P);
            }
        }
        int p3 = 0;
        for (const string &pattern : patternsAddOne) {
            P = pattern;
            m = P.size();
            kmpPreprocess();
            p3 += kmpSearch();
        }
        cout << p3 << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


