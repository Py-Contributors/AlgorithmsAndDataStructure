def fibonacci(n: int):
    fibs = []
    for i in range(n):
        if i < 2:
            fibs.append(i)
        else:
            fibs.append(fibs[i - 1] + fibs[i - 2])
    return fibs


if __name__ == "__main__":
    ans = fibonacci(15)
    print(ans)
