#define ONE 1
#define ZERO 0
#define DELIM '\t'
#define NEWLINE '\n'

#include <functional>
#include <numeric>

template <typename T>
/**
 * A generic representation of the matrix class.
 */
class Matrix
{
typedef std::vector<T> vec;
public:
    /**
     * The default constructor.
     */
    Matrix();

    /**
     * A basic constructor for the matrix.
     * @param rows - the number of rows.
     * @param cols - the number of columns.
     */
    Matrix(unsigned int rows, unsigned int cols);

    /**
     * A basic copy constructor for the Matrix.
     * @param other - the other matrix.
     */
    Matrix(const Matrix<T>& other);

    /**
     * A useful init constructor for the matrix
     * @param row - the number of rows.
     * @param cols - the number of cols.
     * @param cells - A vector containing all the elements.
     */
    Matrix(unsigned int row, unsigned int cols, const vec& cells);

    /**
     * A useful move constructor for our matrix
     * @param other - rvalue for setting our matrix.
     */
    Matrix(Matrix<T>&& other);

    /**
     * An override for the assignment operator.
     * @param other - the other matrix to be submitted.
     * @return - the relevant new matrix.
     */
    Matrix<T>& operator=(const Matrix<T>& other);

    /**
     * A destructor for this class.
     */
    ~Matrix();

    /**
     * A getter function for the rows parameter.
     * @return - the relevant number.
     */
    unsigned int rows() const;

    /**
     * A getter function for the cols parameter.
     * @return - the relevant number.
     */
    unsigned int cols() const;

    /**
     * A setter function for the rows parameter
     */
    void setRows(unsigned int rows);

    /**
     * A setter function for the cols parameter
     */
    void setCols(unsigned int cols);

    /**
     * A getter function for the matrix array of elements.
     * @return - the relevant vector array
     */
    const vec &getMatrix() const;

    /**
     * A getter function for a given row
     * @return - the appropriate vector.
     */
    vec getRowVector(const unsigned int row) const;

    /**
     * A getter function for a given column
     * @return - the appropriate vector.
     */
    vec getColVector(const unsigned int col) const;

    /**
     * A useful function for getting a specific element.
     * @param row - the relevant row.
     * @param col - the relevant column.
     * @return - the relevant value.
     */
    T & operator()(unsigned int row, unsigned int col);


    /**
     * A useful function for getting a specific element.
     * @param row - the relevant row.
     * @param col - the relevant column.
     * @return - the relevant value.
     */
    T operator()(unsigned int row, unsigned int col) const;

    /**
     * An implementation for the plus equal operator.
     * @param other - the other matrix that shall be added.
     * @return - the new modified matrix.
     */
    template<typename U>
    Matrix<T>& operator +=(const Matrix<U>& other);

    /**
     * An implementation for the plus operator.
     * @param rhs - the right hand matrix that shall be added.
     * @return - the new modified matrix.
     */
    Matrix<T>& operator +(const Matrix<T>& rhs);

    /**
     * An implementation for the minus operator.
     * @param rhs - the right hand matrix that shall be added.
     * @return - the new modified matrix.
     */
    Matrix<T>& operator -(const Matrix<T>& rhs);

    /**
     * An implementation for the multiply operator.
     * @param rhs - the right hand matrix that shall be added.
     * @return - the new modified matrix.
     */
    Matrix<T> operator *(const Matrix<T>& rhs);

    /**
     * An override for the equal operator.
     * @param other - the other matrix to be submitted.
     * @return - true iff the matrices are equal.
     */
    bool operator==(const Matrix<T>& other) const;

    /**
     * An override for the non equal operator.
     * @param other - the other matrix to be submitted.
     * @return - true iff the matrices are not equal.
     */
    bool operator!=(const Matrix<T>& rhs) const;

    /**
     * A transpose operation which is quite useful for any matrix.
     * return - the relevant new transposed matrix.
     */
    Matrix<T> trans() const;

    /**
     * A bidirectional iterator from the beginning of the matrix
     * @return - the appropriate iterator
     */
    typename vec::iterator begin() const;

    /**
     * A bidirectional iterator from the end of the matrix
     * @return - the appropriate iterator
     */
    typename std::vector<T>::iterator end() const;

private:
    unsigned int _rows;
    unsigned int _cols;
    vec _matrix;
};



/**
 * The default constructor.
 */
template <typename T>
Matrix<T>::Matrix():
    _rows(ONE), _cols(ONE), _matrix(vec(ONE, T(ZERO)))
{
    return;
}

/**
 * A basic constructor for the matrix.
 * @param rows - the number of rows.
 * @param cols - the number of columns.
 */
