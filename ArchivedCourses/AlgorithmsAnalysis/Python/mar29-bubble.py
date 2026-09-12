# Python: dynamically-typed
# name = 1
# print(name)
# name = "Vuong"
# print(name)


# O(n^2)
# typing: optional
def bubble_sort(nums: list[int]):
    comps = 0
    for i in range(len(nums) - 1):
        for j in range(len(nums) - 1 - i):
            if nums[j+1] < nums[j]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
                # temp = nums[j]
                # nums[j] = nums[j+1]
                # nums[j+1] = temp
            comps += 1
            print(nums)
    print('comparisons:', comps)


def optimized_bubble_sort(nums: list[int]):
    comps = 0
    swapped = False
    for i in range(len(nums) - 1):
        for j in range(len(nums) - 1 - i):
            if nums[j+1] < nums[j]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
                swapped = True
                
            comps += 1
            print(nums)
            
        if not swapped:
            break
            
    print('comparisons:', comps)
                
nums = [15, 21, 1, 25, 12, 6, 8, 3, 5, 19, 10, 18]
optimized_bubble_sort(nums)
print('bubble sort:', nums)


# def bubble_sort_while(nums: list[int]):
#     swapped = False
#     while swapped:
#         ...