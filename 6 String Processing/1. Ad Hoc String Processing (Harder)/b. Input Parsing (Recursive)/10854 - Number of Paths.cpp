#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// for example
// IF
// ELSE
// IF
// ELSE
// END_IF
// IF
// ELSE
// END_IF
// END_IF
// ENDPROGRAM
//
//
// IF
// ELSE
// 2
// IF
// ELSE
// END_IF
// END_IF
// ENDPROGRAM
//
//
// IF
// ELSE
// 2
// 2
// END_IF
// ENDPROGRAM
//
//
// 1 + 1 * 2 * 2 = 5
// ENDPROGRAM



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        vector<string> program;
        while (cin >> s, s != "ENDPROGRAM") {
            if (s != "S") {
                program.push_back(s);
            }
        }
        stack<string> st;
        ull ans = 1;
        for (int i = 0; i < program.size(); ++i) {
            if (program[i] != "END_IF") st.push(program[i]);
            else {
                vector<string> temp;
                while (st.top() != "IF") {
                    temp.push_back(st.top());
                    st.pop();
                }
                temp.push_back(st.top());
                st.pop();
                // should have 2 or more elements e.g. IF 2 3 4 ELSE 3 4. but at least IF ELSE
                ull curr = 0;
                if (temp.size() == 2) {
                    curr = 2;
                } else {
                    reverse(temp.begin(), temp.end());
                    // check if any digit behind IF or ELSE
                    ull ifPart = 1, elsePart = 1;
                    bool upToIf = true;
                    for (int j = 1; j < temp.size(); ++j) {
                        if (isdigit(temp[j][0])) {
                            if (upToIf) {
                                ifPart *= stoull(temp[j]);
                            } else {
                                elsePart *= stoull(temp[j]);
                            }
                        } else {
                            upToIf = false;
                        }
                    }
                    curr = ifPart + elsePart;
                }
                st.push(to_string(curr));
            }
        }
        while (!st.empty()) {
            if (isdigit(st.top()[0])) {
                ans *= stoull(st.top());
            }
            st.pop();
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


