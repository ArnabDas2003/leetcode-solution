class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
         auto gain = [](int pass, int total) {
            double before = (double)pass / total;
            double after  = (double)(pass + 1) / (total + 1);
            return after - before;
        };

        // Max heap: store {gain, pass, total}
        priority_queue<array<double,3>> pq;

        for (auto &c : classes) {
            int pass = c[0], total = c[1];
            pq.push({gain(pass, total), (double)pass, (double)total});
        }

        // Assign extra students
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            double pass = top[1], total = top[2];
            pass++; total++;
            pq.push({gain(pass, total), pass, total});
        }

        // Compute final average
        double sum = 0.0;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            sum += top[1] / top[2];
        }
        return sum / classes.size();
    }
};