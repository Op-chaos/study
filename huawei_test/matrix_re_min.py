import re
table = []
n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    table.append(['',a,b])
# print(table)
expr = input()
pos = 0
for i in expr:
    if i != '(' and i != ')':
        table[pos][0] = i
        pos+=1
print(table)
flop = 0
result = re.findall(r'\(\w+\)',expr)  # (AB)
while result != []:
    for j in result:
        length = len(table)
        pos1 = -1
        pos2 = -1
        print(j)
        for k in range(length):
            if j[1] == table[k][0]:
                pos1 = k
            if j[2] == table[k][0]:
                pos2 = k
            if pos1 != -1 and pos2 != -1:
                break
        flop += (table[pos1][1]*table[pos1][2]*table[pos2][2])
        table[pos1][2] = table[pos2][2]
        expr = expr.replace(j, table[pos1][0])
    result = re.findall(r'\(\w+\)',expr)  # (AB)
print(flop)

