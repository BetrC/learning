#include <stack>
#include <assert.h>

class Solution {
public:

    // data stack
    stack<int> m_data;
    // min stack
    stack<int> m_min;


    void push(int value) {

        this->m_data.push(value);
        if(this->m_min.size() == 0 || this->m_min.top() > value){
            this->m_min.push(value);
            return;
        }
        this->m_min.push(this->m_min.top());

    }
    void pop() {
        assert(this->m_data.size() > 0 && this->m_min.size() > 0);

        this->m_data.pop();
        this->m_min.pop();

    }
    int top() {

        return this->m_data.top();
    }
    int min() {
        return this->m_min.top();
    }
};