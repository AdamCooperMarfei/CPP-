#include<vector>
using namespace std;
class Solution1{
public:
    void setMatrixZeros(vector<vector<int>>&matrix){
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);
        for(size_t i = 0; i < m; ++i){
            for(size_t j = 0; j < n; ++j){
                if(matrix[m][n] == 0){
                    row[i] = col[j] = true;
                }
            }
        }
        for(size_t i = 0; i < m; ++i){
            if(row[i]) fill(&matrix[i][0], &matrix[i][0] + n, 0);
        }
        for(size_t j = 0; j < n; ++j){
            if(col[j]){
                for(size_t i = 0; i < m; ++i)
                    matrix[i][j] = 0;
            }
        }
    }
};

class Solution2{
public:
    void setMatrixZeros(vector<vector<int>>&matrix){
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool row_has_zero = false;
        bool col_has_zero = false;
        for(size_t j = 0; j < n; ++j){
            if(matrix[0][j] == 0){
                col_has_zero = true;
                break;
            }
        }
        for(size_t i = 0; i < m; ++i){
            if(matrix[i][0] == 0){
                row_has_zero = true;
                break;
            }
        }
        for(size_t i = 1; i < m; ++i)
            for(size_t j = 1; j < n; ++j)
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        for(size_t i = 1; i < m; ++i)
            for(size_t j = 1; j < n; ++j)
                if(matrix[i][0]||matrix[0][j]){
                    matrix[i][j] = 0;
                }
        if(row_has_zero)
            for(size_t i = 0; i < m; ++i)
                matrix[i][0] = 0;
        if(col_has_zero)
            for(size_t j = 0; j < n; ++j){
                matrix[0][j] = 0;
            }
    }
};