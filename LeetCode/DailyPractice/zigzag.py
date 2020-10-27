def convert(s, numRows):
        if(s == ""):
            return s
        if(numRows == 0):
            return s
        totalSpace = (len(s)*numRows) + numRows
        resultList = ["" for i in range(totalSpace)]
        count = 0
        offset = 0
        appending = 0
        ascending = True
        for j in s:
            
            if(ascending == True):
                resultList[offset + appending] = j
                if (offset == (numRows-1)*len(s)):
                    appending +=1
                    ascending = False
                    offset -= len(s)*2
                
                offset += len(s)
                
              
            else:
                resultList[offset + appending] = j
                if (offset == 0):
                    appending +=1
                    ascending = True
                    offset += len(s)*2
                
                offset -= len(s)
                
            
        result = "".join(resultList)
      
        return result

def main():
    s = "PAYPALISHIRING"
    num = 3
    print(s)
    print(convert(s, num))




main()