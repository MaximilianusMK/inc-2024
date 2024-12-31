#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const int MXN = 1e5, MXM = 2e5, MXA = 26, INF = 1e9;

struct Trie
{
	int dep, pos;
	Trie *p[MXA];
	
	inline void bld(int curDep)
	{
		dep = curDep;
		pos = 0;
		for(int i = 0; i < MXA; i++)
		{
			p[i] = 0;
		}
	}
	void ins(string &s, int curPos)
	{
		if(dep < (int)s.length())
		{
			int k = s[dep] - 'A';
			if(!p[k])
			{
				p[k] = new Trie;
				p[k]->bld(dep + 1);
			}
			p[k]->ins(s, curPos);
		}
		else
		{
			pos = curPos;
		}
	}
};

int N[2], M = 0, cap[MXM * 4 + 69];
vector<pair<int, int>> adj[MXN * 2 + 69];

inline void addEdge(int u, int v)
{
	adj[u].push_back({v, M});
	adj[v].push_back({u, M + 1});
	cap[M] = 1;
	cap[M + 1] = 0;
	M += 2;
}

vector<pair<int, int>> par[MXN * 2 + 69];
bitset<MXN * 2 + 69> matched, vis;

bool dfs(int u)
{
	vis[u] = true;
	
	if(u <= N[0] && !matched[u])
	{
		matched[u] = true;
		return 1;
	}
	
	for(int i = 0; i < (int)par[u].size(); i++)
	{
		int v, p;
		v = par[u][i].fr;
		p = par[u][i].sc;
		
		if(!vis[v])
		{
			if(dfs(v))
			{
				matched[u] = true;
				cap[p]--;
				cap[p ^ 1]++;
				return 1;
			}
		}
	}
	
	return 0;
}

int main()
{
	int D;
	scanf("%d", &D);
	
	string W[D + 69];
	for(int i = 1; i <= D; i++)
	{
		cin >> W[i];
	}
	
	string A[2][MXN + 69];
	Trie trie[2][2];
	for(int ii = 0; ii < 2; ii++)
	{
		scanf("%d", N + ii);
		for(int i = 1; i <= N[ii]; i++)
		{
			cin >> A[ii][i];
		}
		
		for(int jj = 0; jj < 2; jj++)
		{
			trie[ii][jj].bld(0);
			for(int i = 1; i <= N[ii]; i++)
			{
				trie[ii][jj].ins(A[ii][i], i);
			}
			
			for(int i = 1; i <= N[ii]; i++)
			{
				reverse(A[ii][i].begin(), A[ii][i].end());
			}
		}
	}
	
	for(int i = 1; i <= D; i++)
	{
		for(int ii = 0; ii < 2; ii++)
		{
			int posses[2][W[i].length() + 69];
			Trie *cur;
			
			cur = &trie[ii][0];
			for(int j = 0; j < (int)W[i].length(); j++)
			{
				int k = W[i][j] - 'A';
				
				if(cur)
				{
					cur = cur->p[k];
				}
				
				if(cur)
				{
					posses[0][j] = cur->pos;
				}
				else
				{
					posses[0][j] = 0;
				}
			}
			
			cur = &trie[!ii][1];
			for(int j = (int)W[i].length() - 1; j >= 0; j--)
			{
				int k = W[i][j] - 'A';
				
				if(cur)
				{
					cur = cur->p[k];
				}
				
				if(cur)
				{
					posses[1][j] = cur->pos;
				}
				else
				{
					posses[1][j] = 0;
				}
			}
			
			for(int j = 0; j < (int)W[i].length() - 1; j++)
			{
				if(posses[0][j] != 0 && posses[1][j + 1] != 0)
				{
					if(ii == 0)
					{
						addEdge(posses[0][j], N[0] + posses[1][j + 1]);
					}
					else
					{
						addEdge(posses[1][j + 1], N[0] + posses[0][j]);
					}
				}
			}
		}
	}
	
	int ans = 0;
	while(true)
	{
		int dis[N[0] + N[1] + 69];
		for(int i = 1; i <= N[0] + N[1]; i++)
		{
			dis[i] = INF;
		}
		
		queue<int> q;
		for(int i = 1; i <= N[0]; i++)
		{
			if(!matched[i])
			{
				q.push(i);
				dis[i] = 0;
			}
		}
		
		vector<int> leaves;
		int maxDis = INF;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			
			if(dis[u] >= maxDis)
			{
				continue;
			}
			
			for(int i = 0; i < (int)adj[u].size(); i++)
			{
				int v, p;
				v = adj[u][i].fr;
				p = adj[u][i].sc;
				
				if(cap[p] > 0)
				{
					if(dis[u] + 1 < dis[v])
					{
						q.push(v);
						dis[v] = dis[u] + 1;
						par[v].clear();
						
						if(v > N[0] && !matched[v])
						{
							leaves.push_back(v);
							maxDis = dis[v];
						}
					}
					
					if(dis[u] + 1 == dis[v])
					{
						par[v].push_back({u, p});
					}
				}
			}
		}
		
		if(leaves.empty())
		{
			break;
		}
		
		vis.reset();
		for(int i = 0; i < (int)leaves.size(); i++)
		{
			ans += dfs(leaves[i]);
		}
	}
	printf("%d\n", ans);
}
