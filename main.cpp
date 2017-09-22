#include <cstdio>
#include <cmath>
#include <cassert>

const int SS_INF_ROOTS = 3;

int SolveSquare(double a,double b,double c, double* root1, double* root2);

int SovleLinear(double b, double c, double* root);

int main() {
    printf("Enter coefficients of a*x^2 + b*x + c = 0 : ");
    double a = NAN,b = NAN,c = NAN;
    scanf("%lf%lf%lf",&a,&b,&c);
    assert(a!=NAN);
    assert(b!=NAN);
    assert(c!=NAN);
    double root1 = NAN,root2 = NAN;
    int nRoots = SolveSquare(a,b,c,&root1,&root2);
    switch (nRoots) {
        case 0:{
            printf("No roots here(only mushrooms)\n");
            break;
        }
        case 1:{
            printf("There is only one root and it is %lg\n",root1);
            break;
        }
        case 2:{
            printf("There are two roots\n"
                           "x1 = %lg\n"
                           "x2 = %lg\n",root1,root2);
            break;
        }
        case SS_INF_ROOTS:{
            printf("A lot of roots(No mushrooms)\n");
            break;
        }
    }

    return 0;
}

int SolveSquare(double a,double b,double c, double* root1, double* root2){
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    assert(root1!=nullptr);
    assert(root2!=nullptr);
    assert(root1!=root2);
    if (a == 0) {
        return SovleLinear(b, c, root1);
    }
    double D = b*b-4*a*c;
    if (D > 0){
        double sqrtD = sqrt(D);
        *root1 = (-b-sqrtD)/(2*a);
        *root2 = (-b+sqrtD)/(2*a);
        return 2;
    }
    if (D == 0){
        *root1 = -b/(2*a);
        return 1;
    }
    if (D < 0){
        return 0;
    }
}

int SovleLinear(double b, double c, double* root){
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    assert(root!=nullptr);
    if (b == 0 && c == 0 ) {
        return SS_INF_ROOTS;
    }
    if (b == 0) {
        return 0;
    }
    *root = -c/b;
    return 1;
}
