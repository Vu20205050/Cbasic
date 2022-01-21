#include <stdio.h>
#include <stdlib.h>

#define sqr(x) ((x) * (x))

typedef struct {
    double x;
    double y;
} point_t;

typedef struct {
    point_t center;
    double radius;
} circle_t;

int is_in_circle(point_t* p, circle_t* c) {
    double x_dist, y_dist;
    x_dist = p->x - c->center.x;
    y_dist = p->y - c->center.y;

    return (sqr(x_dist) + sqr(y_dist) <= sqr(c->radius));
}

int main() {
    point_t p; circle_t c;
    printf("Nhap toa do diem: ");
    scanf("%lf%lf", &p.x, &p.y);
    printf("Nhap tam hinh tron:");
    scanf("%lf%lf", &c.center.x, &c.center.y);
    printf("Nhap ban kinh: ");
    scanf("%lf", &c.radius);

    if(is_in_circle(&p, &c)) {
        printf("Diem nam trong hinh tron");
    } else {
        printf("Diem nam ngoai hinh tron");
    }
    return 0;
}
