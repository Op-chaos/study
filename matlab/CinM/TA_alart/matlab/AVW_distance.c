#include<stdio.h>
#include <stdlib.h>
#include "mex.h"

#define SAFE_DISTANCE     -1.0f

static float _Vetalk_calcSafeDistance_Oncoming(float readiness_time, float frontvehicle_speed, float frontvehicle_lonaccel, float rearvehicle_speed, float rearvehicle_lonaccel, float min_safety_distance)
{
    float Distance;
    
    Distance = 0.0f;

    // printf("rearvehicle_speed %f, frontvehicle_speed %f, frontvehicle_lonaccel %f, rearvehicle_lonaccel %f, readiness_time %f\n", rearvehicle_speed, frontvehicle_speed, frontvehicle_lonaccel, rearvehicle_lonaccel, readiness_time);

    /*d = (v1 - v0) * t + 1/2 * v1 *v1 / a1 - v0 * v1/ a1 - 1/2 * a0 * (v1/a1) ^ 2+ d0 */
    Distance = readiness_time * (rearvehicle_speed - frontvehicle_speed) 
                + 0.5f * rearvehicle_speed *  rearvehicle_speed / (-rearvehicle_lonaccel) 
                - frontvehicle_speed * rearvehicle_speed / (-rearvehicle_lonaccel) 
                - 0.5f * frontvehicle_lonaccel * rearvehicle_speed / (-rearvehicle_lonaccel) * rearvehicle_speed / (-rearvehicle_lonaccel)
                + min_safety_distance;

    return Distance;
}

/*
 * _Vetalk_calcSafeDistance_Inreadinesstime()
 * 
 * 计算反映时间内的安全距离
 * 
 * @readiness_time: 反映时间
 * @frontvehicle_speed: 前车速度
 * @rearvehicle_speed: 后车速度
 * @frontvehicle_lonaccel: 前车加�?�? * @rearvehicle_lonaccel: 后车加�?�? * @min_safety_distance: �?��安全距离
 *
 * return float，反映时间内的安全距�? */
static float _Vetalk_calcSafeDistance_Inreadinesstime(float readiness_time, float frontvehicle_speed, float rearvehicle_speed, float frontvehicle_lonaccel, float min_safety_distance)
{
    float Distance;

    Distance = 0.0f;

    // printf("join in readines time safe distance\n");    

    /* d = (v1-v2) * t - 1/2 * a2 * t ^2  + d0 */
    Distance =  readiness_time * (rearvehicle_speed - frontvehicle_speed) - 0.5f  * frontvehicle_lonaccel * readiness_time * readiness_time  + min_safety_distance;

    return Distance;
}

/*
 * _Vetalk_calcSafeDistance_RearVehicleStopedFirst()
 * 
 * 计算后先停止的安全距��?
 * 
 * @readiness_time: 反映时间
 * @frontvehicle_speed: 前车速度
 * @rearvehicle_speed: 后车速度
 * @frontvehicle_lonaccel: 前车加�?�? * @rearvehicle_lonaccel: 后车加�?�? * @min_safety_distance: �?��安全距离
 *
 * return float，后车先停止的安全距�? */

static float _Vetalk_calcSafeDistance_RearVehicleStopedFirst(float readiness_time, float frontvehicle_speed, float rearvehicle_speed, float frontvehicle_lonaccel, float rearvehicle_lonaccel, float min_safety_distance)
{
    float Distance;
    float equal_time; /* The moment when the front and rear cars are at the same speed. */

    Distance = 0.0f;
    equal_time = 0.0f;

    equal_time = (rearvehicle_speed - frontvehicle_speed - readiness_time * frontvehicle_lonaccel) / (frontvehicle_lonaccel - rearvehicle_lonaccel);

    // printf("join in rear vehicle stop first\n");    

    if (equal_time < 0.0f) {
        printf("calc error, the speed of front vehicle can not equal to rear\n");
        return 1000;
    }

    // printf("rearvehicle_speed %f, frontvehicle_speed %f, frontvehicle_lonaccel %f, rearvehicle_lonaccel %f, readiness_time %f, equal_time %f\n", rearvehicle_speed, frontvehicle_speed, frontvehicle_lonaccel, rearvehicle_lonaccel, readiness_time, equal_time);

    /* d= -v1 * t *et - 1/2 * a1 *et ^2 + 1/2(t + et)^2 +d0 */
    Distance = -rearvehicle_lonaccel * readiness_time * equal_time - 0.5f * rearvehicle_lonaccel * equal_time * equal_time \
               + 0.5f * frontvehicle_lonaccel * (equal_time + readiness_time) * (equal_time + readiness_time) \
                + min_safety_distance;
    // printf("disd %f", Distance);
    
    return Distance;
}

