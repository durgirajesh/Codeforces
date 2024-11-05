
from collections import defaultdict
from queue import PriorityQueue

def start_up(nums, n, k) :
    container = defaultdict(int)
    for brand, cost in nums :
        container[brand] += cost
    
    max_cost = 0
    costs = []

    for brand in container :
        costs.append(container[brand])
    
    costs.sort(reverse=True)
    max_cost = sum(costs[ : n])
    return max_cost

def main() :
    t = int(input())
    while t :
        n, k = list(map(int, input().split()))
        bottles = []

        while k :
            bi, ci = list(map(int, input().split()))
            bottles.append((bi, ci))
            k -= 1

        print(start_up(bottles, n, k))
        t -= 1

main()
