#include <bits/stdc++.h>
using namespace std;

char S[15];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string lang;
    int i = 0;
    scanf("%s", S);
    while (strcmp(S, "#") != 0) {
        if (strcmp(S, "HELLO") == 0) {
            lang = "ENGLISH";
        } else if (strcmp(S, "HOLA") == 0) {
            lang = "SPANISH";
        } else if (strcmp(S, "HALLO") == 0) {
            lang = "GERMAN";
        } else if (strcmp(S, "BONJOUR") == 0) {
            lang = "FRENCH";
        } else if (strcmp(S, "CIAO") == 0) {
            lang = "ITALIAN";
        } else if (strcmp(S, "ZDRAVSTVUJTE") == 0) {
            lang = "RUSSIAN";
        } else {
            lang = "UNKNOWN";
        }
        printf("Case %d: %s\n", ++i, lang.c_str());
        scanf("%s", S);
    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}