#include <stdio.h>
#include <math.h>

double dist(double p1x, double p1y, double p2x, double p2y);
double forca(char c, int i,
             double x0, double y0, double m0,
             double x1, double y1, double m1,
             double x2, double y2, double m2);
void atualize(double *x, double *y, double *vx, double *vy,
             double ax, double ay, double dt);
double grav(double massa1, double massa2, double d);
double sen_cos(double alfa, double beta, double p1x, double p1y, double p2x, double p2y);

int main(){
    double rx0, ry0, vx0, vy0, m0, rx1, ry1, vx1, vy1, m1, rx2, ry2, vx2, vy2, m2;
    double ax0, ay0, ax1, ay1, ax2, ay2;
    int t, dt, tmax;

    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %d %d",
            &rx0, &ry0, &vx0, &vy0, &m0, &rx1, &ry1, &vx1, &vy1, &m1, &rx2, &ry2, &vx2, &vy2, &m2, &tmax, &dt);

    printf("%g %g %g %g %g %g\n", rx0, ry0, rx1, ry1, rx2, ry2);

    for(t = 0; t < tmax; t += dt){
        ax0 = forca('x', 0, rx0, ry0, m0, rx1, ry1, m1, rx2, ry2, m2) / m0;
        ay0 = forca('y', 0, rx0, ry0, m0, rx1, ry1, m1, rx2, ry2, m2) / m0;
        ax1 = forca('x', 1, rx0, ry0, m0, rx1, ry1, m1, rx2, ry2, m2) / m1;
        ay1 = forca('y', 1, rx0, ry0, m0, rx1, ry1, m1, rx2, ry2, m2) / m1;
        ax2 = forca('x', 2, rx0, ry0, m0, rx1, ry1, m1, rx2, ry2, m2) / m2;
        ay2 = forca('y', 2, rx0, ry0, m0, rx1, ry1, m1, rx2, ry2, m2) / m2;

        atualize(&rx0, &ry0, &vx0, &vy0, ax0, ay0, dt);
        atualize(&rx1, &ry1, &vx1, &vy1, ax1, ay1, dt);
        atualize(&rx2, &ry2, &vx2, &vy2, ax2, ay2, dt);

        printf("%g %g %g %g %g %g\n", rx0, ry0, rx1, ry1, rx2, ry2);
    }

    return 0;
}

double dist(double p1x, double p1y, double p2x, double p2y){
    double dis;
    dis = sqrt(pow(p1x - p2x, 2) + pow(p1y - p2y, 2));
    return dis;
}

