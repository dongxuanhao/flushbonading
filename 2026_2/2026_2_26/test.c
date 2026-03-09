// #include <stdio.h>

// typedef struct
// {
//     char name[20];
//     int age;
// } Person;

// int main(int argc, char const *argv[])
// {
//     Person person;
//     printf("please input name:");
//     scanf("%s", person.name);
//     printf("please input age:");
//     scanf("%d", &person.age);
//     printf("name:%s,age:%d", person.name, person.age);
//     return 0;
// }

// #include <stdio.h>

// enum Gender
// {
//     MALE,
//     FMALE,
// };

// typedef struct
// {
//     char id[20];
//     char name[20];
//     enum Gender gender;
//     int score;
// } Student;

// int main(int argc, char const *argv[])
// {
//     Student student1 = {"001", "zhangsan", MALE, 80};
//     Student student2 = {"002", "lisi", FMALE, 90};
//     Student student3 = {"003", "wangwu", MALE, 85};
//     printf("id:%s,name:%s,gender:%d,score:%d\n\n", student1.id, student1.name, student1.gender, student1.score);
//     printf("id:%s,name:%s,gender:%d,score:%d\n\n", student2.id, student2.name, student2.gender, student2.score);
//     printf("id:%s,name:%s,gender:%d,score:%d\n\n", student3.id, student3.name, student3.gender, student3.score);
//     return 0;
// }

// #include <stdio.h>
// #include <windows.h>

// enum LightState
// {
//     RED,
//     GREEN,
//     YELLOW,
// };

// int main(int argc, char const *argv[])
// {
//     enum LightState current_light = RED;
//     while (1)
//     {
//         switch (current_light)
//         {
//         case RED:
//             current_light = GREEN;
//             printf("current light is:RED\n");
//             Sleep(1000);
//             break;
//         case GREEN:
//             current_light = YELLOW;
//             printf("current light is:GREEN\n");
//             Sleep(1000);
//             break;
//         case YELLOW:
//             current_light = RED;
//             printf("current light is:YELLOW\n");
//             Sleep(1000);
//             break;
//         }
//     }
//     return 0;
// }

// #include <stdio.h>

// enum SensorType
// {
//     TEMPERATURE,
//     HUMIDITY,
//     PRESSURE
// };

// union SensorData
// {
//     float temperature;
//     int humidity;
//     float pressure;
// };

// int main(int argc, char const *argv[])
// {
//     union SensorData sensor_data;
//     enum SensorType sensor_type;
//     printf("Enter sensor type (0:Temperature 1:Humidity 2:Pressure): ");
//     scanf("%d", &sensor_type);
//     switch (sensor_type)
//     {
//     case TEMPERATURE:
//         printf("please enter the temperature:\n");
//         scanf("%f", &sensor_data.temperature);
//         break;
//     case HUMIDITY:
//         printf("please enter the humidity:\n");
//         scanf("%d", &sensor_data.humidity);
//         break;
//     case PRESSURE:
//         printf("please enter the pressure:\n");
//         scanf("%f", &sensor_data.pressure);
//         break;
//     default:
//         printf("invalid sensor type!");
//     }
//     printf("the sensor type is:%d\n", sensor_type);
//     switch (sensor_type)
//     {
//     case TEMPERATURE:
//         printf("the sensor data is:%f", sensor_data.temperature);
//         break;
//     case HUMIDITY:
//         printf("the sensor data is:%d", sensor_data.humidity);
//         break;
//     case PRESSURE:
//         printf("the sensor data is:%f", sensor_data.pressure);
//         break;
//     }
//     return 0;
// }

// #include <stdio.h>

// enum Status
// {
//     AVAILABLE,
//     BORROWED
// };

// typedef struct
// {
//     char id[10];
//     char title[30];
//     enum Status status;
// } Book;

// int main(int argc, char const *argv[])
// {
//     Book book1 = {"001", "book1", AVAILABLE};
//     Book book2 = {"002", "book2", BORROWED};
//     Book book3 = {"003", "book3", AVAILABLE};

