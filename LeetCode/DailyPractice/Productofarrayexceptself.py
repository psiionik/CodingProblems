def productExceptSelf(nums):
    """
    :type nums: List[int]
    :rtype: List[int]
    """
    prodToLeft = [1]
    prodToRight = [1]
    for i in range(1, len(nums)):
        prodToLeft.append(prodToLeft[i-1]* nums[i-1])
    for i in range(len(nums)-2, -1, -1):
        prodToRight = [nums[i+1]*prodToRight[0]] + prodToRight
    for i in range(0, len(nums)):
        nums[i] = prodToLeft[i]*prodToRight[i]
    return nums

def main():
    i1 = [1, 2, 3, 4]
    i2 = [12, 11, 13]
    x = productExceptSelf(i2)
    print(x)

main()