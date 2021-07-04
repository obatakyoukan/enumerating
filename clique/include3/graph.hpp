#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <tuple>
#include <numeric>
#include "CompResult.hpp"
#include "Vector.hpp"
#include "permutation.hpp"

class graph {
 private:
  int n;
  std::vector< std::vector< bool > > g;
  //std::vector< int > deg;
 public:
  //std::vector< int > V;
  graph() {}
  graph( int n );
  graph( std::vector< std::vector< bool > > &_g );

  int size();
  bool is_edge( int x, int y );
  //void make_deg();
  std::vector< int > make_deg( std::vector< int > &Vs );

  //int getdeg(int i );

  //Algorithm 7.1
  std::map< std::tuple<int, Vector> , std::vector<int> > getPartitions();
  std::map< std::tuple<int, Vector> , std::vector<int> > getPartitions(std::vector< int > &Vs);

  //Algorithm 7.5
  std::map<int, std::set< int > > REFINE( std::map<int, std::set< int > > &A );
  void SpritAndUpdate( std::map<int, std::set< int > > &B , int j , 
    int &N , std::set< int > &U, std::map<int, std::set< int > > &S, std::set< int > &T);
  int AbsAndSet( int u , std::set< int > &T );// | T and N_g(u) |

  //Algorithm 7.6
  CompResult Compare( std::vector< int > &mu , std::vector< int > &pi, int l ); 

  //Algorithm 7.7
  void Canon1( std::map< int , std::set<int> > &P, std::vector<int> &mu, bool &BestExist );
  //Algorithm 7.8
  std::string Cert1();
  //Algorithm 7.9
  void Canon2( permutation &beta, std::vector< std::set< permutation > > &G, std::map< int , std::set<int> > &P, std::vector<int> &mu , bool &BestExist );
  //Algorithm 7.10
  std::string Cert2();
  std::string Cert3();
  std::string Cert4();

  std::vector<int> Cert1v();
  std::vector<int> Cert2v();
  std::vector<int> Cert3v();
  std::vector<int> Cert4v();

  void print( std::vector< int > &Vs );
  void print_V( std::vector<int> &Vs );
  void print_V_alphabet( std::vector<int> &Vs );
  void print_G( std::vector<int> &Vs );

};

graph::graph( int n ): n(n) {
 //V = std::vector<int> ( n );
 //iota( V.begin() , V.end() , 0 );
 //make_deg();
}

graph::graph( std::vector< std::vector< bool > > &_g) : g(_g) {
 n = g.size();
 //V = std::vector<int> ( n );
 //iota( V.begin() , V.end() , 0 );
 //make_deg();
}

int graph::size() { return n; }
bool graph::is_edge( int x , int y ) { return g[x][y] ; }

std::vector< int > graph::make_deg( std::vector< int > &Vs ) {
 std::vector< int > res( Vs.size() , 0  );
 for( int i = 0 ; i < Vs.size() ; i++ )
  for( int j = 0 ; j < Vs.size() ; j++ )
   if( is_edge( Vs[i] , Vs[j] ) ) res[i]++;
 return res;
}

#endif