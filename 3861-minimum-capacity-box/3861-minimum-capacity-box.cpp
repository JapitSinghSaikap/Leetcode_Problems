class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minsz=INT_MAX;
        int mini = INT_MAX;
        for(int i = 0 ; i < capacity.size() ; i++)
            {
                if(capacity[i] >= itemSize)
                {
                    if(capacity[i] < minsz)
                    {
                        mini = i;
                        minsz = capacity[i];
                    }
                }
            }
        return mini == INT_MAX ? -1 : mini;
    }
};