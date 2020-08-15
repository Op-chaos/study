import re
while True:
    try:
        a,b = input().strip(),input().strip()
        a = a.replace("?","\w{1}").replace(".","\.").replace("*","\w*")
        result = re.findall(a,b)
        print(a,result)
        if result != []:
            print("True")
        else:
            print("False")
    except:
        break