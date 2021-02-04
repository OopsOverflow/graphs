#include "util.h"
#include <iostream>
#include <list>



// Let's intitialize our graph (empty)
graph::graph():
	matrix({}),
	num_nodes(0),
	num_edges (0)
{}

// Incidence Matrix
std::vector<std::vector<int>> graph::generate_incidence_matrix(){
	for (auto i : matrix){
		for (auto j : i){
			std::cout << j << ", ";
		}
		std::cout <<"\n";
	}
	return matrix;
}

//		Exercice 1 ---------------- 



// Ajouter un sommet en lui affectant un indice entier non encore attribué
node graph::new_node() {
	num_nodes ++;
	matrix.push_back( {} );
	return node(num_nodes-1);
}


// Ajouter une arête entre deux sommets repérés par leurs indices
void graph::new_edge(int start, int end){
	for (auto &i : matrix){
		i.push_back(0);
	}
	
	matrix[end -1][num_edges] = 1;
	matrix[start - 1][num_edges] = -1;
	num_edges ++;

}


// Donner la liste des sommets directement adjacent à un sommet donné
std::vector<int> graph::neighbours(node choice){

	// Initializing neighbors list holder
	std::vector<int> list;

	for(auto i = 0; i < num_edges; ++i) {
		if(matrix[choice.id - 1][i] == -1) {
			for(auto j = 0; j < num_nodes; j++) {
				if(matrix[j][i] == 1) {
					list.push_back(j+1);
					break;
				}
			}
		}
	}

	return list;
}


// Obtenir le nombre de sommets du graphe
size_t graph::fetch_num_nodes(){
	return num_nodes;
}


// Obtenir le nombre d’arêtes du graphe
size_t graph::fetch_num_edges() {
	return num_edges;
}

// 		---------------------------




//		Exercice 2 ---------------- 

/* Algorithm

	Fonction degré_entrant:
	Entrées:
		* matrice : tableau 2D
		* node : entier
	
	Sortie:
		* c : entier, le nombre de degrés

	Variables:
		* i   : entier, compter

	======================================
	
		c <- 0

		pour i de 0 jusqu'à taille(matrice[node]) faire
			si matrice[node][i] == -1
				c <- c + 1

		retourne c
	Fin

	Complexité: 
		On parcourt un tableau de taille = nombre d'arrets, soit n.
		Donc la complexité est linéaire en fonction de n: O(n).
 */

/** \brief nombre d’arêtes entrants d’un sommet donné
 * 
 * \param[in] choice \p node chosen node supplied by user
 * 
 * \return \p count integer holding number of degrees
 **/
size_t graph::in_degree(node choice){ 

	// Holding counter Initialization
	size_t count = 0;

	for(auto i = 0; i < num_edges; i++) {
		if(matrix[choice.id - 1][i] == 1) 
			count ++;
	}
	return count;
}


/* 	Presque le meme algorithme, on compare maintenant avec -1 et pas 1
	Meme complexité O(n)
 */

/** \brief nombre d’arêtes sortant d’un sommet donné
 * 
 * \param[in] choice \p node chosen node supplied by user
 * 
 * \return \p count \p int holding number of degrees
 **/
size_t graph::out_degree(node choice){

	size_t count = 0;

	for(auto i = 0; i < num_edges; i++) {
		if(matrix[choice.id - 1][i] == -1)
			count ++;
	}
	return count;
}

// 		---------------------------





//		Exercice 3 ---------------- 

	// Deux fameux algorithms pour la recherche d'un chemin entre 2 sommets d'un graphe BFS et DFS.
	//On ne donne que BFS en pseudo code


/* Algorithm
	 
	Fonction : ParcoursLargeur
		Entreées:
			* Graphe : G
			* Sommet : s
			* Sommet : d

		Sortie:
			* Bool : indc, vrai si un chemin existe, faux sinon.
		
		Variables:
			* File : f
			* sommet : n
			* Dictionnaire : visité, instialisé au sommets du graphe comme clés
										et valeurs tous fausse
		==========================================

			f = CreerFile();
			f.enfiler(s);
			visité[s] = vrai;
			tant que la file est non vide
				n = f.defiler();
				si n = d 
					retourne vrai
				pour tout i dans G[n]
					si visité[i] = faux
						f.enfiler(t);
						visité[i] = vrai;
			retoune faux

		Fin

	Complexité :
		La complexité en temps dans le pire cas est en O ( | S | + | A | ) où | S | est le nombre de sommets et | A | 
		est le nombre d'arcs. En effet, chaque arc et chaque sommet est visité au plus une seule fois. 

 */



/** \brief A BFS based function to check whether destination is reachable from start. 
 *
 * \param[in] start : starting node supplied by user
 * \param[in] destination : destination node supplied by user  
 *
 * \return true if a path exists.
 */
bool graph::is_reachable(node start, node destination) 
{ 
    // Base case 
    if (start.id == destination.id) 
      return true; 
  
    // Mark all the nodes as not visited 
    bool *visited = new bool[num_nodes]; 
    for (int i = 0; i < num_nodes; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    std::list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[start.id] = true; 
    queue.push_back(start.id);

  
    // it will be used to get all adjacent vertices of a vertex 

  
    while (!queue.empty()) 
    { 
        // Dequeue a node from queue and print it 
        start.id = queue.front(); 
        queue.pop_front(); 
  
        // Get all adjacent nodes of the dequeued node start 
        // If an adjacent has not been visited, then mark it visited 
        // and enqueue it 
        for (auto i : neighbours(start)) 
        { 
            // If this adjacent node is the destination node, then  
            // return true 
            if (i == destination.id) 
                return true; 
  
            // Else, continue to do BFS 
            if (!visited[i]) 
            { 
                visited[i] = true; 
                queue.push_back(i); 
            } 
        } 
    } 
      
    // If BFS is complete without visiting destination 
    return false; 
};
