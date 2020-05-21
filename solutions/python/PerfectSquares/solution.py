from typing import List


def squares(n: int) -> List[int]:
    current = 1
    diff = 3
    ret = []
    while current <= n:
        ret.append(current)
        current += diff
        diff += 2
    return ret


def num_squares_bfs(n: int) -> int:
    sq = squares(n)
    visited = [False] * (n + 1)
    queue = [n]
    visited[n] = True
    count = 0
    while len(queue):
        count += 1
        q_size = len(queue)
        while q_size:
            q_size -= 1
            current = queue.pop(0)
            for s in sq:
                nxt = current - s
                if nxt < 0:
                    break
                if nxt == 0:
                    return count
                if visited[nxt]:
                    continue
                visited[nxt] = True
                queue.append(nxt)
    return count


if __name__ == '__main__':
    assert([1, 4, 9, 16] == squares(20))
    assert(3 == num_squares_bfs(12))
    assert(2 == num_squares_bfs(13))
