import pytest

from LetterCombinations.solution import letter_combinations


@pytest.mark.parametrize(
    "digits, expected",
    [(
            "23",
            ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
    ), (
            "",
            []
    )]
)
def test_letter_combinations(digits, expected):
    assert set(expected) == set(letter_combinations(digits))
