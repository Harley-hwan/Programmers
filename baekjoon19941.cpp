#include <iostrema>
#include <vector>
#include <queue>

using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K; cin >> N >> K;

    for (int i = 0; i < N; i++) {
        char PH; cin >> PH;
        v.push_back(PH);
    }

    int arr[N] = {0,}

    for (int i = 0; i < N; i++) {
        if(v[i] = "H")  arr[i] = 1;
        else            arr[i] = 0;
    }

    while (!v.empty()) {
        if (v.back() == "H") {
            v.pop_back();
            if (v.back() == "H")

        }
    }
    return 0;
}