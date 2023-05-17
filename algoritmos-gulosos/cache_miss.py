def next(occ: dict, ref: int, idx: int):
    ans = -1
    for x in occ[ref]:
        if x > idx:
            return x
    return ans


def optimal_cache_miss(v: list, k) -> int:
    miss = 0
    cache = [-1 for _ in range(k)]
    occ = {}
    for i, x in enumerate(v):
        if x in occ.keys():
            occ[x].append(i)
        else:
            occ[x] = [i]
    i = 0
    j = 0
    while i < k and i < len(v):
        if not v[i] in cache:
            cache[j] = v[i]
            j += 1
            miss += 1
        i += 1

    while i < len(v):
        if v[i] in cache:
            i += 1
            continue
        miss += 1
        next_reference = next(occ, v[i], i)
        cache_references = []
        for j, x in enumerate(cache):
            cache_references.append((j, next(occ, x, i)))
        if next_reference == -1:
            i += 1
        else:
            maximum_dist = next_reference
            replace = -1
            for j, x in cache_references:
                if x > maximum_dist:
                    maximum_dist = x
                    replace = j
            if replace != -1:
                cache[replace] = v[i]
            i += 1
    return miss


if __name__ == '__main__':
    v = [4, 1, 2, 3, 4, 4, 1, 4, 4, 2]
    print(optimal_cache_miss(v, 3))
