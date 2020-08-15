#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Num1 2000
#define N_count 50
#define PI 3.141592653589793  /*********圆周率**********/


double equator_radius=6378137;  //赤道半径 




double rad (double d)
{
  return d * PI / 180.0;
}

double north_angle(double angle)
{
	if (angle > -0.5*PI&&angle < PI)
	{
		return 0.5 * PI-angle;
	}
	else
	{
		return -angle-1.5*PI;

	}
	
	
}

double distance_calculation(double lat1, double lon1, double lat2, double lon2) //距离公式
{
    double d; 
    double d1;
    double d2;
    d1=pow(sin((rad(lat1)-rad(lat2))/2),2);
    d2=pow(sin((rad(lon1)-rad(lon2))/2),2)*cos(rad(lat1))*cos(rad(lat2));
    d=2*equator_radius*asin(sqrt(d1+d2));
    return d;
}

/*********最小距离编号**********/
int min_distance(double Local_real_lat, double Local_real_lon, double remote_ph_lat[], double remote_ph_lon[])
{
	  int length = N_count;
	  double distance_value[N_count];
	  int i;
	  int num=0;
	  int Judge_nearest_point=0;
	  double minvalue = distance_calculation(Local_real_lat,Local_real_lon,remote_ph_lat[0],remote_ph_lon[0]);
	  
	  for (i = 0; i < length; i++)
	  {
		distance_value[i]=distance_calculation(Local_real_lat,Local_real_lon,remote_ph_lat[i],remote_ph_lon[i]);
		if (minvalue > distance_value[i])
		 {
			 minvalue = distance_value[i];
             num=i;			 
		 }
	  }
	  
	  if (num == N_count-1)
	  {
	  Judge_nearest_point=1;
	  }	 
      
	  return Judge_nearest_point;
}

/*********同向反向判定**********/
double orientation_judge(double Local_real_lat, double Local_real_lon, double remote_ph_lat[], double remote_ph_lon[], double Local_real_angle)
{
	int length = N_count;
	double distance_value[N_count];
	int i;
	int num = 0;
	double Judge_orientation_angle = 0;
	double minvalue = distance_calculation(Local_real_lat, Local_real_lon, remote_ph_lat[0], remote_ph_lon[0]);

	for (i = 0; i < length; i++)
	{
		distance_value[i] = distance_calculation(Local_real_lat, Local_real_lon, remote_ph_lat[i], remote_ph_lon[i]);
		if (minvalue > distance_value[i])
		{
			minvalue = distance_value[i];
			num = i;
		}
	}

	if (num == N_count-1)
	{
		Judge_orientation_angle = north_angle(atan2(cos(rad(remote_ph_lat[N_count - 2]))*(remote_ph_lon[N_count - 1] - remote_ph_lon[N_count - 2]), (remote_ph_lat[N_count - 1] - remote_ph_lat[N_count - 2]))) - rad(Local_real_angle);
			
	}
	else 
	{
		Judge_orientation_angle = north_angle(atan2(cos(rad(remote_ph_lat[num]))*(remote_ph_lon[num + 1] - remote_ph_lon[num]), (remote_ph_lat[num + 1] - remote_ph_lat[num]))) - rad(Local_real_angle);

	}

	return Judge_orientation_angle;
}

