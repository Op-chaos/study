import re
inp = input()
result = re.findall(r"\"\w+ \w+\"",inp)
print(result)
for i in result:
    print(i)
    j=i.replace(" ","_$").replace('"','')
    print(j)
    inp = inp.replace(i,j)
print(inp)
inp = inp.split(' ')
print(len(inp))
for i in inp:
    i = i.replace("_$"," ")
    print(i)
