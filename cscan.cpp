#include <bits/stdc++.h>
using namespace std;

class CSCAN {
    int head, total = 0;

public:
    void run(vector<int> requests, int diskSize) {
        cin>>head;
        vector<int> left, right;
        for (int r : requests) {
            if (r < head) left.push_back(r);
            else right.push_back(r);
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        for (int r : right) {
            total += abs(head - r);
            head = r;
        }
        if (!left.empty()) {
            total += abs(head - (diskSize - 1));
            total += (diskSize - 1);
            head = 0;
            for (int r : left) {
                total += abs(head - r);
                head = r;
            }
        }
        cout<<"Total Seek Time: "<<total<<"\n";
    }
};

int main() {
    CSCAN c;
    c.run({82, 170, 43, 140, 24, 16, 190}, 200);
    return 0;
}
