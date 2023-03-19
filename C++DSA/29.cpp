vector<int> sumInRanges(vector<int> &A, int n, vector<vector<long long>> &q, int m) {
long long  mo = 1000000007;
vector <int> ans(m);
vector <long long> presum(n+1);
presum[0] = 0;
for(long long i = 0; i < n; i++)
    presum[i+1] = (presum[i] + A[i]) % mo;
long long temp;
for(long long i = 0; i < m; i++)
{
    long long l=q[i][0];
    long long r=q[i][1];
    l--;
    temp = (presum[r % n] - presum[l % n] + ((presum[n] * ((r/n - l/n) % mo)))) % mo ;
    ans[i] = temp;
}
return ans;
}