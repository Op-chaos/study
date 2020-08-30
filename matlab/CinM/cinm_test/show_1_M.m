a=1:12;

a = reshape(a,3,4)
mex show_1.c;
show_1(a)