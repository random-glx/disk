#include <bits/stdc++.h>
using namespace std;

class SSTF {
    int head, total = 0;

public:
    void run(vector<int> requests) {
        cin >> head;
        set<int> reqs(requests.begin(), requests.end());
        while (!reqs.empty()) {
            auto it = reqs.lower_bound(head);
            int best;
            if (it == reqs.end()) best = *prev(it);
            else if (it == reqs.begin()) best = *it;
            else {
                int after = *it;
                int before = *prev(it);
                best = abs(after - head) < abs(before - head) ? after : before;
            }
            total += abs(best - head);
            head = best;
            reqs.erase(best);
        }
        cout<<"Total Seek Time: "<<total<<"\n";
    }
};

int main() {
    SSTF s;
    s.run({82, 170, 43, 140, 24, 16, 190});
    return 0;
}
