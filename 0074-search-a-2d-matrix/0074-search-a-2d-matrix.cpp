
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool result=false;

        ///matrix size
        int row=matrix.size();
        int column=matrix[0].size();


        int start=0;
        int end=(column*row)-1;


        while (end>=start)
        {

                    int mid=start+(end-start)/2;
                    int mid_num=matrix[mid/column][mid%column];

                    
                if (mid_num==target)
                {
                    result=true;
                    break;
                }
                
                if (mid_num>target)
                {
                        end=mid-1;
                }
                else{
                    start=mid+1;

                }



                




        }
        return result;
        
        
        





    }
};