/*
 * _Vetalk_calcSafeDistance_FrontVehicleStopedFirst()
 * 
 * 计算前车先停止的安全距离
 * 
 * @readiness_time: 反映时间
 * @frontvehicle_speed: 前车速度
 * @rearvehicle_speed: 后车速度
 * @frontvehicle_lonaccel: 前车加�?�? * @rearvehicle_lonaccel: 后车加�?�? * @min_safety_distance: �?��安全距离
 *
 * return float，前车先停止的安全距�? */
static float _Vetalk_calcSafeDistance_FrontVehicleStopedFirst(float readiness_time, float frontvehicle_speed, float rearvehicle_speed, float frontvehicle_lonaccel, float rearvehicle_lonaccel, float min_safety_distance)
{
    float Distance;
    
    Distance = 0.0f;

    // printf("rearvehicle_speed %f, frontvehicle_speed %f, frontvehicle_lonaccel %f, rearvehicle_lonaccel %f, readiness_time %f\n", rearvehicle_speed, frontvehicle_speed, frontvehicle_lonaccel, rearvehicle_lonaccel, readiness_time);

    /*d = v1 *t + 1/2 * v1 *v1 /a1 - 1/2 * v2 * v2/a2 + d0  */
    Distance = readiness_time * rearvehicle_speed + 0.5f * rearvehicle_speed *  rearvehicle_speed / (-rearvehicle_lonaccel) - 0.5f * frontvehicle_speed * frontvehicle_speed / (-frontvehicle_lonaccel) + min_safety_distance;

    return Distance;
}

/*
 * _Vetalk_calcSafeDistance()
 * 
 * 计算安全距离
 * 
 * @readiness_time: 反映时间
 * @frontvehicle_speed: 前车速度
 * @rearvehicle_speed: 后车速度
 * @frontvehicle_lonaccel: 前车加�?�? * @rearvehicle_lonaccel: 后车加�?�? * @min_safety_distance: �?��安全距离
 *
 * return float，安全距�? */
