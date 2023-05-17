from dataclasses import dataclass
from functools import cmp_to_key


@dataclass
class item:
    w: float
    v: float


def cmp(a: item, b: item):
    if a.v < b.v:
        return 1
    return -1


def mochila_frac(items: list, k: float) -> float:
    items.sort(key=cmp_to_key(cmp))
    cur_k = k
    value = 0
    i = 0
    while cur_k > 0 and i < len(items):
        qt = min(items[i].w, cur_k)
        value += items[i].v*qt
        cur_k -= qt
        i += 1
    return value


if __name__ == '__main__':
    items = [item(4, 3), item(8, 8), item(10, 12)]
    print(mochila_frac(items,12))
