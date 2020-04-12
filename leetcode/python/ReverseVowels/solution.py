def reverse_vowels(s: str) -> str:
    i, j = 0, len(s) - 1
    lst = list(s)
    vows = 'aeiouAEIOU'
    while i < j:
        if lst[i] in vows and lst[j] in vows:
            lst[i], lst[j] = lst[j], lst[i]
            i += 1
            j -= 1
        elif lst[i] not in vows:
            i += 1
        else:
            j -= 1
    return ''.join(lst)


if __name__ == '__main__':
    assert(reverse_vowels('.,') == '.,')
