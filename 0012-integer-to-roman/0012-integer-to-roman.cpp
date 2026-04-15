#include <string>
    class Solution {
public:
    string intToRoman(int num) {
        string result="";
        if (num==0)
        {
            return result;
        }
        

        //break num into....
        int thousand=num/1000;
        int hundred=(num % 1000)/100;
        int ten= (num % 100)/10;
        int one=num % 10;

string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
string thousands[] = {"", "M", "MM", "MMM"};
string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
string ones[]     = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        //NOW PUSH accordingly
        result=result+thousands[thousand]+hundreds[hundred]+tens[ten]+ones[one];

        return result;

        
    }
};



        
    
