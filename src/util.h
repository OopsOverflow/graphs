/**RENDU TP C++
 * MAHMOUD  HOUSSEM  ET3-INFO GR2
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>


struct node {
    node(char s) : id(s) {};
    int id;
};

class graph {

public:
    graph();

    node                                new_node();
    void                                new_edge(int start, int finish);

    size_t                              out_degree(node node_id); // size_t to represent size, else it's another int
    size_t                              in_degree(node node_id);
    std::vector<int>                    neighbours(node node);

    bool                                is_reachable(node node1, node node2);

    size_t                              fetch_num_nodes();
    size_t                              fetch_num_edges();
    std::vector<std::vector<int>>       generate_incidence_matrix();

private:
    std::vector<std::vector<int>>       matrix;
    size_t                              num_nodes; 
    size_t                              num_edges;

};

#endif
