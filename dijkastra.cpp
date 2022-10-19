template<class C, bool directed> struct Dijkstra {
	int SZ; vector<C> dist; 
	vector<vector<pair<int,C>>> adj;
	
	void init(int _SZ) { 
		SZ = _SZ; adj.clear(); adj.resize(SZ); 
	}
	
	void ae(int u, int v, C cost) {
		adj[u].push_back({v,cost}); if (!directed) adj[v].push_back({u,cost}); 
	}
	
	void gen(int st) {
		dist.assign(SZ,numeric_limits<C>::max());
		using T = pair<C,int>; priority_queue<T,vector<T>,greater<T>> pq; 
		auto ad = [&](int a, C b) {
			if (dist[a] <= b) return;
			pq.push({dist[a] = b,a});
		}; 
		
		ad(st,0);
		
		while (pq.size()) {
			T x = pq.top(); pq.pop(); if (dist[x.second] < x.first) continue;
			for (auto& y : adj[x.second]) ad(y.first, x.first + y.second);
		}
	}
};
