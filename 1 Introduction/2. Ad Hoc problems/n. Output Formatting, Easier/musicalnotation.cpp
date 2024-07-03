#include <bits/stdc++.h>

using namespace std;

// consider using an array of strings?

string l0 = "G: ";
string l1 = "F: ";
string l2 = "E: ";
string l3 = "D: ";
string l4 = "C: ";
string l5 = "B: ";
string l6 = "A: ";
string l7 = "g: ";
string l8 = "f: ";
string l9 = "e: ";
string l10 = "d: ";
string l11 = "c: ";
string l12 = "b: ";
string l13 = "a: ";

void updateInitial(const vector<int>& duration){
    int cnt = accumulate(duration.begin(), duration.end(), 0);
    cnt += duration.size() - 1;
    for (int i = 0; i < cnt; i++) {
        l0 += " ";
        l1 += "-";
        l2 += " ";
        l3 += "-";
        l4 += " ";
        l5 += "-";
        l6 += " ";
        l7 += "-";
        l8 += " ";
        l9 += "-";
        l10 += " ";
        l11 += " ";
        l12 += " ";
        l13 += "-";
    }
}

void updateNotes(const vector<int>& duration, const vector<char>& notes){
    int cnt = 3;
    for (int i = 0; i < duration.size(); i++) {
        if (notes[i] == 'G'){
            for (int j = 0; j < duration[i]; j++) {
                l0[cnt + j] = '*';
            }
        } else if (notes[i] == 'F'){
            for (int j = 0; j < duration[i]; j++) {
                l1[cnt + j] = '*';
            }
        } else if (notes[i] == 'E'){
            for (int j = 0; j < duration[i]; j++) {
                l2[cnt + j] = '*';
            }
        } else if (notes[i] == 'D'){
            for (int j = 0; j < duration[i]; j++) {
                l3[cnt + j] = '*';
            }
        } else if (notes[i] == 'C'){
            for (int j = 0; j < duration[i]; j++) {
                l4[cnt + j] = '*';
            }
        } else if (notes[i] == 'B'){
            for (int j = 0; j < duration[i]; j++) {
                l5[cnt + j] = '*';
            }
        } else if (notes[i] == 'A'){
            for (int j = 0; j < duration[i]; j++) {
                l6[cnt + j] = '*';
            }
        } else if (notes[i] == 'g'){
            for (int j = 0; j < duration[i]; j++) {
                l7[cnt + j] = '*';
            }
        } else if (notes[i] == 'f'){
            for (int j = 0; j < duration[i]; j++) {
                l8[cnt + j] = '*';
            }
        } else if (notes[i] == 'e'){
            for (int j = 0; j < duration[i]; j++) {
                l9[cnt + j] = '*';
            }
        } else if (notes[i] == 'd'){
            for (int j = 0; j < duration[i]; j++) {
                l10[cnt + j] = '*';
            }
        } else if (notes[i] == 'c'){
            for (int j = 0; j < duration[i]; j++) {
                l11[cnt + j] = '*';
            }
        } else if (notes[i] == 'b'){
            for (int j = 0; j < duration[i]; j++) {
                l12[cnt + j] = '*';
            }
        } else if (notes[i] == 'a'){
            for (int j = 0; j < duration[i]; j++) {
                l13[cnt + j] = '*';
            }
        }
        cnt += duration[i] + 1;
    }
}

void printScore(){
    cout << l0 << endl;
    cout << l1 << endl;
    cout << l2 << endl;
    cout << l3 << endl;
    cout << l4 << endl;
    cout << l5 << endl;
    cout << l6 << endl;
    cout << l7 << endl;
    cout << l8 << endl;
    cout << l9 << endl;
    cout << l10 << endl;
    cout << l11 << endl;
    cout << l12 << endl;
    cout << l13 << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    vector<char> notes;
    vector<int> duration;
    for (int i = 0; i < n; i++) {
        string note;
        cin >> note;
        notes.push_back(note[0]);
        note = note.substr(1);
        if (!note.empty()){
            duration.push_back(stoi(note));
        } else {
            duration.push_back(1);
        }
    }

    updateInitial(duration);
    updateNotes(duration, notes);
    printScore();

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}