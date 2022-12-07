#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Hash{
	int m; 	// Modulo, opciones: 1e9+7, 1e9+9, 1e9+123
	int b, b2; 	// Base, mayor que el número de elementos distintos. 
					// Algunos dicen que mayor al mayor valor de los elementos.
					// Opciones: 31, 127, 139
	std::vector<int> pot, H, H2;
	int n;
	Hash(T &s, int b = 139, int m = 1e9+7) : b(b), m(m), n(s.size()) {
		pot.resize(n + 1); H.resize(n + 1);
		H[n - 1] = s[n - 1];
		for (int i = n - 2; i >= 0; i --)
			H[i] = (s[i] + H[i + 1] * b) % m;
		pot[0] = 1;
		for (int i = 1; i <= n; i ++)
			pot[i] = (pot[i - 1] * b) % m;
	}
	// Calcula el hash del substring que parte en i de largo k.
	// k debería ser mayor a 0.
	int hash(int i, int k){
		if (i + k <= n) 
			return (m + H[i] - (H[i + k] * pot[k] % m)) % m;
		return (hash(i, n - i) + hash(0, k - (n - i)) * pot[n - i]) % m;
	}
};
