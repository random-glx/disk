#include <bits/stdc++.h>
using namespace std;

class FCFS {
    int head, total = 0;

public:
    void run(vector<int> requests) {
        cin>>head;
        for (int req : requests) {
            total += abs(req - head);
            head = req;
        }
        cout<<"Total Seek Time: "<<total<<"\n";
    }
};

int main() {
    FCFS f;
    f.run({82, 170, 43, 140, 24, 16, 190});
    return 0;
}
