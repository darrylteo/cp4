#include <bits/stdc++.h>

using namespace std;

bool complement = false, transpose = false;
int w;
void command1(vector<vector<int>> &AM, vector<vector<int>> &AMT, vector<vector<int>> &AMC, vector<vector<int>> &AMCT) {

    for (auto &i: AM) {
        i.emplace_back(w);
    }
    AM.emplace_back(AM[0].size(), w);
    for (auto &i: AMT) {
        i.emplace_back(w);
    }
    AMT.emplace_back(AMT[0].size(), w);
    for (auto &i: AMC) {
        i.emplace_back(!w);
    }
    AMC.emplace_back(AMT[0].size(), !w);
    for (auto &i: AMCT) {
        i.emplace_back(!w);
    }
    AMCT.emplace_back(AMCT[0].size(), !w);
}

void command2(vector<vector<int>> &AM, vector<vector<int>> &AMT, vector<vector<int>> &AMC, vector<vector<int>> &AMCT, int A, int B) {
    AM[A][B] = !w;
    AMT[B][A] = !w;
    AMC[A][B] = w;
    AMCT[B][A] = w;
}

void command3(vector<vector<int>> &AM, vector<vector<int>> &AMT, vector<vector<int>> &AMC, vector<vector<int>> &AMCT, int A) {
    for (int i = 0; i < AM.size(); ++i) {
        AM[i][A] = w;
        AM[A][i] = w;
    }
    for (int i = 0; i < AMT.size(); ++i) {
        AMT[i][A] = w;
        AMT[A][i] = w;
    }
    for (int i = 0; i < AMC.size(); ++i) {
        AMC[i][A] = !w;
        AMC[A][i] = !w;
    }
    for (int i = 0; i < AMCT.size(); ++i) {
        AMCT[i][A] = !w;
        AMCT[A][i] = !w;
    }
}

void command4(vector<vector<int>> &AM, vector<vector<int>> &AMT, vector<vector<int>> &AMC, vector<vector<int>> &AMCT, int A, int B) {
    AM[A][B] = w;
    AMT[B][A] = w;
    AMC[A][B] = !w;
    AMCT[B][A] = !w;
}

void myPrint(vector<vector<int>> &AL) {
    cout << AL.size() << endl;
    for (int i = 0; i < AL.size(); ++i) {
        cout << AL[i].size() << " ";
        long long hash = 0, n = 1;
        for (int j = 0; j < AL[i].size(); ++j) {
            hash += AL[i][j] * n;
            hash %= 1000000007;
            n *= 7;
            n %= 1000000007;
        }
        cout << hash << endl;
    }
}

// must be O(V) so cannot do transpose or complement
// need all 4 matrices as cannot do command 1 to a transposed matrix (need add to top and left - O(n^2). bottom and right - O(n))
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, Q;
    cin >> V >> E >> Q;
    // Edge List
    vector<int> EL[V]; // V since we have V vertices and E for E edges in for loop
    for (int i = 0; i < E; ++i) {
        int A, B;
        cin >> A >> B;
        EL[A].push_back(B);
    }
    // Adjacency Matrix
    vector<vector<int>> AM(V, vector<int>(V, 0)), AMT(V, vector<int>(V, 0)), AMC(V, vector<int>(V, 1)), AMCT(V, vector<int>(V, 1));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < EL[i].size(); ++j) {
            AM[i][EL[i][j]] = 1; // directed graph
            AMT[EL[i][j]][i] = 1;
            AMC[i][EL[i][j]] = 0;
            AMCT[EL[i][j]][i] = 0;
        }
    }
    // Query
    for (int i = 0; i < Q; ++i) {
        int command;
        cin >> command;
        if (complement) w = 1;
        else w = 0;
        if (command == 1) {
            command1(AM, AMT, AMC, AMCT);
        } else if (command == 2) {
            int A, B;
            cin >> A >> B;
            if (transpose) swap(A, B);
            command2(AM, AMT, AMC, AMCT, A, B);
        } else if (command == 3) {
            int A;
            cin >> A;
            command3(AM, AMT, AMC, AMCT, A);
        } else if (command == 4) {
            int A, B;
            cin >> A >> B;
            if (transpose) swap(A, B);
            command4(AM, AMT, AMC, AMCT, A, B);
        } else if (command == 5) {
            transpose = !transpose;
        } else if (command == 6) {
            complement = !complement;
        }
    }
    // Adjacency List
    vector<vector<int>> AL(AM.size());
    // lazy replace
    if (transpose && complement) { AM = AMCT; }
    else if (transpose) { AM = AMT; }
    else if (complement) { AM = AMC; }
    // remember that i = j must be equal 0
    for (int i = 0; i < AM.size(); ++i) {
        AM[i][i] = 0;
    }
    // convert to AL
    for (int i = 0; i < AM.size(); ++i) {
        for (int j = 0; j < AM[i].size(); ++j) {
            if (AM[i][j] == 1) {
                AL[i].push_back(j);
            }
        }
    }
    // Print
    myPrint(AL);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
