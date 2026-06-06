#include <iostream>
#include <vector>
using namespace std;

struct Process { int id, at, bt; bool comp; };

int main() {
    vector<Process> p = {{1, 0, 6, false}, {2, 1, 8, false}, {3, 2, 7, false}, {4, 3, 3, false}};
    int n = p.size(), time = 0, done = 0;
    float wt = 0, tat = 0;

    cout << "SJF Gantt Chart:\n" << time;

    while (done < n) {
        int idx = -1, min_bt = 9999;
        
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && !p[i].comp && p[i].bt < min_bt) {
                min_bt = p[i].bt; 
                idx = i;
            }
        }

        if (idx != -1) {
            time += p[idx].bt;
            cout << "-[ P" << p[idx].id << " ]-" << time;
            
            int curr_tat = time - p[idx].at;
            tat += curr_tat; 
            wt += (curr_tat - p[idx].bt);
            
            p[idx].comp = true; 
            done++;
        } else {
            time++;
            cout << "-[IDLE]-" << time;
        }
    }

    cout << "\n\nAvg WT: " << wt/n << ", Avg TAT: " << tat/n << "\n";
    return 0;
}