static float _Vetalk_calcSafeDistance(float readiness_time, float frontvehicle_speed, float rearvehicle_speed, float frontvehicle_lonaccel, float rearvehicle_lonaccel, float min_safety_distance)
{
        float  frontvehicle_slowdown_time; /* the time of front vehicle slow down to zero */
        float  rearvehicle_slowdown_time; /* the time of rear vehicle slow down to zero */
        float  frontvehicle_speedup_time; /* the time of front vehicle time accelerate to the rear vehicle  */

        frontvehicle_slowdown_time = 0.0f;
        rearvehicle_slowdown_time = 0.0f;
        frontvehicle_speedup_time = 0.0f;

       /* The direction of the rear vehicle is in the positive direction */
        if (frontvehicle_speed < 0) { 
            return _Vetalk_calcSafeDistance_Oncoming(readiness_time, frontvehicle_speed, frontvehicle_lonaccel, rearvehicle_speed, rearvehicle_lonaccel, min_safety_distance);
        } else {
       
            if (frontvehicle_lonaccel > 0) {
                /* front vehicle speed up */

                frontvehicle_speedup_time = (rearvehicle_speed - frontvehicle_speed) / frontvehicle_lonaccel;

                if (frontvehicle_speedup_time < 0.0f) {
                /* front vehicle is quicker than rear vehicle */
                    return 1000;
                } else if (frontvehicle_speedup_time < readiness_time) {
                    return _Vetalk_calcSafeDistance_Inreadinesstime(readiness_time, frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel, min_safety_distance);                  

                } else { 
                    /* front vehicle speed up in low acceleration , use the formula of rearvehicle speed stop first*/                  
                    return _Vetalk_calcSafeDistance_RearVehicleStopedFirst(readiness_time, frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel, rearvehicle_lonaccel, min_safety_distance);
                }
            } else if (frontvehicle_lonaccel == 0) {
            /* front vehicle uniform, use the formula of rearvehicle speed stop first*/

                return _Vetalk_calcSafeDistance_RearVehicleStopedFirst(readiness_time, frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel, rearvehicle_lonaccel, min_safety_distance);

            } else {
            /* front vehicle slow down */
                frontvehicle_slowdown_time = frontvehicle_speed / (-frontvehicle_lonaccel);
                rearvehicle_slowdown_time = readiness_time + rearvehicle_speed / (-rearvehicle_lonaccel);
                
                if (frontvehicle_slowdown_time < rearvehicle_slowdown_time) {
                    return _Vetalk_calcSafeDistance_FrontVehicleStopedFirst(readiness_time, frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel, rearvehicle_lonaccel, min_safety_distance);

                } else {

                        return _Vetalk_calcSafeDistance_RearVehicleStopedFirst(readiness_time, frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel, rearvehicle_lonaccel, min_safety_distance);

                }

           }
      }
}


/*
 * Vetalk_calcAVWSlowedDistance()
 * 
 * 计算主车已刹车的AVW安全距离
 * 
 * @pTA: 指针，指向结构体tTA, 代表TA全局变量
 * @frontvehicle_speed: 前车速度
 * @rearvehicle_speed: 后车速度
 * @frontvehicle_lonaccel: 前车加�?�? * @rearvehicle_lonaccel: 后车加�?�? *
 * return
 * float，主车已刹车的AVW安全距离
 */
float Vetalk_calcAVWSlowedDistance(float frontvehicle_speed, float rearvehicle_speed, float frontvehicle_lonaccel, float rearvehicle_lonaccel)
{
    float   readiness_time = 0.0f;
    float   min_safety_distance = 0.0f;

    min_safety_distance = 2; //.Min_Safety_Distance_m;

    if (frontvehicle_speed > rearvehicle_speed) {
        return SAFE_DISTANCE;
    } else {

        return _Vetalk_calcSafeDistance(readiness_time, frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel, rearvehicle_lonaccel, min_safety_distance);

    }
}

/*
 * Vetalk_calcAVWWarningDistance()
 * 
 * 计算提示级别的AVW安全距离
 * 
 * @pTA: 指针，指向结构体tTA, 代表TA全局变量
 * @frontvehicle_speed: 前车速度
 * @rearvehicle_speed: 后车速度
 * @frontvehicle_lonaccel: 前车加�?�? *
 *
 * return
 * float，提示级别的AVW安全距离
 */
float Vetalk_calcAVWWarningDistance(float frontvehicle_speed, float rearvehicle_speed, float frontvehicle_lonaccel)
{
    float   readiness_time = 0.0f;
    float   min_safety_distance = 0.0f;    
    float   rearvehicle_lonaccel = 0.0f;
	float 	Tr = 0.0f;
	float 	Ts = 0.0f;

	Tr = 3.2;   //.AVW_warning_reaction_time_s;
	Ts = 0.6;

    readiness_time = Tr + Ts;
    min_safety_distance = 2;     //.Min_Safety_Distance_m;
    rearvehicle_lonaccel = -3;   //.AVW_min_decelerate_mps2;

    if (frontvehicle_speed < rearvehicle_speed ) {
        return _Vetalk_calcSafeDistance(readiness_time, frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel, rearvehicle_lonaccel, min_safety_distance);
    } else {
        return SAFE_DISTANCE;
    }

}

