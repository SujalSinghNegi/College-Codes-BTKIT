#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process { int id, at, bt, rem; };

int main() {
    vector<Process> p = {{1, 0, 5, 5}, {2, 1, 3, 3}, {3, 2, 2, 2}};
    int n = p.size(), tq = 2, time = 0, done = 0;
    float wt = 0, tat = 0;

    cout << "RR Gantt Chart:\n" << time;

    while (done < n) {
        bool idle = true;
        
        for (auto& pr : p) {
            if (pr.at <= time && pr.rem > 0) {
                idle = false;
                
                int step = min(pr.rem, tq);
                time += step; 
                pr.rem -= step;
                
                cout << "-[ P" << pr.id << " ]-" << time;

                if (pr.rem == 0) {
                    done++;
                    int curr_tat = time - pr.at;
                    tat += curr_tat; 
                    wt += (curr_tat - pr.bt);
                }
            }
        }
        if (idle) {
            time++;
            cout << "-[IDLE]-" << time;
        }
    }

    cout << "\n\nAvg WT: " << wt/n << ", Avg TAT: " << tat/n << "\n";
    return 0;
}