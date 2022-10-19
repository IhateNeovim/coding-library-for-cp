#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) {
    return a + rng() % (b - a + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

}	
