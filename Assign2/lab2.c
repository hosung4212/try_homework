/*
이 프로젝트는 1학년 김아붕이와 친구들이 진행하는 오픈소스 프로젝트입니다.
마음대로 코드를 수정하지 말아주세요! 아직 개발중이고 코드가 더럽습니다...
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int choice;
int best;
int temp_var;
int input = 0;
float max_input = 500;
unsigned short input2, reservation = 5;

//이 함수는 누가 추가한거야? 뭐하는 함수지
int flag() {
    char temp[100];
    int fd = open("./flag", O_RDONLY);
    if(temp_var < best) exit(0);
    read(fd, temp, 15);
    if(temp_var < best) exit(0);
    write(1, temp, 15);
    exit(0);
}

void reservation_seat() {
    //강의실 좌석 예약 프로그램도 나중에 만들면 좋을듯
    int seats[10] = { 0 };
    int seatNumber;
    char choice;

    do {
        printf("좌석을 예약하시겠습니까?(y 또는 n) ");
        scanf(" %c", &choice);

        printf("---------------------------------\n");
        for (int i = 1; i <= 10; i++) 
        {
            printf("  %d", i);
        }
        printf("\n---------------------------------\n");
        for (int i = 0; i < 10; i++) 
        {
            printf("  %d", seats[i]);
        }
        printf("\n\n");

        if (choice == 'y') {
            printf("몇 번째 좌석을 예약하시겠습니까 : ");
            scanf("%d", &seatNumber);

            if (seats[seatNumber - 1] == 0)   // 0인경우 빈자리이기 때문에 가능 
            {
                seats[seatNumber - 1] = 1;   // 1인경우 누군가 예약한 좌석이기 때문에 불가능
                printf("예약되었습니다.\n\n");
            }
            else {
                printf("이미 예약된 자리입니다.\n\n");
            }
        }
    } while (choice != 'n');
    //내가 개발중인 함수 리스트 나중에 지우셈
    you_must_see_it();
}

void you_must_see_it() {
    printf("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
}

//버블 정렬 연습 ㅋㅋ
void bubble_sort(int list[], int n){
    int i, j, temp;
    for(i=n-1; i>0; i--){
        // 0 ~ (i-1)까지 반복
        for(j=0; j<i; j++){
        // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
        if(list[j]<list[j+1]){
            temp_var = list[j];
            list[j] = list[j+1];
            list[j+1] = temp_var;
        }
        }
    }
}

void test() {
    //아래 기능은 아직 개발중... 완성후 추가할 예정
    __asm__(
        "push %rbp;"
    );

    char yes_or_no[3];
    while(1) {
        temp_var = 0;
        printf("건강검진 예약 서비스\n");
        printf("1. 예약 2. 예약 취소 3. 종료\n");
        scanf("%d", &input2);
        if(input2 == 1) {
            printf("예약 인원 +1\n");
            reservation++;
        } else if(input2 == 2) {
            printf("예약 인원 -1\n");
            reservation--;
        } else if(input2 == 3) {
            printf("총인원 추합 저장\n");
            temp_var = reservation;
            printf("저장완료.....\n");
            printf("정말 종료 하시겠습니까? (y/n)\n");
            getchar();
            fgets(yes_or_no, max_input, stdin);
            if(!strcmp(yes_or_no, "y")) {
                break;
            }else {
                continue;
            }
            break;
        }
    }
}

void main()
{
    best = 1000;
    int limit = 4;
    int end = 0;
    char name[10];
    char grade[2];
    printf("====후이즈대학교 학사서비스====\n\n");
    printf("원하시는 서비스를 선택해주세요\n");
    while(1) {
        if(end == 1) {
            break;
        }
        printf("\n1. 서울대 편입\n2. 자체종강 신청\n3. 자퇴 신청\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Seoul National University 편입 판독기 V3.8.1\n");
                printf("License by National Intelligence Service 1901-2022....\n");
                printf("\n당신의 편입 시험 점수를 입력해주세요\n");
                scanf("%d", &input);
                if(input > 100) {
                    printf("100점 보다 높은 점수는 없습니다.\n");
                    exit(0);
                }
                temp_var = input;
                if(temp_var < 98) {
                    printf("삐빅- 그 점수로 서울대를 간다고?\n");
                    exit(-1);
                }
                printf("그 점수면... 갈만 할 것 같습니다.\n");
                printf("서울대 학적 등록을 위해 이름을 입력해주세요\n");
                getchar();
                read(0, name, max_input);
                printf("예비 서울대생 %s 님! 후이즈대 탈출을 축하드립니다!\n", (char *)name);
                break;
            case 2:
                printf("자신의 학년을 알려주세요 : \n");
                getchar();
                fgets(grade, max_input, stdin);
                if(atoi(grade) > limit) {
                    printf("충격,, 대학교 5학년 이상이 있다?\n");
                    exit(0);
                } else if(atoi(grade) == 4) {
                    printf("4학년이면... 자체 종강해도될듯..\n");
                    end = 1;
                    break;
                }else {
                    printf("자체 종강하기엔 이른듯...\n");
                    continue;
                }
                continue;
            case 3:
                printf("자퇴는 불가능합니다 ㅋㅋ\n");
                continue;
            default:
                printf("다시 입력해주세요\n");
                continue;
        }
    }
}
