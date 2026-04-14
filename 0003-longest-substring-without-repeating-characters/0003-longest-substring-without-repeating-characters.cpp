class Solution {
private:

    
    bool isrepeated(string temp){

        map<char,int> mp;

        for (int i = 0; i < temp.length(); i++)
        {
           if(mp[temp[i]]!=0){
            return true;
           }else{
            mp[temp[i]]++;
           }
        }
        return false;


    }
public:
    int lengthOfLongestSubstring(string s) {

            
        int size=s.length();
        int maxlength=0;

        for (int i = 0; i<size; i++)
        {
            string temp;
            for (int j=i;j<size;j++)
            {
                //now 
               temp=temp+s[j];

               //now each time we have temp
               if(!isrepeated(temp)){

                if (temp.length()>maxlength)
                {
                    maxlength=temp.length();
                }
               }    
            }
        }
            return maxlength;
            

        
    }
};