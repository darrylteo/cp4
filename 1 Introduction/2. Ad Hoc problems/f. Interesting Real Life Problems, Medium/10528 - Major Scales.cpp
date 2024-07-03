#include <bits/stdc++.h>

using namespace std;
// weird qn...
// always follow this scale C, C#, D, D#, E, F, F#, G, G#, A, A#, B, C
// take this pattern from original scale [1,0,1,0,1,1,0,1,0,1,0,1] and shift it by x
// btw from qn, tone means there's a note. semitone means no note... original score semitone is between E-F, and B-C

const string score[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
const int major[12] = {1,0,1,0,1,1,0,1,0,1,0,1};

// following clang-tidy advice to use pointer instead of string
// they say it prevents copies from being made at each invocation
int getValue (string* s) {
    for (int i = 0; i < 12; i++) {
        if (score[i] == *s) return i;
    }
    return -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string line;

    while(getline(cin, line)) {
        if (line == "END") break;
        bool available[12] = {}; // same pattern as 'score'
        stringstream ss(line); // need convert string to stream to use getline
        string s;
        while (getline(ss, s, ' ')) {
            available[getValue(&s)] = true;
        }

        bool start = true; // just to avoid printing a space in front of the first note


        for (int i = 0; i < 12; i++) { // try all 12 possible majors
            bool isMajor = false;
            for (int j = 0; j < 12; j++) { // check if the next 12 keys follow current 'major' IF there's a note in input
                if (available[(i+j)%12]){
                    if (!major[j]) {
                        isMajor = false;
                        break;
                    }
                    isMajor = true;
                }
            }
            if (isMajor) {
                if (!start) cout << " ";
                cout << score[i];
                start = false;
            }
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
