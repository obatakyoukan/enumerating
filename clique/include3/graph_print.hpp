#ifndef GRAPH_PRINT_HPP
#define GRAPH_PRINT_HPP
#include "graph.hpp"

void graph::print_V( std::vector<int> &Vs ){
 for(int i = 0 ; i < Vs.size() ; i++ ) {
  if( i != 0 ) std::cout<<' ';
  std::cout<<Vs[i];
 }
 std::cout<<std::endl;
}

void graph::print_V_alphabet( std::vector<int> &Vs ) {
 for(int i = 0 ; i < Vs.size() ; i++ ) {
  if( i != 0 ) std::cout<<' ';
  std::cout<<(char)('a'+Vs[i]);
 }
 std::cout<<std::endl;
}

void graph::print_G( std::vector<int> &Vs ) {
 for(int i = 0 ; i < Vs.size() ; i++ ){
  for(int j = 0 ; j < Vs.size() ; j++ ){
   if( j != 0 ) std::cout<<' ';
   std::cout<<is_edge(Vs[i],Vs[j]) ? 1 : 0;
  }
  std::cout<<std::endl;
 }
}

void graph::print(std::vector<int> &Vs) {
 print_V(Vs);
 print_G(Vs);
}


#endif
