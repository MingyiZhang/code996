import pytest

from FriendCircles.solution import find_circle_num


@pytest.mark.parametrize(
    "m, expected",
    [(
            [[1, 1, 0],
             [1, 1, 0],
             [0, 0, 1]],
            2
    ), (
            [[1, 1, 0],
             [1, 1, 1],
             [0, 1, 1]],
            1
    ), (
            [[1, 0, 0, 1],
             [0, 1, 1, 0],
             [0, 1, 1, 1],
             [1, 0, 1, 1]],
            1
    )]
)
def test_find_circle_num(m, expected):
    assert expected == find_circle_num(m)
