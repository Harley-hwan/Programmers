#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int front = 0, end = people.size() - 1;
    sort(people.begin(), people.end());
    
    while(front <= end) {
        if (people[front] + people[end] <= limit) {
            front++;
            end--;
        }
        else    end--; 
        // 가장 작은 무게의 사람과 가장 많이 나가는 사람이 같이 못타는 경우에는 가장 많이 나가는 사람은 무조건 보트를 혼자 타야한다. 
        
        answer++;
    }
    return answer;
}

// int solution(vector<int> people, int limit) {
//     int answer = 1;
//     sort(people.begin(), people.end(), greater<int>());
//     int sum = 0;
    
//     for (int i = people.size()-1; i >= 0; i--) {
        
//         sum += people.back();
//         people.pop_back();

//         if (sum > limit) { 
//             sum = 0;
//             answer++;
//         }
//     }
//     return answer;
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //vector<int> people = {70, 50, 80, 50};
    vector<int> people = {70, 80, 50};
    int limit = 100;
    cout << solution(people, limit);   
    
    return 0;
}