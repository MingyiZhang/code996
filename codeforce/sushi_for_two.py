def inp():
    return int(input())


def int_lst():
    return list(map(int, input().split()))


def c_lst():
    return list(input())


def int_lst_split():
    return map(int, input().split())


def solve():
    n = inp()
    aa = int_lst()
    curr_length = 0
    prev_length = None
    the_length = None
    fish = aa[0]
    for a in aa:
        if a == fish:
            curr_length += 1
        else:
            if prev_length is None:
                prev_length = curr_length
                curr_length = 1
                fish = a
            else:
                propose_length = min(prev_length, curr_length)
                if the_length is None:
                    the_length = propose_length
                else:
                    the_length = max(the_length, propose_length)
    
    min_length = min(min_length, curr_length)
    if count_flip == 1:
        print(0)
    else:
        print(min_length * 2)
 

if __name__ == "__main__":
    solve()
