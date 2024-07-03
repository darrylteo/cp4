#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

class SuffixArray {
private:
    vi RA;                                         // rank array

    void countingSort(int k) {                     // O(n)
        int maxi = max(300, n);                      // up to 255 ASCII chars
        vi c(maxi, 0);                               // clear frequency table
        for (int i = 0; i < n; ++i)                  // count the frequency
            ++c[i + k < n ? RA[i + k] : 0];                // of each integer rank
        for (int i = 0, sum = 0; i < maxi; ++i) {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }
        vi tempSA(n);
        for (int i = 0; i < n; ++i)                  // sort SA
            tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
        swap(SA, tempSA);                            // update SA
    }

    void constructSA() {                           // can go up to 400K chars
        SA.resize(n);
        iota(SA.begin(), SA.end(), 0);               // the initial SA
        RA.resize(n);
        for (int i = 0; i < n; ++i) RA[i] = T[i];    // initial rankings
        for (int k = 1; k < n; k <<= 1) {            // repeat log_2 n times
            // this is actually radix sort
            countingSort(k);                           // sort by 2nd item
            countingSort(0);                           // stable-sort by 1st item
            vi tempRA(n);
            int r = 0;
            tempRA[SA[0]] = r;                         // re-ranking process
            for (int i = 1; i < n; ++i)                // compare adj suffixes
                tempRA[SA[i]] = // same pair => same rank r; otherwise, increase r
                        ((RA[SA[i]] == RA[SA[i - 1]]) && (RA[SA[i] + k] == RA[SA[i - 1] + k])) ?
                        r : ++r;
            swap(RA, tempRA);                          // update RA
            if (RA[SA[n - 1]] == n - 1) break;             // nice optimization
        }
    }

    void computeLCP() {
        vi Phi(n);
        vi PLCP(n);
        PLCP.resize(n);
        Phi[SA[0]] = -1;                             // default value
        for (int i = 1; i < n; ++i)                  // compute Phi in O(n)
            Phi[SA[i]] = SA[i - 1];                      // remember prev suffix
        for (int i = 0, L = 0; i < n; ++i) {         // compute PLCP in O(n)
            if (Phi[i] == -1) {
                PLCP[i] = 0;
                continue;
            } // special case
            while ((i + L < n) && (Phi[i] + L < n) && (T[i + L] == T[Phi[i] + L]))
                ++L;                                     // L incr max n times
            PLCP[i] = L;
            L = max(L - 1, 0);                           // L dec max n times
        }
        LCP.resize(n);
        for (int i = 0; i < n; ++i)                  // compute LCP in O(n)
            LCP[i] = PLCP[SA[i]];                      // restore PLCP
    }

public:
    const char *T;                                 // the input string
    const int n;                                   // the length of T
    vi SA;                                         // Suffix Array
    vi LCP;                                        // of adj sorted suffixes

    SuffixArray(const char *initialT, const int _n) : T(initialT), n(_n) {
        constructSA();                               // O(n log n)
        computeLCP();                                // O(n)
    }

    ii stringMatching(const char *P) {             // in O(m log n)
        int m = (int) strlen(P);                      // usually, m < n
        int lo = 0, hi = n - 1;                        // range = [0..n-1]
        while (lo < hi) {                            // find lower bound
            int mid = (lo + hi) / 2;                     // this is round down
            int res = strncmp(T + SA[mid], P, m);        // P in suffix SA[mid]?
            (res >= 0) ? hi = mid : lo = mid + 1;        // notice the >= sign
        }
        if (strncmp(T + SA[lo], P, m) != 0) return {-1, -1}; // if not found
        ii ans;
        ans.first = lo;
        hi = n - 1;                                    // range = [lo..n-1]
        while (lo < hi) {                            // now find upper bound
            int mid = (lo + hi) / 2;
            int res = strncmp(T + SA[mid], P, m);
            (res > 0) ? hi = mid : lo = mid + 1;         // notice the > sign
        }
        if (strncmp(T + SA[hi], P, m) != 0) --hi;      // special case
        ans.second = hi;
        return ans;                                  // returns (lb, ub)
    }                                              // where P is found

