#include <bits/stdc++.h>

using namespace std;

vector<string> instructions;
int direction = 0; // 0 = north, 1 = east, 2 = south, 3 = west

// changes the value of the instruction at index idx
void nextInstruction(int idx) {
    if (instructions[idx] == "Forward") instructions[idx] = "Right";
    else if (instructions[idx] == "Right") instructions[idx] = "Left";
    else if (instructions[idx] == "Left") instructions[idx] = "Forward";
}

// note: x1 and y1 are passed by reference so we are modifying the original values
void moveNext(int &x1, int &y1) {
    if (direction == 0) y1++;
    else if (direction == 1) x1++;
    else if (direction == 2) y1--;
    else if (direction == 3) x1--;
}

// x and y are final destination, x1 and y1 are current position
bool testInstructions(int x, int y, int n) {
    int x1 = 0, y1 = 0;
    direction = 0;
    for (int i = 0; i < n; i++) {
        if (instructions[i] == "Forward") moveNext(x1, y1);
        else if (instructions[i] == "Right") direction = (direction + 1) % 4;
        else if (instructions[i] == "Left") direction = (direction + 3) % 4;
    }
    return (x1 == x && y1 == y);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int x, y, n;
    cin >> x >> y >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        instructions.push_back(s);
    }

    // test the instructions after changing each instruction
    for (int i = 0; i < n; i++) {
        nextInstruction(i);
        if (testInstructions(x, y, n)) {
            cout << i + 1 << " " << instructions[i] << endl;
            return 0;
        }
        nextInstruction(i);
        if (testInstructions(x, y, n)) {
            cout << i + 1 << " " << instructions[i] << endl;
            return 0;
        }
        nextInstruction(i);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}