template <typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols):
    _rows(rows), _cols(cols), _matrix(vec(rows * cols, T(ZERO)))
{
    return;
}

/**
 * A basic copy constructor for the Matrix.
 * @param other - the other matrix.
 */
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other)
{
    Matrix<T> temp = other;
    this = temp;
}


/**
 * A useful init constructor for the matrix
 * @param row - the number of rows.
 * @param cols - the number of cols.
 * @param cells - A vector containing all the elements.
 */
template <typename T>
Matrix<T>::Matrix(unsigned int row, unsigned int cols, const vec& cells):
        _rows(row), _cols(cols), _matrix(cells)
{
    return;
}

/**
 * A useful move constructor for our matrix
 * @param other - rvalue for setting our matrix.
 */
template <typename T>
Matrix<T>::Matrix(Matrix<T>&& other):
    _rows(other.rows()), _cols(other.cols()), _matrix(std::move(other.getMatrix()))
{
    return;
}

/**
 * A destructor for this class.
 */
template <typename T>
Matrix<T>::~Matrix()
{
    return;
}

/**
 * A getter function for the rows parameter.
 * @return - the relevant number.
 */
template <typename T>
unsigned int Matrix<T>::rows() const
{
    return _rows;
}


/**
 * A getter function for the cols parameter.
 * @return - the relevant number.
 */
template <typename T>
unsigned int Matrix<T>::cols() const
{
    return _cols;
}

/**
 * A setter function for the rows parameter
 */
template <typename T>
void Matrix<T>::setRows(unsigned int rows)
{
    _rows = rows;
}

/**
 * A setter function for the cols parameter
 */
template <typename T>
void Matrix<T>::setCols(unsigned int cols)
{
    _cols = cols;
}

/**
 * A getter function for the matrix array of elements.
 * @return - the relevant vector array
 */
template <typename T>
const typename Matrix<T>::vec& Matrix<T>::getMatrix() const
{
    return _matrix;
}


/**
 * An override for the assignment operator.
 * @param other - the other matrix to be submitted.
 * @return - the relevant new matrix.
 */
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other)
{
    /* in case we refer to the same object */
    if(this == &other)
    {
        return (*this);
    }
    setCols(other.cols());
    setRows(other.rows());
    _matrix = other.getMatrix();
    return (*this);
}

/**
 * A useful function for getting a specific element copy.
 * @param row - the relevant row.
 * @param col - the relevant column.
 * @return - the relevant value.
 */
template <typename T>
T Matrix<T>::operator()(unsigned int row, unsigned int col) const
{
    unsigned int index = ((row * cols()) + col);
//    TODO : throw out of bound exception.
    return _matrix[index];
}


/**
 * A useful function for getting a specific element mutable
 * @param row - the relevant row.
 * @param col - the relevant column.
 * @return - the relevant value.
 */
template <typename T>
T & Matrix<T>::operator()(unsigned int row, unsigned int col)
{
    unsigned int index = ((row * cols()) + col);
//    TODO : throw out of bound exception.
    return _matrix[index];
}


//TODO: potential bonus.
/**
 * An implementation for the plus operator.
 * @param rhs - the right hand matrix that shall be added.
 * @return - the new modified matrix.
 */
template <typename T>
Matrix<T>& Matrix<T>::operator+(const Matrix<T>& rhs)
{
    Matrix<T> res = Matrix<T>(rhs.rows(), rhs.cols());
    //    TODO: throw a beautiful number of exceptions (dimensions).
    for (unsigned int i = 0; i < (rhs.rows() * rhs.cols()); ++i)
    {
        res.getMatrix()[i] = (getMatrix()[i] + rhs.getMatrix()[i]);
    }
    return res;
}

//TODO: potential bonus.
/**
 * An implementation for the minus operator.
 * @param rhs - the right hand matrix that shall be added.
 * @return - the new modified matrix.
 */
template <typename T>
Matrix<T>& Matrix<T>::operator-(const Matrix<T>& rhs)
{
    Matrix res = Matrix<T>(rhs.rows(), rhs.cols());
//    TODO: throw a beautiful number of exceptions (dimensions).
    for (unsigned int i = 0; i < (rhs.rows() * rhs.cols()); ++i)
    {
        res.getMatrix()[i] = (getMatrix()[i] - rhs.getMatrix()[i]);
    }
    return res;
}



/**
 * An implementation for the plus equal operator.
 * @param other - the other matrix that shall be added.
 * @return - the new modified matrix.
 */
