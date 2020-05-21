package main

import (
  "bytes"
  "testing"
)

func TestSolve(t *testing.T) {
  tests := []struct {
    board    [][]byte
    expected [][]byte
  }{
    {
      board: [][]byte{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}},
      expected: [][]byte{
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'}},
    }, {
      board: [][]byte{
        {'X', 'O', 'X'},
        {'X', 'O', 'X'},
        {'X', 'O', 'X'}},
      expected: [][]byte{
        {'X', 'O', 'X'},
        {'X', 'O', 'X'},
        {'X', 'O', 'X'}},
    },
  }
  for _, tt := range tests {
    solve(tt.board)
    for i := 0; i < len(tt.expected); i++ {
      if !bytes.Equal(tt.expected[i], tt.board[i]) {
        t.Errorf("expected %v; got %v", tt.expected, tt.board)
      }
    }
  }
}
