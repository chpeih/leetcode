/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        const int n = points.size();
        if(0==n || 1==n)return n;
        vector<int> visit;
        int ans = -1;
        map<float,int> mp;
        for (int i = 0;i<n;++i)visit.push_back(0);
        int same,line;
        for(int i = 0;i<n;i++)if(!visit[i]){
            same = 1;
            line  = 0;
            visit[i] = 1;
            mp.clear();
            for (int j = 0;j<n;++j)if(i!=j){
                if (points[i].x==points[j].x && points[i].y==points[j].y)same++,visit[j] = 1;
                else if(points[i].x==points[j].x)line++;
                else {
                    float k = ((float)points[i].y-points[j].y)/(points[i].x-points[j].x);
                    mp[k]++;
                }
            }
            int cnt = line;
            for(map<float,int>::iterator it = mp.begin();it!=mp.end();++it){
                cnt = max(cnt,it->second);
            }
            ans = max(ans,same+cnt);
        }
        return ans;
    }
};