/*********左邻，左远邻等分类**********/
int specification_judge(double refer_real_lat, double refer_real_lon, double reference_ph_lat[], double reference_ph_lon[])
{
	int length = N_count;
	double distance_value[N_count];
	int i;
	int num = 0;
	int Judge_classification_kind = 0;
	double calculation_angle;
	double calculation_distance;
	double test1;
	double test2;

	double minvalue = distance_calculation(refer_real_lat, refer_real_lon, reference_ph_lat[0], reference_ph_lon[0]);

	for (i = 0; i < length; i++)
	{
		distance_value[i] = distance_calculation(refer_real_lat, refer_real_lon, reference_ph_lat[i], reference_ph_lon[i]);
		if (minvalue > distance_value[i])
		{
			minvalue = distance_value[i];
			num = i;
		}
	}

	if (num == 49)
	{
		calculation_angle = north_angle(atan2(cos(rad(reference_ph_lat[N_count - 2]))*(reference_ph_lon[N_count - 1] - reference_ph_lon[N_count - 2]), (reference_ph_lat[N_count - 1] - reference_ph_lat[N_count - 2]))) - north_angle(atan2(cos(rad(refer_real_lat))*(reference_ph_lon[N_count - 1] - refer_real_lon), (reference_ph_lat[N_count - 1] - refer_real_lat)));
		calculation_distance = fabs(sin(calculation_angle))*distance_calculation(refer_real_lat, refer_real_lon, reference_ph_lat[49], reference_ph_lon[49]);

	}
	else
	{
		calculation_angle = north_angle(atan2(cos(rad(reference_ph_lat[num]))*(reference_ph_lon[num + 1] - reference_ph_lon[num]), (reference_ph_lat[num + 1] - reference_ph_lat[num]))) - north_angle(atan2(cos(rad(refer_real_lat))*(reference_ph_lon[num + 1] - refer_real_lon), (reference_ph_lat[num + 1] - refer_real_lat)));
		calculation_distance = fabs(sin(calculation_angle))*distance_calculation(refer_real_lat, refer_real_lon, reference_ph_lat[num + 1], reference_ph_lon[num + 1]);

	}

	if (calculation_distance < 1.75)
	{
		Judge_classification_kind = 6;//同向后方同车道
	}
	else if (calculation_distance < 5.25)
	{
		if (calculation_angle < 0)
		{
			Judge_classification_kind = 7;//同向后方左邻道
		}
		else
		{
			Judge_classification_kind = 8;//同向后方右邻道

		}
	}
	else
	{
		if (calculation_angle < 0)
		{
			Judge_classification_kind = 9;//同向后方左远邻
		}
		else
		{
			Judge_classification_kind = 10;//同向后方右远邻

		}
	}

	return Judge_classification_kind;
}

int specification_judge1(double refer_real_lat, double refer_real_lon, double reference_ph_lat[], double reference_ph_lon[])
{
	int length = N_count;
	double distance_value[N_count];
	int i;
	int num = 0;
	int Judge_classification_kind = 0;
	double calculation_angle;
	double calculation_distance;

	double minvalue = distance_calculation(refer_real_lat, refer_real_lon, reference_ph_lat[0], reference_ph_lon[0]);

	for (i = 0; i < length; i++)
	{
		distance_value[i] = distance_calculation(refer_real_lat, refer_real_lon, reference_ph_lat[i], reference_ph_lon[i]);
		if (minvalue > distance_value[i])
		{
			minvalue = distance_value[i];
			num = i;
		}
	}

	if (num == 49)
	{
		calculation_angle = north_angle(atan2(cos(reference_ph_lat[N_count - 2])*(reference_ph_lon[N_count - 1] - reference_ph_lon[N_count - 2]), (reference_ph_lat[N_count - 1] - reference_ph_lat[N_count - 2]))) - north_angle(atan2(cos(refer_real_lat)*(reference_ph_lon[N_count - 1] - refer_real_lon), (reference_ph_lat[N_count - 1] - refer_real_lat)));
		calculation_distance = fabs(sin(calculation_angle))*distance_calculation(refer_real_lat, refer_real_lon, reference_ph_lat[49], reference_ph_lon[49]);

	}
	else
	{
		calculation_angle = north_angle(atan2(cos(reference_ph_lat[num])*(reference_ph_lon[num + 1] - reference_ph_lon[num]), (reference_ph_lat[num + 1] - reference_ph_lat[num])))-north_angle(atan2(cos(refer_real_lat)*(reference_ph_lon[num + 1] - refer_real_lon), (reference_ph_lat[num + 1] - refer_real_lat)));
		calculation_distance = fabs(sin(calculation_angle))*distance_calculation(refer_real_lat, refer_real_lon, reference_ph_lat[num + 1], reference_ph_lon[num + 1]);
	}

	if (calculation_distance < 1.75)
	{
		Judge_classification_kind =1;//同向前方同车道
	}
	else if (calculation_distance < 5.25)
	{
		if (calculation_angle < 0)
		{
			Judge_classification_kind = 3;//同向前方右邻道
		}
		else
		{
			Judge_classification_kind = 2;//同向前方左邻道

		}
	}
	else
	{
		if (calculation_angle < 0)
		{
			Judge_classification_kind = 5;//同向前方右远邻
		}
		else
		{
			Judge_classification_kind = 4;//同向前方左远邻

		}
	}

	return Judge_classification_kind;
}

/*********主函数**********/

