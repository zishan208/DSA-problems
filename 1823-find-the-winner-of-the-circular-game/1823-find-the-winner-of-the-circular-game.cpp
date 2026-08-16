class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
       for(int i=1;i<=n;i++){
        q.push(i);
       }
       int count=0;
      while(q.size()!=1){
        count++;
        if(count==k){
            count=0;
            q.pop();
        }else{
            int temp=q.front();
            q.pop();
            q.push(temp);

        }

      }

      return q.front();
        

    }
};