
def quintomania(n, notes) :
    for i in range(n - 1) :
        if abs(notes[i] - notes[i+1]) != 5 and abs(notes[i] - notes[i+1]) != 7 :
            return "No"
    
    return "yeS"

def main() :
    t = int(input())
    result = []

    while t :
        n = int(input())
        notes = list(map(int, input().split()))
        result.append(quintomania(n, notes))
        t -= 1
    
    for i in range(len(result)) :
        print(result[i])

main()