/*
 * Vetalk_calcAVWMajorDistance()
 * 
 * 计算警告级别的AVW安全距离
 * 
 * @pTA: 指针，指向结构体tTA, 代表TA全局变量
 * @frontvehicle_speed: 前车速度
 * @rearvehicle_speed: 后车速度
 * @frontvehicle_lonaccel: 前车加�?�? *
 * return
 * 警告级别的AVW安全距离
 */
float Vetalk_calcAVWMajorDistance(float frontvehicle_speed, float rearvehicle_speed, float frontvehicle_lonaccel)
{
    float   readiness_time = 0.0f;
    float   min_safety_distance = 0.0f;    
    float   rearvehicle_lonaccel = 0.0f;
	float 	Tr = 0.0f;
	float 	Ts = 0.0f;    

	Tr = 1.8;    //.AVW_major_reaction_time_s;
    
	Ts = 0.6;

    readiness_time = Tr + Ts;
    min_safety_distance = 2;  //.Min_Safety_Distance_m;
    rearvehicle_lonaccel = -3;  //.AVW_min_decelerate_mps2;

    if (frontvehicle_speed < rearvehicle_speed) {
        return _Vetalk_calcSafeDistance(readiness_time, frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel, rearvehicle_lonaccel, min_safety_distance);
    } else {
        return SAFE_DISTANCE;
    } 

}

/*
 * Vetalk_calcAVWEmergencyDistance()
 * 
 * 计算严重警告级别的AVW安全距离
 * 
 * @pTA: 指针，指向结构体tTA, 代表TA全局变量
 * @frontvehicle_speed: 前车速度
 * @rearvehicle_speed: 后车速度
 * @frontvehicle_lonaccel: 前车加�?�? *
 * return
 * 严重警告级别的AVW安全距离
 */
float Vetalk_calcAVWEmergencyDistance(float frontvehicle_speed, float rearvehicle_speed, float frontvehicle_lonaccel)
{
    float   readiness_time = 0.0f;
    float   min_safety_distance = 0.0f;    
    float   rearvehicle_lonaccel = 0.0f;
	float 	Ts = 0.0f;    
	float 	Tr = 0.0f;    

    Tr = 0.6;   //.AVW_emergency_reaction_time_s;
	Ts = 0.6;

    readiness_time = Ts + Tr;
    min_safety_distance = 2;  //.Min_Safety_Distance_m;
    rearvehicle_lonaccel = -3; //.AVW_min_decelerate_mps2;

    if (frontvehicle_speed < rearvehicle_speed) {
        return _Vetalk_calcSafeDistance(readiness_time, frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel, rearvehicle_lonaccel, min_safety_distance);
    } else {
        return SAFE_DISTANCE;
    } 
    
}

/*
 * Vetalk_calcAVWWarningFlexibleDistance()
 * 
 * 计算提示级别的AVW安全回置距离
 * 
 * @pTA: 指针，指向结构体tTA, 代表TA全局变量
 * @frontvehicle_speed: 前车速度
 * @rearvehicle_speed: 后车速度
 * @frontvehicle_lonaccel: 前车加�?�? *
 *
 * return
 * float，提示级别的AVW安全回置距离
 */
float Vetalk_calcAVWWarningFlexibleDistance(float frontvehicle_speed, float rearvehicle_speed, float frontvehicle_lonaccel)
{
    return (float)(1.0f + 5.0f / 100.0f) * (Vetalk_calcAVWWarningDistance(frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel));
}

/*
 * Vetalk_calcAVWMajorFlexibleDistance()
 * 
 * 计算警告级别的AVW安全回置距离
 * 
 * @pTA: 指针，指向结构体tTA, 代表TA全局变量
 * @frontvehicle_speed: 前车速度
 * @rearvehicle_speed: 后车速度
 * @frontvehicle_lonaccel: 前车加�?�? *
 *
 * return
 * float，警告级别的AVW安全回置距离
 */
