#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main() {


    return 0;
}

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;

    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode *Clone(RandomListNode *pHead) {

        if (pHead == NULL) {
            return NULL;
        }

        RandomListNode *newHead = NULL;
        RandomListNode *oldHead = pHead;

        cloneNext(oldHead);
        oldHead = pHead;
        cloneRandom(oldHead);
        oldHead = pHead;
        return breakList(oldHead);
    }

    void cloneNext(RandomListNode *node) {


        while (node != NULL) {
            RandomListNode *newNode = new RandomListNode(node->label);

            newNode->next = node->next;
            node->next = newNode;

            node = newNode->next;
        }

    }

    void cloneRandom(RandomListNode *node) {

        while (node != NULL) {
            RandomListNode *newNode = node->next;

            if (node->random) {
                newNode->random = node->random->next;
            }

            node = newNode->next;

        }
    }

    RandomListNode *breakList(RandomListNode *node) {
        RandomListNode *newHead = node->next;

        RandomListNode *tmp;

        //
        while (node->next) {
            tmp = node->next;
            node->next = tmp->next;
            node = tmp;
        }
        return newHead;
    }
};

