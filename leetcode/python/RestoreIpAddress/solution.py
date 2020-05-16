from typing import List


def backtracking(prefix: str, rest: str, count: int, ip: List[str]) -> None:
    if count == 4 or len(rest) == 0:
        if count == 4 and len(rest) == 0:
            ip.append(prefix)
        return
    for i in range(0, min(len(rest), 3)):
        if i != 0 and rest[0] == '0':
            break
        part = rest[:i+1]
        if int(part) <= 255:
            if len(prefix) != 0:
                part = '.' + part
            prefix += part
            backtracking(prefix, rest[i+1:], count + 1, ip)
            prefix = prefix[:-len(part)]


def restore_ip_addresses(s: str) -> List[str]:
    ret = []
    backtracking('', s, 0, ret)
    return ret
