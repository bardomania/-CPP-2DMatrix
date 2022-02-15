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

    /* Scalar mult */ 
    Matrix<double> mult = (matrix * 2);
    std::cout << mult << std::endl;
    std::cout << std::endl;

    /* Scalar divide */ 
    Matrix<double> div = (matrix / 2);
    std::cout << div << std::endl;
    std::cout << std::endl;

    /* Matrix add */ 
    Matrix<double> m_add = (matrix + matrix);
    std::cout << m_add << std::endl;
    std::cout << std::endl;

    /* Matrix mult */
    Matrix<double> m1 = Matrix<double>(1, 3, 1);
    m1(0) = 1;
    m1(1) = 2;
    m1(2) = 3;

    Matrix<double> m2 = Matrix<double>(3, 1, 1);
    m2(0) = 4;
    m2(1) = 5;
    m2(2) = 6;


    /*
                 [4]
    [1][2][3] *  [5] = 32
                 [6]

    */
    Matrix<double> result = m1 * m2;
    std::cout << result << std::endl;
    std::cout << std::endl;

    return 0;
}
