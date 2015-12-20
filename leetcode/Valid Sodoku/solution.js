/**********
 * Valid Sudoku
 * https://leetcode.com/problems/valid-sudoku/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 212ms | 2015.12.20 23:42 GMT+08
 * Beats 90.91% JS submissions
 */

/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
  'use strict'
  
  let rows = []
    , columns = []
    , squares = []
  
  for (let i = 0; i < 9; ++i) {
    rows.push(new Map())
    columns.push(new Map())
    squares.push(new Map())
  }
  
  for (let i = 0; i < 9; ++i) { // row
    for (let j = 0; j < 9; ++j) { // column
      let c = board[i][j]
      if (c !== '.') {
        let squareIndex = Math.floor(i/3) * 3 + Math.floor(j/3)
        if (rows[i].has(c)) return false
        if (columns[j].has(c)) return false
        if (squares[squareIndex].has(c)) return false
        rows[i].set(c, true)
        columns[j].set(c, true)
        squares[squareIndex].set(c, true)
      }
    }
  }
  return true
}