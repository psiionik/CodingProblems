def findAndReplacePattern(words, pattern):
    result = []
    for word in words:
        if(boolret(word, pattern)):
            result.append(word)

    return result

def boolret(word, pattern):
    dic = {}

    if(len(word) != len(pattern)):
        return False
    
    for w, p in zip(word, pattern):
        if(w not in dic):
            if(p in dic.values()):
                return False
            dic[w] = p
        else:
            if(dic[w] != p):
                return False
    

    return True
        

def main():
    words = ["qqcojjumwp","mqidrqudxu","xwrvnueult","lubbymxyro","fcvxuskhcl"]
    words2= ["abc","deq","mee","aqq","dkd","ccc"]
    pattern ="rdzkpkbmda"
    pattern2 = "abb"
    words3 = ["ktittgzawn","dgphvfjniv","gceqobzmis","alrztxdlah","jijuevoioe","mawiizpkub","onwpmnujos","zszkptjgzj","zwfvzhrucv","isyaphcszn"]
    pattern3 ="zdqmjnczma"
    words4 = ["otyih","xpbij","mphcm","yftcn","neoxv","xgtuc","xsted","qzmyj","lgtzi","xgadb","ltcog","juwrt","yovdw","bafus","wixvl","wipfh","txavv","zrdyx","tnron","ckklv","hcfok","zdnuh","xvktl","uiokh","lksgy","ttkxo","xmzgf","fjubp","imhkk","dticv","fspay","ztcse","mmgvd","mptwo","zbiuf","klndt","zqsgf","jhknn","qgegc","hgouh","pickb","nzamf","ykpkl","chwls","huqzi","ggmwv","cserm","nujnp","pliht","tviwe"]
    pattern4 = "drpsr"
    words5 =["t","k","g","n","k"]
    pattern5 ="v"




    x = findAndReplacePattern(words5, pattern5)
    print(x)

main()