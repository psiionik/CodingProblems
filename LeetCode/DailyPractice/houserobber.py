def rob(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    result = [0]*len(nums)

    if(len(nums) == 0):
        return 0
    if(len(nums) == 1):
        return nums[0]
    if(len(nums) == 2):
        return max(nums[0], nums[1])

    for i in range(0, len(nums)):
        if (i == 0):
            result[i] = nums[i]
        if (i == 1):
            result[i] = nums[i]
        # if (i == 2):
        #     result[i] = max(nums[i], result[i-2] + nums[i] )
        if(i > 1):
            result[i] = max(nums[i], result[i-2] + nums[i], result[i-3] + nums[i] )
    res = max(result)
    return res

def testing():
    return None


def main():
    s = [1, 1, 1]
    x = rob(s)
    print(x)




main()
