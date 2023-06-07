from dataclasses import dataclass
from functools import cmp_to_key


@dataclass
class item:
    w: float
    v: float
    idx: int


def cmp(a: item, b: item):
    if a.v < b.v:
        return 1
    return -1


def mochila_frac(items: list, k: float) -> tuple[list,float]:
    items.sort(key=cmp_to_key(cmp))
    sol = []
    cur_k = k
    value = 0
    i = 0
    while cur_k > 0 and i < len(items):
        qt = min(items[i].w, cur_k)
        value += items[i].v*qt
        cur_k -= qt
        sol.append((qt,items[i].idx)) 
        i += 1
    return (sol,value)


if __name__ == '__main__':
    items = [item(4, 3, 0), item(8, 8, 1), item(10, 12, 2)]
    print(mochila_frac(items, 12))
