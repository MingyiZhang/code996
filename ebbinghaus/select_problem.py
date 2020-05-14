import os

import numpy as np
import pandas as pd

from config import storage


def get_weight(row, tc: pd.Timestamp):
    dt = (tc - row.last_time) / np.timedelta64(1, 'h') / 24
    return 1 - np.exp(- dt / (row.practice + row.remember))


if __name__ == '__main__':
    if not os.path.exists(storage):
        print(f'{storage} doesn\'t exist.')
        exit(0)
    df = pd.read_pickle(storage)
    tc = pd.Timestamp.now()
    do_next = True
    while do_next:
        # Calculate weights based on forgetting curve
        df['r'] = df.apply(lambda row: get_weight(row, tc), axis=1)
        print(df)
        # sample a problem based on weights, get index
        sample = df.sample(n=1, weights='r')
        idx = sample.idx.values[0]
        problem = sample.problem.values[0]
        print(f'Practice problem {idx}. {problem}.')
        is_mem = input('Remembered? (y/N): ')
        if is_mem.lower() == 'y':
            df.loc[df.idx == idx, 'remember'] += 1
        df.loc[df.idx == idx, 'practice'] += 1
        print(df)
        if input('Next problem? (y/N): ').lower() == 'y':
            do_next = True
        else:
            do_next = False
    df.to_pickle(storage)
