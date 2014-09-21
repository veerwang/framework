/*
 * =====================================================================================
 *
 *       Filename:  ProjectFixHead.h
 *
 *    Description:  Record something that not chang follow the project
 *
 *        Version:  1.0
 *        Created:  2010年05月17日 22时05分13秒
 *       Revision:  none
 *       Compiler:  gcc-arm
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  eddysun (XIAMEN) eddysun (XIAMEN)
 *
 * =====================================================================================
 */


#ifndef  _PROJECTFIXHEAD_INC
#define  _PROJECTFIXHEAD_INC
/*-----------------------------------------------------------------------------
 *  DATA TYPE USED BY PROJECT
 *-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 *      SYSTEM DATA TYPE
 *-----------------------------------------------------------------------------*/
typedef unsigned char  		UCHAR;
typedef char                    CHAR;
typedef unsigned short          UINT16;
typedef short                   INT16;
typedef unsigned int            UINT32;
typedef int                     INT32;
typedef double                  DOUBLE;
typedef long long               INT64;
typedef unsigned long long      UINT64;
typedef bool                    BOOL;
/*-----------------------------------------------------------------------------
 *      APPLICATION DATA TYPE
 *-----------------------------------------------------------------------------*/
typedef double         DATATYPE;
typedef short	       ETDATA;                           /* the data type get from ET broad */
typedef float	       DVTYPE;                  	        /* The data type of device */
typedef short 	       COLORTYPE;

/*-----------------------------------------------------------------------------
 *  Debug Message MAROC  when release programal did not need define _DEBUG_ MAROC 
 *-----------------------------------------------------------------------------*/
#define _DEBUG_
#if defined(_DEBUG_)
#define DMESSAGE(index,S)      printf("index %d:%s\n",index,S);
#define DMS(S)                 printf("%s\n",S);
#define DM1S(N,V)              printf("%s = %d\n",N,V);
#else
#define DMESSAGE(index,S) 
#define DMS(S)
#define DM1S(N,V)              
#endif

/*-----------------------------------------------------------------------------
 *  enum that device type 
 *-----------------------------------------------------------------------------*/
typedef enum {
	T308  = 1,
	T5097 = 2,
} DEVICETYPE;

/*-----------------------------------------------------------------------------
 *  PCB parameters enum variables
 *-----------------------------------------------------------------------------*/
typedef enum {
	EEC = 1,
	EMS = 2,
	EEC_EMS = 3,
	RFT = 4,
	EEC_SIN = 99,
} ETIO_FUN;

typedef enum {
	PCB_IO_M1 = 1,
	PCB_IO_M2 = 2,
} ETIO_IOMODE;

typedef enum {
	PCB_RD_M1 = 1,
	PCB_RD_M2 = 2,
} ETIO_RDMODE;

typedef struct {
	ETDATA* bufx; 
	ETDATA* bufy; 
	INT32   capacity;
	INT32   max;
	UINT64  sumx;
	UINT64  sumy;
	UCHAR   shiftv;
	INT32   index;
	BOOL    overf;
} DFilter;
/*-----------------------------------------------------------------------------
 *  Define the color used by project
 *-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 *  Description:  The color define with 16 bits mode under Linux environment
 *                         00000   000000   00000
 *                field     red     green    blue
 *  example:
 *                 red     1111 1000 0000 0000   0xf800
 *                 green   0000 0111 1110 0000   0x07e0
 *                 blue    0000 0000 0001 1111   0x001f
 *-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 *  16 bpp used
 *-----------------------------------------------------------------------------*/
#define	RED_16     	0xf800			
#define	TESTRED_16     	0xf800			
#define	GREEN_16        0x07e0		
#define BLUE_16         0x001F         
#define	WHITE_16        0xffff	
#define	BLACK_16        0x0000	
#define YELLOW_16	0xffe0
#define PINK_16		0xf81f
#define ORANGE_16	0xfE00
#define GRASS_16	0x87e0 
#define LIGHTBLUE_16	0x4610
/*-----------------------------------------------------------------------------
 *  8 BPP USED SYSTEM DEFINE  MY VALUE
 *-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 *  USED BY 308 DEVICE DEFAULT VALUE
 *-----------------------------------------------------------------------------*/
