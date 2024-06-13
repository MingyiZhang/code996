from codeforce_utils import inp, int_lst

def can_add(i, sums: set, k):
    new_sums = {i}
    for s in sums:
        x = s + i
        if x == k:
            return False
        if x > k:
            break
        new_sums.add(x)
    sums.update(new_sums)
    return True


def solve_single():
    n, k = int_lst()
    sums = {0}
    ans = []
    for i in range(1, n + 1):
        if can_add(i, sums, k):
            ans.append(f"{i}")
    print(len(ans))
    print(" ".join(ans))


def solve():
    for _ in range(inp()):
        solve_single()

if __name__ == "__main__":
    solve()