mex EBW_distance.c
mex ICW_distance.c
mex FCW_distance.c
mex AVW_distance.c
mex EVW_distance.c

clear

%% AVWÔ¤¾¯
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
xlabel('ahead speed'),ylabel('behind speed'),zlabel('warning¼¶±ðAVWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_m)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('major¼¶±ðAVWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_e)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('emergency¼¶±ðAVWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('AVW°²È«Ô¤¾¯¾àÀë')
hold on
mesh(V1',V2',d_m)
hold on
mesh(V1',V2',d_e)

%% EBWÔ¤¾¯
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
xlabel('ahead speed'),ylabel('behind speed'),zlabel('warning¼¶±ðEBWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_m)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('major¼¶±ðEBWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_e)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('emergency¼¶±ðEBWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('EBW°²È«Ô¤¾¯¾àÀë')
hold on
mesh(V1',V2',d_m)
hold on
mesh(V1',V2',d_e)

%% FCWÔ¤¾¯
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
xlabel('ahead speed'),ylabel('behind speed'),zlabel('warning¼¶±ðFCWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_m)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('major¼¶±ðFCWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_e)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('emergency¼¶±ðFCWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_w)
xlabel('ahead speed'),ylabel('behind speed'),zlabel('FCW°²È«Ô¤¾¯¾àÀë')
hold on
mesh(V1',V2',d_m)
hold on
mesh(V1',V2',d_e)

%% ICWÔ¤¾¯
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
xlabel('HV speed'),ylabel('RV speed'),zlabel('warning¼¶±ðICWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_m)
xlabel('HV speed'),ylabel('RV speed'),zlabel('major¼¶±ðICWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_e)
xlabel('HV speed'),ylabel('RV speed'),zlabel('emergency¼¶±ðICWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_w)
xlabel('HV speed'),ylabel('RV speed'),zlabel('ICW°²È«Ô¤¾¯¾àÀë')
hold on
mesh(V1',V2',d_m)
hold on
mesh(V1',V2',d_e)

%% EVW Ô¤¾¯
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
xlabel('RV speed'),ylabel('HV speed'),zlabel('information¼¶±ðEVWÔ¤¾¯¾àÀë')

figure
mesh(V1',V2',d_w)
xlabel('RV speed'),ylabel('HV speed'),zlabel('warning¼¶±ðEVWÔ¤¾¯¾àÀë')

figure
[V1,V2]= meshgrid(1:maxv);
mesh(V1',V2',d_i)
hold on
mesh(V1',V2',d_w)
xlabel('RV speed'),ylabel('HV speed'),zlabel('EVWÔ¤¾¯¾àÀë')



