#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize, n = *obstacleGridColSize;

    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

    long** res = (long**)calloc(m, sizeof(long*));
    for (int i = 0; i < m; i++) {
        res[i] = (long*)calloc(n, sizeof(long));
    }
    
    res[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                res[i][j] = 0;
            } else {
                if (i > 0) res[i][j] += res[i - 1][j];
                if (j > 0) res[i][j] += res[i][j - 1];
            }
        }
    }

    int result = res[m - 1][n - 1];
    for (int i = 0; i < m; i++) {
        free(res[i]);
    }
    free(res);

    return result;
}

int main() {
    int obstacleGrid1[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int* obstacleGrid1Ptrs[3] = {obstacleGrid1[0], obstacleGrid1[1], obstacleGrid1[2]};
    int obstacleGrid1ColSize = 3;
    printf("Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]\n");
    printf("Output: %d\n", uniquePathsWithObstacles(obstacleGrid1Ptrs, 3, &obstacleGrid1ColSize));

    int obstacleGrid2[2][2] = {{0, 1}, {0, 0}};
    int* obstacleGrid2Ptrs[2] = {obstacleGrid2[0], obstacleGrid2[1]};
    int obstacleGrid2ColSize = 2;
    printf("Input: obstacleGrid = [[0,1],[0,0]]\n");
    printf("Output: %d\n", uniquePathsWithObstacles(obstacleGrid2Ptrs, 2, &obstacleGrid2ColSize));

    return 0;
}
