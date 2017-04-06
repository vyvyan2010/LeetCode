class Solution(object):
    def uniquePaths(self, m, n):
        d = [[1 for i in range(n)] for j in range(m)]
        i= 1
        while i <= m-1:
            j = 1
            while j <= n-1:
                d[i][j] = d[i-1][j] + d[i][j-1]
                j = j + 1;
            i = i + 1
        return d[m-1][n-1]

ans = Solution();
path = ans.uniquePaths(3, 1);
print(path)