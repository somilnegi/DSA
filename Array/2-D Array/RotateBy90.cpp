class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // Transpose the matrix
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(i==j){
                    continue;
                }
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};