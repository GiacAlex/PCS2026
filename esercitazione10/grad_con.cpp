#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

Eigen::VectorXd grad_con(Eigen::MatrixXd A, Eigen::VectorXd b, double res_tol, int maxit){
    int n= A.rows();    
    double tol = 10e-15;
    if(abs(A.determinant()) < tol){
        std::cout<< "Sistema non singolare";
        return Eigen::VectorXd::Zero(n);
    }

    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
    Eigen::VectorXd r = b - A*x;
    Eigen::VectorXd p = r;

    double r_norm_0 = r.norm();
    int it = 0;
    while(it <= maxit && r.norm()> res_tol*r_norm_0){
        double a = p.dot(r)/(p.dot(A*p));
        x = x + a* p;
        r = b - A*x ;
        double beta = p.dot(A*r)/(p.dot(A*p));
        p = r - beta*p;
        it++;
    }
    std::cout<< "Numero di iterazioni: " << it<< "   n = " << n << '\n';
    return x;
}
    
int main(){
    Eigen::MatrixXd rans = Eigen::MatrixXd::Random(1,1);
    for(int n = 2; n<=50; n++){
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
    Eigen::MatrixXd A = B.transpose()*B;
    Eigen::VectorXd x_esatta = Eigen::VectorXd::Ones(n);
    Eigen::VectorXd b = A * x_esatta;

    auto xc = grad_con(A, b, 10e-11, 1000); 
    double errore = (xc-x_esatta).norm();
    std::cout<< "Errore: " << errore << '\n'; 
    if((xc-x_esatta).norm() > 10e-5){
        return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}