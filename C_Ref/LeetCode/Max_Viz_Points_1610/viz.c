// You are given an array points, an integer angle, and your location, where 
// location = [posx, posy] and points[i] = [xi, yi] both denote integral 
// coordinates on the X-Y plane.

// Initially, you are facing directly east from your position. You cannot move 
// from your position, but you can rotate. In other words, posx and posy cannot 
// be changed. Your field of view in degrees is represented by angle, 
// determining how wide you can see from any given view direction. Let d be the 
// amount in degrees that you rotate counterclockwise. Then, your field of view 
// is the inclusive range of angles [d - angle/2, d + angle/2].

// You can see some set of points if, for each point, the angle formed by the 
// point, your position, and the immediate east direction from your position is
// in your field of view.

// There can be multiple points at one coordinate. There may be points at your 
// location, and you can always see these points regardless of your rotation. 
// Points do not obstruct your vision to other points.

// Return the maximum number of points you can see.

#include <stdio.h>
#ifndef __USE_MISC
#define __USE_MISC
#endif
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define INPUT_FILE "./input.txt"
#define DIGIT_SIZE 4
#define MAX_NUM_PTS 100000

typedef struct
{
    double r;
    double t;
} polar_t;

int polar_compare(const void* a, const void* b)
{
    polar_t* p1 = (polar_t*) a;
    polar_t* p2 = (polar_t*) b;

    if(p1->t < p2->t)
    {
        return -1;
    }
    
    return 1;
}

void center_points(int** points, int pointsSize, int* location)
{
    int i;
    for(i = 0; i < pointsSize; ++i)
    {
        points[i][0] -= location[0];
        points[i][1] -= location[1];
    }

    location[0] = 0;
    location[1] = 0;
}

int convert_to_radians(int** points, polar_t* p, int pointsSize, int* location)
{
    int i;
    int x;
    int y;
    int num_colocated = 0;
    for(i = 0; i < pointsSize; ++i)
    {
        x = points[i][0];
        y = points[i][1];

        // Forward kinematics
        // x = r * cos(theta)
        // y = r * sin(theta)
        // 
        // Reverse Kinematics
        // r = sqrt(x*x + y*y)   -> pos 0
        // theta = tan-1(y/x)    -> pos 1

        if((x == 0) && (y == 0))
        {
            p[i].r = -1.0;
            p[i].t = 0.0;
            num_colocated++;
            continue;
        }

        p[i].r = sqrt((double) ((x*x) + (y*y)));

        if(x == 0)
        {
            p[i].t = M_PI_2;
            if (y < 0)
            {
                p[i].t *= -1;
            }
            
        }
        else
        {
            p[i].t = atan2(((double) y), ((double)x));
        }

        if(p[i].t < 0)
        {
            p[i].t += ((2.0*M_PI));
        }

        if(p[i].t < 0 || p[i].t >= (2.0*M_PI))
        {
            printf("Invalid angle) %lf\n", p[i].t);
            printf("(2.0*M_PI) = %lf\n", (2.0*M_PI));
            free(p);
            exit(1);
        }
    }
    return num_colocated;
}

void sort(polar_t* p, int N)
{
    qsort(p, N, sizeof(polar_t), polar_compare);
}

int in_view(double right, double point, double angle)
{
    double left = right+ angle;
    if(left >= (2.0*M_PI))
    {
        left = left - (2.0*M_PI);
        if(point >= 0 && point <= left )
        {
            return 1;
        }

        if(point <= (2.0*M_PI) && point >= right)  // case where points = hits here
        {
            return 1;
        }

        return 0;

    }
    else
    {
        if(point <= left && point >= right)
        {
            return 1;
        }

        return 0;
    }
}

int window(polar_t* p_first, polar_t* p_last, double angle)
{
    if(p_first == p_last)
    {
        return 0;
    }

    int n = 0;
    int n_max = 0;

    polar_t* p1 = p_first;
    polar_t* p2 = p_first;

    while(1)
    {
        if(in_view(p1->t, p2->t, angle))
        {
            ++n;
            if(n > n_max)
            {
                n_max = n;
            }

            ++p2;
            if(p2 == p_last)
            {
                p2 = p_first;
            }

            if(p1 == p2)
            {
                return n_max;
            }

        }
        else
        {
            while(!in_view(p1->t, p2->t, angle))
            {
                ++p1;
                --n;
                if(p1 == p2)
                {
                    break;
                }
                else if(p1 == p_last)
                {
                    return n_max;
                }
            }
        }
    }
    return n_max;
}

