#include "header.hpp"
#include <iostream>
#include <list>

int main(){
    undirected_graph<int> grafo;
	bool test = true;
	grafo.add_edge(1,2); //0
	grafo.add_edge(1,3); //1
	grafo.add_edge(1,4); //2
	grafo.add_edge(1,5); //3
	grafo.add_edge(3,4); //4
	grafo.add_edge(5,6); //5
	grafo.add_edge(6,7); //6
    std::set<int> set_prova{2,3,4,5}; //sono i vicini del nodo 1
	if (grafo.neighbours(1) != set_prova) {
		std::cout << "Errore nei neighbours di 1\n";
        test = false;
	}
    else { std::cout << "giustoo"<<'\n';}

    std::set<undirected_edge<int>> 
	archi_prova = {
		undirected_edge<int>(1,2),
		undirected_edge<int>(1,3), 
		undirected_edge<int>(1,4),
		undirected_edge<int>(1,5), 
		undirected_edge<int>(3,4), 
		undirected_edge<int>(5,6),
		undirected_edge<int>(6,7)};
	if (grafo.all_edges() != archi_prova) {
		std::cout << "Errore in all_edges()\n";
        test = false;
	}else { std::cout << "giusto"<< '\n';}

    std::set<int> nodi_prova{1,2,3,4,5,6,7};
	if (grafo.all_nodes() != nodi_prova) {
		std::cout << "Errore in all_nodes\n"; 
        test = false;
	}else { std::cout << "giusto"<< '\n';}

    undirected_edge<int> arco_prova(5,6); 
	if (grafo.edge_at(5) != arco_prova) {
		std::cout << "Errore in edge_at\n";
		test=false;
	}else { std::cout << "giusto"<< '\n';}



    undirected_graph<int> grafo2;
	
	grafo2.add_edge(1,3);
	grafo2.add_edge(3,4);
	grafo2.add_edge(1,4);
	undirected_graph<int> differenza = grafo - grafo2;
	if (differenza.all_edges().size() != 4) {
		std::cout << "Errore nella dimensione della differenza\n"; 
	}
	
	if (test) {
		std::cout << "Test eseguito con successo.\n";
		return EXIT_SUCCESS;
	}
	else {
		return EXIT_FAILURE;
	}
}



/* for (const auto& elemento : v) {
        std::cout << elemento << " ";
        }*/