    ii LRS() {                                     // (LRS length, index)
        int idx = 0, maxLCP = -1;
        for (int i = 1; i < n; ++i)                  // O(n), start from i = 1
            if (LCP[i] > maxLCP)
                maxLCP = LCP[i], idx = i;
        return {maxLCP, idx};
    }

    ii LCS(int split_idx) {                        // (LCS length, index)
        int idx = 0, maxLCP = -1;
        for (int i = 1; i < n; ++i) {                // O(n), start from i = 1
            // if suffix SA[i] and suffix SA[i-1] came from the same string, skip
            if ((SA[i] < split_idx) == (SA[i - 1] < split_idx)) continue;
            if (LCP[i] > maxLCP)
                maxLCP = LCP[i], idx = i;
        }
        return {maxLCP, idx};
    }

    vi computeInverseSA() {
        vi inverseSA(n);
        for (int i = 0; i < n; ++i) {
            inverseSA[SA[i]] = i;
        }
        return inverseSA;
    }
};

class SparseTable {                              // OOP style
private:
    vi A, P2, L2;
    vector<vi> SpT;                                // the Sparse Table
public:
    SparseTable() {}                               // default constructor

    SparseTable(vi &initialA) {                    // pre-processing routine
        A = initialA;
        int n = (int)A.size();
        int L2_n = (int)log2(n)+1;
        P2.assign(L2_n+1, 0);
        L2.assign((1<<L2_n)+1, 0);
        for (int i = 0; i <= L2_n; ++i) {
            P2[i] = (1<<i);                            // to speed up 2^i
            L2[(1<<i)] = i;                            // to speed up log_2(i)
        }
        for (int i = 2; i < P2[L2_n]; ++i)
            if (L2[i] == 0)
                L2[i] = L2[i-1];                         // to fill in the blanks

        // the initialization phase
        SpT = vector<vi>(L2[n]+1, vi(n));
        for (int j = 0; j < n; ++j)
            SpT[0][j] = j;                             // RMQ of sub array [j..j]

        // the two nested loops below have overall time complexity = O(n log n)
        for (int i = 1; P2[i] <= n; ++i)             // for all i s.t. 2^i <= n
            for (int j = 0; j+P2[i]-1 < n; ++j) {      // for all valid j
                int x = SpT[i-1][j];                     // [j..j+2^(i-1)-1]
                int y = SpT[i-1][j+P2[i-1]];             // [j+2^(i-1)..j+2^i-1]
                SpT[i][j] = A[x] <= A[y] ? x : y;
            }
    }

    int RMQ(int i, int j) {
        int k = L2[j-i+1];                           // 2^k <= (j-i+1)
        int x = SpT[k][i];                           // covers [i..i+2^k-1]
        int y = SpT[k][j-P2[k]+1];                   // covers [j-2^k+1..j]
        return A[x] <= A[y] ? x : y;
    }
};

const int MAX_N = 450010;                        // can go up to 450K chars

char T[MAX_N];
char P[MAX_N];
char LRS_ans[MAX_N];
char LCS_ans[MAX_N];

// above from cp4 code ch6 and ch9 and ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_6_String_Processing/Suffix_Array/kattis_automatictrading.cpp
// kinda weirdchamp asking us to use sparse table when it is not taught yet >:(
// book describes Computing Longest Common Prefix Between Consecutive Sorted Suffixes
// so if not consecutive, we need to find the min LCP between the two suffixes

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> T;
    int n = (int) strlen(T);                        // count n
    T[n++] = '$';                                  // add terminating symbol
    SuffixArray S(T, n);                           // construct SA+LCP

    printf("T = '%s'\n", T);
    printf(" i SA[i] LCP[i]   Suffix SA[i]\n");
    for (int i = 0; i < n; ++i)
        printf("%2d    %2d    %2d    %s\n", i, S.SA[i], S.LCP[i], T + S.SA[i]);

    vi inverseSA = S.computeInverseSA();
    SparseTable ST(S.LCP);

    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l = inverseSA[l];
        r = inverseSA[r];
        if (l > r) swap(l, r);
        int idx = ST.RMQ(l+1, r); // this version of RMQ returns the index
        cout << S.LCP[idx] << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}