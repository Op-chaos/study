#include <stdio.h>
#include <string.h>

int main(){
    FILE *fp,*fpL_lon,*fpL_lat,*fpR_lon,*fpR_lat,*fpL_heading, *fplast_kind, *fpkind;
    char find_str[100];
    int i = 0, j=0; 
    char file_str[1024],file_str1[1024];
    fp=fopen("C:/Users/neusoft/Desktop/log/����/vetalk3-5_debug.log","r");

    if (fp==NULL)
    {
        printf("打开错误14\n");
        return -1;
    }

    fpL_lon     = fopen("LOCAL_lon.txt","w");
    fpL_lat     = fopen("LOCAL_lat.txt","w");
    fpL_heading =fopen("LOCAL_heading.txt","w");
    fpR_lon     = fopen("pRemote_lon.txt","w");
    fpR_lat     = fopen("pRemote_lat.txt","w");
    fplast_kind = fopen("fplast_kind.txt","w");
	fpkind      = fopen("fpkind.txt","w");

    /* 判断关键字并提取所在行保存到文件*/
    while (fgets(file_str,sizeof(file_str),fp))
    {
        if (strstr(file_str,"TC_Update(2629)"))
        {
            if (p=strstr(file_str,"lat:"))
            {
            	char *s=p;
                for (i = 4; *(s+i) != ' '; i++){
                // printf("%c", *(s+i));
                fprintf(fpR_lat,"%c",*(s+i));
                }
                // printf("\n");
                fprintf(fpR_lat,"\n");
            }
            // save rv's longitude
            if (p=strstr(file_str,"lon:"))
            {
            	char *s=p;
                for (i = 4; *(s+i) != ' '; i++){
                // printf("%c", *(s+i));
                fprintf(fpR_lon,"%c",*(s+i));
                }
                // printf("\n");
                fprintf(fpR_lon,"\n");
            }
        }

        if (p=strstr(file_str,"<<Local_lon[49]>>="))
        {
        	char *s=p;
            for (i = 18; *(s+i) != ','; i++)
			{
                fprintf(fpL_lat,"%c",*(s+i));
            }
            fprintf(fpL_lat,"\n");
        }
        
        if (p=strstr(file_str,"<<Local_lat[49]>>="))
        {
            char *s=p;
            for (i = 18; *(s+i) != '\n'; i++)
			{
                fprintf(fpL_lon,"%c",*(s+i));
            }
            fprintf(fpL_lon,"\n");
        }
        
        if (p=strstr(file_str,"<<Local_real_angle>>="))
        {
            char *s=p;
            for (i = 21; *(s+i) != '\n'; i++)
			{
                fprintf(fpL_heading,"%c",*(s+i));
            }
            fprintf(fpL_heading,"\n");
        }
        
        if (p=strstr(file_str,"<last_kind>["))
        {
            char *s=p;
            for (i = 12; *(s+i) != '\n'; i++)
			{
                fprintf(fplast_kind,"%c",*(s+i));
            }
            fprintf(fplast_kind,"\n");
        }
        
        if (p=strstr(file_str,"<kind>="))
        {
            char *s=p;
            for (i = 7; *(s+i) != '\n'; i++)
			{
                fprintf(fpkind,"%c",*(s+i));
            }
            fprintf(fpkind,"\n");
        }
        
    }
    printf("����") ; 
    fclose(fpL);
    fclose(fpL_lon);
    fclose(fpL_lat);
    fclose(fpL_heading);
    fclose(fpR_lon);
    fclose(fpR_lat);
    fclose(fplast_kind);
    fclose(fpkind);
    return 0;
}
