import os
from typing import List

import pandas as pd

from config import storage, col


def parse_str(prompt: str, default: str, use_default: bool, use_null: bool) -> str:
    s = input(f'{prompt} ({default}): ')
    if not s:
        if use_default:
            return default
        elif use_null:
            return ''
        else:
            print(f'{prompt} is needed.')
            return parse_str(prompt, default, use_default, use_null)
    return s


def parse_int(prompt: str, default: str, use_default: bool, use_null: bool) -> int:
    s = parse_str(prompt, default, use_default, use_null)
    if not s and use_null:
        return 0
    try:
        i = int(s)
        return i
    except ValueError:
        print(f'{prompt} should be an integer.')
        return parse_int(prompt, default, use_default, use_null)


def parse_time(prompt: str, default: str, use_default: bool, use_null: bool) -> pd.Timestamp:
    s = parse_str(prompt, default, use_default, use_null)
    if not s and use_null:
        return pd.Timestamp.now()
    try:
        t = pd.Timestamp(s)
        return t
    except ValueError:
        print(f'{prompt} should be in the format like {default}.')
        return parse_time(prompt, default, use_default, use_null)


def get_new_problem(dff: pd.DataFrame) -> List:
    idx = parse_int('Index', '0', False, False)
    while idx in dff.idx.values:
        print(f'{idx} has already existed.')
        idx = parse_int('Index', '0', False, False)
    problem = parse_str('Problem', 'Two Sum', False, False)
    while problem in dff.problem.values:
        print(f'{problem} has already existed.')
        problem = parse_str('Problem', 'Two Sum', False, False)
    create_time = parse_time('Create Time', '2020-01-01', False, True)
    return [idx, problem, create_time, create_time, 1, 1]


if __name__ == '__main__':
    if os.path.exists(storage):
        df = pd.read_pickle(storage)
    else:
        df = pd.DataFrame(columns=col)

    new_problems = []
    while True:
        new_problems.append(get_new_problem(df))
        if not input('Add new problem? (y/N)').lower() == 'y':
            break
    new_df = pd.DataFrame(data=new_problems, columns=col)
    df = pd.concat([df, new_df], ignore_index=True)
    df.to_pickle(storage)
