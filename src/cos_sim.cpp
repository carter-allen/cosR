#include <Rcpp.h>
using namespace Rcpp;

double dot_prod(NumericVector x, NumericVector y) {
    double dot = 0;
    int n = x.size();
    int m = y.size();
    if(n != m)
    {
        printf("Error: Vectors of different dimension. Returning 0.");
        return 0;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            double xi = x[i];
            double yi = y[i];
            dot = dot + xi * yi;
        }
        return dot;
    }
}

double l2_norm(NumericVector x)
{
    double l2_sum = 0;
    int n = x.size();
    for(int i = 0; i < n; i++)
    {
        double xi = x[i];
        l2_sum = l2_sum + xi*xi;
    }
    return sqrt(l2_sum);
}

// [[Rcpp::export]]
double cos_sim(NumericVector x, NumericVector y) {
    double dot = dot_prod(x,y);
    double l2_x = l2_norm(x);
    double l2_y = l2_norm(y);
    if(l2_x == 0 || l2_y == 0)
    {
        printf("Error: Zero vector supplied. Returning NaN.");
    }
    return (dot / (l2_x * l2_y));
}

