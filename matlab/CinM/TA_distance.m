% v1 = 30/3.6
% v2 = 40/3.6 
a1 = 0
a2 = 0

maxv = 40;
d_w = [];
d_m = [];
d_e = [];

for v1=1:maxv
    for v2=1:maxv
        d = distance(v1, v2, a1, a2);
        d_w(v1,v2) = d(1);
        d_m(v1,v2) = d(2);
        d_e(v1,v2) = d(3);
    end
end

[V1,V2]= meshgrid(1:maxv);
mesh(V1,V2,d_w)
xlabel('ahead car speed'),ylabel('behind car speed'),zlabel('Ô¤¾¯¾àÀë')