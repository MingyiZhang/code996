def is_valid(s: str) -> bool:
    stack = []
    pairs = {'(': ')', '[': ']', '{': '}'}

    for c in s:
        if c in pairs:
            stack.append(c)
        else:
            if len(stack) == 0 or pairs[stack[-1]] != c:
                return False
            stack.pop(len(stack) - 1)
    return len(stack) == 0
