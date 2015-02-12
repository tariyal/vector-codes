#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <unordered_map>
using namespace std;
unordered_map<int,int>  ladders;
unordered_map<int,int>  snakes;
queue<int> q;
int getminsteps()
{
	bool visited[101];
	int l,m,n,i,j,steps=0,nex,t;
	for(i=0;i<101;i++)
		visited[i]=false;
	q.push(1);
	visited[1]=true;
	while(!q.empty())
	{
  		l = q.size();
  		steps++;
  		
  		for(i=0;i<l;i++)
  		{
  			m = q.front();
  			q.pop();
  			for(j=1;j<7;j++)
  			{
  				nex  = m+j;
  				t = nex;
  				if(snakes.find(t)!=snakes.end())
  					nex = snakes[t];
  				else if(ladders.find(t)!=ladders.end())
  					nex = ladders[t];
  				if(nex==100)
  					return steps;
  				if(visited[nex]==false)
  				{
  					visited[nex]=true;
  					q.push(nex);
  				}
  			}
  		}
  	}
  	return -1;
}
int main() {
    int t,a,b,i,z,L,S;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        while(!q.empty())
            q.pop();
        cin>>L;
        cin.ignore();
        cin>>S;
        ladders.clear();
        snakes.clear();
        for(i=0;i<L;i++){
            cin>>a;
            cin.ignore();
            cin>>b;
            ladders[a]=b;
        }
        for(i=0;i<S;i++){
            cin>>a;
            cin.ignore();
            cin>>b;
            snakes[a]=b;
        }
        cout<<getminsteps()<<endl;
    }
    return 0;
}
