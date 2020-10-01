def solve():
    n = int(input())
    a = list(map(int, input().split()))

    if n <= 1:
        return 0
    if n == 2:
        return int(a[-2] > a[-1])

    answer = 0

    for i in range(n):
        if a[i] - (i + 1) > 2:
            return None
        for j in range(max(0, a[i] - 2), i):
            answer += a[j] > a[i]

    return answer


def main():
    tests = int(input())
    answers = [None] * tests

    for test in range(tests):
        answers[test] = solve()

    print('\n'.join(
            map(lambda x: str(x) if x is not None else 'Too chaotic',
                answers)))


if __name__ == '__main__':
    main()
