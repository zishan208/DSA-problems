class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {


                int remained=0;
                int n=gas.size();
                int start=0;
                int t=0;

                for(int i=0;i <n ;i++){
                    remained+=gas[i];


                    if(remained >=cost[i]){
                        remained-=cost[i];

                    }else{
                        if(i+1<n){
                        start=i+1;
                        }
                        remained=0;
                    }
                    t=t+gas[i]-cost[i];

                }

                return t>=0 ? start : -1;

        
    }
};