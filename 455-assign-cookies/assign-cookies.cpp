class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int countg = 0;
        int counts = 0;
        while(countg < n && counts < m){
            if(s[counts] >= g[countg]){
                countg++;
            }
            counts++;
        }
        return countg;
    }
};