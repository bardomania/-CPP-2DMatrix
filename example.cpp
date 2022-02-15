#include "2DMatrix.hpp"

int main(int argc, char const *argv[])
{
    /* Creation */
    Matrix<double> matrix(5, 5, 1);

    /* Acces elements */
    matrix(0) = 4;
    matrix(5) = 8;
    matrix(1, 1) = 6;

    std::cout << matrix << std::endl;
    std::cout << std::endl;

    /* Scalar Add */
    Matrix<double> add = (matrix + 1);
    std::cout << add << std::endl;
    std::cout << std::endl;

    /* Scalar sub */ 
    Matrix<double> sub = (matrix - 1);
    std::cout << sub << std::endl;
    std::cout << std::endl;

    /* Scalar mult */ 
    Matrix<double> mult = (matrix * 2);
    std::cout << mult << std::endl;
    std::cout << std::endl;

    /* Scalar divide */ 
    Matrix<double> div = (matrix / 2);
    std::cout << div << std::endl;
    std::cout << std::endl;

    return 0;
}
