class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<int> temp;
        vector<vector<int>> res;
        res={{1},{1,1}};
         if(n==0) return {};
         if(n==1) return {{1}};
        if(n==2) return res;
        for(int i=3;i<=n;i++){
            temp.clear();
            temp.push_back(1);
            for(int j=0;j<res[i-2].size()-1;j++){
                temp.push_back(res[i-2][j]+res[i-2][j+1]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};
