class Solution {
public:
    //Map & set
    /*int findJudge(int n, vector<vector<int>>& trust) {
        
        unordered_set<int> check;
        unordered_map<int, vector<int>> trustMap;
        
        for(auto a : trust){
            check.insert(a[0]);
            trustMap[a[1]].push_back(a[0]);
        }
        
        for(int i = 1;i <= n; i ++){
            if(check.count(i)) continue;
            if(trustMap[i].size() == n - 1) return i;
        }
        return -1;
    }*/
    //Array
    /*int findJudge(int n, vector<vector<int>>& trust){
        
        vector<int> check(n + 1);
        
        for(auto a : trust){
            check[a[0]] --;
            check[a[1]] ++;
        }
        
        for(int i = 1; i <= n; i ++){
            if(check[i] == n - 1) return i;
        }
        return -1;
    }*/
    //Adjacency list
    int findJudge(int n, vector<vector<int>>& trust) 
	{
        if(n == 1) return 1;
		vector<vector<int>> check(n+1);

		for(int i = 0; i < trust.size(); ++i){
            check[trust[i][1]].push_back(trust[i][1]);
        } 

		int tj = -1,max = 0;
		for(int i = 1; i <= n; ++i)
			if(check[i].size() > max) {tj = i; max = check[i].size();}
		if(max != n-1) return -1;
		for(int i = 0; i < trust.size(); ++i) if(trust[i][0] == tj) return -1; 

		return tj;
	}
};
