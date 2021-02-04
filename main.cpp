#include <iostream>
#include "src/graphs.cpp"

int main(){
    graph dummy;

    for (int i = 0; i < 5; i++) dummy.new_node();
    std::cout << " =========================================== START =========================================== " << "\n" << "\n";

    // Construction du graphe donné
    dummy.new_edge(1,2);
    dummy.new_edge(2,3);
    dummy.new_edge(3,4);
    dummy.new_edge(4,5);
    dummy.new_edge(5,1);
    dummy.new_edge(5,2);
    std::cout << "Graph's Incidence Matrix: " << "\n";
    dummy.generate_incidence_matrix();
    std::cout << "\n";
    std::cout << "Total Number of Nodes is : " << dummy.fetch_num_nodes() << "\n";
    std::cout << "Total Number of Edges is : " << dummy.fetch_num_edges() <<"\n";
    std::cout << "\n";

    // Donner la liste des sommets directement adjacent à un sommet donné exp 5
    auto list = dummy.neighbours(node(5));
    std::cout << "List of neighbours for node(5): ";
    for (auto i : list){
        std::cout << i << "; ";
    }
    std::cout << "\n" << "\n";


    // Nb d'arrets entrants pour node(5) par exp.
    std::cout << "In for node(5): " <<dummy.in_degree(node(5)) <<"\n";
    // Nb d'arrets sortants pour node(5) par exp.
    std::cout << "Out for node(5) : " << dummy.out_degree(node(5)) <<"\n" <<"\n";
    

    // Test de BFS
    std::cout << std::boolalpha;
    std::cout << "A path exists between node(3) and node(1)? " << dummy.is_reachable(node(3), node(1)) << "\n" << "\n";

    std::cout << " =========================================== END =========================================== ";



    return 0;
}
