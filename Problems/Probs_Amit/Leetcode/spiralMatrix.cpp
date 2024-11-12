// Problem_54 || Spiral Matrix
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;
       
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;
        int count=0;
        int startRow=0;
        int startCol=0;
        int endRow=row-1;
        int endCol=col-1;
        while(count<total){
            for(int i=startCol;count<total && i<=endCol;i++){
                out.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            for(int i=startRow;count<total && i<=endRow;i++){
                out.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            for(int i=endCol;count<total && i>=startCol;i--){
                out.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            for(int i=endRow;count<total && i>=startRow;i--){
                out.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return out;
        
    }
};