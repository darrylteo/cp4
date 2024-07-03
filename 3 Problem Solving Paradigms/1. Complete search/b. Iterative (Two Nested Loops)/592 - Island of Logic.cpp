#include <bits/stdc++.h>

using namespace std;

// about as tedious as section 1.2.p. time waster problems (harder)

// reference: https://github.com/morris821028/UVa/blob/master/volume005/592%20-%20Island%20of%20Logic.cpp
char stmt[100][100]; // holds a few statements
// kind[0] to kind[4] are A to E (0 divine, 1 evil, 2 human), kind[5] is day/night (0 day, 1 night)
// table[0] to table[4] are A to E (0 divine, 1 evil, 2 human), table[5] is day/night (0 day, 1 night)
// e.g. table[0][2] = 1 means A is human
// if table[i] is all 0, means all other tables also all 0, and no solution was found among our permutations
// if table[i] has only one 1, means that we CONFIRMED that i is that kind
// if table[i] has more than one 1, means that we are not sure about i since there are more than one possible kinds
int n, kind[6], table[6][3] = {};
// check() updates table if the current soln passes all the statements. we return if encounter a wrong stmt
void check() {
    int i;
    char f1[20], f2[20], f3[20], f4[20], who[20];
    for(i = 0; i < n; i++) {
        if (sscanf(stmt[i], "%s %s %s %s %s", who, f1, f2, f3, f4) == 5) {
            // I/X am/is not (divine, human, evil, lying);
            if (f1[0] == 'I' && f1[1] == '\0') {
                if (kind[who[0] - 'A'] == 0) {// divine
                    if (f4[0] == 'd') { return; } // I am not divine.
                }
                if (kind[who[0] - 'A'] == 1) {// evil
                    if (f4[0] == 'e' || f4[0] == 'l') {} // I am not evil, I am not lying.
                    else
                        return;
                }
                if (kind[who[0] - 'A'] == 2) {// human
                    if (kind[5] == 0) {// day
                        if (f4[0] == 'h') { return; } // I am not human
                    } else {// night
                        if (f4[0] == 'h' || f4[0] == 'l') {}// I am not human, I am not lying.
                        else
                            return;
                    }
                }
            } else {
                if (kind[who[0] - 'A'] == 0 || (kind[who[0] - 'A'] == 2 && kind[5] == 0)) {
                    // truth guy talking
                    if (kind[f1[0] - 'A'] == 0 && f4[0] == 'd') // X is not divine
                        return;
                    if (kind[f1[0] - 'A'] == 1 && f4[0] == 'e') // X is not evil
                        return;
                    if (kind[f1[0] - 'A'] == 2 && f4[0] == 'h') // X is not human
                        return;
                    // false if truth guy say lie guy is not lying
                    if ((kind[f1[0] - 'A'] == 2 && kind[5] == 1 || kind[f1[0] - 'A'] == 1) && f4[0] == 'l')
                        return;
                } else {
                    // lie guy talking
                    if (kind[f1[0] - 'A'] == 0 &&
                        (f4[0] == 'e' || f4[0] == 'h')) // lie guy says divine is not evil/human (incorrect)
                        return;
                    if (kind[f1[0] - 'A'] == 1 && (f4[0] == 'd' || f4[0] == 'h'))
                        return;
                    if (kind[f1[0] - 'A'] == 2 && (f4[0] == 'd' || f4[0] == 'e'))
                        return;
                    // false if lie guy say truth guy is not lying
                    if ((kind[f1[0] - 'A'] == 2 && kind[5] == 0 || kind[f1[0] - 'A'] == 0) && f4[0] == 'l')
                        return;
                }
            }
        } else {
            sscanf(stmt[i], "%s %s %s %s", who, f1, f2, f3);
            // I/X am/is (divine, human, evil, lying)
            // It is (day, night)
            if (f1[0] == 'I' && f1[1] == 't') {
                // truth guy speaking
                if (kind[who[0] - 'A'] == 0 || (kind[who[0] - 'A'] == 2 && kind[5] == 0)) {
                    if (kind[5] == 0 && f3[0] == 'n')
                        return;
                    if (kind[5] == 1 && f3[0] == 'd')
                        return;
                } else {
                    // lie guy speaking
                    if (kind[5] == 0 && f3[0] == 'd')
                        return;
                    if (kind[5] == 1 && f3[0] == 'n')
                        return;
                }
            } else if (f1[0] == 'I' && f1[1] == '\0') {
                if (kind[who[0] - 'A'] == 0) {// divine
                    if (f3[0] != 'd') { return; } // I am (evil/human/lying).
                }
                if (kind[who[0] - 'A'] == 1) {// evil
                    if (f3[0] == 'l' || f3[0] == 'e') { return; } // I am lying. I am evil.
                }
                if (kind[who[0] - 'A'] == 2) {// human
                    if (kind[5] == 0) {// day
                        if (f3[0] != 'h') { return; } // I am (lying/evil/divine).
                    } else {// night
                        if (f3[0] == 'h' || f3[0] == 'l') { return; } // I am human.
                    }
                }
            } else {
                if (kind[who[0] - 'A'] == 0 || (kind[who[0] - 'A'] == 2 && kind[5] == 0)) {
                    // truth guy talking
                    if (kind[f1[0] - 'A'] != 0 && f3[0] == 'd') // he say X is divine when X is not divine
                        return;
                    if (kind[f1[0] - 'A'] != 1 && f3[0] == 'e') // he say X is evil when X is not evil
                        return;
                    if (kind[f1[0] - 'A'] != 2 && f3[0] == 'h') // he say X is human when X is not human
                        return;
                    // false if truth guy say truth guy is lying
                    if ((kind[f1[0] - 'A'] == 2 && kind[5] == 0 || kind[f1[0] - 'A'] == 0) && f3[0] == 'l')
                        return;
                } else {
                    // lie guy talking
                    if (kind[f1[0] - 'A'] == 0 && f3[0] == 'd') // he say X is divine when X is divine
                        return;
                    if (kind[f1[0] - 'A'] == 1 && f3[0] == 'e') // he say X is evil when X is evil
                        return;
                    if (kind[f1[0] - 'A'] == 2 && f3[0] == 'h') // he say X is human when X is human
                        return;
                    // false if lie guy say lie guy is lying
                    if ((kind[f1[0] - 'A'] == 2 && kind[5] == 1 || kind[f1[0] - 'A'] == 1) && f3[0] == 'l')
                        return;
                }
            }
        }
    }
    // if we reach here, means that the current soln passes all the statements
    for(i = 0; i < 6; i++)
        table[i][kind[i]] = 1;
}