#define	BLACK_8         0xE0	
#define	RED_8     	0xE1
#define BLUE_8          0xE2
#define	GREEN_8         0xE3
#define YELLOW_8	0xE4
#define ORANGE_8	0xE5
#define PINK_8		0xE6
#define LIGHTBLUE_8	0xE7
#define LIGHTGREEN_8    0xE8
#define HIGHGREEN_8     0xE9
#define GOLD_8          0xF0
#define GRASS_8		0xF1
#define GRAY_8          0xF2
#define	WHITE_8         0xFD
/*-----------------------------------------------------------------------------
 *  1 BPP USED SYSTEM DEFINE
 *-----------------------------------------------------------------------------*/
#define	WHITE_1         1	
#define	BLACK_1         0	

/*-----------------------------------------------------------------------------
 *  Key value used by project
 *-----------------------------------------------------------------------------*/
#ifdef _KEY_X3_

//#define KEY_ENTER     0x14 
//#define KEY_ESC	0x21                  
//#define KEY_F1        0x05                
//#define KEY_F2        0x06                
//#define KEY_F3        0x11 
//
//#define KEY_LEFT      0x09 
//#define KEY_RIGHT     0x44 
//#define KEY_UP        0x24 
//#define KEY_DOWN      0x0c 
//
//#define KEY_0         0x12 
//#define KEY_1         0x41 
//#define KEY_2         0x7e 
//#define KEY_3         0x03 
//#define KEY_4         0x7b 
//#define KEY_5         0x6f 
//
//#define KEY_6         0x22 
//#define KEY_7         0x77 
//#define KEY_8         0x48 
//#define KEY_9         0x7d 
//#define KEY_10        0x42                   /* # */
//#define KEY_11        0x0a                   /* * */

//#define KEY_ENTER     0x28 
//#define KEY_ESC	      0x7b                  
//#define KEY_F1        0x5f                
//#define KEY_F2        0x60                
//#define KEY_F3        0x77 
//
//#define KEY_LEFT      0x6f 
//#define KEY_RIGHT     0x22 
//#define KEY_UP        0x24 
//#define KEY_DOWN      0x30
//
//#define KEY_0         0x48
//#define KEY_1         0x7d 
//#define KEY_2         0x7e 
//#define KEY_3         0x3f 
//#define KEY_4         0x21 
//#define KEY_5         0x09 
//
//#define KEY_6         0x44
//#define KEY_7         0x11 
//#define KEY_8         0x12 
//#define KEY_9         0x41 
//#define KEY_10        0x42                   /* # */
//#define KEY_11        0x50                   /* * */

#define KEY_ENTER       0x28 
#define KEY_ESC	        0x50             
#define KEY_F1          0x06              
#define KEY_F2          0x05           
#define KEY_F3          0x48 

#define KEY_LEFT        0x03 
#define KEY_RIGHT       0x30 
#define KEY_UP          0x60 
#define KEY_DOWN        0x18 

#define KEY_0           0x0a 
#define KEY_1           0x41 
#define KEY_2           0x42 
#define KEY_3           0x44 
#define KEY_4           0x21 
#define KEY_5           0x22 

#define KEY_6           0x24 
#define KEY_7           0x11 
#define KEY_8           0x12 
#define KEY_9           0x14 
#define KEY_10          0x0c                 /* # */
#define KEY_11          0x09                 /* * */

#define KEY_QUIT        0xfe 

#endif

#ifdef _KEY_308_1_
#define KEY_BOTTOM1  0x3f                        /* first bottom button key value */
#define KEY_BOTTOM2  0x5f
#define KEY_BOTTOM3  0x60
#define KEY_BOTTOM4  0x6f 
#define KEY_BOTTOM5  0x50
#define KEY_BOTTOM6  0x30
#define KEY_BOTTOM7  0x03                        /*  */
#define KEY_QUIT     0xfe 
#define KEY_ESCAPE   0x18 
#define KEY_FUN1L    0x7e
#define KEY_FUN1R    0x7d
#define KEY_FUN2L    0x41
#define KEY_FUN2R    0x42
#define KEY_FUN3L    0x21                        /*  */
#define KEY_FUN3R    0x22
#define KEY_FUN4L    0x11
#define KEY_FUN4R    0x12
#define KEY_FUN5L    0x09                        /*  */
#define KEY_FUN5R    0x0a 
#define KEY_FUN6L    0x05
#define KEY_FUN6R    0x06
#define KEY_ENTER    0x0c 
#define KEY_ESC	     0x18                        /*  */
#define KEY_F1       0x7b                        /* re-define */
#define KEY_F2       0x77                        /* re-define */
#define KEY_F3       0x44                        /* re-define */
#define KEY_F4       0x48                        /* re-define */
#define KEY_F5       0x24                        /* re-define */
#define KEY_F6       0x28                        /* re-define */
#define KEY_F7       0x14                        /* re-define */

