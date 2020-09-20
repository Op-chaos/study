mex EBW_distance.c
mex ICW_distance.c
mex FCW_distance.c
mex AVW_distance.c

clear
maxv = 40;
a1 = 0
a2 = 0
d_w = [];
d_m = [];
d_e = [];

%% AVWԤ��
for v1=1:maxv
    for v2=1:maxv
        d = AVW_distance(v1, v2, a1, a2);
        d_w(v1,v2) = d(1);
        d_m(v1,v2) = d(2);
        d_e(v1,v2) = d(3);
    end
end
figure
[V1,V2]= meshgrid(1:maxv);
mesh(V1,V2,d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('AVW��ȫԤ������')
hold on
mesh(V1,V2,d_m)
hold on
mesh(V1,V2,d_e)

%% EBWԤ��
a1 = -6
a2 = 0
for v1=1:maxv
    for v2=1:maxv
        d = EBW_distance(v1, v2, a1, a2);
        d_w(v1,v2) = d(1);
        d_m(v1,v2) = d(2);
        d_e(v1,v2) = d(3);
    end
end
figure
[V1,V2]= meshgrid(1:maxv);
mesh(V1,V2,d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('EBW��ȫԤ������')
hold on
mesh(V1,V2,d_m)
hold on
mesh(V1,V2,d_e)

%% FCWԤ��
for v1=1:maxv
    for v2=1:maxv
        d = FCW_distance(v1, v2, a1, a2);
        d_w(v1,v2) = d(1);
        d_m(v1,v2) = d(2);
        d_e(v1,v2) = d(3);
    end
end
figure
[V1,V2]= meshgrid(1:maxv);
mesh(V1,V2,d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('FCW��ȫԤ������')
hold on
mesh(V1,V2,d_m)
hold on
mesh(V1,V2,d_e)

%% ICWԤ��
for v1=1:maxv
    for v2=1:maxv
        d = ICW_distance(v1, v2, a1, a2);
        d_w(v1,v2) = d(1);
        d_m(v1,v2) = d(2);
        d_e(v1,v2) = d(3);
    end
end
figure
[V1,V2]= meshgrid(1:maxv);
mesh(V1,V2,d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('ICW��ȫԤ������')
hold on
mesh(V1,V2,d_m)
hold on
mesh(V1,V2,d_e)





