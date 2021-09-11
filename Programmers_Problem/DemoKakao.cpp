#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans(2);
    
    for (int i = 0; i < 2; i++) {
        for (int j = i+1; j < 3; j++) {
            if (v[i][0] == v[j][0]) {
                ans[0] = v[abs(i+j-3)][0];
            }
            if (v[i][1] == v[j][1]) {
                ans[1] = v[abs(i+j-3)][1];
            }              
        }
    }
    return ans;
}