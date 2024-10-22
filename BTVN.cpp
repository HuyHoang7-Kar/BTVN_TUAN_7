#include<stdio.h>

typedef struct {
    int nam;
    int so_nguoi_dan;
} danso;
typedef struct 
{
    int so_nguoi_dan;
    int cout;
} dem;

void Nhap(danso a[], int n) {
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].nam, &a[i].so_nguoi_dan);
    }
}
void FindCommon(danso a[], int n){
    dem p[50];
    int count = 0;
    for(int i = 0; i < n; i++){
        int found = 0;
        for(int j = 0; j < count;j++){
            if(p[j].so_nguoi_dan == a[i].so_nguoi_dan){
                p[j].cout++;
                found = 1;
                break;
            }
        }
        if(found == 0){
            p[count].so_nguoi_dan= a[i].so_nguoi_dan;
            p[count].cout = 1;
            count++;
        }
    }
    printf("So nam co so luong nguoi trung nhau: \n");
        for(int i = 0; i < count; i++){
            if(p[i].cout != 1) printf("So nam co cung %d nguoi la : %d\n", p[i].so_nguoi_dan,p[i].cout);
    }
}
void min(danso a[], int n) { 
    int min = a[0].so_nguoi_dan;
    int minYear[50];
    int minCount = 0;

    for (int i = 1; i < n; i++) {
        if (min > a[i].so_nguoi_dan) {
            min = a[i].so_nguoi_dan;
            minYear[0] = a[i].nam;
            minCount = 1;
        } else if (a[i].so_nguoi_dan == min) {
            minYear[minCount] = a[i].nam;
            minCount++;
        }
    }

    printf("Cac nam co so nguoi sinh ra it nhat la:\n");
    for (int i = 0; i < minCount; i++) {
        printf("%d ", minYear[i]);
    }
    printf("\n");
}
void max(danso a[], int n){
    int max = a[0].so_nguoi_dan;
    int maxCout = 0;
    int maxYear[50];
    for (int i = 1; i < n; i++){
        if(max < a[i].so_nguoi_dan){
            max = a[i].so_nguoi_dan;
            maxYear[0] = a[i].nam;
            maxCout = 1;
        } else if (a[i].so_nguoi_dan == max)
        {
            maxYear[maxCout] = a[i].nam;
            maxCout++;
        }
    }
    printf("Nam co so nguoi sinh ra nhieu nhat la\n");
        for(int i = 0; i < maxCout;i++){
            printf("%d ", maxYear[i]);
        }
        printf("\n");
}
int main() {
    danso a[50];
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    Nhap(a, n);
    min(a, n);
    max(a,n);
    FindCommon(a, n);
    return 0;
}
