// #include <stdio.h>

// typedef struct
// {
//     char name[20];
//     char ID[10];
//     int classgrade[3];
//     int average_grade;
//     int sum_grade;
// } Student;
// int main()
// {
//     Student stu[5];
//     printf("please input the information of 5 students:\n");
//     for (int i = 0; i < 5; i++)
//     {
//         stu[i].sum_grade = 0;
//         printf("please input the name of student %d:", i + 1);
//         scanf("%s", stu[i].name);
//         printf("please input the ID of student %d:", i + 1);
//         scanf("%s", stu[i].ID);
//         printf("please input the classgrade of student %d:", i + 1);
//         for (int j = 0; j < 3; j++)
//         {
//             scanf("%d", &stu[i].classgrade[j]);
//             stu[i].sum_grade += stu[i].classgrade[j];
//         }
//         stu[i].average_grade = stu[i].sum_grade / 3;
//     }
//     printf("\nthe information of 5 students is:\n");
//     printf("Name\tID\tGrade1\tGrade2\tGrade3\tAverage\tTotal\n");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",
//                stu[i].name,
//                stu[i].ID,
//                stu[i].classgrade[0],
//                stu[i].classgrade[1],
//                stu[i].classgrade[2],
//                stu[i].average_grade,
//                stu[i].sum_grade);
//     }
// }

#include <stdio.h>

int main(int argc, char const *argv[])
{

    return 0;
}
