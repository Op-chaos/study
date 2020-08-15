#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define RADSTOHDU 1.043038e4  /*< Rads to Heading Units  */
#define HDUTORADS 9.587380e-5f /*< Heading Units to Rads  */
#define DEGSTOHDUS 182.044444 /*< Degs to Heading Units  */
#define POW_MACRO_AXIS 40680631590769.0
#define POW_MINOR_AXIS 40408299803555.29

double rad(double d) {
    return d * 0.0174533; /* PI / 180.0 */
}

void earth_distance_simple(double latStart, double lngStart, double latEnd, double lngEnd, 
                           double *lngDistance, double *latDistance, double *distance)
{

    double latStart_r = rad(latStart);
    double lngStart_r = rad(lngStart);
    double latEnd_r = rad(latEnd);
    double lngEnd_r = rad(lngEnd);

    double a = POW_MACRO_AXIS;
    double b = POW_MINOR_AXIS;
    double c = pow(tan(latStart_r), 2.0);
    double d = pow(1 / tan(latStart_r), 2.0);
    
    double x = a / sqrt(a + b * c);
    double y = b / sqrt(b + a * d);

    c = pow(tan(latEnd_r), 2.0);
    d = pow(1 / tan(latEnd_r), 2.0);

    double m = a / sqrt(a + b * c);
    double n = b / sqrt(b + a * d);

    double cordinateY = sqrt(pow((x - m), 2.0) + pow((y - n), 2.0));

    double cx = pow(tan(latStart_r), 2.0);
    double xx = a / sqrt(a + b * cx);
    double cordinateX = xx * (lngEnd_r - lngStart_r);

    // 两点经度距离(mm)
    if (lngDistance != NULL) {
        *lngDistance = cordinateX;
    }
    // 两点纬度距离(mm)
    if (latDistance != NULL) {
        *latDistance = cordinateY;
        // 2015/11/02 座标系使用错误，由0度经度坐标修改为0度赤道座标
        if (latEnd_r < latStart_r)
        {
            *latDistance *= -1;
        }
    }

    //两点距离
    if(distance != NULL) {
        *distance = sqrt(pow(cordinateX, 2.0) + pow(cordinateY, 2.0));
    }
    
    return;
}

float PointToLineDis(int point_lat, int point_lon,
                          int line_start_lat, int line_start_lon, float line_heading)
{
    float  rb10, x10;
    double pX10, pY10, pS10, b10;
    double line_start_lat_f = (double)(line_start_lat / 10000000.0);  
    double line_start_lon_f = (double)(line_start_lon / 10000000.0);
    double point_lat_f = (double)(point_lat / 10000000.0);  
    double point_lon_f = (double)(point_lon / 10000000.0);

    earth_distance_simple(line_start_lat_f, line_start_lon_f, point_lat_f, point_lon_f, &pX10, &pY10, &pS10);

    // TODO: 以下方向要考虑正负及象限！
    // 两点的经纬度 => 两点间的相对方向(hdu)
    b10 = (int)(RADSTOHDU * atan2(pX10, pY10));

    // 起点的头向及两点间的相对方向 => 两点间的头相对方向(hdu)
    rb10 = (float)(b10 - line_heading * DEGSTOHDUS);

    x10 = (float)(pS10 * sin(HDUTORADS * rb10));

    return x10;

}

int main()
{
    double d;                 /* 两点距离*/
	double d_r;               /* 投影距离*/
	int lane_change_result = 0;   /* 变道分析结果*/

    int point_lat = (int)(41.694314 * 10000000);
    int point_lon = (int)(123.443911 * 10000000);
    int line_start_lat = (int)(41.694099 * 10000000);
    int line_start_lon = (int)(123.443782 * 10000000);
    double line_heading = 32;

    d_r = PointToLineDis(point_lat, point_lon, line_start_lat, line_start_lon, line_heading);
    printf("the distance of lane change = %lf, d = %lf", d_r, d);
}