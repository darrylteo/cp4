#include <bits/stdc++.h>

using namespace std;

bool solve1(vector<int> v) {
    stack<int> st;
    st.push(-10000000);
    int currSize = 0;
    for (int i: v) {
        if (i < 0) {
            if (i < st.top()) { // in a smaller toy
                cout << ":-( Try again." << endl;
                return false;
            } else {
                st.push(i);
            }
        } else {
            if (i == -st.top()) {
                st.pop();
            } else {
                cout << ":-( Try again." << endl;
                return false;
            }
        }
    }
    if (st.size() == 1) {
        return true; // can go for round 2 solve
    } else {
        cout << ":-( Try again." << endl;
        return false;
    }
}
// example
// -9 -7 -3 3 7 -2 -1 1 2 9
// first check 9
// 7 is inside 9 so we are at index 5 after this loop of finding 7's match
// 2 is inside 9 so we are at index 9 after this loop of finding 2's match
// 9 matches -9 so we go to check for next idx toy i.e. 7
void solve2(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < 0) { // i wanna find who is his match
            int sizeSum = 0;
            for (int j = i + 1; j < v.size(); ++j) {
                if (v[i] == -v[j]) break; // found his match
                if (v[j] < 0) { // found something inside him (qn term this "contains directly")
                    for (int k = j + 1; k < v.size(); ++k) { // find the match of this "inside" toy
                        if (v[k] == -v[j]) {
                            sizeSum += v[k];
                            j = k; // skip this "inside" toy
                            break;
                        }
                    }
                }
            }
            if (sizeSum >= -v[i]) {
                cout << ":-( Try again." << endl;
                return;
            }
        }
    }
    cout << ":-) Matrioshka!" << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s;
    while (getline(cin, s)) {
        vector<int> v;
        stringstream ss(s);
        int x;
        while (ss >> x) {
            v.push_back(x);
        }
        if (solve1(v)) {
            solve2(v);
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
