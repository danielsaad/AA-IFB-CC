def epaminondas(distances:list[int],c:int) -> int:
    autonomia = c
    paradas = 0
    for d in distances:
        if d > c:
            return -1
        elif d > autonomia:
            paradas += 1
            autonomia = c
        autonomia -= d
    return paradas   




if __name__ == '__main__':
    tests = [([20,30,40,11],50)]
    for dist,c in tests:
        print(epaminondas(dist,c),'paradas')
