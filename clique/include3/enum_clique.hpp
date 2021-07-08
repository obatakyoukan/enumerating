#ifndef ENUM_CLIQUE_HPP
#define ENUM_CLIQUE_HPP

#include "graph.hpp"
#include "graph_lib.hpp"
#include "graph_print.hpp"
#include "basic_function.hpp"
#include "CompResult.hpp"
#include "refine.hpp"
#include "permutation.hpp"
#include "permutation_library.hpp"
#include "cert1.hpp"
#include "cert2.hpp"

#include "tree.hpp"
#include "tree_function.hpp"

#include <string>
#include <map>

class CliqueSolve : public graph {
 public:
  using graph::graph;
  tree t;
  std::map< std::string ,  node* > chache;
  int node_num;

  void expand(std::vector<int>& Vs , node* a);
  void enumeration();
  void expand2(std::vector<int>& Vs , node* a);
  void enumeration2();
  void expand3(std::vector<int>& Vs , node* a);
  void enumeration3();
  void expand_bf(std::vector<int>& Vs , node* a);
  void enumeration_bf();

};


#endif
