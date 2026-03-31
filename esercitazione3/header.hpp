#pragma once
#include <numeric>
template<typename I> requires std::integral<I>
class rational{
    I num_;
    I den_;
public :
    rational()
        : num_(I{0}),  den_(I{1})
    {}

    rational(const I& nume, const I& deno)
        : num_(nume), den_(deno)
    {semplifica();}

    
    I num()  const { return num_; }
    I den() const { return den_; }
    bool Inf() const {return (num()!= 0 && den() == 0);}
    bool NaN() const {return (num()== 0 && den() == 0); }

    rational& operator+=(const rational& other){
        num_ = num_* other.den_ + den_*other.num_;
        den_ = den_ * other.den_;
        return *this;
    }

    rational operator+(const rational& other) const{
        rational ret = *this;
        ret += other;
        return ret;
    }

    rational& operator*=(const rational& other){
        num_ = num_*other.num_;
        den_ = den_*other.den_;
        return *this;
    }

    rational operator*(const rational& other) const{
        rational ret = *this;
        ret *= other;
        return ret;
    }
    void semplifica(){
        if (den_ <0){
            den_ = -1* den_;
            num_ = -1* num_;
        }
        int mcd = std::gcd(std::abs(num_), den_);
        if (mcd != 0){
            den_/= mcd;
            num_/= mcd;
        }
    }
    
   
};

template<typename I>
std::ostream& 
operator<<(std::ostream& os,  rational<I>& r){
    if(r.NaN()){ 
        os << "Not a number " << '\n';
        return os;
    }
    if(r.Inf()){
        os << "Inf " << '\n';
        return os;
    }
    if(r.num()== 0){
        os << '0' << '\n';
        return os;
    }
    if(r.den()== 1){
        os << r.num() << '\n';
        return os;
    }
    r.semplifica();
    os << r.num()<< '/' <<r.den();
    return os;
}
