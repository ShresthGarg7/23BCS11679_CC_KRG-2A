#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[city] = 1;
        int n = isConnected.size();
        for (int j = 0; j < n; j++) {
            if (isConnected[city][j] == 1 && visited[j] == 0) {
                dfs(j, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int province = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                province++;
                dfs(i, isConnected, visited);
            }
        }
        return province;
    }
};
int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }
    Solution obj;
    cout << "Total provinces : " << obj.findCircleNum(isConnected);
    return 0;
}