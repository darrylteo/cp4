#include <bits/stdc++.h>

using namespace std;

// soln is quite slow... many people <0.05s. mine is 0.94s.
// maybe because of the sorting and searching of the commands, since this is under hashmap section...
// at least correct on first try
// also, if string only separated by spaces can try something like. about 6x faster than stringstream
//    string s = "asdad asdasd asdasd";
//    string word;
//    int a = 0, b = s.find(' ');
//    word = s.substr(a, b);
//    while (b != string::npos) {
//        a = b + 1;
//        b = s.find(' ', a);
//        word = s.substr(a, b);
//    }

struct command {
    int label;
    string cmd;
};

vector<command> cmds;
int vars[26] = {}; // 'A' to 'Z'

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string buf;
    while (getline(cin, buf)) {
        if (buf.empty()) continue;
        command cmd;
        cmd.label = stoi(buf.substr(0, buf.find(' ')));
        cmd.cmd = buf.substr(buf.find(' ') + 1);
        cmds.push_back(cmd);
    }
    sort(cmds.begin(), cmds.end(), [](const command &a, const command &b) {
        return a.label < b.label;
    });

    int currLine = 0, maxLine = cmds.size();
    while (currLine < maxLine) {
        command cmd = cmds[currLine];
        if (cmd.cmd.substr(0, 7) == "PRINTLN") {
            if (std::count(cmd.cmd.begin(), cmd.cmd.end(), '"') == 2) {
                cout << cmd.cmd.substr(9, cmd.cmd.size() - 10);
            } else {
                cout << vars[cmd.cmd[8] - 'A'];
            }
            cout << endl;
        } else if (cmd.cmd.substr(0, 5) == "PRINT") {
            if (std::count(cmd.cmd.begin(), cmd.cmd.end(), '"') == 2) {
                cout << cmd.cmd.substr(7, cmd.cmd.size() - 8);
            } else {
                cout << vars[cmd.cmd[6] - 'A'];
            }
        } else if (cmd.cmd[0] == 'L') {
            stringstream ss(cmd.cmd);
            string s;
            ss >> s >> s >> s; // up to '='
            int arg1, arg2, rval;

            // 3 space means only 1 arg
            if (std::count(cmd.cmd.begin(), cmd.cmd.end(), ' ') == 3) {
                ss >> s;
                if (isalpha(s[0])) {
                    rval = vars[s[0] - 'A'];
                } else {
                    rval = stoi(s);
                }
            } else {
                ss >> s;
                if (isalpha(s[0])) {
                    arg1 = vars[s[0] - 'A'];
                } else {
                    arg1 = stoi(s);
                }
                ss >> s >> s;
                if (isalpha(s[0])) {
                    arg2 = vars[s[0] - 'A'];
                } else {
                    arg2 = stoi(s);
                }
                if (std::count(cmd.cmd.begin(), cmd.cmd.end(), '+') == 1) {
                    rval = arg1 + arg2;
                } else if (std::count(cmd.cmd.begin(), cmd.cmd.end(), '-') == 1) {
                    rval = arg1 - arg2;
                } else if (std::count(cmd.cmd.begin(), cmd.cmd.end(), '*') == 1) {
                    rval = arg1 * arg2;
                } else {
                    rval = arg1 / arg2;
                }
            }
            vars[cmd.cmd[4] - 'A'] = rval;
        } else {
            stringstream ss(cmd.cmd);
            string s, op;
            ss >> s >> s;
            int arg1, arg2;
            if (isalpha(s[0])) {
                arg1 = vars[s[0] - 'A'];
            } else {
                arg1 = stoi(s);
            }
            ss >> op;
            ss >> s;
            if (isalpha(s[0])) {
                arg2 = vars[s[0] - 'A'];
            } else {
                arg2 = stoi(s);
            }

            if (op == "=") {
                if (arg1 != arg2) {
                    currLine++;
                    continue;
                }
            } else if (op == "<") {
                if (arg1 >= arg2) {
                    currLine++;
                    continue;
                }
            } else if (op == ">") {
                if (arg1 <= arg2) {
                    currLine++;
                    continue;
                }
            } else if (op == "<=") {
                if (arg1 > arg2) {
                    currLine++;
                    continue;
                }
            } else if (op == ">=") {
                if (arg1 < arg2) {
                    currLine++;
                    continue;
                }
            } else if (op == "<>") {
                if (arg1 == arg2) {
                    currLine++;
                    continue;
                }
            }

            // if get here then need do GOTO statement
            ss >> s >> s >> s;
            currLine =
                    lower_bound(cmds.begin(), cmds.end(), command{stoi(s), ""}, [](const command &a, const command &b) {
                        return a.label < b.label;
                    }) - cmds.begin();
            continue;
        }
        currLine++;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
