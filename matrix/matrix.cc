#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Matrix{
    private:
        T data;
        T** matrix;
        int rows, columns;

    public:
        Matrix(int rows = 1, int columns = 1){
            cout << "Construindo "<< endl;
            this->rows = rows;
            this->columns = columns;
            matrix = new T*[rows];
            for (int i = 0; i < rows; i++){
                matrix[i] = new T[columns];
            }
        }

        Matrix(Matrix<T> &old){
            cout << "Construindo "<< endl;

            this->rows = old.rows;
            this->columns = old.columns;
            matrix = new T*[rows];
            for(int c = 0; c < rows; c++){
                matrix[c] = new T[columns];
            }

            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    matrix[i][j] = old.getValue(i, j);
                }
            }
        }

        void setValue(int i, int j, T data){
            matrix[i][j] = data;
        }

        T getValue(int i, int j){
            return matrix[i][j];
        }

        Matrix<T> operator+(const Matrix<T> &__o){
            M
            for(int c = 0; c < __o; c++){
                for(int k = 0; k < __o; k++){

                }
            }
        }

        void printMatrix(){
            for(int c = 0; c < rows; c++){
                cout << "[ ";
                for(int v = 0; v < columns; v++){
                    cout << matrix[c][v] << ",";
                }
                cout << " ]" << endl;
            }
        }


        void sum()

};



int main(){

    Matrix<int> matrix(2, 2);
    matrix.setValue(0, 0, 4);
    matrix.setValue(0, 1, 2);
    matrix.setValue(1, 0, 6);
    matrix.setValue(1, 1, -12);

    matrix.printMatrix();

    Matrix<int> matrix2(matrix);
    matrix2.printMatrix();
}