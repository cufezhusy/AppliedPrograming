#include <iostream>
#include "armadillo.hpp"
#include<string>
#include<cmath>

arma::vec gradient(arma::mat x, arma::mat y, arma::vec w)
{
	arma::vec out(x.n_cols);
	out.fill(0);
	for (int i = 0; i < x.n_rows; i++)
	{
		out -= (y(i,0) * x.row(i).t()/(1+exp(y(i,0) *x.row(i)*w)[0]));
	}
	return out/x.n_rows;
}

int main()
{
    arma::mat X,Y,X_test;
    double alpha = 0.5;
    double epsilon = pow(10,-7);
    X.load("dataX.dat");
    Y.load("dataY.dat");
    X_test.load("dataXtest.dat");
    arma::Col <int> answer = arma::Col <int>(X_test.n_rows); 
    arma::vec w = arma::zeros(X.n_cols);
    arma::vec L = gradient(X,Y,w);
    while (norm(L) > epsilon)
    {
        w = w - alpha*L;
        L = gradient(X,Y,w);
    }

    arma::vec y_hat = X_test * w;
    for (int i = 0; i < X_test.n_rows; i++)
	{
		if (y_hat(i) > 0)
		{
			answer(i) = 1;
		}
		else
		{
			answer(i) = -1;
		}
	}
    answer.save("LogReg.dat",arma::raw_ascii);
    return 0;
}