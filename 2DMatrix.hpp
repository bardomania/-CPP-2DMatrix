#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Matrix
{
private:
    /* Dimension */
    unsigned int _height;
    unsigned int _width;
    /* Matrix */
    std::vector<T> _data;
public:
    Matrix(unsigned int height, unsigned int width, const T& init = 0);
    Matrix(const Matrix<T>& other);
    ~Matrix();

    // Basic function
    unsigned int width() const;
    unsigned int height() const;

    /*Overload operator*/
    T& operator()(unsigned int y, unsigned int x);
    T& operator()(unsigned int y);

    Matrix<T>& operator=(const Matrix<T>& other);
    Matrix<T> operator+(const Matrix<T>& other);
    Matrix<T> operator-(const Matrix<T>& other);
    Matrix<T> operator*(const Matrix<T>& other);
    Matrix<T> operator/(const Matrix<T>& other);

    Matrix<T> operator+(const T& scalar);
    Matrix<T> operator-(const T& scalar);
    Matrix<T> operator*(const T& scalar);
    Matrix<T> operator/(const T& scalar);

    template<typename O>
        friend ostream& operator<<(ostream& out, const Matrix<O>& m);
};


// Constructor
template <typename T>
Matrix<T>::Matrix(unsigned int height, unsigned int width, const T& init)
: _height {height}
, _width {width}
{
    _data.resize(height * width, init);
}

// Copy Constructor
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other)
{
    this->_height = other._height;
    this->_width = other._width;
    this->_data = other._data;
}

// Destructor
template <typename T>
Matrix<T>::~Matrix()
{
}

/* Basic Function */
template<typename T>
inline unsigned int Matrix<T>::height() const
{
    return _height;
}

template<typename T>
inline unsigned int Matrix<T>::width() const
{
    return _width;
}

/* Overload operator */

// Access elements
template<typename T>
T& Matrix<T>::operator()(unsigned int y, unsigned int x)
{
    assert(y < _height and x < _width);
    return _data[y * _width + x];
}

template<typename T>
T& Matrix<T>::operator()(unsigned int x)
{
    assert(x < _height * _width);
    return _data[x];
}

/* Matrix Operation */

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
    if (other == *this)
        return *this;
    
    this->_height = other._height;
    this->_width = other._width;

    this->_data.resize(this->_height * this->_width);

    for (unsigned int i = 0; i < this->_height * this->_width; ++i)
        this->_data(i) = other._data(i);

    return *this
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other)
{
    Matrix<T> result(this->_height, this->_width);
    try
    {
        if (this->_height != other._height || this->_width != other._width)
            throw "ERROR: Attempting to add two matrices of different size";

        for (unsigned int i = 0; i < this->_height * this->_width ; ++i)
            result(i) = other(i) + *this(i);

        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& matrix)
{
    Matrix<T> result(this->_height, this->_width);
    try
    {
        if (this->_height != other._height || this->_width != other._width)
            throw "ERROR: Attempting to substrate two matrices of different size";

        for (unsigned int i = 0; i < this->_height * this->_width ; ++i)
            result(i) = *this(i) - other(i);

        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other)
{
    Matrix<T> result(this->_height, other._width, 0);
    try
    {
        if (this->_height * this->_width != other._width * other._width)
            throw "ERROR: Attempting to multiply two matrices of different size";

        for (unsigned int k = 0; k < this->_height; ++k) {
            for (unsigned int i = 0; i < this->_width; ++i) {
                for (unsigned int j = 0; j < other._height; ++j) {
                    result(i) += (*this(i) * other(k))
                }
            }
        }

        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& matrix)
{
    Matrix<T> result(this->_height, this->_width);
    try
    {
        if (this->_height * this->_width != other._width * other._width)
            throw "ERROR: Attempting to divide two matrices of different size";

        //TODO

        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return result;
}

/* Scalar operation */

template<typename T>
Matrix<T> Matrix<T>::operator+(const T& scalar)
{
    Matrix<T> result(this->_height, this->_data);

    for(unsigned int i = 0; i < this->_height * this->_width; ++i)
    {
        result(i) = this->_data(i) + scalar;
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T& scalar)
{
    Matrix<T> result(this->_height, this->_data);

    for(unsigned int i = 0; i < this->_height * this->_width; ++i)
    {
        result(i) = this->_data(i) - scalar;
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& scalar)
{
    Matrix<T> result(this->_height, this->_data);

    for(unsigned int i = 0; i < this->_height * this->_width; ++i)
    {
        result(i) = this->_data(i) * scalar;
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T& scalar)
{
    Matrix<T> result(this->_height, this->_data);

    for(unsigned int i = 0; i < this->_height * this->_width; ++i)
    {
        result(i) = this->_data(i) / scalar;
    }
    return result;
}

// Print Matrix data
template<typename O>
std::ostream& operator<<(std::ostream& out, const Matrix<O>& m) {
    for(unsigned int i = 0; i < m._height * m._width; ++i)
    {
        out << m._data(i) << " ";
        if (i != 0 && i % m._width == 0)
            out << endl;
    }
    out << endl;
    return out;
}