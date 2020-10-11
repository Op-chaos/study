mex EBW_distance.c
mex ICW_distance.c
mex FCW_distance.c
mex AVW_distance.c
mex EVW_distance.c

clear

%% AVW预警
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
xlabel('ahead speed'),ylabel('behind speed'),zlabel('warning级别AVW预警距离')

figure
mesh(V1',V2',d_m)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('major级别AVW预警距离')

figure
mesh(V1',V2',d_e)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('emergency级别AVW预警距离')

figure
mesh(V1',V2',d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('AVW安全预警距离')
hold on
mesh(V1',V2',d_m)
hold on
mesh(V1',V2',d_e)

%% EBW预警
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
xlabel('ahead speed'),ylabel('behind speed'),zlabel('warning级别EBW预警距离')

figure
mesh(V1',V2',d_m)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('major级别EBW预警距离')

figure
mesh(V1',V2',d_e)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('emergency级别EBW预警距离')

figure
mesh(V1',V2',d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('EBW安全预警距离')
hold on
mesh(V1',V2',d_m)
hold on
mesh(V1',V2',d_e)

%% FCW预警
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
xlabel('ahead speed'),ylabel('behind speed'),zlabel('warning级别FCW预警距离')

figure
mesh(V1',V2',d_m)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('major级别FCW预警距离')

figure
mesh(V1',V2',d_e)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('emergency级别FCW预警距离')

figure
mesh(V1',V2',d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('FCW安全预警距离')
hold on
mesh(V1',V2',d_m)
hold on
mesh(V1',V2',d_e)

figure;
plot(1:40,d_w(20,:))
xlabel('behind speed'),ylabel('前车20m/s,FCW安全预警距离')

figure;
plot(1:40,d_w(:,20))
xlabel('ahead speed'),ylabel('后车20m/s,FCW安全预警距离')
%% ICW预警
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
xlabel('HV speed'),ylabel('RV speed'),zlabel('warning级别ICW预警距离')

figure
mesh(V1',V2',d_m)
xlabel('HV speed'),ylabel('RV speed'),zlabel('major级别ICW预警距离')

figure
mesh(V1',V2',d_e)
xlabel('HV speed'),ylabel('RV speed'),zlabel('emergency级别ICW预警距离')

figure
mesh(V1',V2',d_w)
xlabel('HV speed'),ylabel('RV speed'),zlabel('ICW安全预警距离')
hold on
mesh(V1',V2',d_m)
hold on
mesh(V1',V2',d_e)

%% EVW 预警
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
xlabel('RV speed'),ylabel('HV speed'),zlabel('information级别EVW预警距离')

figure
mesh(V1',V2',d_w)
xlabel('RV speed'),ylabel('HV speed'),zlabel('warning级别EVW预警距离')

figure
[V1,V2]= meshgrid(1:maxv);
mesh(V1',V2',d_i)
hold on
mesh(V1',V2',d_w)
xlabel('RV speed'),ylabel('HV speed'),zlabel('EVW预警距离')



