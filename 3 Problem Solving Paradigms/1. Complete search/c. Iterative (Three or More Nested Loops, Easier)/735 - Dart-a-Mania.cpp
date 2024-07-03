#include <bits/stdc++.h>

using namespace std;

// for permutations can count normally
// for combinations we sort and throw into a (unordered) set
// can have more optimizations to short circuit the search but 3s is enough time

// decided to precompute @_@

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    // answer can be just this
//    set<int> possibleValues;
//    for (int i = 0; i <= 20; ++i) {
//        possibleValues.insert(i);
//        possibleValues.insert(i * 2);
//        possibleValues.insert(i * 3);
//    }
//    possibleValues.insert(50); // bullseye
//
//    int n;
//    while (cin >> n) {
//        if (n <= 0) {
//            cout << "END OF OUTPUT" << endl;
//            break;
//        }
//        int permutations = 0;
//        set<vector<int>> s;
//
//        if (n > 180) {
//            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
//            cout << "**********************************************************************" << endl;
//            continue;
//        }
//
//        // all breaks are optional
//        for (int i1: possibleValues) {
//            if (i1 > n) {
//                break;
//            }
//            for (int i2: possibleValues) {
//                if (i1 + i2 > n) {
//                    break;
//                }
//                if (i1 + 60 + 60 < n) {
//                    break;
//                }
//                for (int i3: possibleValues) {
//                    if (i1 + i2 + 60 < n) { // exit if i1 and i2 too small
//                        break;
//                    }
//                    if (i1 + i2 + i3 > n) { // exit if dunnid check rest of i3
//                        break;
//                    }
//                    if (i1 + i2 + i3 == n) {
//                        ++permutations;
//                        vector<int> v = {i1, i2, i3};
//                        sort(v.begin(), v.end());
//                        s.insert(v);
//                    }
//                }
//            }
//        }
//        if (s.empty()) {
//            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
//        } else {
//            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << s.size() << "." << endl;
//            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << permutations << "." << endl;
//        }
//
//        cout << "**********************************************************************" << endl;
//    }




//    // precompute stuff
//    // for input file
//    for (int i = 1; i <= 180; ++i) {
//        cout << i << '\n';
//    }
//    cout << 0 << '\n';
//
//    // compute and return nice format to copy paste
//    set<int> possibleValues;
//    for (int i = 0; i <= 20; ++i) {
//        possibleValues.insert(i);
//        possibleValues.insert(i * 2);
//        possibleValues.insert(i * 3);
//    }
//    possibleValues.insert(50); // bullseye
//
//    int n;
//    cout << "{0, 0}, ";
//    while (cin >> n) {
//        int permutations = 0;
//        set<vector<int>> s;
//
//        // all breaks are optional
//        for (int i1: possibleValues) {
//            if (i1 > n) {
//                break;
//            }
//            for (int i2: possibleValues) {
//                if (i1 + i2 > n) {
//                    break;
//                }
//                if (i1 + 60 + 60 < n) {
//                    break;
//                }
//                for (int i3: possibleValues) {
//                    if (i1 + i2 + 60 < n) { // exit if i1 and i2 too small
//                        break;
//                    }
//                    if (i1 + i2 + i3 > n) { // exit if dunnid check rest of i3
//                        break;
//                    }
//                    if (i1 + i2 + i3 == n) {
//                        ++permutations;
//                        vector<int> v = {i1, i2, i3};
//                        sort(v.begin(), v.end());
//                        s.insert(v);
//                    }
//                }
//            }
//        }
//        cout << '{' << s.size() << ", " << permutations << "}, "; // remove last , manually
//    }

    vector<pair<int, int>> v = {{0, 0}, {1, 3}, {2, 6}, {3, 10}, {4, 15}, {5, 21}, {7, 28}, {8, 36}, {10, 45}, {12, 55}, {14, 66}, {16, 78}, {19, 91}, {21, 105}, {24, 120}, {27, 136}, {30, 153}, {33, 171}, {37, 190}, {40, 210}, {44, 231}, {48, 253}, {52, 276}, {55, 297}, {60, 319}, {62, 339}, {67, 360}, {70, 382}, {75, 405}, {77, 426}, {83, 448}, {84, 468}, {90, 489}, {92, 511}, {98, 534}, {99, 555}, {106, 577}, {106, 597}, {113, 618}, {114, 640}, {121, 663}, {121, 684}, {129, 706}, {128, 726}, {135, 744}, {135, 763}, {141, 783}, {140, 798}, {148, 820}, {146, 834}, {153, 852}, {152, 868}, {159, 888}, {157, 900}, {166, 925}, {163, 936}, {170, 951}, {168, 961}, {174, 978}, {171, 984}, {180, 1009}, {176, 1014}, {182, 1026}, {178, 1027}, {184, 1038}, {179, 1035}, {187, 1054}, {182, 1053}, {187, 1056}, {183, 1056}, {187, 1059}, {181, 1047}, {188, 1063}, {181, 1047}, {184, 1044}, {179, 1035}, {182, 1032}, {174, 1008}, {181, 1024}, {172, 996}, {175, 990}, {170, 976}, {171, 969}, {161, 930}, {168, 949}, {157, 906}, {160, 906}, {154, 885}, {156, 885}, {144, 834}, {153, 862}, {140, 810}, {144, 813}, {138, 792}, {139, 786}, {126, 729}, {135, 760}, {121, 699}, {125, 705}, {120, 685}, {120, 678}, {107, 618}, {118, 655}, {102, 588}, {106, 591}, {102, 579}, {100, 558}, {88, 507}, {99, 547}, {84, 480}, {87, 483}, {85, 477}, {81, 450}, {70, 399}, {82, 445}, {66, 375}, {69, 375}, {69, 379}, {63, 342}, {54, 306}, {65, 349}, {50, 279}, {52, 279}, {53, 288}, {46, 246}, {39, 219}, {51, 268}, {35, 195}, {38, 198}, {41, 219}, {32, 165}, {27, 153}, {38, 198}, {23, 126}, {26, 132}, {31, 160}, {21, 105}, {18, 102}, {29, 147}, {14, 78}, {18, 87}, {23, 117}, {13, 63}, {11, 66}, {21, 103}, {8, 45}, {11, 54}, {17, 84}, {8, 36}, {7, 42}, {16, 73}, {4, 21}, {7, 33}, {12, 55}, {4, 15}, {4, 24}, {10, 45}, {2, 9}, {4, 18}, {8, 36}, {2, 6}, {2, 12}, {7, 28}, {0, 0}, {2, 9}, {5, 21}, {0, 0}, {1, 6}, {4, 15}, {0, 0}, {1, 3}, {3, 10}, {0, 0}, {0, 0}, {2, 6}, {0, 0}, {0, 0}, {1, 3}, {0, 0}, {0, 0}, {1, 1}, {1, 1}};
    int n;
    while (cin >> n) {
        if (n <= 0) {
            cout << "END OF OUTPUT" << '\n';
            break;
        }
        set<vector<int>> s;

        if (n > 180) {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << '\n';
            cout << "**********************************************************************" << '\n';
            continue;
        }

        int combinations = v[n].first, permutations = v[n].second;
        if (permutations == 0) {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << '\n';
        } else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << combinations << "." << '\n';
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << permutations << "." << '\n';
        }

        cout << "**********************************************************************" << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
