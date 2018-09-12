//
// Created by Betr on 2018/9/11.
//

#include <stack>
#include <vector>

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {

        if(pushV.size( ) == 0 || popV.size( ) == 0)
        {
            return false;
        }

        stack<int> s;

        int push, pop;

        s.push(pushV[0]);

        for(pop = 0, push = 0; pop < popV.size() && push < pushV.size();){
            if(!s.empty() && s.top() == popV[pop])
            {
                s.pop();
                pop++;
            }
            else
            {
                s.push(++pushV[push]);
            }
        }

        return s.empty() ? true : false;
    }
};