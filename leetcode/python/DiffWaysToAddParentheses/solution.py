from typing import List, Dict


def operator_helper(x: int, y: int, op: str) -> int:
    if op == '+':
        return x + y
    elif op == '-':
        return x - y
    elif op == '*':
        return x * y


def dynamic_programming(input: str, mp: Dict[str, List[int]]) -> List[int]:
    if input in mp:
        return mp[input]
    if input.isdigit():
        mp[input] = [int(input)]
        return mp[input]

    ret = list()
    for i, c in enumerate(input):
        if c in '+-*':
            str1 = input[:i]
            if str1 in mp:
                ret1 = mp[str1]
            else:
                ret1 = dynamic_programming(str1, mp)
                mp[str1] = ret1
            str2 = input[i + 1:]
            if str2 in mp:
                ret2 = mp[str2]
            else:
                ret2 = dynamic_programming(str2, mp)
            for x in ret1:
                for y in ret2:
                    ret.append(operator_helper(x, y, c))
    mp[input] = ret
    return ret


def diff_ways_to_compute_dynamic_programming(input: str) -> List[int]:
    mp = dict()
    return dynamic_programming(input, mp)


def diff_ways_to_compute_divide_conquer(input: str) -> List[int]:
    if input.isdigit():
        return [int(input)]
    ret = []
    for i, c in enumerate(input):
        if c in '+-*':
            str1 = input[:i]
            str2 = input[i + 1:]
            ret1 = diff_ways_to_compute_divide_conquer(str1)
            ret2 = diff_ways_to_compute_divide_conquer(str2)
            for x in ret1:
                for y in ret2:
                    ret.append(operator_helper(x, y, c))
    return ret


if __name__ == '__main__':
    print(diff_ways_to_compute_dynamic_programming("2-1-1"))
    print(diff_ways_to_compute_dynamic_programming('2*3-4*5'))
    print(diff_ways_to_compute_divide_conquer("2-1-1"))
    print(diff_ways_to_compute_divide_conquer("2*3-4*5"))
