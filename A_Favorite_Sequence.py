def solve(seq):
    i, j, turn = 0, len(seq) - 1, 0
    num = []

    while i <= j:
        k = ""
        if turn % 2 == 0:
            k += seq[i]
            i += 1
        else:
            k += seq[j]
            j -= 1
        
        turn += 1
        num.append(k)
    
    nums = " ".join(num)
    return nums

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        n = int(input())
        seq = input()

        seq_list = seq.split()
        print(solve(seq_list), end="\n")

        t -= 1