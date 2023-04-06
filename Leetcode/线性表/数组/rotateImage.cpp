#include<vector>
using namespace std;
class Solution1{
public:
    void rotateImage(vector<vector<int>>&matrix){
        const int n = matrix.size();
        //沿着副对角线旋转
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n - 1- j][n - 1- i]);
        //沿着水平中线反转
        for(int i = 0; i < n / 2; ++i)
            for(int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n - 1- i][j]);
    }
};

class Solution2{
public:
    bool rotateImage(vector<vector<int>>&matrix){
        const int n = matrix.size();
        //沿着水平中线反转
        for(int i = 0; i < n / 2; ++i)
            for(int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n - 1- i][j]);
        //沿着主对角线旋转
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};