# Big O: O(n^2)
def two_sum_1(nums, target):
    comps = 0
    for i in range(len(nums) - 1):
        for j in range(i+1, len(nums)):
            # print(nums[i], nums[j])
            comps += 1
            if nums[i] + nums[j] == target:
                print('comps:', comps)
                return [i, j]
    return []
            

nums = [2,7,11,15]
target = 26

print(two_sum_1(nums, target))

# 26 - 2 -> 24
# 26 - 7 -> 19
# 26 - 11 -> 15


# Optimize from O(n^2) down to O(n)

def two_sum_2(nums, target):
    seen = {}
    comps = 0
    for i in range(len(nums)):
        complement = target - nums[i]
        comps += 1
        # Dictionary look-up: O(1)
        if complement in seen:
            print('comps:', comps)
            return [i, seen[complement]]
        seen[nums[i]] = i
        

print(two_sum_2(nums, target))