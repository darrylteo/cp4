#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string note, tonality;
    int i = 0;
    while (cin >> note >> tonality) {
        i++;
        int unique = 0;
        cout << "Case " << i << ": ";
        if (note == "A#") cout << "Bb";
        else if (note == "Bb") cout << "A#";
        else if (note == "C#") cout << "Db";
        else if (note == "Db") cout << "C#";
        else if (note == "D#") cout << "Eb";
        else if (note == "Eb") cout << "D#";
        else if (note == "F#") cout << "Gb";
        else if (note == "Gb") cout << "F#";
        else if (note == "G#") cout << "Ab";
        else if (note == "Ab") cout << "G#";
        else {
            unique = 1;
            cout << "UNIQUE";
        }
        if (unique == 0) cout << " " << tonality << endl;
        else cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
