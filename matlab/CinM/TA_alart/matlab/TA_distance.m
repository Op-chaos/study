mex EBW_distance.c
mex ICW_distance.c
mex FCW_distance.c
mex AVW_distance.c
mex EVW_distance.c

clear

%% AVWԤ��
maxv = 40;
a1 = 0
a2 = 0
d_w = [];
d_m = [];
d_e = [];
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
mesh(V1',V2',d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('warning����AVWԤ������')

figure
mesh(V1',V2',d_m)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('major����AVWԤ������')

figure
mesh(V1',V2',d_e)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('emergency����AVWԤ������')

figure
mesh(V1',V2',d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('AVW��ȫԤ������')
hold on
mesh(V1',V2',d_m)
hold on
mesh(V1',V2',d_e)

%% EBWԤ��
maxv = 40;
a1 = -6
a2 = 0
d_w = [];
d_m = [];
d_e = [];
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
mesh(V1',V2',d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('warning����EBWԤ������')

figure
mesh(V1',V2',d_m)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('major����EBWԤ������')

figure
mesh(V1',V2',d_e)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('emergency����EBWԤ������')

figure
mesh(V1',V2',d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('EBW��ȫԤ������')
hold on
mesh(V1',V2',d_m)
hold on
mesh(V1',V2',d_e)

%% FCWԤ��
maxv = 40;
a1 = 0
a2 = 0
d_w = [];
d_m = [];
d_e = [];
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
mesh(V1',V2',d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('warning����FCWԤ������')

figure
mesh(V1',V2',d_m)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('major����FCWԤ������')

figure
mesh(V1',V2',d_e)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('emergency����FCWԤ������')

figure
mesh(V1',V2',d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('FCW��ȫԤ������')
hold on
mesh(V1',V2',d_m)
hold on
mesh(V1',V2',d_e)

%% ICWԤ��
maxv = 40;
a1 = 0
a2 = 0
d_w = [];
d_m = [];
d_e = [];
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
mesh(V1',V2',d_w)
xlabel('HV speed'),ylabel('RV speed'),zlabel('warning����ICWԤ������')

figure
mesh(V1',V2',d_m)
xlabel('HV speed'),ylabel('RV speed'),zlabel('major����ICWԤ������')

figure
mesh(V1',V2',d_e)
xlabel('HV speed'),ylabel('RV speed'),zlabel('emergency����ICWԤ������')

figure
mesh(V1',V2',d_w)
xlabel('HV speed'),ylabel('RV speed'),zlabel('ICW��ȫԤ������')
hold on
mesh(V1',V2',d_m)
hold on
mesh(V1',V2',d_e)

%% EVW Ԥ��
maxv = 40;
a1 = 0
a2 = 0
d_i = [];
d_w = [];
for v1=1:maxv
    for v2=1:maxv
        [d1, d2] = EVW_distance(v1, v2);
        d_i(v1,v2) = d1;
        d_w(v1,v2) = d2;
    end
end

figure
[V1,V2]= meshgrid(1:maxv);
mesh(V1',V2',d_i)
xlabel('RV speed'),ylabel('HV speed'),zlabel('information����EVWԤ������')

figure
mesh(V1',V2',d_w)
xlabel('RV speed'),ylabel('HV speed'),zlabel('warning����EVWԤ������')

figure
[V1,V2]= meshgrid(1:maxv);
mesh(V1',V2',d_i)
hold on
mesh(V1',V2',d_w)
xlabel('RV speed'),ylabel('HV speed'),zlabel('EVWԤ������')



