#include <bits/stdc++.h>
using namespace std;
int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    });
    int currentEnergy = 0;
    int initialEnergy = 0;
    for (auto &task : tasks) {
        int actual = task[0];
        int minimum = task[1];
        if (currentEnergy < minimum) {
            int diff = minimum - currentEnergy;
            initialEnergy += diff;
            currentEnergy += diff;
        }
        currentEnergy -= actual;
    }
    return initialEnergy;
}
int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;
    vector<vector<int>> tasks(n, vector<int>(2));
    cout << "Enter actual energy and minimum energy for each task:\n";
    for (int i = 0; i < n; i++) {
        cin >> tasks[i][0] >> tasks[i][1];
    }
    cout << "Minimum initial energy required = " << minimumEffort(tasks);
    return 0;
}