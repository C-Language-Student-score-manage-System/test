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
    int score_id[4];
    char score_name[4][32];
}Score;
typedef struct stu
{
    long stu_id;
    char stu_name[32]; 
    struct sex;
    struct collage;
    struct score;
}STU;