void notDFS() {
    for (int i1 = 0; i1 < 3; i1++) {
        for (int i2 = 0; i2 < 3; i2++) {
            for (int i3 = 0; i3 < 3; i3++) {
                for (int i4 = 0; i4 < 3; i4++) {
                    for (int i5 = 0; i5 < 3; i5++) {
                        for (int i6 = 0; i6 < 2; i6++) {
                            kind[0] = i1;
                            kind[1] = i2;
                            kind[2] = i3;
                            kind[3] = i4;
                            kind[4] = i5;
                            kind[5] = i6;
                            check();
                        }
                    }
                }
            }
        }
    }
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);

    int cases = 1;
    string buf;
    while (getline(cin, buf)) {
        if (buf == "0") break;
        n = stoi(buf);
        memset(table, 0, sizeof(table));
        cout << "Conversation #" << cases++ << endl;
        for (int i = 0; i < n; i++) {
            getline(cin, buf);
            strcpy(stmt[i], buf.c_str());
        }
        notDFS();
        int impossible = 0, atLeastOneFact = 0;
        for (int i = 0; i < 6; i++) {
            int sum = 0;
            if (i == 5) {
                sum = table[i][0] + table[i][1];
            } else {
                sum = table[i][0] + table[i][1] + table[i][2];
            }
            if (sum == 0) { // it will break on the first and the rest are also all 0
                impossible = 1;
                break;
            }
            if (sum == 1) { // exactly 1 correct kind
                atLeastOneFact = 1;
            }
        }
        if (impossible) {
            printf("This is impossible.\n");
        } else if (!atLeastOneFact) {
            printf("No facts are deducible.\n");
        } else {
            for (int i = 0; i < 6; i++) {
                int sum = 0;
                if (i == 5) {
                    sum = table[i][0] + table[i][1];
                } else {
                    sum = table[i][0] + table[i][1] + table[i][2];
                }
                if (sum == 1) { // exactly 1 correct kind
                    if (i == 5) {
                        printf("It is ");
                        if (table[i][0] == 1) {
                            printf("day.\n");
                        } else {
                            printf("night.\n");
                        }
                    } else {
                        printf("%c is ", i + 'A');
                        if (table[i][0] == 1) {
                            printf("divine.\n");
                        } else if (table[i][1] == 1) {
                            printf("evil.\n");
                        } else {
                            printf("human.\n");
                        }
                    }
                }
            }
        }
        printf("\n");
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
