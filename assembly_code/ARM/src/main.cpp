/***********************************************************************************************************/
/*      *This is a sample code illustrating use of ARM assembly and the NEON vector extensions.            */
/*      *The sample also compares the performance of a simple kernel's C, armv7 assembly,                  */
/*       armv7 NEON assembly and armv7 NEON intrinsics implementations.                                    */
/***********************************************************************************************************/

/*********************************************
    Author : Siddheshwar P Sharma
    Date   : 18th August 2017
*********************************************/

#include <iostream>
#include <stdio.h>
#include <arm_neon.h>
using namespace std;

#define NUM_ITR 100
#define WIDTH 1024
#define HEIGHT 584
#define STRIDE 1024

#define WRITE_ENABLED

extern "C"
{
    void SimpleADD_arm_asm(unsigned char *src1, unsigned char *src2, unsigned char *dst, int height, int width, int stride);
}

int64_t getTimeNsec() 
{
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return (int64_t) (now.tv_sec*1000000000LL + now.tv_nsec);
}

void dump_uchar(unsigned char *src, int height, int width, int stride, char fileName[])
{
    FILE *fp = fopen(fileName, "a");
    if(fp == NULL)
        cout<<"\nFailed to dump file "<<fileName<<endl;
    else
    {
        fwrite(src, sizeof(unsigned char ), stride*height, fp);
        fclose(fp);
    }
}

void SimpleADD_C(unsigned char *src1, unsigned char *src2, unsigned char *dst, int height, int width, int stride)
{
    for(int y=0; y<height; y++)
        for(int x=0; x<width; x++)
            *(dst+y*stride+x) = *(src1+y*stride+x) + *(src2+y*stride+x);
}

void SimpleADD_NEON_intrinsic(unsigned char *src1, unsigned char *src2, unsigned char *dst, int height, int width, int stride)
{
    for(int y=0; y<height; y++)
    {
        unsigned char *ptr1 = src1 + y*stride;
        unsigned char *ptr2 = src2 + y*stride;
        unsigned char *ptr  = dst  + y*stride;
        for(int x=0 ;x<width; x+=16)
        {
            uint8x16_t vec1 = vld1q_u8(ptr1 + x);
            uint8x16_t vec2 = vld1q_u8(ptr2 + x);
            uint8x16_t vec  = vaddq_u8(vec1, vec2);
            vst1q_u8(ptr + x, vec);
        }
    }
}   

int main()
{
    long start, end;
    long double time_process;

    int inWidth  = WIDTH;
    int inHeight = HEIGHT;
    int inStride = STRIDE;

    unsigned char *inImg1 = new unsigned char[ inStride * inHeight ];
    unsigned char *inImg2 = new unsigned char[ inStride * inHeight ];

    unsigned char *dst_C                = new unsigned char[ inStride * inHeight ];
    unsigned char *dst_ARM_ASM          = new unsigned char[ inStride * inHeight ];
    unsigned char *dst_NEON_ASM         = new unsigned char[ inStride * inHeight ];
    unsigned char *dst_NEON_INTRINSIC   = new unsigned char[ inStride * inHeight ];

    //Generate manual input
    for(int y=0; y<inHeight; y++)
    {
        for(int x=0; x<inWidth; x++)
        {
            *(inImg1 + y*inStride + x) = ((y+1)*(x+3))%7;
            *(inImg2 + y*inStride + x) = ((y+3)*(x+5))%9;
        }
    }

    start = getTimeNsec();
    for(int itr=1; itr<=NUM_ITR; itr++)
        SimpleADD_C(inImg1, inImg2, dst_C, inHeight, inWidth, inStride);
    end = getTimeNsec();    
    time_process = (end-start)/10e6;
    cout<<"\nTotal time elapsed in processing C: "<<time_process<<" ms, avg  :  "<<time_process/NUM_ITR<<endl;

    start = getTimeNsec();
    for(int itr=1; itr<=NUM_ITR; itr++)
        SimpleADD_arm_asm(inImg1, inImg2, dst_NEON_INTRINSIC, inHeight, inWidth, inStride);
    end = getTimeNsec();    
    time_process = (end-start)/10e6;
    cout<<"\nTotal time elapsed in processing NEON_INTRINSIC: "<<time_process<<" ms, avg  :  "<<time_process/NUM_ITR<<" ms"<<endl;

    start = getTimeNsec();
    for(int itr=1; itr<=NUM_ITR; itr++)
        SimpleADD_NEON_intrinsic(inImg1, inImg2, dst_NEON_INTRINSIC, inHeight, inWidth, inStride);
    end = getTimeNsec();    
    time_process = (end-start)/10e6;
    cout<<"\nTotal time elapsed in processing NEON_INTRINSIC: "<<time_process<<" ms, avg  :  "<<time_process/NUM_ITR<<" ms"<<endl;

#ifdef WRITE_ENABLED
    dump_uchar(dst_C, inHeight, inWidth, inStride, "/data/sample/dst_C.txt");
    dump_uchar(dst_NEON_INTRINSIC, inHeight, inWidth, inStride, "/data/sample/dst_NEON_INTRINSIC.txt");
    
#endif

    delete[] inImg1;
    delete[] inImg2;

    delete[] dst_C;
    delete[] dst_ARM_ASM;
    delete[] dst_NEON_ASM;
    delete[] dst_NEON_INTRINSIC;   
 
    return 0;
}
