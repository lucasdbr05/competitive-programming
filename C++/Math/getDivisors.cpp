vector<pii> factorization(int n) {
    vector<pii> factorization;
    int aux = 0;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            aux++;
            n /= d;
        }
        if(aux>0) {
            factorization.emplace_back(d, aux);
            aux = 0;
        }
    }
    if (n > 1)
        factorization.emplace_back(n, 1);
    return factorization;
}

vector<int> divisores(int n) {
    vector<pii> fatores = factorization(n);
    int cnt_divisores = 1;
    for(auto [ignore, expoente] : fatores) cnt_divisores *= expoente + 1;
    vector<int> divisores;
    divisores.reserve(cnt_divisores);
    divisores.push_back(1);
    for(auto [fator, expoente] : fatores) {
        int sz = (int)divisores.size();
        int k = fator;
        for(int j = 1; j <= expoente; j++, k *= fator) {
        for(int i = 0; i < sz; i++) {
            divisores.push_back(k * divisores[i]);
        }
        }
     }
    return divisores;
}
