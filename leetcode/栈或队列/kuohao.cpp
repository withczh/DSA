#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        int i=0;
        if(s.length()<=1) return false;
        while(s[i]!='\0'){
            switch (s[i])
            {
            case '(':
                stack.push(s[i]);
                break;
            case '[':
                stack.push(s[i]);
                break;
            case '{':
                stack.push(s[i]);
                break;
            case ')':
                if(!stack.empty()&&stack.top()=='('){
                    stack.pop();
                }
                else return false;
                break;
            case ']':
                if(!stack.empty()&&stack.top()=='['){
                    stack.pop();
                }
                else return false;
                break;
            case '}':
                if(!stack.empty()&&stack.top()=='{'){
                    stack.pop();
                }
                else return false;
                break;
            default:
                break;
            }
            i++;
        }
        if(stack.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    Solution so;
    string s;
    cin>>s;
    if(so.isValid(s)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
    
    return 0;
}