class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    //create a result vector
    vector<int> res(temperatures.size(),0);
    //create a stack
    stack <pair<int,int>> st; //storing it in {temp, index}

    for(int i = 0; i < temperatures.size(); i++)
    {
        int t = temperatures[i];
        while(!st.empty() and t > st.top().first)
        {
            auto p = st.top();
            st.pop();
            res[p.second] = i - p.second;
        }
        st.push({t,i});
    }
    return res;
    }
};