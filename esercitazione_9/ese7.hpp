#pragma once
#include "header.hpp"
#include <vector>
#include <queue>

template <typename T> 
class coda{
    std::vector<T> coda_;
public:
    coda():
    coda_({})
    {}

    void put(const T elemento){
        coda_.push_back(elemento);
    };

    T get(){
        T ret = coda_[0];
        coda_.erase(coda_.begin());
        return ret;
    };
    
    bool empty(){
        bool vuoto = coda_.empty();
        return vuoto ;
    };
};

template <typename T>
class stack{
    std::vector<T> stack_;
public:
    stack():
    stack_({})
    {}

    void put(const T elemento){
        stack_.push_back(elemento);
    };

    T get(){
        T ret = stack_.back();
        stack_.pop_back();
        return ret;
    };
    
    bool empty(){
        return stack_.empty();
    };
};


template<typename T, typename contenitore>
undirected_graph<T> graph_visit(undirected_graph<T>grafo, T nodo, contenitore cont){
    undirected_graph<T> grafo_nuovo;

    std::set<T> nodes = grafo.all_nodes();
    std::map<T, bool> reached;
    int n_nodi = nodes.size();
    
    
    for( auto& node:nodes){
        reached[node] = false;}
    cont.put(nodo);
    reached[nodo] = 1;
    while(!cont.empty()){
        T u = cont.get();
        std::set<T> vicini = grafo.neighbours(u);
        for (auto& vicino :vicini){
            if (reached[vicino]== 0){
                reached[vicino] = 1;
                cont.put(vicino);
                undirected_edge<T> arco(u, vicino);
                grafo_nuovo.add_edge(arco); 

            }
        }

    };
    return grafo_nuovo;
}


template<typename T>
undirected_graph<T> dfs_rec(undirected_graph<T>& grafo, T nodo){
    auto nodi = grafo.all_nodes();
    std::map<T, bool> visitati;
    for (auto& nodo:nodi){
        visitati[nodo] = false;
    }
    undirected_graph<T> res;
    esplora_nodo(grafo, nodo, visitati, res);
    return res;
}



template<typename T>
void esplora_nodo(undirected_graph<T>& grafo, T origine, std::map<T, bool>& visitati, undirected_graph<T>& res){
    visitati[origine] = true;
    for (auto& nodo:grafo.neighbours(origine)){
        if (visitati[nodo] == false){
            res.add_edge(origine, nodo);
            esplora_nodo(grafo, nodo, visitati, res);
        }
    }
}



template<typename T>
std::map<T, int> dijkstra(undirected_graph<T> grafo, T sorgente){
    int n = grafo.size();
    auto nodi = grafo.all_nodes();
    std::map<T, T> pred;
    std::map<T, int> dist;
    std::map<T, bool> visitati;
    
    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<std::pair<int,T>> > pq;

    for(auto& nodo:nodi){
        pred[nodo] = -1;
        dist[nodo] =  100000000;
        pq.push({100000000, nodo});
    }
    pred[sorgente] = sorgente;
    dist[sorgente] = 0;
    pq.push({0, sorgente});
    int nvisitati = 0;
    while (nvisitati < n){
        auto el = pq.top();
        pq.pop();
        auto distanza = el.first;
        auto node = el.second;
        if (!visitati[node]){
            visitati[node] = true;
            nvisitati++;
            for(auto& vicino:grafo.neighbours(node)){
                if(dist[vicino] > dist[node]+1){
                    dist[vicino] = dist[node] +1;
                    pred[vicino] = node;
                    pq.push({dist[vicino], vicino});
                }
            }
        }
    }
    return dist;
}

