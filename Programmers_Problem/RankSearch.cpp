#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> v1;
vector<string> v2;

void removeSpace(string str) {
    istringstream ss1(str);
    string stringBuffer;

    while (getline(ss1, stringBuffer, ' ')) {
        v1.push_back(stringBuffer);
    }
}

void removeAnd(string str) {
    istringstream ss1(str);
    string stringBuffer;

    while (getline(ss1, stringBuffer, ' ')) {
        if (stringBuffer != "and") v2.push_back(stringBuffer);            
        else continue;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<string> info = 
            {{"java backend junior pizza 150",
            "python frontend senior chicken 210",
            "python frontend senior chicken 150",
            "cpp backend senior pizza 260",
            "java backend junior chicken 80",
            "python backend senior chicken 50"}};
    vector<string> query = 
            {{"java and backend and junior and pizza 100",
            "python and frontend and senior and chicken 200",
            "cpp and - and senior and pizza 250",
            "- and backend and senior and - 150",
            "- and - and - and chicken 100",
            "- and - and - and - 150"}};

    // string string1 = "java backend junior pizza 150";
    // string string2 = "java and backend and junior and pizza 100";
    // string string3 = "java backend junior pizza 100";

    // for (int i = 0; i < query.size(); i++) {
    //     for (int j = 0; j < info.size(); j++){
    //         removeAnd(query[i], i);
    //         removeSpace(info[j], j);
    //         //for(int k = 0; j < query[i]; k++)
    //     }
    // }
    

    for (int i = 0; i < query.size(); i++) {
        int count = 0;
        for (int j = 0; j < info.size(); j++) {
            removeAnd(query[i]);
            removeSpace(info[j]);

            if (( (v1[0] == v2[0]) || (v2[0] == "-") )
                && ( (v1[1] == v2[1]) || (v2[1] =="-") )
                && ( (v1[2] == v2[2]) || (v2[2] =="-") )
                && ( (v1[3] == v2[3]) || (v2[3] =="-") )
                && ( (stoi(v1[4]) >= stoi(v2[4])) ) ) count++;

            v1.clear();
            v2.clear();
        }
        
        cout << count << "\n";
    }
    // v1.clear();
    // v2.clear();

    // for(int i = 0; i < info.size(); i++) {
    //     removeSpace(info[i]);
    // }
    // for(int i = 0; i < query.size(); i++) {
    //     removeAnd(query[i]);
    // }

    // for(int i = 0; i< v1.size(); i++) {
    //     cout << v1[i] << "\n";
    // }
    // cout << "\n";
    // for(int i = 0; i< v2.size(); i++) {
    //     cout << v2[i] << " ";
    // }
    
    return 0;
}
