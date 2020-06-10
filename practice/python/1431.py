#!/usr/bin/python3

class Solution:
    def kidsWithCandies(self, candies, extraCandies):
        nMax = max(candies) - extraCandies
        listB = []
        for i in candies:
            listB.append(nMax <= i)
        return listB

test = [2, 3, 5, 1, 3]
so = Solution()
ret = so.kidsWithCandies(test, 3)

print(ret)