double forca(char c, int i,
             double x0, double y0, double m0,
             double x1, double y1, double m1,
             double x2, double y2, double m2){
    double fsobre0x, fsobre0y, fsobre1x, fsobre1y, fsobre2x, fsobre2y, a;

    if (c == 'x'){
        if (i == 0){
            if ((x2 > x0 && x1 < x0) || (x2 < x0 && x1 > x0)){
                if (x1 > x2)
                    fsobre0x = grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(x1, x0, x0, y0, x1, y1) - grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(x0, x2, x0, y0, x2, y2);
                if (x2 > x1)
                    fsobre0x = grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(x2, x0, x0, y0, x2, y2) - grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(x0, x1, x0, y0, x1, y1);
            }
            else if (x0 > x1 && x0 > x2)
                fsobre0x = -grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(x0, x1, x0, y0, x1, y1) - grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(x0, x2, x0, y0, x2, y2);
            else if (x0 < x1 && x0 < x2)
                fsobre0x = grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(x1, x0, x0, y0, x1, y1) + grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(x2, x0, x0, y0, x2, y2);

            a = fsobre0x;
        }

        if (i == 1){
            if ((x2 > x1 && x0 < x1) || (x2 < x1 && x0 > x1)){
                if (x0 > x2)
                    fsobre1x = grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(x0, x1, x0, y0, x1, y1) - grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(x1, x2, x1, y1, x2, y2);
                if (x2 > x0)
                    fsobre1x = grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(x2, x1, x1, y1, x2, y2) - grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(x1, x0, x0, y0, x1, y1);
            }
            else if (x1 > x0 && x1 > x2)
                fsobre1x = -grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(x1, x0, x0, y0, x1, y1) - grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(x1, x2, x1, y1, x2, y2);
            else if (x1 < x0 && x1 < x2)
                fsobre1x = grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(x0, x1, x0, y0, x1, y1) + grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(x2, x1, x1, y1, x2, y2);

            a = fsobre1x;
        }

        if (i == 2){
            if ((x0 > x2 && x1 < x2) || (x0 < x2 && x1 > x2)){
                if (x1 > x0)
                    fsobre2x = grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(x1, x2, x1, y1, x2, y2) - grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(x2, x0, x0, y0, x2, y2);
                if (x0 > x1)
                    fsobre2x = grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(x0, x2, x0, y0, x2, y2) - grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(x2, x1, x1, y1, x2, y2);
            }
            else if (x2 > x0 && x2 > x1)
                fsobre2x = -grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(x2, x1, x1, y1, x2, y2) - grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(x2, x0, x0, y0, x2, y2);
            else if (x2 < x0 && x2 < x1)
                fsobre2x = grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(x1, x2, x1, y1, x2, y2) + grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(x0, x2, x0, y0, x2, y2);

            a = fsobre2x;
        }
    }

    if (c == 'y'){
        if (i == 0){
            if ((y2 > y0 && y1 < y0) || (y2 < y0 && y1 > y0)){
                if (y1 > y2)
                    fsobre0y = grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(y1, y0, x0, y0, x1, y1) - grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(y0, y2, x0, y0, x2, y2);
                if (y2 > y1)
                    fsobre0y = grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(y2, y0, x0, y0, x2, y2) - grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(y0, y1, x0, y0, x1, y1);
            }
            else if (y0 > y1 && y0 > y2)
                fsobre0y = -grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(y0, y1, x0, y0, x1, y1) - grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(y0, y2, x0, y0, x2, y2);
            else if (y0 < y1 && y0 < y2)
                fsobre0y = grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(y1, y0, x0, y0, x1, y1) + grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(y2, y0, x0, y0, x2, y2);

            a = fsobre0y;
        }

        if (i == 1){
            if ((y2 > y1 && y0 < y1) || (y2 < y1 && y0 > y1)){
                if (y0 > y2)
                    fsobre1y = grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(y0, y1, x0, y0, x1, y1) - grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(y1, y2, x1, y1, x2, y2);
                if (y2 > y0)
                    fsobre1y = grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(y2, y1, x1, y1, x2, y2) - grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(y1, y0, x0, y0, x1, y1);
            }
            else if (y1 > y0 && y1 > y2)
                fsobre1y = -grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(y1, y0, x0, y0, x1, y1) - grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(y1, y2, x1, y1, x2, y2);
            else if (y1 < y0 && y1 < y2)
                fsobre1y = grav(m0, m1, dist(x0, y0, x1, y1)) * sen_cos(y0, y1, x0, y0, x1, y1) + grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(y2, y1, x1, y1, x2, y2);

            a = fsobre1y;
        }

        if (i == 2){
            if ((y0 > y2 && y1 < y2) || (y0 < y2 && y1 > y2)){
                if (y1 > y0)
                    fsobre2y = grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(y1, y2, x1, y1, x2, y2) - grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(y2, y0, x0, y0, x2, y2);
                if (y0 > y1)
                    fsobre2y = grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(y0, y2, x0, y0, x2, y2) - grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(y2, y1, x1, y1, x2, y2);
            }
            else if (y2 > y0 && y2 > y1)
                fsobre2y = -grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(y2, y1, x1, y1, x2, y2) - grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(y2, y0, x0, y0, x2, y2);
            else if (y2 < y0 && y2 < y1)
                fsobre2y = grav(m1, m2, dist(x1, y1, x2, y2)) * sen_cos(y1, y2, x1, y1, x2, y2) + grav(m0, m2, dist(x0, y0, x2, y2)) * sen_cos(y0, y2, x0, y0, x2, y2);

            a = fsobre2y;
        }
    }

    return a;
}

void atualize(double *x, double *y, double *vx, double *vy,
              double ax, double ay, double dt){

    *vx = (*vx) + dt * ax;
    *vy = (*vy) + dt * ay;
    *x = (*x) + dt * (*vx);
    *y = (*y) + dt * (*vy);
}

double grav(double massa1, double massa2, double d){
    double f, G;
    G = 6.67 * pow(10, -11);

    if (d != 0)
        f = (G * massa1 * massa2)/ (pow(d, 2));
    else
        f = 0;

    return f;
}

double sen_cos(double alfa, double beta, double p1x, double p1y, double p2x, double p2y){
    double num, distancia;
    distancia = dist(p1x, p1y, p2x, p2y);

    if (distancia != 0)
        num = (alfa - beta)/(distancia);
    else
        num = 0;

    return num;
}