main()
{
	
	

	double remote_lat;
	double remote_lon;
	double local_lat;
	double local_lon;

	double Local_real_angle;
	
	int curve_classification_result = 0;
	double reference_ph_lon[N_count];
	double reference_ph_lat[N_count];
	double refer_real_lat;
	double refer_real_lon;
	int buffer_flag=0;


	errno_t err;
	FILE* fp;
	if ((err = fopen_s(&fp, "F:\\V2X\\algorithm\\curve_class_test\\curve_class_test\\1.txt", "r")) != 0)
	{
		printf("Cannot open this filefp1\n");
		exit(0);
	}
	int i, j, res = 0;
	double Local_lat[50], Local_lon[50], Remote_lat[50], Remote_lon[50], heading;
	for (i = 0; i <= Num1; i++)
	{
		if (res == EOF)
			break;
		for (j = 1; j<50; j++)
		{
			Local_lat[j - 1] = Local_lat[j];
			Local_lon[j - 1] = Local_lon[j];
			Remote_lat[j - 1] = Remote_lat[j];
			Remote_lon[j - 1] = Remote_lon[j];
		}
		res = fscanf_s(fp, "%lf", &Local_lat[49]);
		res = fscanf_s(fp, "%lf", &Local_lon[49]);
		res = fscanf_s(fp, "%lf", &heading);
		res = fscanf_s(fp, "%lf", &Remote_lat[49]);
		res = fscanf_s(fp, "%lf", &Remote_lon[49]);

		Local_real_angle = heading;
		remote_lat = Remote_lat[49];
		remote_lon = Remote_lon[49];
		local_lat = Local_lat[49];
		local_lon = Local_lon[49];
		buffer_flag++;
		if (buffer_flag > N_count - 1)
		{
			double orientation_minus = orientation_judge(local_lat, local_lon, Remote_lat, Remote_lon, Local_real_angle);
			int distance_label = min_distance(local_lat, local_lon, Remote_lat, Remote_lon);
			int i = 0;
			if (fabs(orientation_minus) * 180 / PI < 90) //同向1-10
			{
				if (distance_label == 1) //远车在后方
				{
					for (i = 0; i < 50; i++)
					{
						reference_ph_lon[i] = Local_lon[i];
						reference_ph_lat[i] = Local_lat[i];
						refer_real_lat = remote_lat;
						refer_real_lon = remote_lon;
					}
					curve_classification_result = specification_judge(refer_real_lat, refer_real_lon, reference_ph_lat, reference_ph_lon);
				}
				else //远车在前方
				{
					int i = 0;
					for (i = 0; i < 50; i++)
					{
						reference_ph_lon[i] = Remote_lon[i];
						reference_ph_lat[i] = Remote_lat[i];
						refer_real_lat = local_lat;
						refer_real_lon = local_lon;
					}
					curve_classification_result = specification_judge1(refer_real_lat, refer_real_lon, reference_ph_lat, reference_ph_lon);

				}
			}
			else //反向11
			{
				if (distance_label == 1)
				{
					curve_classification_result = 11;
				}
			}

			printf("%d ", curve_classification_result);
		}

	}
	
	fclose(fp);


	system("pause");









	//double orientation_minus = orientation_judge(local_lat, local_lon, remote_ph_lat, remote_ph_lon, Local_real_angle);
	//int distance_label = min_distance(local_lat, local_lon, remote_ph_lat, remote_ph_lon);

	//if (fabs(orientation_minus)*180/PI < 90) //同向1-10
	//{
	//	if (distance_label == 1) //远车在后方
	//	{
	//		for (int i = 0; i < 50; i++)
	//		{
	//			reference_ph_lon[i] = local_ph_lon[i];
	//			reference_ph_lat[i] = local_ph_lat[i];
	//			refer_real_lat = remote_lat;
	//			refer_real_lon = remote_lon;


	//		}

	//		curve_classification_result = specification_judge(refer_real_lat, refer_real_lon, reference_ph_lat, reference_ph_lon);
	//	}
	//	else //远车在前方
	//	{
	//		for (int i = 0; i < 50; i++)
	//		{
	//			reference_ph_lon[i] = remote_ph_lon[i];
	//			reference_ph_lat[i] = remote_ph_lat[i];
	//			refer_real_lat = local_lat;
	//			refer_real_lon = local_lon;
	//		}
	//		curve_classification_result = specification_judge1(refer_real_lat, refer_real_lon, reference_ph_lat, reference_ph_lon);

	//	}
	//}
	//else //反向11
	//{
	//	if (distance_label == 1)
	//	{
	//		curve_classification_result = 11;
	//	}
	//}



}
