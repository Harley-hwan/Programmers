#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[501];
int brr[501];

bool compare(pair<double, int> a, pair<double, int> b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    else
        return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<pair<double, int> > answer;
    vector<int> result;

    sort(stages.begin(), stages.end());
    
    int num = 1;
    for (int i = 0; i < stages.size(); i++) {
        while(1) {
            if (num > N) break;
            if (stages[i] == num) {
                arr[num]++;
                break;
            }  
            else 
                num++;
        }
    }
    int NN = stages.size();
    
    for (int i = 1; i <= N; i++) {
        answer.push_back(make_pair((double)arr[i] / NN, i));
        NN -= arr[i];
    }

    stable_sort(answer.begin(), answer.end(), compare);

    for (auto x : answer) {
        result.push_back(x.second);
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> stages = {4, 4, 4, 4, 4};
    int N = 4;
    
    for (auto x : solution(N, stages)){
        cout << x << " ";
    }

    return 0;
}