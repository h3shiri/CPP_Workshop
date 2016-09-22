
#include "Matrix.hpp"

using namespace std;

int main()
{
    int myMat[] = {1, 2, 3 ,4 , 5, 6};
    vector<int> myVec = vector<int>();
    for(int i = 0; i< 6; ++i)
    {
        myVec.push_back(myMat[i]);
    }
    Matrix<int> mat1 = Matrix<int>(2, 3, myVec);
    Matrix<int> mat2 = Matrix<int>(3, 2, myVec);
    Matrix<int> mat3 = Matrix<int>(2, 2);
    mat3 = (mat1 * mat2);
    cout << mat3;
    cout << (mat1.trans());
    return 0;
}