from functools import cmp_to_key


def cmp(i1: tuple[int, int], i2: tuple[int, int]):
    if i1[0] < i2[0]:
        return -1
    elif i2[0] < i1[0]:
        return 1
    elif i1[1] > i2[1]:
        return -1
    return 1


def inclusao_subintervalos(intervals: list) -> list:
    intervals.sort(key=cmp_to_key(cmp))  # \Theta(n \lg n)
    ans = [intervals[0]]
    candidate = (-1, -1)
    for i in range(1, len(intervals)):  # \Theta(n)
        if intervals[i][1] <= ans[-1][1]:  # intervalo coberto
            continue
        # intervalo não está coberto, mas está sobreposto ao último inserido na resposta
        if intervals[i][0] <= ans[-1][1]:
            if intervals[i][1] > candidate[1]:
                candidate = intervals[i]
        else:  # buraco
            if candidate != (-1, -1):
                ans.append(candidate)
                candidate = intervals[i]

    if candidate != (-1, -1) and candidate[1] > ans[-1][1]:
        ans.append(candidate)

    print(ans)
    return ans


if __name__ == '__main__':
    tests = [[(0, 5), (3, 6), (3, 8), (9, 11), (9, 12), (10, 15)],
             [(3, 8), (0, 3), (1, 6)],
             [(0, 2), (3, 5), (7, 9), (11, 13), (15, 17), (0, 20)],
             [(0, 2), (3, 5), (7, 9), (11, 13), (15, 17), (1, 20)]]
    for t in tests:
        inclusao_subintervalos(t)
