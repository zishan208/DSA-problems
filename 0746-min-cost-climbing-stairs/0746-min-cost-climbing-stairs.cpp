class Solution {

private:
int find(vector<int>& cost,int step_count,vector<int>& methods){
    if(step_count>=cost.size()) return 0;


    if(methods[step_count]!=-1) return methods[step_count];

    int oneStep = cost[step_count] + find(cost, step_count + 1, methods);
      int twoSteps = cost[step_count] + find(cost, step_count + 2, methods);


    methods[step_count] = min(oneStep, twoSteps);
        return methods[step_count];



}

public:
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> methods(cost.size()+1,-1);
        
         return min(find(cost,0,methods),find(cost,1,methods));
        
    }
};