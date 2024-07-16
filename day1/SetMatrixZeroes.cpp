class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        //BRUTE FORCE SOLUTION with 0(n*m)extra space and time 0(m*n)*(m+n)+(n*m)
        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<vector<int>> target = matrix;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         if(matrix[i][j] == 0){
        //             for(int k = 0; k < m; k++){
        //                 target[i][k] = 0;
        //             }
        //             for(int l = 0;l<n; l++){
        //                 target[l][j] = 0;
        //             }
        //         }
        //     }
        // }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         matrix[i][j] = target[i][j];
        //     }
        // }
        // Brute force solution with sametime complexity with space = 0(1)
/*        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0; k < m; k++){
                        if(matrix[i][k] != 0){
                            matrix[i][k] = -9999;
                        }
                    }
                    for(int k = 0; k < n; k++){
                        if(matrix[k][j] != 0){
                            matrix[k][j] = -9999;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == -9999){
                    matrix[i][j] = 0;
                }
            }
        }
*/
    // another approach
    // time complexity 0(2*m*n) and space (n+m)
    int n = matrix.size();
    if(n == 0)return;
    int m = matrix[0].size();
    vector<int> row(n,0);
    vector<int> col(m,0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            if(row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }     
    }
};