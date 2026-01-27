
class Solution {
    
public:
    int romanToInt(string s) {

        // or numbe rmaade by afddition
        int num=0;
        // priority list=M>D>C>L>X>V>I
        //we map elemnt here
        string list="MDCLXVI";
        int list_data[7]={1000,500,100,50,10,5,1};

        // now calculate
        for (int i = 0; i < s.size()-1; i++)
        {
            char roman1=s[i];
            char roman2=s[i+1];
            //we unknown about elemnt we gwt .now,find index for compare;
            int index1=list.find(roman1);
            int index2=list.find(roman2);
            if (list_data[index1]<list_data[index2])
            {
                num=num-list_data[index1];
            }
            else{
                

                num=num+list_data[index1];
            }

        }
        int pos=list.find(s[s.size()-1]);
       num=num+list_data[pos];

return num;

    }
};

