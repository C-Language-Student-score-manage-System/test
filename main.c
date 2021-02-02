#include<stdio.h>
#include<string.h>
//#include "function1.h"
//#include "struct.c"
struct collage
{
    int collage_id;
    char collage_name[32];
};
struct sex
{
    int sex_id;
    char sex_name[32];
};
struct score
{
    int score_i[4];
    char score_name[4][32];
};
typedef struct stu
{
    long stu_id;
    char stu_name[32];
    struct score;
    struct sex;
    struct collage;
}STU;
STU s[500];
int collage_num,stu_num;
int class_num;
void inputCinfo(STU s[])		 
{
	int i;
	FILE *fp;
	fp  = fopen("C_Info1.txt", "r");
	
    fscanf(fp, "%d", &collage_num);
	for(i=0;i<collage_num;i++)
	{
		fscanf(fp, "%d%s", &(s[i].collage_id), &(s[i].collage_name));
		//printf("%d %s\n", (s[i].collage_id), s[i].collage_name );
	}
	fclose(fp);
}
void inputStuinfo(STU s[])
{
    int i;
    FILE *fp;
    fp = fopen("Stu_Info3.txt","r");
    fscanf(fp,"%d",&stu_num);
    fscanf(fp,"%d",&class_num);
    for(i=0;i<stu_num;i++)
    {
        fscanf(fp,"%d %s %d %s %d %d %d %d %d",&(s[i].stu_id),&(s[i].stu_name),&(s[i].sex_name),&(s[i].sex_name),&(s[i].collage_id),&(s[i].score_i[0]),&(s[i].score_i[1]),&(s[i].score_i[2]),&(s[i].score_i[3]));
        if(s[i].collage_id==1)
            strcpy(s[i].collage_name,"信息学院");
        else if(s[i].collage_id==2)
            strcpy(s[i].collage_name,"计算机学院");
        else if(s[i].collage_id==3)
            strcpy(s[i].collage_name,"文法学院");
            
    }
    
    fclose(fp);

}
void Namesorting(STU student[])
{
	int i,j;
	for(i=0;i<stu_num-1;i++)
		for(j=0;j<stu_num-i-1;j++)
		{
			STU temp;
			if(strcmp(student[j].stu_name,student[j+1].stu_name)>0)
			{
				temp=student[j];
				student[j]=student[j+1];
				student[j+1]=temp;
			}
		}
	printf("学号\t姓名\t性别\t学院\t\t科1\t%科2\t科3\t科4\t\n");
	for(i=0;i<stu_num;i++)
        printf("%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",s[i].stu_id,s[i].stu_name,s[i].sex_name,s[i].collage_name,s[i].score_i[0],s[i].score_i[1],s[i].score_i[2],s[i].score_i[3]);

}
void Averagesorting(STU student[])
{
	int i,j;
	double a[41]={0};
	for(j=0;j<stu_num;j++)
	{   a[j]=0;
		for(i=0;i<class_num;i++)
			{   
			    //printf("student[%d].score_i[%d]=%d\n",j,i,student[j].score_i[i]);
			    a[j]+=student[j].score_i[i];
			}
		a[j]=a[j]/class_num;
		//printf("%lf\n",a[j]);
	}
	//printf("class_num=%d\n",class_num);
	for(i=0;i<stu_num-1;i++)
		for(j=i+1;j<stu_num;j++)
		{
			STU temp;
			if(a[i]>a[j])
			{
				temp=student[i];
				student[i]=student[j];
				student[j]=temp;
			}
		}	
	printf("学号\t姓名\t性别\t学院\t\t科1\t%科2\t科3\t科4\t平均成绩\n");
	for(i=0;i<stu_num;i++)
        printf("%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%.2lf\n",s[i].stu_id,s[i].stu_name,s[i].sex_name,s[i].collage_name,s[i].score_i[0],s[i].score_i[1],s[i].score_i[2],s[i].score_i[3],a[i]);

}
void Collagequerying(STU student[])
{
	int n;
	int colnum; 
	printf("请输入查找学院代号：");
	scanf("%d",&colnum);
	int i,j;
	if(colnum<0||colnum>collage_num)
		printf("该学院代号为空!\n");
	else
	{
		printf("*********************************************************************************\n");
		printf("*学号\t姓名\t性别\t学院\t科1\t科2\t科3\t科3\t科4\n");
		for(i=0;i<n;i++)
		{
			if(student[i].collage_id==colnum)
			{
				printf("%d\t%s\t%s\t%s",student[i].stu_id,student[i].stu_name,student[i].sex_name,student[i].collage_name);
				for(j=0;j<class_num;j++)
				{
					printf("\t%d\t%d\t%d\t%d\t",student[i].score_i[j]);
				}
			}	
		}	
		printf("*********************************************************************************\n");
	}	
}
void Revisegrade(STU student[])
{
	char Stu_name[30];
	printf("请输入需修改的学生姓名：");
	scanf("%s",Stu_name);
	int i,j;
	for(i=0;i<stu_num;i++)
	{
		if(strcmp(student[i].stu_name,Stu_name)!=0)
			printf("查无此人!\n");
		else
		{
			printf("*********************************************************************************\n");
			printf("*原信息:\t学号\t姓名\t性别\t学院\t%s\t%s\t%s\t%s\t*\n",student[0].score_name[0],student[0].score_name[1],student[0].score_name[2],student[0].score_name[3]);
			printf("*********************************************************************************\n");
			printf("请输入新成绩:\n");
			for(j=0;j<class_num;j++)
			{
				printf("%s:",student[i].score_name[j]);
				scanf("%d\n",&student[i].score_i[j]);	
			}
			printf("信息修改成功。\n");
		}
	}	
}
void Namequerying(STU student[])
{
	char Stu_name[30];
	printf("请输入查询学生姓名：");
	scanf("%s",Stu_name);
	int i,j;
	for(i=0;i<stu_num;i++)
	{
		if(strcmp(student[i].stu_name,Stu_name)!=0)
			printf("查无此人!\n");
		else
		{
			printf("*********************************************************************************\n");
			printf("*学号\t姓名\t性别\t学院\t%s\t%s\t%s\t%s\t*\n",student[0].score_name[0],student[0].score_name[1],student[0].score_name[2],student[0].score_name[3]);
			printf("%ld\t%s\t%s\t%s",student[i].stu_id,student[i].stu_name,student[i].sex_name,student[i].collage_name);
			for(j=0;j<class_num;j++)
			{
				printf("\t%d\t%d\t%d\t%d\t*\n",student[i].score_i[j]);
			}
			printf("*********************************************************************************\n");

		}
	}
}

