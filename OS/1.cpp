#include <iostream>
#include <vector>
using namespace std;

struct Process { int id, at, bt; };

int main() {
    vector<Process> p = {{1, 0, 4}, {2, 2, 3}, {3, 5, 2}};
    int time = 0; 
    float wt = 0, tat = 0;

    cout << "FCFS Gantt Chart:\n" << time;

    for (auto& pr : p) {
        if (time < pr.at) {
            time = pr.at;
            cout << "-[IDLE]-" << time;
        }
        
        time += pr.bt;
        cout << "-[ P" << pr.id << " ]-" << time;
        
        int curr_tat = time - pr.at;
        tat += curr_tat; 
        wt += (curr_tat - pr.bt);
    }
    
    cout << "\n\nAvg WT: " << wt/p.size() << ", Avg TAT: " << tat/p.size() << "\n";
    return 0;
}