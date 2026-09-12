# O(n^2)
def selection_sort(nums):
    comps = 0
    for i in range(len(nums) - 1):
        min_index = i # assume (the first element)
        for j in range(i+1, len(nums)):
            # print(nums[i], nums[j])
            comps += 1
            if nums[j] < nums[min_index]:
                min_index = j
                
        # swap nums[i] with the smallest num in the sub array
        temp = nums[i]
        nums[i] = nums[min_index]
        nums[min_index] = temp
        
        print('> nums:', nums)
    
    print('comparisons:', comps)


nums = [15, 21, 1, 25, 12, 6, 8, 3, 5, 19, 10, 18]
selection_sort(nums)
print(nums)


