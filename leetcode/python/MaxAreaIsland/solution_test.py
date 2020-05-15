import pytest

from MaxAreaIsland.solution import max_area_of_island


@pytest.mark.parametrize(
    "grid, expected",
    [
        (
                [[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
                 [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
                 [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
                 [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
                 [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
                 [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
                 [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
                 [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]],
                6
        ),
        (
                [[0, 0, 0, 0, 0, 0, 0, 0]],
                0
        )
    ]
)
def test_max_area_of_island(grid, expected):
    assert expected == max_area_of_island(grid)
