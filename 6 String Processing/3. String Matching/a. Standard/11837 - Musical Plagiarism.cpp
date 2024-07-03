#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100005;

vector<int> T, P; // T = text, P = pattern
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
            // printf("P is found at index %d in T\n", i-j);
            j = b[j];                                   // prepare j for the next
        }
    }
    return freq;
}

// follow book hint to transform into distances. notes from the picture in problem statement
const unordered_multimap<string, int> noteToIndex = {
        {"B#", 0},
        {"C",  0},
        {"C#", 1},
        {"Db", 1},
        {"D",  2},
        {"D#", 3},
        {"Eb", 3},
        {"E",  4},
        {"Fb", 4},
        {"E#", 5},
        {"F",  5},
        {"F#", 6},
        {"Gb", 6},
        {"G",  7},
        {"G#", 8},
        {"Ab", 8},
        {"A",  9},
        {"A#", 10},
        {"Bb", 10},
        {"B",  11},
        {"Cb", 11}
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y;
    while (cin >> x >> y, x) {
        if (y == 1) {
            cout << "S\n";
            for (int i = 0; i < x + y; i++) {
                string s;
                cin >> s;
            }
            continue;
        } else if (x == 1) {
            cout << "N\n";
            for (int i = 0; i < x + y; i++) {
                string s;
                cin >> s;
            }
            continue;
        }

        T.clear();
        P.clear();
        T.resize(x - 1);
        P.resize(y - 1);
        string curr, prev;
        cin >> prev;
        for (int i = 0; i < x - 1; i++) {
            cin >> curr;
            T[i] = (noteToIndex.find(curr)->second - noteToIndex.find(prev)->second + 12) % 12;
            prev = curr;
        }
        cin >> prev;
        for (int i = 0; i < y - 1; i++) {
            cin >> curr;
            P[i] = (noteToIndex.find(curr)->second - noteToIndex.find(prev)->second + 12) % 12;
            prev = curr;
        }
        n = T.size();
        m = P.size();
        kmpPreprocess();
        cout << (kmpSearch() > 0 ? "S" : "N") << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


