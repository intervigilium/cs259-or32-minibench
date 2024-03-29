#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <or1k-support.h>

#ifndef TIMER_HZ
#define TIMER_HZ 1000
#endif

#ifndef WAVES
#define WAVES 4
#endif

#ifndef LENGTH
#define LENGTH 4096
#endif

int main(int argc, char *argv[]) {
    unsigned MAXSIZE;
    unsigned MAXWAVES;
    unsigned i,j;
    float *RealIn;
    float *ImagIn;
    float *RealOut;
    float *RealOutErr;
    float *ImagOut;
    float *ImagOutErr;
    float *coeff;
    float *amp;
    int invfft=0;
    unsigned int ticks;

    switch (argc) {
        case 0:
        case 1:
        case 2:
            printf("Usage: fft <waves> <length> -i\n");
            printf("-i performs an inverse fft\n");
            printf("make <waves> random sinusoids");
            printf("<length> is the number of samples\n");
            printf("Defaulting to %d waves and %d length\n", WAVES, LENGTH);
            MAXWAVES=WAVES;
            MAXSIZE=LENGTH;
            break;
        case 3:
            MAXSIZE=atoi(argv[2]);
            MAXWAVES=atoi(argv[1]);
            break;
        case 4:
            MAXSIZE=atoi(argv[2]);
            MAXWAVES=atoi(argv[1]);
            invfft = !strncmp(argv[3],"-i",2);
            break;
        default:
            exit(-1);
    }

    srand(1);

    RealIn=(float*)malloc(sizeof(float)*MAXSIZE);
    ImagIn=(float*)malloc(sizeof(float)*MAXSIZE);
    RealOut=(float*)malloc(sizeof(float)*MAXSIZE);
    ImagOut=(float*)malloc(sizeof(float)*MAXSIZE);
    coeff=(float*)malloc(sizeof(float)*MAXWAVES);
    amp=(float*)malloc(sizeof(float)*MAXWAVES);

    RealOutErr=(float*)malloc(sizeof(float)*MAXSIZE);
    ImagOutErr=(float*)malloc(sizeof(float)*MAXSIZE);

    /* Makes MAXWAVES waves of random amplitude and period */
    for(i=0; i<MAXWAVES; i++) {
        coeff[i] = rand()%1000;
        amp[i] = rand()%1000;
    }
    for(i=0; i<MAXSIZE; i++) {
        /*   RealIn[i]=rand();*/
        RealIn[i]=0;
        for(j=0; j<MAXWAVES; j++) {
            /* randomly select sin or cos */
            if (rand()%2) {
                RealIn[i]+=coeff[j]*cos(amp[j]*i);
            } else {
                RealIn[i]+=coeff[j]*sin(amp[j]*i);
            }
            ImagIn[i]=0;
        }
    }

    or1k_timer_init(TIMER_HZ);
    or1k_timer_enable();

    /* regular*/
    fft_float (MAXSIZE,invfft,RealIn,ImagIn,RealOut,ImagOut,0);

    /* introduce some error */
    fft_float (MAXSIZE,invfft,RealIn,ImagIn,RealOutErr,ImagOutErr,0.42);

#if 0
    printf("RealOut:\n");
    for (i=0; i<MAXSIZE; i++)
        printf("%f\n", RealOut[i]);
    printf("\n");

    printf("ImagOut:\n");
    for (i=0; i<MAXSIZE; i++)
        printf("%f\n", ImagOut[i]);
    printf("\n");
#endif
#if 0
    printf("Real\n");
    for (i=0; i<MAXSIZE; i++) {
        printf("%d, %f\n", i, 100*(RealOut[i]-RealOutErr[i])/RealOut[i]);
    }

    printf("Imaginary\n");
    for (i=0; i<MAXSIZE; i++) {
        printf("%d, %f\n", i, 100*(ImagOut[i]-ImagOutErr[i])/ImagOut[i]);
    }
#endif
    printf("Real\n");
    for (i=0; i<MAXSIZE; i++) {
        printf("%d,%f,%f\n", i, RealOut[i], RealOutErr[i]);
    }

    printf("Imaginary\n");
    for (i=0; i<MAXSIZE; i++) {
        printf("%d,%f,%f\n", i, ImagOut[i], ImagOutErr[i]);
    }

    ticks = or1k_timer_get_ticks();
    printf("Elapsed: %d ticks at %d Hz\n", ticks, TIMER_HZ);

    free(RealIn);
    free(ImagIn);
    free(RealOut);
    free(ImagOut);
    free(coeff);
    free(amp);
    exit(0);


}
