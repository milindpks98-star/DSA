from collections import Counter
import heapq
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        freq=Counter(nums)
        heap=[]
        for num,count in freq.items():
                heapq.heappush(heap,(count,num))
                if len(heap)>k:
                    heapq.heappop(heap)
        ans=[]
        while heap:
            ans.append(heapq.heappop(heap)[1])
        return ans        