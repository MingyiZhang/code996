import pytest

from ValidParentheses.solution import is_valid


@pytest.mark.parametrize(
    's, expected',
    [
        (
                '()',
                True
        ),
        (
                '[(]',
                False
        )
    ]
)
def test_is_valid(s, expected):
    assert expected == is_valid(s)