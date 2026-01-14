vector<int> Solution::prevSmaller(vector<int> &A)
{

    stack<int> stk;
    vector<int> ans;

    int n = A.size();

    if (n == 1)
    {
        ans.push_back(-1);
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        int num = A[i];

        if (stk.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            while (!stk.empty() && stk.top() >= num)
                stk.pop();

            if (stk.empty())
                ans.push_back(-1);
            else
                ans.push_back(stk.top());
        }
        stk.push(num);
    }

    return ans;
}