int visiblePoints(int** points, int pointsSize, int* pointsColSize, int angle, int* location, int locationSize) {
    int i = 0;
    int n = 0;
    int n_max = 0;
    int j = 0;
    int num_collocated = 0;
    polar_t* p = (polar_t*) malloc(pointsSize * sizeof(polar_t));
    clock_t tick, tock;

    double a = (((double)angle) / 360.0) * (2.0*M_PI);

    tick = clock();
    center_points(points, pointsSize, location);
    tock = clock();
    printf("Centering Took %lfms\n", ((tock-tick)*1000.0) / CLOCKS_PER_SEC);

    tick = clock();
    num_collocated = convert_to_radians(points, p, pointsSize, location);
    tock = clock();
    printf("Polar Convert Took %lfms\n", ((tock-tick)*1000.0) / CLOCKS_PER_SEC);

    tick = clock();
    sort(p, pointsSize);
    tock = clock();
    printf("Sort Took %lfms\n", ((tock-tick)*1000.0) / CLOCKS_PER_SEC);

    tick = clock();
    n_max = window(p + num_collocated, p + pointsSize, a);
    tock = clock();
    printf("Window Took %lfms\n", ((tock-tick)*1000.0) / CLOCKS_PER_SEC);


    free(p);
    return n_max + num_collocated;
}

int main()
{
    FILE* fp;
    int fp_len = 0;
    char* buffer;
    char temp_buffer[DIGIT_SIZE];
    int** points = malloc(MAX_NUM_PTS * sizeof(int*));
    int location[2];
    location[0] = 6;
    location[1] = 59;

    int i = 0;
    int buff_ptr = -1;
    int temp_buff_ptr = 0;
    int x;
    int y;
    int n;
    clock_t tick, tock;

    tick = clock();
    
    // Open the input file
    fp = fopen(INPUT_FILE, "r");
    if(fp == NULL)
    {
        printf("Failed to open %s\n", INPUT_FILE);
        free(points);
        return 1;
    }

    // Determine the input file's size
    fseek(fp, 0L, SEEK_END);
    fp_len = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    printf("Input File = %s\n", INPUT_FILE);
    printf("File Size  = %d\n", fp_len);

    // Allocate Buffer and read file into memory
    buffer = malloc(fp_len+1); 
    while(n < fp_len)
    {
        n = fread(buffer + n, 1, fp_len-n, fp);
        printf("%d/%d bytes read \n", n, fp_len);
    }

    // File format is [[a,b],[c,d],...,[y,z]]
    for(i = 0; i < MAX_NUM_PTS; ++i)
    {
        buff_ptr += 3;  // Skip bracket comma bracket
        if(buff_ptr >= fp_len)
        {
            break;
        }

        temp_buff_ptr = 0;
        while(buffer[buff_ptr] != ',')
        {
            temp_buffer[temp_buff_ptr] = buffer[buff_ptr];
            buff_ptr++;
            temp_buff_ptr++;
        }
        buff_ptr++;    // Skip comma

        temp_buffer[temp_buff_ptr] = 0;
        x = atoi(temp_buffer);

        temp_buff_ptr = 0;
        while(buffer[buff_ptr] != ']')
        {
            temp_buffer[temp_buff_ptr] = buffer[buff_ptr];
            buff_ptr++;
            temp_buff_ptr++;
        }

        temp_buffer[temp_buff_ptr] = 0;
        y = atoi(temp_buffer);

        points[i] = malloc(2 * sizeof(int));
        points[i][0] = x;
        points[i][1] = y;
    }
    tock = clock();

    printf("Loading Points took %lfms\n", ((tock - tick) * 1000.0) / CLOCKS_PER_SEC);

    tick = clock();
    int ans = visiblePoints(points, i, NULL, 248, location, 2);
    tock = clock();

    printf("Calculation took %lfms\n", ((tock - tick) * 1000.0) / CLOCKS_PER_SEC);
    printf("Answer = %d\n", ans);

    return 0;
}