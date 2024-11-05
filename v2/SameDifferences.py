from collections import defaultdict

def same_differences(n, nums) :
    container = defaultdict(int)
    i, count = 0, 0

    while i < len(nums) :
        if (i - nums[i]) in container :
            count += container[(i - nums[i])]

        container [(i - nums[i])] += 1
        i += 1
    
    return count

def main() :
    t = int(input())
    while t :
        t -= 1

        n = int(input())
        arr = list(map(int, input().split(" ")))
        print(same_differences(n, arr))

main()