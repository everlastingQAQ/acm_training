import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    t = int(input_data[0])
    idx = 1
    out = []
    for _ in range(t):
        n = int(input_data[idx])
        p = [int(x) for x in input_data[idx+1:idx+1+n]]
        idx += 1 + n
        for i in range(n):
            if p[i] != n - i:
                j = p.index(n - i)
                p[i:j+1] = p[i:j+1][::-1]
                break
        out.append(" ".join(map(str, p)))
    sys.stdout.write("\n".join(out) + "\n")

if __name__ == '__main__':
    solve()