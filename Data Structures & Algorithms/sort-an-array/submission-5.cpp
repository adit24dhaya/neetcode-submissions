class Solution {
public:
    vector<int> sortArray(vector<int>& nums) { 
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    void mergeSort(vector <int> &arr, int l, int r)
    {
        if (l>=r) return;

        int m = (l+r)/2;
        mergeSort(arr,l, m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
    void merge(vector <int> &arr, int l, int m, int r)
    {
        //create a temp arr
        vector <int> temp;
        //intialize int i and j as they work as a pointer
        int i = l, j = m+1;

        while(i<=m and j <= r)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i++]);
            }
            else{
                temp.push_back(arr[j++]);
            }
        }
        //any remaining left over elements in the arr are merged directly
        while(i<=m) temp.push_back(arr[i++]);
        while(j<=r) temp.push_back(arr[j++]);
        //copy the temp arr to the actual arr
        for(int i = l; i<=r;i++)
        {
            arr[i] = temp[i-l];
        }
    }
};