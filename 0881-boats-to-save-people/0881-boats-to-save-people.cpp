class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        int e=people.size()-1;
        int s=0;
        int count=0;

        sort(people.begin(),people.end());

        while(s<=e){

            if(people[s]+people[e] <= limit){
                    s++;
            }
            e--;
            count++;

        }

        return count;
        
    }
};