class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        for(int a:arr)
        {
            freq[a]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto itr:freq)
        {
            pq.push({itr.second,itr.first});
            // {
            //     if(pq.size()>k)
            //     pq.pop();
            // }
        }
        while(!pq.empty() && k>=pq.top().first)
        {
            k=k-pq.top().first;
            pq.pop();
        }
        
        
        return pq.size();
    }
};