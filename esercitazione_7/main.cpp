#include "contenitori.hpp"
#include <iostream>

int main(){
    undirected_graph<int> grafo;
	
	grafo.add_edge(1,2); 
	grafo.add_edge(1,3); 
	grafo.add_edge(1,4); 
	grafo.add_edge(1,6); 
	grafo.add_edge(2,4); 
	grafo.add_edge(2,5); 
	grafo.add_edge(2,7);
    grafo.add_edge(3,6); 
	grafo.add_edge(4,6); 
	grafo.add_edge(4,7);
	grafo.add_edge(5,7);
	grafo.add_edge(6,7);
    grafo.add_edge(6,8);
	grafo.add_edge(7,9); 
	grafo.add_edge(8,9); 
	
    coda<int> cod;
	std::map<int, int> dijksta_distanze = dijkstra(grafo,1);
    undirected_graph<int> grafo_dfs = dfs_rec(grafo, 1);
	undirected_graph<int> grafo2 = graph_visit(grafo,1, cod);

	auto edges = grafo2.all_edges();
    for(auto& edge:edges){
        std::cout<<edge;
    }

	std::cout<<'\n';

    auto archi = grafo_dfs.all_edges();
    for(auto& arco:archi){
        std::cout<<arco;
    }

	for (const auto& [chiave, valore] : dijksta_distanze) {
    std::cout << "Nodo: " << chiave << " -> Distanza: " << valore << std::endl;
	}

    return 0;
}