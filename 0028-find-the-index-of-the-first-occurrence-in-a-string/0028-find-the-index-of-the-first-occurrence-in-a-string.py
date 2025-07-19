class Solution:
    def strStr(self, haystack, needle):
        if not needle:
            return 0
        return haystack.find(needle)