float Vetalk_calcAVWMajorFlexibleDistance(float frontvehicle_speed, float rearvehicle_speed, float frontvehicle_lonaccel)
{
    return (float)(1.0f + 5.0f / 100.0f) * (Vetalk_calcAVWMajorDistance(frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel));
}

/*
 * Vetalk_calcAVWMajorFlexibleDistance()
 * 
 * 计算警告级别的AVW安全回置距离
 * 
 * @pTA: 指针，指向结构体tTA, 代表TA全局变量
 * @frontvehicle_speed: 前车速度
 * @rearvehicle_speed: 后车速度
 * @frontvehicle_lonaccel: 前车加�?�? *
 *
 * return
 * float，警告级别的AVW安全回置距离
 */
float Vetalk_calcAVWEmergencyFlexibleDistance(float frontvehicle_speed, float rearvehicle_speed, float frontvehicle_lonaccel)
{
    return (float)(1.0f + 5.0f / 100.0f) * (Vetalk_calcAVWEmergencyDistance(frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel));
}

void TA_EvaluateThreatAVW(float frontvehicle_speed, float rearvehicle_speed, float frontvehicle_lonaccel, float rearvehicle_lonaccel, double distance[])
{
    float d;
    float d_warning;
    float d_major;
    float d_emergency;
    float d_slowed;
    int kind = 1;           // 1:AHEAD

    d = 0.0f;
    d_warning = 0.0f;
    d_major = 0.0f;
    d_emergency = 0.0f;
    d_slowed = 0.0f;

    /*  ahead has soft , hard severe levels */
    if (frontvehicle_speed < 0) {
        d_warning = -1;
        d_major = -1;
        d_emergency = -1;
    } else if (kind == 1) {
        /* 车辆已刹车，并且减�?度达到一定程度，不�?虑反映时间，使用已减速公�?*/
        if (rearvehicle_lonaccel < -3) {

            /* The vehicle has slowed down */
            d_slowed = Vetalk_calcAVWSlowedDistance(frontvehicle_speed, 
                                                    rearvehicle_speed, 
                                                    frontvehicle_lonaccel, 
                                                    rearvehicle_lonaccel);
            d_warning = d_slowed;
            d_major = -1;
            d_emergency = -1;
        } else {
            d_warning = Vetalk_calcAVWWarningDistance(frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel);
            d_major = Vetalk_calcAVWMajorDistance(frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel);
            d_emergency = Vetalk_calcAVWEmergencyDistance(frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel);
        }
    } else {
        /* 车辆已刹车，并且减�?度达到一定程度，不�?虑反映时间，使用已减速公�?*/
        if (rearvehicle_lonaccel < -3) {

            /* The vehicle has slowed down */
            d_slowed = Vetalk_calcAVWSlowedDistance(frontvehicle_speed, 
                                                    rearvehicle_speed, 
                                                    frontvehicle_lonaccel, 
                                                    rearvehicle_lonaccel);
            d_warning = d_slowed;
            d_major = -1;
            d_emergency = -1;
        } else {
            d_warning = Vetalk_calcAVWWarningDistance(frontvehicle_speed, rearvehicle_speed, frontvehicle_lonaccel);
            d_major = -1;
            d_emergency = -1;
        }
    }
    distance[0] = d_warning > 300 ? 300 : d_warning;
    distance[1] = d_major > 300 ? 300 : d_major;
    distance[2] = d_emergency > 300 ? 300 : d_emergency;
    return;
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double v1, v2, a1, a2, *d;
    v1 = *(mxGetPr(prhs[0]));
    v2 = *(mxGetPr(prhs[1]));
    a1 = *(mxGetPr(prhs[2]));
    a2 = *(mxGetPr(prhs[3]));
    plhs[0] = mxCreateDoubleMatrix(1,3,mxREAL);
    d = mxGetPr(plhs[0]);
    if(nrhs != 4) {
        printf("format is : d = AVW_distance(v1, v2, a1, a2)\n");
    } else {
        TA_EvaluateThreatAVW(v1, v2, a1, a2, d);
    }
}