a = 1:12;
a = reshape(a,3,4)

mex reverse.c
[b, c] = reverse(a)