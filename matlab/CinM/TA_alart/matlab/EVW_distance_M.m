mex EVW_distance.c
max_spped = 40;
d_info = [];
d_warning = [];
X_front_speed = [];
Y_rear_speed = [];
for front_speed = 1:max_spped
    for rear_speed = 1:max_spped
        [d1, d2] = EVW_distance(front_speed, rear_speed);
        X_front_speed(front_speed, rear_speed) = front_speed;
        Y_rear_speed(front_speed, rear_speed) = rear_speed;
        d_info(front_speed, rear_speed) = d1;
        d_warning(front_speed, rear_speed) = d2;
    end
end

figure
mesh(X_front_speed, Y_rear_speed,d_info)
hold on
mesh(X_front_speed, Y_rear_speed,d_warning)
xlabel('HV front speed'); ylabel('rear speed'); zlabel('Ô¤¾¯¾àÀë');
hold on
plot3()

[d1, d2] = EVW_distance(front_speed, rear_speed);