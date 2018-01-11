class Solution {
	public:
		int maxAreaOfIsland(vector< vector<int> > &grid)
		{
			int n = grid.size();
			if(n == 0) return 0;
			int m = grid[0].size();
			if(m==0) return 0;
			unordered_set<int> visit;
			queue<int> qe;
			int ans = 0;
			int dx[4] = {-1, 1, 0, 0};
			int dy[4] = {0, 0, 1, -1};
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<m;j++)
				{
					if(grid[i][j] == 1 && visit.find(i*m+j) == visit.end())
					{
						int sum = 0;
						qe.push(i*m+j);
						visit.insert(i*m+j);
						while(!qe.empty())
						{
							int cur = qe.front();
							sum++;
							qe.pop();
							int x = cur / m, y = cur % m;
							for(int k=0; k<4; k++)
							{
								int xx = x + dx[k];
								int yy = y + dy[k];
								if(xx < 0 || xx > m) continue;
								if(yy < 0 || yy > n) continue;
								if(grid[xx][yy]	== 1 && visit.find(xx*m+yy) == visit.end())
								{
									qe.push(xx*m+yy);
									visit.insert(xx*m+yy);
								}
							}
						}
						if(ans < sum) ans = sum;
					}
				}
			}
			return ans;
		}
		
}
