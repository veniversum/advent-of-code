# Day 3: Spiral Memory
# http://adventofcode.com/2017/day/3


def partA(target):
    x = 0
    y = 0
    cur = 1
    leg_length = 1
    sign = 1
    while(cur < target):
        for j in range(leg_length):
            x += sign
            cur += 1
            if cur == target:
                return abs(x) + abs(y)
        for j in range(leg_length):
            y += sign
            cur += 1
            if cur == target:
                return abs(x) + abs(y)
        leg_length += 1
        sign *= -1
    return 0


def partB(target):
    from collections import defaultdict

    def neighbors(grid, x, y):
        return grid[(x - 1, y + 1)] + grid[(x, y + 1)] + grid[(x + 1, y + 1)] +
        grid[(x - 1, y)] + grid[(x + 1, y)] + grid[(x - 1, y - 1)] +
        grid[(x, y - 1)] + grid[(x + 1, y - 1)]

    grid = defaultdict(int)
    x = 0
    y = 0
    leg_length = 1
    sign = 1
    grid[(0, 0)] = 1
    while(True):
        for j in range(leg_length):
            x += sign
            sum = neighbors(grid, x, y)
            if sum >= target:
                return sum
            grid[(x, y)] = sum
        for j in range(leg_length):
            y += sign
            sum = neighbors(grid, x, y)
            if sum >= target:
                return sum
            grid[(x, y)] = sum
        leg_length += 1
        sign *= -1
    return 0
