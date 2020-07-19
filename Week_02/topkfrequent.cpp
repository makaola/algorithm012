class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> r;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> fre_cor_num;
        //build hash map
        for(int i=0; i<nums.size(); ++i){
            if(fre_cor_num[nums[i]]){
                fre_cor_num[nums[i]] += 1;
            }else{
                fre_cor_num[nums[i]] = 1;
            }
        }

        for(auto it: fre_cor_num){
            if(pq.size() == k){
                if(it.second > pq.top().first){
                    pq.pop();
                    pq.push(make_pair(it.second, it.first));
                }
            }else{
                pq.push(make_pair(it.second, it.first));
            }
        }
        
        while(pq.size()){
            r.push_back(pq.top().second);
            pq.pop();
        }

        return vector<int>(r.rbegin(), r.rend());
    }
};
