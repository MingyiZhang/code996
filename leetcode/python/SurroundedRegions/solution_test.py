import pytest

from SurroundedRegions.solution import solve


@pytest.mark.parametrize(
    "board, expected",
    [(
            [['X', 'X', 'X', 'X'],
             ['X', 'O', 'O', 'X'],
             ['X', 'X', 'O', 'X'],
             ['X', 'O', 'X', 'X']],
            [['X', 'X', 'X', 'X'],
             ['X', 'X', 'X', 'X'],
             ['X', 'X', 'X', 'X'],
             ['X', 'O', 'X', 'X']]
    ), (
            [['X', 'O', 'X'],
             ['X', 'O', 'X'],
             ['X', 'O', 'X']],
            [['X', 'O', 'X'],
             ['X', 'O', 'X'],
             ['X', 'O', 'X']]
    )]
)
def test_solve(board, expected):
    solve(board)
    assert expected == board
