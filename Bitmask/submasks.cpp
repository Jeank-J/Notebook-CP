#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> submasks(int x){
    vector <int> ans = {0};
    for (int i = x; i > 0 ; i = (i-1) & x){
        ans.push_back(i);
    }
    return ans;
}
