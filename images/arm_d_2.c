#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_ARM_D_2
#define LV_ATTRIBUTE_IMG_ARM_D_2
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_ARM_D_2 uint8_t arm_d_2_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x2f, 0xff, 0x64, 0xff, 0x6e, 0xff, 0x4d, 0xff, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0x1e, 0xff, 0xbb, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xed, 0xff, 0x5a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xff, 0x2e, 0xff, 0xf1, 0xdb, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb6, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0x05, 0xff, 0xcf, 0xdb, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xff, 0xff, 0xff, 0x45, 0x00, 0x00, 
  0xff, 0x63, 0xff, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xd7, 0xff, 0xff, 0xd3, 0x00, 0x00, 
  0xff, 0xa8, 0xdb, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xff, 0xff, 0xff, 0x17, 
  0xff, 0xbe, 0xd7, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xff, 0xff, 0xff, 0x2e, 
  0xff, 0xa9, 0xdb, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xff, 0xff, 0xff, 0x19, 
  0xff, 0x67, 0xff, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xd7, 0xff, 0xff, 0xd7, 0x00, 0x00, 
  0xff, 0x07, 0xff, 0xd5, 0xd7, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xff, 0xff, 0xff, 0x4c, 0x00, 0x00, 
  0x00, 0x00, 0xff, 0x34, 0xff, 0xf5, 0xdb, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb2, 0xff, 0xb6, 0xff, 0xff, 0xff, 0xff, 0x99, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0x24, 0xff, 0xc4, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xf2, 0xff, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0xff, 0x3a, 0xff, 0x6f, 0xff, 0x79, 0xff, 0x58, 0xff, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x2f, 0xff, 0xff, 0x64, 0xff, 0xff, 0x6e, 0xff, 0xff, 0x4d, 0xff, 0xff, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x1e, 0xff, 0xff, 0xbb, 0xbe, 0xf7, 0xff, 0xdb, 0xe6, 0xff, 0x9a, 0xde, 0xff, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xed, 0xff, 0xff, 0x5a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0xff, 0x2e, 0xff, 0xff, 0xf1, 0xf8, 0xcd, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0xf4, 0xac, 0xff, 0x5d, 0xef, 0xff, 0xff, 0xff, 0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x05, 0xff, 0xff, 0xcf, 0xb6, 0xc5, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x92, 0xa4, 0xff, 0x9e, 0xf7, 0xff, 0xff, 0xff, 0x45, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x63, 0xfc, 0xe6, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x75, 0xbd, 0xff, 0xff, 0xff, 0xd3, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xa8, 0xf8, 0xcd, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x71, 0x9c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x17, 
  0xff, 0xff, 0xbe, 0x55, 0xbd, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x7e, 0xf7, 0xff, 0xff, 0xff, 0x2e, 
  0xff, 0xff, 0xa9, 0xf7, 0xcd, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x71, 0x9c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x19, 
  0xff, 0xff, 0x67, 0xfb, 0xe6, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x55, 0xb5, 0xff, 0xff, 0xff, 0xd7, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x07, 0xff, 0xff, 0xd5, 0x96, 0xbd, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x72, 0xa4, 0xff, 0x7e, 0xf7, 0xff, 0xff, 0xff, 0x4c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0xff, 0x34, 0xff, 0xff, 0xf5, 0xd7, 0xc5, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0x51, 0x9c, 0xff, 0xf3, 0xac, 0xff, 0x3d, 0xef, 0xff, 0xff, 0xff, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x24, 0xff, 0xff, 0xc4, 0x7e, 0xf7, 0xff, 0xba, 0xde, 0xff, 0x79, 0xd6, 0xff, 0x1c, 0xef, 0xff, 0xff, 0xff, 0xf2, 0xff, 0xff, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0xff, 0xff, 0x3a, 0xff, 0xff, 0x6f, 0xff, 0xff, 0x79, 0xff, 0xff, 0x58, 0xff, 0xff, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x2f, 0xff, 0xff, 0x64, 0xff, 0xff, 0x6e, 0xff, 0xff, 0x4d, 0xff, 0xff, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x1e, 0xff, 0xff, 0xbb, 0xf7, 0xbe, 0xff, 0xe6, 0xdb, 0xff, 0xde, 0x9a, 0xff, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xed, 0xff, 0xff, 0x5a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0xff, 0x2e, 0xff, 0xff, 0xf1, 0xcd, 0xf8, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0xac, 0xf4, 0xff, 0xef, 0x5d, 0xff, 0xff, 0xff, 0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x05, 0xff, 0xff, 0xcf, 0xc5, 0xb6, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0xa4, 0x92, 0xff, 0xf7, 0x9e, 0xff, 0xff, 0xff, 0x45, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x63, 0xe6, 0xfc, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0xbd, 0x75, 0xff, 0xff, 0xff, 0xd3, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xa8, 0xcd, 0xf8, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x71, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x17, 
  0xff, 0xff, 0xbe, 0xbd, 0x55, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0xf7, 0x7e, 0xff, 0xff, 0xff, 0x2e, 
  0xff, 0xff, 0xa9, 0xcd, 0xf7, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x71, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x19, 
  0xff, 0xff, 0x67, 0xe6, 0xfb, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0xb5, 0x55, 0xff, 0xff, 0xff, 0xd7, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x07, 0xff, 0xff, 0xd5, 0xbd, 0x96, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0xa4, 0x72, 0xff, 0xf7, 0x7e, 0xff, 0xff, 0xff, 0x4c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0xff, 0x34, 0xff, 0xff, 0xf5, 0xc5, 0xd7, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0x9c, 0x51, 0xff, 0xac, 0xf3, 0xff, 0xef, 0x3d, 0xff, 0xff, 0xff, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x24, 0xff, 0xff, 0xc4, 0xf7, 0x7e, 0xff, 0xde, 0xba, 0xff, 0xd6, 0x79, 0xff, 0xef, 0x1c, 0xff, 0xff, 0xff, 0xf2, 0xff, 0xff, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0xff, 0xff, 0x3a, 0xff, 0xff, 0x6f, 0xff, 0xff, 0x79, 0xff, 0xff, 0x58, 0xff, 0xff, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x2f, 0xff, 0xff, 0xff, 0x64, 0xff, 0xff, 0xff, 0x6e, 0xff, 0xff, 0xff, 0x4d, 0xff, 0xff, 0xff, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x1e, 0xff, 0xff, 0xff, 0xbb, 0xf2, 0xf2, 0xf3, 0xff, 0xd9, 0xd9, 0xde, 0xff, 0xcf, 0xcf, 0xd6, 0xff, 0xe6, 0xe6, 0xe9, 0xff, 0xfe, 0xfe, 0xfe, 0xed, 0xff, 0xff, 0xff, 0x5a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x2e, 0xfc, 0xfc, 0xfc, 0xf1, 0xbd, 0xbd, 0xc6, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x9d, 0x9d, 0xab, 0xff, 0xe8, 0xe8, 0xeb, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x05, 0xff, 0xff, 0xff, 0xcf, 0xb2, 0xb2, 0xbc, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x8e, 0x8e, 0x9d, 0xff, 0xef, 0xef, 0xf1, 0xff, 0xff, 0xff, 0xff, 0x45, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x63, 0xdd, 0xdd, 0xe2, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0xaa, 0xaa, 0xb5, 0xff, 0xff, 0xff, 0xff, 0xd3, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xa8, 0xbc, 0xbc, 0xc5, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x8b, 0x8b, 0x9b, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x17, 
  0xff, 0xff, 0xff, 0xbe, 0xa9, 0xa9, 0xb5, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0xec, 0xec, 0xef, 0xff, 0xff, 0xff, 0xff, 0x2e, 
  0xff, 0xff, 0xff, 0xa9, 0xbb, 0xbb, 0xc4, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x8b, 0x8b, 0x9b, 0xff, 0xfb, 0xfb, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x19, 
  0xff, 0xff, 0xff, 0x67, 0xdb, 0xdb, 0xe0, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0xa8, 0xa8, 0xb3, 0xff, 0xff, 0xff, 0xff, 0xd7, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xd5, 0xae, 0xae, 0xb9, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x8d, 0x8d, 0x9c, 0xff, 0xed, 0xed, 0xef, 0xff, 0xff, 0xff, 0xff, 0x4c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x34, 0xfa, 0xfa, 0xfb, 0xf5, 0xb8, 0xb8, 0xc2, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x89, 0x89, 0x99, 0xff, 0x9a, 0x9a, 0xa8, 0xff, 0xe4, 0xe4, 0xe8, 0xff, 0xff, 0xff, 0xff, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x24, 0xff, 0xff, 0xff, 0xc4, 0xed, 0xed, 0xf0, 0xff, 0xd3, 0xd3, 0xd9, 0xff, 0xca, 0xca, 0xd1, 0xff, 0xe1, 0xe1, 0xe5, 0xff, 0xfc, 0xfc, 0xfd, 0xf2, 0xff, 0xff, 0xff, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 0xff, 0x3a, 0xff, 0xff, 0xff, 0x6f, 0xff, 0xff, 0xff, 0x79, 0xff, 0xff, 0xff, 0x58, 0xff, 0xff, 0xff, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
};

const lv_img_dsc_t arm_d_2 = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 13,
  .header.h = 13,
  .data_size = 169 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = arm_d_2_map,
};