class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        const int n = matrix.size(), m = matrix[0].size();
        bool row = false, col = false;

        for (int i = 0; i < m; i++) 
            if (matrix[0][i] == 0) {
                row = true;
                break;
            }
        
        for (int i = 0; i < n; i++) 
            if (matrix[i][0] == 0) {
                col = true;
                break;
            }
        
        for (int i = 1; i < n; i++) 
            for (int j = 1; j < m; j++) 
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        
        for (int i = 1; i < n; i++) 
            if (!matrix[i][0]) 
                fill(matrix[i].begin() + 1, matrix[i].end(), 0);
        
        for (int i = 1; i < m; i++) 
            if (!matrix[0][i]) 
                for(int k = 1; k<n; k++)
                    matrix[k][i] = 0;
        
        if (row)
            fill(matrix[0].begin(), matrix[0].end(), 0);

        if (col) 
            for(int k = 0; k<n; k++)
                matrix[k][0] = 0;
    }
};