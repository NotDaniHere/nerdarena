#include <bits/stdc++.h>
using namespace std;

struct Info {
    int count = 0; 
    priority_queue<long long, vector<long long>, greater<long long>> topK;
};

int main(){
    ifstream fin("cmmdc2.in");
    ofstream fout("cmmdc2.out");

    int n, k; 
    fin >> n >> k;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        fin >> arr[i];
    }
    unordered_map<long long, Info> mp;
    mp.reserve(n * 10);
    for(long long x : arr){
        long long lim = (long long) sqrt(x);
        for(long long d = 1; d <= lim; d++){
            if(x % d == 0){
                {
                    auto &info = mp[d];
                    info.count++;
                    if((int)info.topK.size() < k) {
                        info.topK.push(x);
                    } else if(x > info.topK.top()) {
                        info.topK.pop();
                        info.topK.push(x);
                    }
                }
                long long d2 = x / d;
                if(d2 != d){
                    auto &info2 = mp[d2];
                    info2.count++;
                    if((int)info2.topK.size() < k) {
                        info2.topK.push(x);
                    } else if(x > info2.topK.top()) {
                        info2.topK.pop();
                        info2.topK.push(x);
                    }
                }
            }
        }
    }
    vector<long long> divs;
    divs.reserve(mp.size());
    for(const auto &p : mp){
        divs.push_back(p.first);
    }
    sort(divs.begin(), divs.end(), greater<long long>());
    long long bestDivisor = 0;
    vector<long long> bestGroup;
    for(long long d : divs){
        const auto &info = mp[d];
        if(info.count >= k){
            bestDivisor = d;
            vector<long long> temp;
            temp.reserve(k);
            auto heapCopy = info.topK; 
            while(!heapCopy.empty()){
                temp.push_back(heapCopy.top());
                heapCopy.pop();
            }
            sort(temp.begin(), temp.end(), greater<long long>());
            bestGroup = move(temp);
            break;
        }
    }

    fout << bestDivisor << "\n";
    for(long long x : bestGroup){
        fout << x << " ";
    }
    fout << "\n";

    return 0;
}