#define KEY_UP       0x44
#define KEY_DOWN     0x14
#define KEY_LEFT     0x24
#define KEY_RIGHT    0x28
#endif

#ifdef _KEY_308_2_
#define KEY_BOTTOM1  0x09                      /* first bottom button key value */
#define KEY_BOTTOM2  0x0a
#define KEY_BOTTOM3  0x0c
#define KEY_BOTTOM4  0x08 
#define KEY_BOTTOM5  0x05 
#define KEY_BOTTOM6  0x06 
#define KEY_BOTTOM7  0x04 
#define KEY_QUIT     0xfe 
#define KEY_ESCAPE   0x10 
#define KEY_FUN1L    0x7e
#define KEY_FUN1R    0x41
#define KEY_FUN2L    0x7d
#define KEY_FUN2R    0x42 
#define KEY_FUN3L    0x7b 
#define KEY_FUN3R    0x44 
#define KEY_FUN4L    0x77 
#define KEY_FUN4R    0x48 
#define KEY_FUN5L    0x6f 
#define KEY_FUN5R    0x50 
#define KEY_FUN6L    0x5f 
#define KEY_FUN6R    0x60 
#define KEY_ENTER    0x30 
#define KEY_ESC	     0x10 
#define KEY_F1       0x21                        /* re-define */
#define KEY_F2       0x11                        /* re-define */
#define KEY_F3       0x22                        /* re-define */
#define KEY_F4       0x12                        /* re-define */
#define KEY_F5       0x24                        /* re-define */
#define KEY_F6       0x14                        /* re-define */
#define KEY_F7       0x28                        /* re-define */
#define KEY_F8       0x18                        /* re-define */
#endif

#ifdef _KEY_PC_
#define KEY_BOTTOM1  '1'                       /* first bottom button key value */
#define KEY_BOTTOM2  '2'
#define KEY_BOTTOM3  '3'
#define KEY_BOTTOM4  '4'
#define KEY_BOTTOM5  '5'
#define KEY_BOTTOM6  '6'
#define KEY_BOTTOM7  '7'
#define KEY_QUIT     'q'
#define KEY_ESCAPE   '6'
#define KEY_FUN1L    'y'
#define KEY_FUN1R    'g'
#define KEY_FUN2L    'u'
#define KEY_FUN2R    'h'
#define KEY_FUN3L    'i'
#define KEY_FUN3R    'j'
#define KEY_FUN4L    'o'
#define KEY_FUN4R    'k'
#define KEY_FUN5L    'p'
#define KEY_FUN5R    'l'
#define KEY_FUN6L    '['
#define KEY_FUN6R    ';'
#define KEY_ENTER    10
#define KEY_ESC	     27
#define KEY_F1       'z'                        /* re-define */
#define KEY_F2       'x'                        /* re-define */
#define KEY_F3       'c'                        /* re-define */
#define KEY_F4       'v'                        /* re-define */
#define KEY_F5       'b'                        /* re-define */
#define KEY_F6       'n'                        /* re-define */
#define KEY_F7       'm'                        /* re-define */
#define KEY_F8       ','                        /* re-define */

#define KEY_LEFT     'a'
#define KEY_RIGHT    'd'
#define KEY_UP       'w'
#define KEY_DOWN     's'

#define KEY_0        '0'
#define KEY_1        '1' 
#define KEY_2        '2' 
#define KEY_3        '3'
#define KEY_4        '4' 
#define KEY_5        '5' 

#define KEY_6        '6' 
#define KEY_7        '7' 
#define KEY_8        '8' 
#define KEY_9        '9' 
#define KEY_10       '-'                        /* # */
#define KEY_11       '='                        /* * */
#endif

#endif   /* ----- #ifndef projectfixhead_INC  ----- */
