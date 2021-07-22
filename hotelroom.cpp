#include <iostream>
#include <string>
#include <vector>

using namespace std;

int index;
int brr[200000] = {0, };
void CheckOccupy() {
    if (brr[index] != 1)    brr[index] = 1;
    else {
        index++;
        CheckOccupy();
    }                 
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    return answer;
}

int main() {
    int k = 10;

    vector<long long> answer;
    vector<long long> room_number = {1, 3, 4, 1, 3, 1};


    for(int i = 0; i < room_number.size(); i++) {  
        index = room_number[i];
        CheckOccupy();
        answer.push_back(index);
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] <<",";
    }

    return 0;

}