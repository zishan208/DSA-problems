class Solution {
public:
    NestedInteger deserialize(string s) {
      
        if (s[0] != '[') {
            return NestedInteger(stoi(s)); 
        }

        stack<NestedInteger> st;
        
        int n = s.length();
        int i = 0; 

        while (i < n) {
            char ch = s[i];

          
            if (ch == '[') {
                NestedInteger newList;
                st.push(newList);    
                i++;
            }

          
            else if (ch == ']') {
                NestedInteger completedList = st.top(); 
                st.pop();                          

               
                if (!st.empty()) {
                    st.top().add(completedList);
                } else {
                  
                    return completedList;
                }
                i++;
            }

            else if (ch == ',') {
                i++;
            }

         
            else {
       
                bool isNegative = false;
                if (s[i] == '-') {
                    isNegative = true;
                    i++;
                }

                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

           
                if (isNegative) {
                    num = -num;
                }

           
                NestedInteger numObj;
                numObj.setInteger(num);

             
                st.top().add(numObj);
            }
        }

        return st.top();
    }
};