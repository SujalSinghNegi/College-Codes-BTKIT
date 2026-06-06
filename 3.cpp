#include <iostream>
#include <vector>
using namespace std;

struct Process { int id, at, bt, rem; };

int main() {
    vector<Process> p = {{1, 0, 8, 8}, {2, 1, 4, 4}, {3, 2, 9, 9}, {4, 3, 5, 5}};
    int n = p.size(), time = 0, done = 0, last_p = -1;
    bool was_idle = false;
    float wt = 0, tat = 0;

    cout << "SJRTF Gantt Chart:\n" << time;

    while (done < n) {
        int idx = -1, min_rem = 9999;
        
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rem > 0 && p[i].rem < min_rem) {
                min_rem = p[i].rem; 
                idx = i;
            }
        }

        // If we switch to a new process, print the old one
        if (idx != last_p && time > 0) {
            if (last_p != -1) cout << "-[ P" << p[last_p].id << " ]-" << time;
            else if (was_idle) cout << "-[IDLE]-" << time;
        }

        if (idx != -1) {
            was_idle = false;
            p[idx].rem--; 
            time++;
            
            if (p[idx].rem == 0) {
                done++;
                int curr_tat = time - p[idx].at;
                tat += curr_tat; 
                wt += (curr_tat - p[idx].bt);
                cout << "-[ P" << p[idx].id << " ]-" << time;
                last_p = -1; // Reset so the next process handles its own printing
            } else {
                last_p = idx;
            }
        } else {
            was_idle = true;
            last_p = -1;
            time++;
        }
    }

    cout << "\n\nAvg WT: " << wt/n << ", Avg TAT: " << tat/n << "\n";
    return 0;
}