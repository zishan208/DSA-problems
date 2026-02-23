

 class Solution {
  public:
    int  canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
       // ith station of gas[i] available
       //cost means distamce travel from ith to ith+1
       int net_petrol=0;
       int start=0;
       int kami=0;
        int n=gas.size();
       for (int i = 0; i < n; i++)
       {
                net_petrol+=gas[i]-cost[i];
                if(net_petrol<0){
                    start=i+1;
                    kami+=net_petrol;
                    net_petrol=0;

                }
            
       }
      if(kami+net_petrol>=0) return start;

      return -1;
        
    }
};