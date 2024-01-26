class Solution:
    def findPaths(
        self, m: int, n: int, maxMove: int, startRow: int, startColumn: int
    ) -> int:
        ROWS, COLS = m, n
        Mod = 10**9 + 7

        memo = {}

        def dfs(r, c, moves):
            if r < 0 or r == ROWS or c < 0 or c == COLS:
                return 1
            if moves == 0:
                return 0

            if (r, c, moves) in memo:
                return memo[(r, c, moves)]

            paths = (
                (dfs(r + 1, c, moves - 1) + dfs(r - 1, c, moves - 1)) % Mod
                + (dfs(r, c + 1, moves - 1) + dfs(r, c - 1, moves - 1)) % Mod
            ) % Mod

            memo[(r, c, moves)] = paths
            return paths

        return dfs(startRow, startColumn, maxMove)
