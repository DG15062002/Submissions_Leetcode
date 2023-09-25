class Solution {
public:
    char findTheDifference(string s, string t) {
         char res;
        map<char,int> m1,m2;
        map<char,int>::iterator it;
        for(int i=0;i<s.length();i++)
        {
            m1[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            m2[t[i]]++;
        }
        for(it=m2.begin();it!=m2.end();it++)
        {
            if(it->second!=m1[it->first])
            {res=it->first;
             break;
            }
        }
        return res;
    }
};