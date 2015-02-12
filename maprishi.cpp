#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;

map<string, int> visited;
string s1, s2, x, y, z;
map<string, map<char, bool> > vars;
unordered_set<int> poss;
int n;
int get(string s){
    
    queue<pair<string, int> > Q;
    Q.push(MP(s, 0));
    visited[s] = 1;
    
    int num;    
    while(!Q.empty()){
        
        pair<string, int> ss = Q.front();
        Q.pop();
        s = ss.first;
        int move = ss.second;
        
        if(s == s2)
            return move;
        
        for(int i = 0; i < 3; i++){
           
                s[i] = ((s[i] - 'a' + 1) % 26) + 'a';
                num = (s[0] - 'a') * 26 + (s[1] - 'a') * 26 * 26 + (s[2] - 'a');
                if(!poss.count(num) && !visited.count(s)){
                    visited[s] = 1;
                    Q.push(MP(s, move + 1));
                }
           
                s[i] = ((s[i] - 'a' - 2 + 26) % 26) + 'a';
                num = (s[0] - 'a') * 26 + (s[1] - 'a') * 26 * 26 + (s[2] - 'a');
                if(!poss.count(num) && !visited.count(s)){
                    visited[s] = 1;
                    Q.push(MP(s, move + 1));
                }
                s[i] = ((s[i] - 'a' + 1 + 26) % 26) + 'a';
            }
    }
    return -1;
}

int main() {
    visited.clear();
    poss.clear();
    cin >> s1 >> s2;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> z;
        
        for(int i = 0; i < x.size(); i++){
            for(int j = 0; j < y.size(); j++){
                for(int k = 0; k < z.size(); k++){
                    //string sss = "";
                    //sss += x[i];
                    //sss += y[j];
                    //sss += z[k];
                    int num = (x[i] - 'a') * 26 + (y[j] - 'a') * 26 * 26 + (z[k] - 'a');
                    poss.insert(num);
                }
            }
        }
        
    }
    cout << get(s1) << endl;
    return 0;
}
