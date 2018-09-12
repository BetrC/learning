
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

// 思路：
//    1、使用压栈和出栈的方式
//    2、使用递归的方法实现(本质也是栈)

class PrintLinkedList
{
  public:
    vector<int> res;

    vector<int> printListFromTailToHead(ListNode *head)
    {

        if (head)
        {
            printListFromTailToHead(head->next);
            res.push_back(head->val);
        }
        return res;
    }
};