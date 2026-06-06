#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5, m = 3; 
    vector<vector<int>> alloc = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    vector<vector<int>> max_res = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    vector<int> avail = {3, 3, 2};
    
    vector<vector<int>> need(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max_res[i][j] - alloc[i][j];

    vector<bool> finish(n, false);
    vector<int> safe_seq;
    int count = 0;

    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                bool can_alloc = true;
                for (int j = 0; j < m; j++) {
                    if (need[p][j] > avail[j]) {
                        can_alloc = false;
                        break;
                    }
                }
                if (can_alloc) {
                    for (int j = 0; j < m; j++) avail[j] += alloc[p][j];
                    safe_seq.push_back(p);
                    finish[p] = true;
                    found = true;
                    count++;
                }
            }
        }
        if (!found) {
            cout << "System is in DEADLOCK!\n";
            return 0;
        }
    }

    cout << "System is in SAFE state.\nSafe Sequence: ";
    for (int i = 0; i < n; i++) cout << "P" << safe_seq[i] << (i == n-1 ? "" : " -> ");
    cout << "\n";

    return 0;
}