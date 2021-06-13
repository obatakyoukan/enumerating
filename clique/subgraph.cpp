#include<bits/stdc++.h>
using namespace std;
#define T 4

int main(){
 int n , m ; 
 cin>>n>>m;
 vector<int> x,y;
 
 int N = 0;
 for(int i = 0 ; i < m; i++){
  int u , v;
  cin>>u>>v;
  if( u%T == 0 && v%T==0 ){
   x.push_back( u / T );
   y.push_back( v / T );
   N = max( N , max( u/T , v/T ) );
  }
 }

 cout<< N +1 <<' '<< x.size() << endl;
 for(int i = 0 ; i < x.size() ; i++ ){
  cout<<x[i]<<' '<<y[i]<<endl;
 }


 return 0;
}

