class Solution {
public:
    bool hasDuplicate(string &s1, string &s2)
    {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(auto& x: s1)
        {
            freq1[x - 'a']++;
        }

        for(auto& x: s2)
        {
            freq2[x-'a']++;
        }

        for(int i=0; i<26;i++)
        {
            if(freq1[i] > 0 && freq2[i]>0 || freq1[i]>1 || freq2[i]>1)
                return true;
        }
        return false;

    }
    int solve(int i, int n, vector<string>& arr, string tmp)
    {
        if(i>=n)
            return tmp.size();

        int include = 0;
        int exclude = 0;

        if(hasDuplicate(tmp, arr[i])) //if it has duplicate we can't take obv
        {   
            exclude = solve(i+1, n, arr, tmp);
        }
        else
        {
            exclude = solve(i+1, n, arr, tmp);
            include = solve(i+1, n, arr, tmp + arr[i]);
        }
        return max(exclude,include);
    }
    int maxLength(vector<string>& arr) {
        
        string tmp = "";
        int n = arr.size();

        int i=0;
        return solve(i,n,arr,tmp);
    }
};