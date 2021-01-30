#include<stdio.h>
#include<string.h>
#include<math.h>
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
    void choose_menu();
    print_menu();

    int option;
    printf("请输入数字0-9进入菜单:\n");
    scanf("%d",&option);
    
    switch(option)
    {   
        case 1:
        {
            Namesorting();
            break;
        }
        case 2:
        {
            Averagesorting();
            break;
        }
        case 3:
        {
            Collagequerying();
            break;
        }
        case 4:
        {
            //
            break;
        }
        case 5:
        {
            Revisegrade();
            break;
        }
        case 6:
        {
            Namequerying();
            break;
        }
        case 7:
        {
            delete_stuscore();
            break;
        }
        case 8:
        {
            //
            break;
        }
        case 9:
        {
            print_failstu();
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
    //     printf("文件打开失败,请输入密码\n");
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


// void get_password()
// {
//     FILE *fp_p;
//     char password[32];

//     fp_p=fopen("password.txt","r+");
//     if(fp_p==NULL)
//     {
//         printf("文件打开失败,请输入密码\n");
//         scanf("%s",password);
//         fp_p=fopen("password.txt","w+");
//         fprintf(fp_p,password);
    


//     }


//     fclose(fp_p);
// }

void Namesorting()
{
	STU student[500];
	int n;
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			STU temp;
			if(strcmp(student[j].stu_name,STU[j+1].stu_name)>0)
			{
				temp=student[j];
				student[j]=student[j+1];
				student[j+1]=temp;
			}
		}
}
void Averagesorting()
{
	STU student[500]; 
	int n;
	int i,j;
	float average[n];
	for(j=0;j<n;j++)
	{
		for(i=0;i<class;i++)
			average[j]+=student[j].Score.score_id[i];
		average[j]/=class;
	}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			STU temp;
			if(average[j]>average[j+1])
			{
				temp=student[j];
				student[j]=student[j+1];
				student[j+1]=temp;
			}
		}		
}
void Collagequerying()
{
	STU student[500];
	int n;
	int colnum; 
	printf("请输入查找学院代号：");
	scanf("%d",&colnum);
	int i,j;
	if(colnum<0||colnum>10)
		printf("该学院代号为空!\n");
	else
	{
		printf("*********************************************************************************\n");
		printf("*学号\t姓名\t性别\t学院\t%s\t%s\t%s\t%s\t*\n",student[0].Score.score_name[0],student[0].Score.score_name[1],student[0].Score.score_name[2],student[0].Score.score_name[3]);
		for(i=0;i<n;i++)
		{
			if(student[i].Collage.collage_id==colnum)
			{
				printf("%ld\t%s\t%s\t%s",student[i].stu_id,student[i].stu_name,student[i].Sex.sex_name,student[i].Collage.collage_name)
				for(j=0;j<class;j++)
				{
					printf("\t%d\t%d\t%d\t%d\t*\n",student[i].score.score_id[j])
				}
			}	
		}	
		printf("*********************************************************************************\n");
	}	
}
void Revisegrade()
{
	STU student[500];
	char Stu_name[30];
	printf("请输入需修改的学生姓名：");
	scanf("%s",Stu_name);
	int i,j;
	for(i=0;i<n;i++)
	{
		if(strcmp(student[i].stu_name,Stu_name)!=0)
			printf("查无此人!\n");
		else
		{
			printf("*********************************************************************************\n");
			printf("*原信息:\t学号\t姓名\t性别\t学院\t%s\t%s\t%s\t%s\t*\n",student[0].Score.score_name[0],student[0].Score.score_name[1],student[0].Score.score_name[2],student[0].Score.score_name[3]);
			printf("*********************************************************************************\n");
			printf("请输入新成绩:\n");
			for(j=0;j<class;j++)
			{
				printf("%s:",student[i].Score.score_name[j]);
				scanf("%d\n",&student[i].Score.score_id[j]);	
			}
			printf("信息修改成功。\n");
		}
	}	
}
void Namequerying()
{
	STU student[500];
	char Stu_name[30];
	printf("请输入查询学生姓名：");
	scanf("%s",Stu_name);
	int i,j;
	for(i=0;i<n;i++)
	{
		if(strcmp(student[i].stu_name,Stu_name)!=0)
			printf("查无此人!\n");
		else
		{
			printf("*********************************************************************************\n");
			printf("*学号\t姓名\t性别\t学院\t%s\t%s\t%s\t%s\t*\n",student[0].Score.score_name[0],student[0].Score.score_name[1],student[0].Score.score_name[2],student[0].Score.score_name[3]);
			printf("%ld\t%s\t%s\t%s",student[i].stu_id,student[i].stu_name,student[i].Sex.sex_name,student[i].Collage.collage_name)
			for(j=0;j<class;j++)
			{
				printf("\t%d\t%d\t%d\t%d\t*\n",student[i].score.score_id[j])
			}
			printf("*********************************************************************************\n");

		}
	}
}

void delete_stuscore()
{
	STU student[500];
	char Stu_name[30];
	printf("请输入需删除学生成绩的姓名：");
	scanf("%s",Stu_name);
	int i,j;
	for(i=0;i<n;i++)
	{
		if(strcmp(student[i].stu_name,Stu_name)!=0)
			printf("查无此人!\n");
		else
		{
			for(j=0;j<class;j++)
				student[i].Score.score_id[j]=0;
		}
	} 
} 

void print_failstu()
{
	STU student[500];
	int i,j;
	printf("****************挂科学生及科目名单*************");
	for(i=0;i<n;i++)
	{
		int flag=0;
		for(j=0;j<class;j++)
		{
			if(student[i].score.score_id[j]<60)
			{
				if(flag==0)
					printf("%s\t%s\t",student[i].stu_name,student[i].Score.score_name[j]);
				else
					printf("%s\t",student[i].Score.score_name[j]);
				flag=1;			
			}
		}
		printf("\n");
	}
	printf("**********************************************");
}


