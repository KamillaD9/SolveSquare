#include <cstdio>
#include <cmath>
#include <cassert>
#include <float.h>

const double eps = DBL_EPSILON;
enum rootNum
{
    noRoot,     //! Enum value noRoot.
    oneRoot,    //! Enum value oneRoot.
    twoRoots,   //! Enum value twoRoot.
    infRoots    //! Enum value infRoot.
};


//! \brief Function to solve solve linear equation like `b*x + c = 0`
//! \param b is equation coefficient
//! \param c is equation coefficient
//! \param root is pointer to put result
//! \return rootNum val is number of roots
rootNum SolveLinear(double b, double c, double* root)
{
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    assert(root != nullptr);

    if (std::abs(b) < eps && std::abs(c) < eps)
    {
        return infRoots;
    }

    if (std::abs(b) < eps)
    {
        return noRoot;
    }

    *root = -c / b;

    return oneRoot;
}
rootNum SolveSquare(double a, double b, double c, double* root1, double* root2)
{
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    assert(root1 != nullptr);
    assert(root2 != nullptr);
    assert(root1 != root2);

    if (std::abs(a) < eps)
    {
        return SolveLinear(b, c, root1);
    }

    double D = b * b - 4 * a * c;
    if (D > eps)
    {
        double sqrtD = sqrt(D);
        *root1 = (- b - sqrtD) / (2 * a);
        *root2 = (- b + sqrtD) / (2 * a);
        return twoRoots;
    }
    if (std::abs(D) < eps)
    {
        *root1 = -b / (2*a);
        return oneRoot;
    }
    if (D < -1 * eps)
    {
        return noRoot;
    }
}
void printSolutions(double root1, double root2, rootNum nRoots)
{
    switch (nRoots)
    {
        case noRoot:
        {
            printf("No root here(only mushrooms)\n");
            return;
        }
        case oneRoot:
        {
            printf("There is only one root and it is %lg\n", root1);
            return;
        }
        case twoRoots:
        {
            printf("There are two roots\n"
                           "x1 = %lg\n"
                           "x2 = %lg\n", root1, root2);
            return;
        }
        case infRoots:
        {
            printf("A lot of roots(No mushrooms)\n");
            return;
        }
    }
}
void checkOrDie(double a, double b, double c)
{
    assert(a != NAN);
    assert(b != NAN);
    assert(c != NAN);
}
int main()
{
    printf("Enter coefficients of a*x^2 + b*x + c = 0 :\n");
    double a = NAN, b = NAN, c = NAN;
    scanf("%lf%lf%lf", &a, &b, &c);
    checkOrDie(a, b, c);
    double root1 = NAN, root2 = NAN;
    rootNum nRoots = SolveSquare(a, b, c, &root1, &root2);
    printSolutions(root1, root2, nRoots);
    return 0;
}
