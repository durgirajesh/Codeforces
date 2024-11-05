
def solve(matrix) :
    pass

def main() :
    t = int(input())
    while t :
        t -= 1
        n ,m = list(map(int, input().split()))
        matrix = []

        while n :
            n -= 1
            row = input()
            matrix.append( int(row[i]) for i in range(len(row)) )
        
        for i in range(len(matrix)) :
            for j in range(len(matrix[i])) :
                if matrix[i][j] == '1' :
                    print(solve(matrix, i, j))

main()
