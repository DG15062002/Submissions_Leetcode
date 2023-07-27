class Solution {
public:
    string reverseWords(string s) {string newstr="",temp="",newstr1="";

        for(auto it=s.begin();it!=s.end();it++)

        {

            if(*it!=' ')

            temp+=(*it);

            else

            {

                if(temp!="")

                {temp=" "+temp;

                newstr=temp+newstr;

                temp="";

            }    

        }

        }

        if(temp!="")

            newstr=temp+newstr;

        if(newstr.at(0)==' ')

            newstr.erase(newstr.begin());

         return newstr;   
    }
};