#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include<vector>
template<typename T>
class undirected_edge{
    T from_;
    T to_;
public:
    undirected_edge():
    from_(T(0)), to_(T(0))
    {}

    undirected_edge(const T& e1, const T& e2)
    {from_ = std::min(e1, e2);
    to_ = std::max(e1, e2);}


    T  from() const{
        return from_;
    }
    T  to() const{
        return to_;
    }

    bool operator<(const undirected_edge<T>& other) const {
        if (from_ < other.from_){return true;}
        else{if (from_==other.from_){
            if(to_ < other.to_){return true;}}}
            return false;
    }

    bool operator==(const undirected_edge<T>& other) const {
        if(from_ == other.from_ && to_ == other.to_){return true;}
        return false;
    };

    bool operator!=(const undirected_edge<T>& other) const {
        if(from_ == other.from_ && to_ == other.to_){return false;}
        return true;
    };

    


};

template<typename T>
class undirected_graph{
    std::set<T> nodes_;
    std::set<undirected_edge<T>> edges_;
    std::map<T, std::set<T>> vicini_;
public:
    undirected_graph()
    : nodes_({}), edges_({}), vicini_({})
    {}

    undirected_graph(std::set<undirected_edge<T>> edges)
    : edges_(edges) 
    {for(auto& edge:edges){
        vicini_[edge.from()].insert(edge.to());
        vicini_[edge.to()].insert(edge.from());
        nodes_.insert(edge.from());
        nodes_.insert(edge.from());
        };
    }

    int size() {
        return nodes_.size();
    }

    std::set<T> const  all_nodes(){
        return nodes_;
    }
    std::set<undirected_edge<T>> const all_edges(){
        return edges_;
    }

    auto const vicini(){
        return vicini_;
    }


    auto neighbours(T nodo){
        return vicini_[nodo];
    }
    
    


    void add_edge(const undirected_edge<T>& edge){
        nodes_.insert(edge.from());
        nodes_.insert(edge.to());
        edges_.insert(edge);
        
        vicini_[edge.from()].insert(edge.to());
        vicini_[edge.to()].insert(edge.from());

    }

    void add_edge(const int& e1, const int& e2){
        T from = std::min(e1,e2);
        T to = std::max(e1,e2);
        nodes_.insert(from);
        nodes_.insert(to);
        undirected_edge<T> edge = undirected_edge(e1,e2);
        edges_.insert(edge);
        vicini_[edge.from()].insert(edge.to());
        vicini_[edge.to()].insert(edge.from());

    }



    int edge_number(const undirected_edge<T>& edge){
        auto it = edges_.find(edge);
        if (it != edges_.end()){
        auto indice = std::distance(it, edges_.begin());
        return indice;
        }
        return -1;
    }

    undirected_edge<T> edge_at(int edge_number){
        undirected_edge<T> ret;
        int count = 0;
        for (auto it = edges_.begin(); it != edges_.end(); ++it){
            if(count == edge_number){
                return  *it;}
        ++count; 
        }
        
        return -1;
};


    undirected_graph<T>& operator-=(const undirected_graph& other){
        std::set<undirected_edge<T>> diff;
        std::set_difference(edges_.begin(), edges_.end(),  other.edges_.begin(), other.edges_.end(),   std::inserter(diff, diff.begin()));
        edges_ = diff;
        return *this;
    }

    undirected_graph<T> operator-(const undirected_graph<T> other) const{
        undirected_graph<T> ret = *this;
        ret -= other;
        return ret;
    }
    

};



template<typename T>
std::ostream&  operator<<(std::ostream& os,  undirected_edge<T> ue){
    T from_e = ue.from();
    T to_e = ue.to();
    os << '(' << from_e << ',' << to_e << ')' << '\n';
    return os;
}