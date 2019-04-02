"""动态规划之能否组成给定的数"""
"""
    给出一个数和一个数组(都是正整数),判断数组里面的数能否组合成这个数(不限组合个数)
    能组成就返回True,否则返回False

    首先：跳出条件
                <1> 当arr[i]>s 时候表示arr[i] 这个数不可能组合成s了，就取arr[i-1]来判断能不能
                <2> 当arr[0] == s 时候，就表示到arr[0]这里能组合成s，要判断arr[0]有没有大于s不能使下标越界 
                <3> 存在一个选和不选的状态，选的时候就把s-arr[i]这个数，表示剩下的还要组合的数是多少
                         不选的情况下就直接判断前面arr[i-1]能否组合成功，两者之间选True那个，否则都是False就不能组合

    思想：利用空间换取时间，把所有arr[i]判断能否组成s的值记录，之后到了最后要判断能不能组合S时，只要判断
                选和不选状态是否有方案可以组合成S  所以返回数组的最后一个值，其他的值都是辅助记录的值

    分割子问题： 把每个子问题自下而上的计算保留，之后的问题就是调用前面求好的方案无须计算
"""
import numpy as np

arr = [3, 34, 4, 12, 5, 2]

def dp_subset(arr,S):
    subset = np.zeros((len(arr),S+1),dtype = bool)
    subset[ : , 0 ] = True
    subset[ 0 , : ] = False
    #必须判断，否则下标溢出
    if arr[0] < S:
        subset [0,arr[0]] = True

    for i in range(1,len(arr)):
        for s in range(1,S+1):
            #arr[i]大于s时，没办法存在选择arr[i]的状态，只能看前面一个是否能够组成，若不能，也就不能组合
            if arr[i] > s:
                subset[i , s] = subset[i - 1 , s]
            else:
                #计算选择和不选择的状态
               A = subset[i - 1,s - arr[i]] 
               B = subset[i - 1,s]
               subset[i , s] = A or B

    a,b = subset.shape
    #返回要求的组合状态
    return subset[a - 1,b - 1]

print(dp_subset(arr,9))
print(dp_subset(arr,13))
