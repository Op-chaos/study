while True:
    try:
      arr_I=list(map(int,input().split()))
      n1=arr_I[0]
      arr_I=arr_I[1:]
      arr_R=list(map(int,input().split()))
      n2=arr_R[0]
      arr_R=set(arr_R[1:])
      arr_R=sorted(arr_R)
      res=[]
      for temp in arr_R:
        temp_arr=[]
        for j in range(n1):
          if str(temp) in str(arr_I[j]):
            temp_arr.append(j)
            temp_arr.append(arr_I[j])
        if len(temp_arr):
          res.append(temp)
          res.append(len(temp_arr)//2)
          res.extend(temp_arr)
      print(len(res),end=' ')
      for i in res:
        print(i,end=' ')
      print()
    except:
      break