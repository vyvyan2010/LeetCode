#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        long long temp = 0;
        bool rev = false;
        int pos = 0;
        
        while(str[pos] == ' ')
        {
            pos++;
        }
        
        if(str[pos] == '-')
        {
            rev = true;
            pos++;
        }
        else if(str[pos] == '+')
        {
            pos++;
        }        
        
        for(int i = pos; i < str.length(); i++)
        {
            if(str[i]<='9' && str[i] >= '0')
            {
                temp = temp*10 + (str[i] - '0');
                if(temp >= pow(2, 31) - 1 && rev == false)
                {
                    temp = pow(2, 31) - 1;
                    break;
                }
                else if(temp >= pow(2, 31)  && rev == true)
                {
                    temp = -pow(2, 31) ;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        
        if(rev == true)
        {
            ans = (int)-temp;
        }
        else
        {
            ans = (int)temp;
        }

        return ans;
    }
};


int main()
{
     Solution s1;
     string value ("-0123111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");

     cout<<s1.myAtoi(value)<<endl;
}


// "-0123111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"