void delete_stuscore(STU student[])
{
	char Stu_name[30];
	printf("请输入需删除学生成绩的姓名：");
	scanf("%s",Stu_name);
	int i,j;
	for(i=0;i<stu_num;i++)
	{
		if(strcmp(student[i].stu_name,Stu_name)!=0)
			printf("查无此人!\n");
		else
		{
			for(j=0;j<class_num;j++)
				student[i].score_i[j]=0;
		}
	} 
} 

void print_failstu(STU student[])
{
	int i,j;
	printf("****************挂科学生及科目名单************");
	for(i=0;i<stu_num;i++)
	{
		int flag=0;
		for(j=0;j<class_num;j++)
		{
			if(student[i].score_i[j]<60)
			{
				if(flag==0)
					printf("%s\t%s\t",student[i].stu_name,student[i].score_name[j]);
				else
					printf("%s\t",student[i].score_name[j]);
				flag=1;			
			}
		}
		printf("\n");
	}
	printf("**********************************************");
}
void print_menu()
{
    printf("************学生成绩系统菜单***********************\n");
    printf("*\t1. 按姓名排序，输出                       *\n");
    printf("*\t2. 按平均成绩排序，输出                   *\n");
    printf("*\t3. 输出给定学院学生                       *\n");
    printf("*\t4. 添加学生及其成绩                       *\n");
    printf("*\t5. 修改给定学生成绩信息                   *\n");
    printf("*\t6. 按姓名查询学生，输出                   *\n");
    printf("*\t7. 删除学生成绩                           *\n");
    printf("*\t8. 修改系统密码                           *\n");
    printf("*\t9. 输出挂科学生信息并强调其挂掉的科目     *\n");
    printf("*\t0. 返回上一级菜单                         *\n");
    printf("***************************************************\n");
    
}
void choose_menu()
{   
    void log_in();
    void print_menu();
    print_menu();

    int option;
    printf("请输入数字0-9进入菜单:\n");
    scanf("%d",&option);
    
    switch(option)
    {   
        case 1:
        {
            Namesorting(s);
            break;
        }
        case 2:
        {
            Averagesorting(s);
            break;
        }
        case 3:
        {
            Collagequerying(s);
            break;
        }
        case 4:
        {
            //
            break;
        }
        case 5:
        {
            Revisegrade(s);
            break;
        }
        case 6:
        {
            Namequerying(s);
            break;
        }
        case 7:
        {
            delete_stuscore(s);
            break;
        }
        case 8:
        {
            //
            break;
        }
        case 9:
        {
            print_failstu(s);
            break;
        }
        case 0:
        {
            log_in();
            choose_menu();
            break;
        }

        
        


        
    }
}
void log_in()
{   
    FILE *fp_p;
    char password[32],password_get[32];
    fp_p=fopen("password.txt","r+");
    // if(fp_p==NULL)
    // {
    //     printf("鏂囦欢鎵撳紑澶辫触,璇疯緭鍏ュ瘑鐮乗n");
    //     scanf("%s",password);
    //     fclose(fp_p);
    //     fp_p=fopen("password.txt","w+");
    //     fprintf(fp_p,"%s",password);
    // }
    fscanf(fp_p,"%s",password);

    printf("你好,请输入登录密码:\n");
    scanf("%s",password_get);

    while(strcmp(password,password_get)!=0)
    {
        printf("密码错误,请重新输入:\n");
        scanf("%s",password_get);

    }

    printf("密码正确,登录成功!\n");
    fclose(fp_p);
    

}


int main()
{   
    inputCinfo(s);
    inputStuinfo(s);
    log_in();
    choose_menu();

    // for(int i=0;i<stu_num;i++)
    // printf("%d %s %d %d %d %d %d %d\n",s[i].stu_id,s[i].stu_name,s[i].sex_id,s[i].collage_id,s[i].score_i[0],s[i].score_i[1],s[i].score_i[2],s[i].score_i[3]);

    return 0;
}
