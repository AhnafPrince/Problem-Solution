ans = []
    checkDict  = {}
    for i in range(1,n+1):
        cellKey = checkDict.get(i, i+k)
        checkDict[cellKey] = i
        if cellKey > n:
            return [-1]
        ans.append(cellKey)
    return ans
