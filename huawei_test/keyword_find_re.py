import re
while True:
    try:
        str1 = input()
        re.findall(r'(.{1,}).*\1',str1)
    except:
        break