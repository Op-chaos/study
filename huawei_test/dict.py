# while True:
#     try:
#         in_str = list(raw_input().split())
#         find_word = in_str[-2]
#         find_tag = in_str[-1]
#         my_dict = in_str[1:-2]
#         cnt = 0;
#         sorted_find_word = find_word.sort()
#         find_dict = []
#         print("1")
#         for word in my_dict:
#             if word != find_word:
#                 find_word = list(find_word)
#                 sorted_find_word = find_word.sort()
#                 word = list(word)
#                 sorted_word = word.sort()
#                 if compile(sorted_find_word, sorted_word) == 0:
#                     find_dict[cnt] = word
#                     ++cnt
#         if find_tag < cnt:
#             print("%d\n%s\n"%(cnt,find_dict[find_tag]))

#     except:
#         print("error")
#         break

in_str = list(input().split())
find_word = in_str[-2]
find_tag = int(in_str[-1])
my_dict = in_str[1:-2]
cnt = 0;
find_dict = [int(in_str[0])]
print("1")
for word in my_dict:
    if word != find_word:
        list_find_word = list(find_word)
        list_find_word.sort()
        list_word = list(word)
        list_word.sort()
        print("2")
        if list_find_word == list_word:
            find_dict[cnt] = word
            cnt+=1
            print("3")
print("%d %d\n"%(find_tag,cnt))
if find_tag <= cnt:
    print("%d\n%s\n"%(cnt,find_dict[find_tag-1]))
