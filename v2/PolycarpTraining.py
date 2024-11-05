
def polycarp_training(nums) :
    nums.sort()
    i, k = 0, 1

    while i < len(nums) :
        if nums[i] >= k :
            i += 1
            k += 1
        else :
            while i < len(nums) and nums[i] < k :
                i += 1

    return k - 1


if __name__ == "__main__" :
    n = int(input())
    problems = list(map(int, input().split()))  
    print(polycarp_training(problems))