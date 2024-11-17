#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

void printMatrix(vector<vector<double>>& matrix) {
    for (auto& row : matrix)
    {
        for (double val : row)
        {
            cout << setw(10) << fixed << setprecision(6) << val << " ";
        }
        cout << endl;
    }
}


bool invertMatrix( vector<vector<double>>& matrix , vector<vector<double>>& inverse )
{
    int n = matrix.size();
    vector<vector<double>> augmented( n, vector<double>( 2*n , 0 ));
    for ( int i = 0 ; i < n ; i++ ) 
    {
        for ( int j = 0 ; j < n ; j++ ) 
        {
            augmented[i][j] = matrix[i][j];
        }
        augmented[i][i + n] = 1; 
    }


    for ( int i = 0; i < n; i++ ) 
    {
        double pivot = augmented[i][i];
        if (pivot == 0) 
        {
            bool found = false;
            for ( int k = i + 1 ; k < n ; k++ ) {
                if ( augmented[k][i] != 0 ) {
                    swap( augmented[i], augmented[k] );
                    found = true;
                    break;
                }
            }
            if (!found) 
            {
                return false;
            } 
            pivot = augmented[i][i];
        }


        for ( int j = 0; j < 2 * n; j++ )
        {
            augmented[i][j] /= pivot;
        }

        for ( int k = 0; k < n; k++ ) {
            if (k == i)
            {
                continue;
            }
            double factor = augmented[k][i];
            for ( int j = 0; j < 2 * n; j++ ) {
                augmented[k][j] -= factor * augmented[i][j];
            }
        }
    }

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            inverse[i][j] = augmented[i][j+n];
        }
    }
    return true;
}

int main() {
    int n;
    cout << "请输入矩阵的大小 (n): ";
    cin >> n;

    vector<vector<double>> matrix( n, vector<double>(n));
    vector<vector<double>> inverse( n, vector<double>(n));

    cout << "请输入矩阵元素 (逐行输入):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    if (invertMatrix(matrix, inverse)) {
        cout << "矩阵的逆矩阵为:" << endl;
        printMatrix(inverse);
    } else {
        cout << "矩阵不可逆！" << endl;
    }

    return 0;
}