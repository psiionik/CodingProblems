def subsets(nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []

        def select(c, cur, i):
            print(i)
            if len(cur) == c:
                res.append(list(cur))
                return
            if i >= len(nums):
                return
            cur.append(nums[i])
            select(c, cur, i + 1)
            cur.pop()
            select(c, cur, i + 1)

        for j in range(len(nums) + 1):
            select(j, [], 0)
        return res


def main():
    s = [1, 2, 3]
    k = subsets(s)
    print(k)







main()