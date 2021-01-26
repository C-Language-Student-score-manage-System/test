#include<stdio.h>
#include<string.h>
struct collage
{
    int collage_id;
    char collage_name[32];
}Collage;
struct sex
{
    int sex_id;
    char sex_name[32];
}Sex;
struct score
{
    int score_id;
    char score_name[32];
}Score[4];
typedef struct stu
{
    long stu_id;
    char stu_name[32];
    struct score;
    struct sex;
    struct collage;
}STU;
STU student[1024];