template <typename T>
template<typename U>
Matrix<T>& Matrix<T>::operator +=(const Matrix<U>& other)
{
//    TODO: throw a beautiful number of exceptions (dimensions).
    for (unsigned int i = 0; i < (other.rows() * other.cols()); ++i)
    {
        _matrix[i] += other.getMatrix()[i];
    }
    return (*this);
}


/**
 * An implementation for the multiply operator.
 * @param rhs - the right hand matrix that shall be added.
 * @return - the new modified matrix.
 */
template <typename T>
Matrix<T> Matrix<T>::operator *(const Matrix<T>& rhs)
{
    Matrix<T> res = Matrix<T>(rows(), rhs.cols());
//    TODO: throw error in case of non matching dimensions (cols of lhs to rows of rhs)
    unsigned int insertionIndex = ZERO;
    for(unsigned int i = 0; i < rows(); ++i)
    {
        vec tempRow = getRowVector(i);
        T tempSum = T(0);
        for (unsigned int j = 0; j < rhs.cols(); ++j)
        {
            vec tempCol = rhs.getColVector(j);
            T val = std::inner_product(tempRow.begin(), tempRow.end(), tempCol.begin(), T(ZERO));
            res._matrix[insertionIndex] = val;
            ++insertionIndex;
        }
    }
    return res;
}


/**
 * A getter function for a given row
 * @return - the appropriate vector.
 */
template <typename T>
typename Matrix<T>::vec Matrix<T>::getRowVector(const unsigned int row) const
{
    unsigned int initIndex = (row * cols());
    vec res = vec(cols(), T(ZERO));
    for (unsigned int i = 0; i < cols(); ++i)
    {
        res[i] = (getMatrix()[(initIndex + i)]);
    }
    return res;
}

/**
 * A getter function for a given row
 * @return - the appropriate vector.
 */
template <typename T>
typename Matrix<T>::vec Matrix<T>::getColVector(const unsigned int col) const
{
    vec res = vec(rows(), T(ZERO));
    for (unsigned int i = 0; i < rows(); ++i)
    {
        res[i] = getMatrix()[((cols() * i) + col)];
    }
    return res;
}

/**
 * A useful implementation for the << operator with a given
 * ostream.
 * @return - the relevant ostream.
 */
template <typename T>
std::ostream& operator<< (std::ostream& stream, const Matrix<T>& matrix)
{
    unsigned int index = ZERO;
    for (unsigned int i = 0; i < matrix.rows(); ++i)
    {
        for (unsigned int j = 0; j < matrix.cols(); ++j)
        {
            stream << matrix.getMatrix()[index] << DELIM;
            ++index;
        }
        stream << NEWLINE;
    }
    return stream;
}


/**
 * An override for the equal operator.
 * @param other - the other matrix to be submitted.
 * @return - true iff the matrices are equal.
 */
template <typename T>
bool Matrix<T>::operator==(const Matrix<T>& rhs) const
{
    /* checking dimensions first */
    if(!((rows() == rhs.rows()) && (cols() == rhs.cols())))
    {
        return false;
    }
    for (unsigned int i = 0; i < (cols() * rows()); ++i)
    {
        /* checking for non matching elements */
        if(_matrix[i] != rhs._matrix[i])
        {
            return false;
        }
    }
    return true;
}

/**
 * An override for the non equal operator.
 * @param other - the other matrix to be submitted.
 * @return - true iff the matrices are not equal.
 */
template <typename T>
bool Matrix<T>::operator!=(const Matrix<T>& rhs) const
{
    return !(*this == rhs);
}

/**
 * A transpose operation which is quite useful for any matrix.
 * return - the relevant new transposed matrix.
 */
template <typename T>
Matrix<T> Matrix<T>::trans() const
{
    Matrix<T> res = Matrix<T>(cols(), rows());
    unsigned int readingIndex = ZERO;
    for (unsigned int i = 0; i < rows(); ++i)
    {
        for (unsigned int j = 0; j < cols(); ++j)
        {
            unsigned int insertionIndex = ((j * rows()) + i);
            res._matrix[insertionIndex] = getMatrix()[readingIndex];
            ++readingIndex;
        }
    }
    return res;
}

/**
 * A bidirectional iterator from the beginning of the matrix
 * @return - the appropriate iterator
 */
template <typename T>
typename std::vector<T>::iterator Matrix<T>::begin() const
{
    return _matrix.begin();
}

/**
 * A bidirectional iterator from the end of the matrix
 * @return - the appropriate iterator
 */
template <typename T>
typename std::vector<T>::iterator Matrix<T>::end() const
{
    return _matrix.end();
}