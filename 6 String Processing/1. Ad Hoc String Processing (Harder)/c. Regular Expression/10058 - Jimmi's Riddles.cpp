#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const string VERB = "(hate|love|know|like)s?";
    const string NOUN = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
    const string ARTICLE = "(a|the)";
    const string ACTOR = "(" + NOUN + "|" + ARTICLE + " " + NOUN + ")";
    const string ACTIVE_LIST = "(" + ACTOR + " and )*" + ACTOR;
    const string ACTION = ACTIVE_LIST + " " + VERB + " " + ACTIVE_LIST;
    const string STATEMENT = ACTION + "( *, " + ACTION + ")*";

    string buf;
    while (getline(cin, buf)) {
        if (regex_match(buf, regex(STATEMENT))) {
            cout << "YES I WILL" << endl;
        } else {
            cout << "NO I WON'T" << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

