#include <iostream>
#include "armadillo.hpp"
#include<string>

int main()
{
    bool debug_mode = false;
    int K = 5;
    arma::mat X,Y,X_test;
    X.load("dataX.dat");
    Y.load("dataY.dat");
    X_test.load("dataXtest.dat");
    arma::Col <int> answer = arma::Col <int>(X_test.n_rows); 
    arma::vec P = arma::vec(X.n_rows);
    for (int i=0;i<X_test.n_rows;i++)
    {
        arma::rowvec sample_x = X_test.row(i);
        arma::mat sample_diff = X.each_row() - sample_x;

        for (int j=0;j<X.n_rows;j++)
        {
            P(j) = arma::norm(sample_diff.row(j));
        }
        
        arma::uvec indices = sort_index(P);
        arma::vec Y_sort = Y(indices);
        arma::vec Y_sort_k = Y_sort.subvec(0,K-1);
        if (arma::sum(Y_sort_k) > 0)
        {
            answer(i) = 1;
        }
        else
        {
            answer(i) = -1;
        } 
    }
    answer.save("NN.dat",arma::raw_ascii);
    return 0;
}