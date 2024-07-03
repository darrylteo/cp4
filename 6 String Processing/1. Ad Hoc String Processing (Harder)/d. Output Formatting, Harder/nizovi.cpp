#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    vector<int> spaces;
    vector<string> pieces;
    int curr = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{') {
            pieces.emplace_back("{");
            spaces.push_back(curr);
            curr += 2;
        } else if (s[i] == '}') {
            curr -= 2;
            spaces.push_back(curr);
            if (i + 1 < s.size() && s[i + 1] == ',') {
                pieces.emplace_back("},");
                i++;
            } else {
                pieces.emplace_back("}");
            }
        } else {
            string temp;
            while (i < s.size() && s[i] != ',' && s[i] != '{' && s[i] != '}') {
                temp += s[i];
                i++;
            }
            if (s[i] == ',') {
                temp += s[i];
                pieces.emplace_back(temp);
                spaces.push_back(curr);
            } else {
                pieces.emplace_back(temp);
                spaces.push_back(curr);
                i--;
            }
        }
    }
    for (int i = 0; i < pieces.size(); i++) {
        for (int j = 0; j < spaces[i]; j++) {
            cout << " ";
        }
        cout << pieces[i] << '\n';
    }
    
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

