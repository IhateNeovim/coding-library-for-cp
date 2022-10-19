struct DSU {
	vector<int> e;
	DSU(int N) { 
		e = vector<int>(N, -1); 
	}

	int get(int x) { 
		return e[x] < 0 ? x : e[x] = get(e[x]); 
	}

	int size(int x) { 
		return -e[get(x)]; 
	}

	bool unite(int x, int y) { 
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};
