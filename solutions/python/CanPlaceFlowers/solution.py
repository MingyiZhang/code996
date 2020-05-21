from typing import List


def can_place_flowers(flowerbed: List[int], n: int) -> bool:
    for i in range(len(flowerbed)):
        if not n:
            break
        if not flowerbed[i] \
                and (i == 0 or not flowerbed[i - 1]) \
                and (i == len(flowerbed) - 1 or not flowerbed[i + 1]):
            flowerbed[i] = 1
            n -= 1
    return not n


if __name__ == '__main__':
    assert (can_place_flowers([1, 0, 0, 0, 1], 1))
    assert (not can_place_flowers([1, 0, 0, 0, 1], 2))
    assert (can_place_flowers([0, 0, 1, 0, 0], 1))
    assert (can_place_flowers([0, 0, 0, 1, 0], 0))
