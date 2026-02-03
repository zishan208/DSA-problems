
class Solution {
public:
        void toFind(string digits,int index,string output,vector<string> &result,vector<string> mapp){
            if (index>=digits.length())
            {
                result.push_back(output);
                return;
            }
                    int number=digits[index]-'0';
                    string value=mapp[number];
            
                    for (int i = 0; i < value.length(); i++)
                    {
                        output.push_back(value[i]);
                        toFind(digits,index+1,output,result,mapp);
                        output.pop_back();
                    }
                    



        }

    vector<string> letterCombinations(string digits) {

        int index=0;
        string output="";
        vector<string> result;
        vector<string> mapp={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        toFind(digits,index,output,result,mapp);
               return result;
    }
};