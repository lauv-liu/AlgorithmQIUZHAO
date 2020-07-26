class Solution {
public:
    typedef pair<int,int>Code;

    struct cmp{
        bool operator ()(Code a,Code b){
            return a.first>b.first;//Ð¡µÄ·Å×ó±ß,¼´less
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res;
        if(n <= 0 || k <= 0 || k > n){
            return res;
        }
        map<int,int>hash;
        for(int i = 0;i<n;++i){
            hash[nums[i]]++;
        }
        priority_queue<Code,vector<Code>,cmp>p;
        for(auto it : hash){
            Code c(it.second,it.first);
            p.push(c);
            while(p.size() > k){
                p.pop();
            }
        }
        while(!p.empty()){
            res.push_back(p.top().second);
            p.pop();
        }
        //sort(res.begin(),res.end(),less<int>)
        return res;
    }
};