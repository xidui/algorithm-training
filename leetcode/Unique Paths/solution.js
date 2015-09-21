/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    if(obstacleGrid[0][0]===1||(obstacleGrid[0][1]===1&&(obstacleGrid[1]&&obstacleGrid[1][0]===1))){
        return 0;
    }
    var m = obstacleGrid.length;
    var n = obstacleGrid[0].length;
    var dp = [[1]];
    for(var i=1;i<m;i++){
        dp[i] = [(obstacleGrid[i][0]===1)?0:dp[i-1][0]];
    }
    for(var i=1;i<n;i++){
        dp[0][i] = (obstacleGrid[0][i]===1)?0:dp[0][i-1];
    }
    
    for(var i=1;i<m;i++){
        for(var j=1;j<n;j++){
            dp[i][j] = (obstacleGrid[i][j]===1)?0:(dp[i-1][j] + dp[i][j-1])
        }
    }
    
    return dp[m-1][n-1];
    
};