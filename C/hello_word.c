#include<stdio.h>
#include<string.h>
# include<stdlib.h>

typedef struct inbound_can_data {
    /** 车速, unavailable(65535) 0.001 m/s */
    unsigned int                speed;
    /** 后轮转数，unavailable(65535) */
    unsigned int                rear_wheel_tick;
    /** range：-32767..32766 （-3276.7度到3276.6度）, 单位0.1度， -3276.7度或超出（-32767），3276.6度或超出（-3276.6），unavailable(32767)。
        方向盘转角，右转为正值。
    */
    int                steering_wheel_angle;
    /** range: 0..3600, 3600 shall be used when unavailable. 单位0.1degree */
    unsigned int                heading;
    unsigned int                 transmisn;
    unsigned int                light;
    /** 车辆ESP状态，0: unavailable,1: off, 2: On but notEngaged, 3: Engaged.【事件类数据】 */
    unsigned int                 ESP_status;
    /** 车辆TCS状态，0: unavailable,1: off, 2: On but notEngaged, 3: Engaged.【事件类数据】 */
    unsigned int                 TCS_status;
    /** 车辆ABS状态，0: unavailable,1: off, 2: On but notEngaged, 3: Engaged.【事件类数据】 */
    unsigned int                 ABS_status;
    /** 车辆LDW状态，0: unavailable,1: off, 2: On but notEngaged, 3: Engaged.【事件类数据】 */
    unsigned int                 LDW_status;
    /** 车辆刹车踏板状态，0:unavailable, 1: not pressed, 2: Normal Breaking, 3:Emergency Breaking.【事件类数据】 */
    unsigned int                 brake_pedal;
    /** 车辆刹车踏板百分比，0-100(0%-100%), 101:unavailable.【事件类数据】 */
    unsigned int                 pedal_status;
    /** 车辆失控状态，unavailable, 1: off, 2: On【事件类数据】 */
    unsigned int                 lose_contorl;
    /** 车辆轮胎气压状态， 0x00 :all normal 0x01 :fl warning 0x02:fr warning 0x04:rl warning 0x08:rr warnin 【事件类数据】*/
    unsigned int                 tire_pressure;
    /** reserved1 */
    unsigned int                 rsvd1;
    /** 车辆X轴方向加速度，加速为正值，unavailable(32767) 单位：0.001m/s^2 */
    int                acc_x;
    /** 车辆Y轴方向加速度，加速为正值，unavailable(32767) 单位：0.001m/s^2 */
    int                acc_y;
    /** 车辆Z轴方向加速度，加速为正值，unavailable(32767) 单位：0.001m/s^2 */
    int                acc_z;
    /** 车辆俯仰角角加速度，加速为正值，unavailable(32767) 单位：0.001rad/s */
    int                gyro_x;
    /** 车辆翻滚角角加速度，加速为正值，unavailable(32767) 单位：0.001rad/s */
    int                gyro_y;
    /** 车辆偏航角角加速度，加速为正值，unavailable(32767) 单位：0.001rad/s */
    int                gyro_z;
    /** reserved2 */
    int                rsvd2;
    /** reserved3 */
    int                rsvd3;
    /** reserved4 */
    int                rsvd4;
    /** reserved5 */
    int                rsvd5;
    /** reserved6 */
    int                rsvd6;
}  inbound_can_data_t;

int main()
{
    FILE *fp;
    inbound_can_data_t data;
    int i = 0;
    int last_time = -1;
    int now_time = 0;
    int hours;
    int minutes;
    int second;
    int mi;
    int dura = 0;
    char file_flag[50];
    char func_flag[50];
    if((fp = fopen("main.audit","r")) == NULL) {
        printf("filt error");
        return 0;
    }

    char input[1000];
    memset(&data, 0, sizeof(data));
    // while (1) {
        if (fgets(input, 1000, fp) != NULL) {
            char *fmt = "%d:%d:%d.%d [CAN] %s %s speed:%d, rear_wheel_tick:%d, steering_wheel_angle:%d, heading:%d, transmisn:%d, light:%d, ESP_status:%d, TCS_status:%d, ABS_status:%d, LDW_status:%d, brake_pedal:%d, pedal_status:%d, lose_contorl:%u, tire_pressure:%u, acc_x:%d, acc_y:%d, acc_z:%d, gyro_x:%d, gyro_y:%d, gyro_z:%d";
            sscanf(input, fmt,  &hours,
                    &minutes,
                    &second,
                    &mi,
                    file_flag,
                    func_flag,
                    &data.speed,
                    &data.rear_wheel_tick,
                    &data.steering_wheel_angle,
                    &data.heading,
                    &data.transmisn,
                    &data.light,
                    &data.ESP_status,
                    &data.TCS_status,
                    &data.ABS_status,
                    &data.LDW_status,
                    &data.brake_pedal,
                    &data.pedal_status,
                    &data.lose_contorl,
                    &data.tire_pressure,
                    &data.acc_x,
                    &data.acc_y,
                    &data.acc_z,
                    &data.gyro_x,
                    &data.gyro_y,
                    &data.gyro_z);
            printf("%d:%d:%d.%d [CAN] %s %s speed:%d, rear_wheel_tick:%d, steering_wheel_angle:%d, heading:%d, transmisn:%d, light:%d, ESP_status:%d, TCS_status:%d, ABS_status:%d, LDW_status:%d, brake_pedal:%d, pedal_status:%d, lose_contorl:%u, tire_pressure:%u, acc_x:%d, acc_y:%d, acc_z:%d, gyro_x:%d, gyro_y:%d, gyro_z:%d", hours,minutes,
                    second,
                    mi,
                    file_flag,
                    func_flag,
                    data.speed,
                    data.rear_wheel_tick,
                    data.steering_wheel_angle,
                    data.heading,
                    data.transmisn,
                    data.light,
                    data.ESP_status,
                    data.TCS_status,
                    data.ABS_status,
                    data.LDW_status,
                    data.brake_pedal,
                    data.pedal_status,
                    data.lose_contorl,
                    data.tire_pressure,
                    data.acc_x,
                    data.acc_y,
                    data.acc_z,
                    data.gyro_x,
                    data.gyro_y,
                    data.gyro_z);
        } else {
            // break;
        }
    // }
    
    return 0;
}