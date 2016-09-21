#define ONE 1
#define ZERO 0

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
    unsigned int getRows() const;

    /**
     * A getter function for the cols parameter.
     * @return - the relevant number.
     */
    unsigned int getCols() const;

    /**
     * A setter function for the rows parameter
     */
    void setRows(unsigned int& rows);

    /**
     * A setter function for the cols parameter
     */
    void setCols(unsigned int& rows);

    /**
     * A getter function for the matrix array of elements.
     * @return - the relevant vector array
     */
    vec getMatrix();


    /**
     * A useful function for getting a specific element.
     * @param row - the relevant row.
     * @param col - the relevant column.
     * @return - the relevant value.
     */
    T & operator()(unsigned int row, unsigned int col);

    /**
     * An implementation for the plus equal operator.
     * @param other - the other matrix that shall be added.
     * @return - the new modified matrix.
     */
    Matrix<T>& operator +=(const Matrix<T>& other);

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
    Matrix<T>& operator *(const Matrix<T>& rhs);



private:
    unsigned int _rows;
    unsigned int _cols;
    vec _matrix;
};



/**
 * The default constructor.
 */
Matrix::Matrix():
    _rows(ONE), _cols(ONE), _matrix(vec(ONE, T(ZERO)))
{
    return;
}

/**
 * A basic constructor for the matrix.
 * @param rows - the number of rows.
 * @param cols - the number of columns.
 */
Matrix::Matrix(unsigned int rows, unsigned int cols):
    _rows(rows), _cols(cols), _matrix(vec(rows * cols, T(ZERO)))
{
    return;
}

/**
 * A basic copy constructor for the Matrix.
 * @param other - the other matrix.
 */
Matrix::Matrix(const Matrix& other):
{
    Matrix temp = other;
    this = temp;
}


/**
 * A useful init constructor for the matrix
 * @param row - the number of rows.
 * @param cols - the number of cols.
 * @param cells - A vector containing all the elements.
 */
Matrix::Matrix(unsigned int row, unsigned int cols, const vec& cells):
        _rows(row), _cols(cols), _matrix(cells)
{
    return;
}

/**
 * A useful move constructor for our matrix
 * @param other - rvalue for setting our matrix.
 */
Matrix::Matrix(Matrix<T>&& other):
    _rows(other.getRows()), _cols(other.getRows()), _matrix(std::move(other.getMatrix()))
{
    return;
}

/**
 * A destructor for this class.
 */
Matrix::~Matrix()
{
    return;
}

/**
 * A getter function for the rows parameter.
 * @return - the relevant number.
 */
unsigned int Matrix::getRows() const
{
    return _rows;
}


/**
 * A getter function for the cols parameter.
 * @return - the relevant number.
 */
unsigned int Matrix::getCols() const
{
    return _cols;
}

/**
 * A setter function for the rows parameter
 */
void Matrix::setRows(unsigned int& rows)
{
    _rows = rows;
}

/**
 * A setter function for the cols parameter
 */
void Matrix::setCols(unsigned int& cols)
{
    _cols = cols;
}

/**
 * A getter function for the matrix array of elements.
 * @return - the relevant vector array
 */
vec Matrix::getMatrix()
{
    return _matrix;
}


/**
 * An override for the assignment operator.
 * @param other - the other matrix to be submitted.
 * @return - the relevant new matrix.
 */
Matrix& Matrix::operator=(const Matrix& other):
{
    /* in case we refer to the same object */
    if(this == &other)
    {
        return (*this);
    }
    setCols(other.getCols());
    setRows(other.getRows());
    _matrix = other.getMatrix();
    return (*this);
}

/**
 * A useful function for getting a specific element.
 * @param row - the relevant row.
 * @param col - the relevant column.
 * @return - the relevant value.
 */
T & Matrix::operator()(unsigned int row, unsigned int col)
{
    unsigned int index = ((row * getCols()) + col);
//    TODO : throw out of bound exception.
    return _matrix[index];
}

//TODO: potential bonus.
/**
 * An implementation for the plus operator.
 * @param rhs - the right hand matrix that shall be added.
 * @return - the new modified matrix.
 */
Matrix<T>& Matrix::operator +(const Matrix<T>& rhs)
{
    Matrix<T> res = Matrix<T>(rhs.getRows(), rhs.getCols());
    //    TODO: throw a beautiful number of exceptions (dimensions).
    for (unsigned int i = 0; i < (other.getRows() * other.getCols()); ++i)
    {
        res.getMatrix()[i] = (getMatrix()[i] + other.getMatrix()[i]);
    }
    return res;
}

//TODO: potential bonus.
/**
 * An implementation for the minus operator.
 * @param rhs - the right hand matrix that shall be added.
 * @return - the new modified matrix.
 */
Matrix<T>& Matrix::operator +(const Matrix<T>& rhs)
{
    Matrix res = Matrix<T>(rhs.getRows(), rhs.getCols());
//    TODO: throw a beautiful number of exceptions (dimensions).
    for (unsigned int i = 0; i < (other.getRows() * other.getCols()); ++i)
    {
        res.getMatrix()[i] = (getMatrix()[i] - other.getMatrix()[i]);
    }
    return res;
}



/**
 * An implementation for the plus equal operator.
 * @param other - the other matrix that shall be added.
 * @return - the new modified matrix.
 */
template<typename U>
Matrix<T>& Matrix::operator +=(const Matrix<U>& other)
{
//    TODO: throw a beautiful number of exceptions (dimensions).
    for (unsigned int i = 0; i < (other.getRows() * other.getCols()); ++i)
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
Matrix<T>& Matrix::operator *(const Matrix<T>& rhs)
{
    Matrix res = Matrix<T>(getRows(), rhs.getCols());
//    TODO: throw error in case of non matching dimensions (cols of lhs to rows of rhs)
    for(unsigned int i = 0; i < getRows(); ++i)
    {
        T tempSum = T(0);
        for (unsigned int j = 0; j < rhs.getCols(); ++j)
        {

        }
    }
    return res;
}

//TODO : current position work on getting a row and col getters and use inner_product built in with the vector.