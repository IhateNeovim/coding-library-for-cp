const int V = (int) 2e5 + 1;
vector<Mint> fact(V+1), ifact(V+1);

fact[0] = 1;
for (int i = 1; i <= V; i++) fact[i] = fact[i-1] * Mint(i);

ifact[V] = inv(fact[V]);
for (int i = V; i >= 1; i--) ifact[i-1] = ifact[i] * Mint(i);
 
auto ncr = [&] (int a, int b) {
	Mint res = fact[a] * ifact[a - b] * ifact[b];
	return res;	 	
};
