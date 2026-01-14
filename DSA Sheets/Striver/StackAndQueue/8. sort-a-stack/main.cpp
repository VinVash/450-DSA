#include <bits/stdc++.h>

void sortedInsert(stack<int> &stk, int x)
{
    if (stk.empty() || x > stk.top())
    {
        stk.push(x);
        return;
    }

    int temp = stk.top();
    stk.pop();

    sortedInsert(stk, x);

    stk.push(temp);
}

void sortStack(stack<int> &stack)
{
    if (!stack.empty())
    {
        int x = stack.top();
        stack.pop();

        sortStack(stack);

        sortedInsert(stack, x);
    }
}