//     printf("the ID is:%s\n", book1.id);
//     printf("the title is:%s\n", book1.title);
//     printf("the states is:%d\n", book1.status);
//     printf("the ID is:%s\n", book2.id);
//     printf("the title is:%s\n", book2.title);
//     printf("the states is:%d\n", book2.status);
//     printf("the ID is:%s\n", book3.id);
//     printf("the title is:%s\n", book3.title);
//     printf("the states is:%d", book3.status);
//     return 0;
// }

// #include <stdio.h>

// typedef enum {
//     AVAILABLE,
//     BORROWED
// } Status;

// typedef struct {
//     char id[10];
//     char title[31];   // 最多30个字符 + '\0'
//     Status status;
// } Book;

// const char* status_to_string(Status s) {
//     return (s == AVAILABLE) ? "AVAILABLE" : "BORROWED";
// }

// void print_book(const Book* b) {
//     printf("ID: %s | Title: %s | Status: %s\n",
//            b->id, b->title, status_to_string(b->status));
// }

// int main(void) {
//     Book book1 = {"001", "book1", AVAILABLE};
//     Book book2 = {"002", "book2", BORROWED};
//     Book book3 = {"003", "book3", AVAILABLE};

//     print_book(&book1);
//     print_book(&book2);
//     print_book(&book3);

//     return 0;
// }

// #include <stdio.h>

// enum DeviceState
// {
//     ON,
//     OFF,
//     SLEEP
// };

// typedef struct
// {
//     char id[10];
//     char name[20];
//     enum DeviceState device_state;
// } Device;


// int main(int argc, char const *argv[])
// {
//     Device device1 = {"001", "device1", ON};
//     Device device2 = {"002", "device2", OFF};
//     device1.device_state = SLEEP;
//     printf("device1 ID:%s, name:%s, ",
//            device1.id, device1.name);
//     switch (device1.device_state)
//     {
//     case ON:
//         printf("device1 is ON\n");
//         break;
//     case OFF:
//         printf("device1 is OFF\n");
//         break;
//     case SLEEP:
//         printf("device1 is SLEEP\n");
//         break;
//     default:
//         printf("invalid device state!\n");
//         break;
//     }
//     printf("device2 ID:%s, name:%s, ",
//            device2.id, device2.name);
//     switch (device2.device_state)
//     {
//     case ON:
//         printf("device2 is ON\n");
//         break;
//     case OFF:
//         printf("device2 is OFF\n");
//         break;
//     case SLEEP:
//         printf("device2 is SLEEP\n");
//         break;
//     default:
//         printf("invalid device state!\n");
//         break;
//     }
//     return 0;
// }

// #include <stdio.h>

// enum Role {
//     ADMIIN,
//     USER,
//     GUEST
// };

// typedef struct {
//     char id[10];
//     enum Role role;
// } User;


// int main(int argc, char const *argv[])
// {
//     User user1 = {"001", ADMIIN};
//     User user2 = {"002", USER};
//     User user3 = {"003", GUEST};
//     switch (user1.role)
//     {
//     case ADMIIN:
//         printf("user1 is admin\n");
//         break;
//     case USER:
//         printf("user1 is user\n");
//         break;
//     case GUEST:
//         printf("user1 is guest\n");
//         break;
//     default:
//         printf("invalid role!\n");
//         break;
//     }
//     switch (user2.role)
//     {
//     case ADMIIN:
//         printf("user2 is admin\n");
//         break;
//     case USER:
//         printf("user2 is user\n");
//         break;
//     case GUEST:
//         printf("user2 is guest\n");
//         break;
//     default:
//         printf("invalid role!\n");
//         break;
//     }
//     switch (user3.role)
//     {
//     case ADMIIN:
//         printf("user3 is admin\n");
//         break;
//     case USER:
//         printf("user3 is user\n");
//         break;
//     case GUEST:
//         printf("user3 is guest\n");
//         break;
//     default:
//         printf("invalid role!\n");
//         break;
//     }
//     return 0;
// }

