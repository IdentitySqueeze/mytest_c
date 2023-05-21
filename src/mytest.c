#include <string.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "utils.h"
#include "gjlib_arrays.h"

static int * show_prime_factors(int val, int * element_count, int * rtn, char * pans);
static char * show_is_prime(int i, int x, char * rtn);
static char * show_not_square(int i, int x, int y, char * rtn);
static char * show_is_int(int i, double x, char * rtn);
static char * show_is_square(int i, int x, char * rtn);

extern int max_prime;

int main(){
	time_t t; 
	srand((unsigned)time(&t));
    max_prime = mytest_get_max_prime();

    int test_is_prime = 0;
    int test_rfr = 0;
    int test_ri = 1;
    int test_rd = 0;
    int test_prime_factors = 0;
    int test_lcm = 0;
    int test_hcf = 0;
    int test_sq = 0;
    int test_notSq = 0;
    int test_isSquare = 0;
    int test_int_choose = 0;
    int test_shrink = 0;
    int test_int_not = 0;
    int test_significant_figures = 0;
    int test_to_sub = 0;
    int test_to_super =0;
    int test_to_standard_form = 0;

    int test_otherhfc = 0;
    int test_swap = 0;
    int test_strlen_int = 0;
    int test_isInt = 0;

    char ans[100] ="";
    char *pans = ans;
    int * myarray;
    int x;

    if(test_is_prime ==1){
        int i=1;
        printf("\nis_prime --------------\n");
        show_is_prime(i++, -1, pans);
        show_is_prime(i++, 0,  pans);
        show_is_prime(i++, 1,  pans);
        show_is_prime(i++, 2,  pans);
        show_is_prime(i++, 3,  pans);
        show_is_prime(i++, 4,  pans);
        show_is_prime(i++, 5,  pans);
        show_is_prime(i++, 6,  pans);
        show_is_prime(i++, 7,  pans);
        show_is_prime(i++, 8,  pans);
        show_is_prime(i++, 9,  pans);
        show_is_prime(i++, 10, pans);
        show_is_prime(i++, 11, pans);
        show_is_prime(i++, 12, pans);
        show_is_prime(i++, 13, pans);
        show_is_prime(i++, 14, pans);
        show_is_prime(i++, 15, pans);
        show_is_prime(i++, 16, pans);
        show_is_prime(i++, 17, pans);
        show_is_prime(i++, 18, pans);
        show_is_prime(i++, 19, pans);
        show_is_prime(i++, 20, pans);
        show_is_prime(i++, 21, pans);
        show_is_prime(i++, 22, pans);
        show_is_prime(i++, 23, pans);
        show_is_prime(i++, 31, pans);
        show_is_prime(i++, 33, pans);
        show_is_prime(i++, 37, pans);
        show_is_prime(i++, 41, pans);
        show_is_prime(i++, 43, pans);
        show_is_prime(i++, 47, pans);
        show_is_prime(i++, 51, pans);
        show_is_prime(i++, 53, pans);
        show_is_prime(i++, 57, pans);
        show_is_prime(i++, 61, pans);
        show_is_prime(i++, 63, pans);
        show_is_prime(i++, 67, pans);
        show_is_prime(i++, 71, pans);
        show_is_prime(i++, 73, pans);
        show_is_prime(i++, 77, pans);
        show_is_prime(i++, 81, pans);
        show_is_prime(i++, 83, pans);
        show_is_prime(i++, 87, pans);
        show_is_prime(i++, 91, pans);
        show_is_prime(i++, 93, pans);
        show_is_prime(i++, 97, pans);
        show_is_prime(i++, 101, pans);
        show_is_prime(i++, 103, pans);
        show_is_prime(i++, 107, pans);
        show_is_prime(i++, 151, pans);
        show_is_prime(i++, 153, pans);
        show_is_prime(i++, 157, pans);
        show_is_prime(i++, 501, pans);
        show_is_prime(i++, 503, pans);
        show_is_prime(i++, 507, pans);
        show_is_prime(i++, 1001, pans);
        show_is_prime(i++, 1003, pans);
        show_is_prime(i++, 1007, pans);
        show_is_prime(i++, 10001, pans);
        show_is_prime(i++, 10003, pans);
        show_is_prime(i++, 10007, pans);
        show_is_prime(i++, 100001, pans);
        show_is_prime(i++, 100003, pans);
        show_is_prime(i++, 100007, pans);
        show_is_prime(i++, 1000001, pans);
        show_is_prime(i++, 1000003, pans);
        show_is_prime(i++, 1000007, pans);
        show_is_prime(i++, INT_MAX, pans);
        show_is_prime(i++, INT_MIN, pans);
    }

    if(test_rfr==1){
        //printf("\nrfr --------------\n");

        //Can't have negative widths.
        //Can't have widths > 9.
        //printf("1.  %s\n",gjlib_int_array_implode(mytest_rfr( 0, 0 ),pans));
        //printf("2.  %s\n",gjlib_int_array_implode(mytest_rfr( 0, 1 ),pans));
        //printf("3.  %s\n",gjlib_int_array_implode(mytest_rfr( 1, 0 ),pans));
        printf("4.  %s\n",gjlib_int_array_implode(mytest_rfr( 1, 1 ),pans));
        //printf("5.  %s\n",gjlib_int_array_implode(mytest_rfr(-1, 0 ),pans));
        //printf("6.  %s\n",gjlib_int_array_implode(mytest_rfr( 0,-1 ),pans));
        // printf("7.  %s\n",gjlib_int_array_implode(mytest_rfr( 1,-1 ),pans));
        // printf("8.  %s\n",gjlib_int_array_implode(mytest_rfr(-1, 1 ),pans));
        printf("9.  %s\n",gjlib_int_array_implode(mytest_rfr( 1, 1 ),pans));
        printf("10.  %s\n",gjlib_int_array_implode(mytest_rfr( 1, 2 ),pans));
        printf("11.  %s\n",gjlib_int_array_implode(mytest_rfr( 1, 3 ),pans));
        printf("12.  %s\n",gjlib_int_array_implode(mytest_rfr( 1, 4 ),pans));
        printf("13.  %s\n",gjlib_int_array_implode(mytest_rfr( 1, 5 ),pans));
        printf("14.  %s\n",gjlib_int_array_implode(mytest_rfr( 2, 1 ),pans));
        printf("15.  %s\n",gjlib_int_array_implode(mytest_rfr( 3, 1 ),pans));
        printf("16.  %s\n",gjlib_int_array_implode(mytest_rfr( 4, 1 ),pans));
        printf("17.  %s\n",gjlib_int_array_implode(mytest_rfr( 5, 1 ),pans));
        printf("18.  %s\n",gjlib_int_array_implode(mytest_rfr( 2, 3 ),pans));
        printf("19.  %s\n",gjlib_int_array_implode(mytest_rfr( 2, 4 ),pans));
        printf("20.  %s\n",gjlib_int_array_implode(mytest_rfr( 2, 5 ),pans));
        printf("21.  %s\n",gjlib_int_array_implode(mytest_rfr( 2, 6 ),pans));
        printf("22.  %s\n",gjlib_int_array_implode(mytest_rfr( 3, 2 ),pans));
        printf("23.  %s\n",gjlib_int_array_implode(mytest_rfr( 4, 2 ),pans));
        printf("24.  %s\n",gjlib_int_array_implode(mytest_rfr( 5, 2 ),pans));
        printf("25.  %s\n",gjlib_int_array_implode(mytest_rfr( 6, 2 ),pans));
        printf("26.  %s\n",gjlib_int_array_implode(mytest_rfr( 5, 6 ),pans));
        printf("27.  %s\n",gjlib_int_array_implode(mytest_rfr( 5, 7 ),pans));
        printf("28.  %s\n",gjlib_int_array_implode(mytest_rfr( 5, 8 ),pans));
        printf("29.  %s\n",gjlib_int_array_implode(mytest_rfr( 5, 9 ),pans));
        printf("30.  %s\n",gjlib_int_array_implode(mytest_rfr( 6, 5 ),pans));
        printf("31.  %s\n",gjlib_int_array_implode(mytest_rfr( 7, 5 ),pans));
        printf("32.  %s\n",gjlib_int_array_implode(mytest_rfr( 8, 5 ),pans));
        printf("33.  %s\n",gjlib_int_array_implode(mytest_rfr( 9, 5 ),pans));
        //printf("34.  %s\n",gjlib_int_array_implode(mytest_rfr( 10, 5 ),pans));
        //printf("35.  %s\n",gjlib_int_array_implode(mytest_rfr( 7, 10 ),pans));
        //printf("36.  %s\n",gjlib_int_array_implode(mytest_rfr( -8, -5 ),pans));
        //printf("\nINT_MAX:  %d\nINT_MIN: %d", INT_MAX, INT_MIN);
        //printf("37.  %s\n",gjlib_int_array_implode(mytest_rfr( INT_MAX, INT_MAX ),pans));
        //printf("38.  %s\n",gjlib_int_array_implode(mytest_rfr( INT_MAX, INT_MIN ),pans));
        //printf("39.  %s\n",gjlib_int_array_implode(mytest_rfr( INT_MIN, INT_MAX ),pans));
        //printf("40.  %s\n",gjlib_int_array_implode(mytest_rfr( INT_MIN, INT_MIN ),pans));
    }

    if(test_ri==1){
        printf("\n ri ---------------\n");
        printf("\n1:  %d", mytest_ri( 1, 1));
        printf("\n2:  %d", mytest_ri(-1, 1));
        printf("\n3:  %d", mytest_ri( 1,-1));
        printf("\n4:  %d", mytest_ri(-1,-1));
        printf("\n5.  %d", mytest_ri( 0, 0));
        printf("\n6:  %d", mytest_ri( 1, 0));
        printf("\n7:  %d", mytest_ri(-1, 0));
        printf("\n8:  %d", mytest_ri( 0, 1));
        printf("\n9:  %d", mytest_ri( 0,-1));
        printf("\n10:  %d", mytest_ri( 5, 5));
        printf("\n11:  %d", mytest_ri(-5, 5));
        printf("\n12:  %d", mytest_ri( 5,-5));
        printf("\n13:  %d", mytest_ri(-5,-5));
        printf("\n14:  %d", mytest_ri( 5, 0 ));
        printf("\n15:  %d", mytest_ri(-5, 0 ));
        printf("\n16:  %d", mytest_ri( 0, 5));
        printf("\n17:  %d", mytest_ri( 0,-5));
        printf("\n18:  %d", mytest_ri( 6, 3));
        printf("\n19:  %d", mytest_ri(-6, 3));
        printf("\n20:  %d", mytest_ri( 6,-3));
        printf("\n21:  %d", mytest_ri(-6,-3));
        printf("\n22:  %d", mytest_ri( 3, 6));
        printf("\n23:  %d", mytest_ri(-3, 6));
        printf("\n24:  %d", mytest_ri( 3,-6));
        printf("\n25:  %d", mytest_ri(-3,-6));
        printf("\n26:  %d", mytest_ri(10,1));
        printf("\n27:  %d", mytest_ri(100,10));
        printf("\n28:  %d", mytest_ri(1000,100));
        printf("\n29:  %d", mytest_ri(10000,1000));
        printf("\n30:  %d", mytest_ri(100000,10000));
        printf("\n31:  %d", mytest_ri(1000000,100000));
        printf("\n32:  %d", mytest_ri(-10,10));
        printf("\n33:  %d", mytest_ri(-100,100));
        printf("\n34:  %d", mytest_ri(-1000,1000));
        printf("\n35:  %d", mytest_ri(-10000,10000));
        printf("\n36:  %d", mytest_ri(-100000,100000));
        printf("\n37:  %d", mytest_ri(-1000000,1000000));
        printf("\n38:  %d", mytest_ri(10,-10));
        printf("\n39:  %d", mytest_ri(100,-100));
        printf("\n40:  %d", mytest_ri(1000,-1000));
        printf("\n41:  %d", mytest_ri(10000,-10000));
        printf("\n42:  %d", mytest_ri(100000,-100000));
        printf("\n43:  %d", mytest_ri(1000000,-1000000));
        printf("\n44:  %d", mytest_ri(-1,-10));
        printf("\n45:  %d", mytest_ri(-10,-100));
        printf("\n46:  %d", mytest_ri(-100,-1000));
        printf("\n47:  %d", mytest_ri(-1000,-10000));
        printf("\n48:  %d", mytest_ri(-10000,-100000));
        printf("\n49:  %d", mytest_ri(-100000,-1000000));
        printf("\n50:  %d (INT_MAX: %d, INT_MIN %d)", mytest_ri(INT_MAX, INT_MIN), INT_MAX, INT_MIN);
        printf("\n51:  %d (INT_MAX: %d, INT_MIN %d)", mytest_ri(INT_MIN, INT_MAX), INT_MAX, INT_MIN);
        printf("\n52:  %d (INT_MAX: %d, INT_MAX %d)", mytest_ri(INT_MIN, INT_MAX), INT_MAX, INT_MIN);
        printf("\n53:  %d (INT_MIN: %d, INT_MIN %d)", mytest_ri(INT_MIN, INT_MAX), INT_MAX, INT_MIN);
    }

    if(test_rd==1){
        printf("\nrd -------------------\n");
        printf("\n1:  %.10g",  mytest_rd( 1, 1, 0));
        printf("\n2:  %.10g",  mytest_rd(-1, 1, 0));
        printf("\n3:  %.10g",  mytest_rd( 1,-1, 0));
        printf("\n4:  %.10g",  mytest_rd(-1,-1, 0));
        printf("\n5:  %.10g",  mytest_rd( 0, 0, 0));
        printf("\n6:  %.10g",  mytest_rd( 1, 0, 0));
        printf("\n7:  %.10g",  mytest_rd(-1, 0, 0));
        printf("\n8:  %.10g",  mytest_rd( 0, 1, 0));
        printf("\n9:  %.10g",  mytest_rd( 0,-1, 0));
        printf("\n10:  %.10g", mytest_rd( 5, 5, 0));
        printf("\n11:  %.10g", mytest_rd(-5, 5, 0));
        printf("\n12:  %.10g", mytest_rd( 5,-5, 0));
        printf("\n13:  %.10g", mytest_rd(-5,-5, 0));
        printf("\n14:  %.10g", mytest_rd( 5, 0, 0));
        printf("\n15:  %.10g", mytest_rd(-5, 0, 0));
        printf("\n16:  %.10g", mytest_rd( 0, 5, 0));
        printf("\n17:  %.10g", mytest_rd( 0,-5, 0));
        printf("\n18:  %.10g", mytest_rd( 6, 3, 0));
        printf("\n19:  %.10g", mytest_rd(-6, 3, 0));
        printf("\n20:  %.10g", mytest_rd( 6,-3, 0));
        printf("\n21:  %.10g", mytest_rd(-6,-3, 0));
        printf("\n22:  %.10g", mytest_rd( 3, 6, 0));
        printf("\n23:  %.10g", mytest_rd(-3, 6, 0));
        printf("\n24:  %.10g", mytest_rd( 3,-6, 0));
        printf("\n25:  %.10g", mytest_rd(-3,-6, 0));

        printf("\n26:  %.10g", mytest_rd( 1, 1, 1));
        printf("\n27:  %.10g", mytest_rd(-1, 1, 1));
        printf("\n28:  %.10g", mytest_rd( 1,-1, 1));
        printf("\n29:  %.10g", mytest_rd(-1,-1, 1));
        printf("\n30:  %.10g", mytest_rd( 0, 0, 1));
        printf("\n31:  %.10g", mytest_rd( 1, 0, 1));
        printf("\n32:  %.10g", mytest_rd(-1, 0, 1));
        printf("\n33:  %.10g", mytest_rd( 0, 1, 1));
        printf("\n34:  %.10g", mytest_rd( 0,-1, 1));
        printf("\n35:  %.10g", mytest_rd( 5, 5, 1));
        printf("\n36:  %.10g", mytest_rd(-5, 5, 1));
        printf("\n37:  %.10g", mytest_rd( 5,-5, 1));
        printf("\n38:  %.10g", mytest_rd(-5,-5, 1));
        printf("\n39:  %.10g", mytest_rd( 5, 0, 1));
        printf("\n40:  %.10g", mytest_rd(-5, 0, 1));
        printf("\n41:  %.10g", mytest_rd( 0, 5, 1));
        printf("\n42:  %.10g", mytest_rd( 0,-5, 1));
        printf("\n43:  %.10g", mytest_rd( 6, 3, 1));
        printf("\n44:  %.10g", mytest_rd(-6, 3, 1));
        printf("\n45:  %.10g", mytest_rd( 6,-3, 1));
        printf("\n46:  %.10g", mytest_rd(-6,-3, 1));
        printf("\n47:  %.10g", mytest_rd( 3, 6, 1));
        printf("\n48:  %.10g", mytest_rd(-3, 6, 1));
        printf("\n49:  %.10g", mytest_rd( 3,-6, 1));
        printf("\n50:  %.10g", mytest_rd(-3,-6, 1));

        printf("\n51:  %.10g", mytest_rd( 1, 1, 4));
        printf("\n52:  %.10g", mytest_rd(-1, 1, 4));
        printf("\n53:  %.10g", mytest_rd( 1,-1, 4));
        printf("\n54:  %.10g", mytest_rd(-1,-1, 4));
        printf("\n55:  %.10g", mytest_rd( 0, 0, 4));
        printf("\n56:  %.10g", mytest_rd( 1, 0, 4));
        printf("\n57:  %.10g", mytest_rd(-1, 0, 4));
        printf("\n58:  %.10g", mytest_rd( 0, 1, 4));
        printf("\n59:  %.10g", mytest_rd( 0,-1, 4));
        printf("\n60:  %.10g", mytest_rd( 5, 5, 4));
        printf("\n61:  %.10g", mytest_rd(-5, 5, 4));
        printf("\n62:  %.10g", mytest_rd( 5,-5, 4));
        printf("\n63:  %.10g", mytest_rd(-5,-5, 4));
        printf("\n64:  %.10g", mytest_rd( 5, 0, 4));
        printf("\n65:  %.10g", mytest_rd(-5, 0, 4));
        printf("\n66:  %.10g", mytest_rd( 0, 5, 4));
        printf("\n67:  %.10g", mytest_rd( 0,-5, 4));
        printf("\n68:  %.10g", mytest_rd( 6, 3, 4));
        printf("\n69:  %.10g", mytest_rd(-6, 3, 4));
        printf("\n70:  %.10g", mytest_rd( 6,-3, 4));
        printf("\n71:  %.10g", mytest_rd(-6,-3, 4));
        printf("\n72:  %.10g", mytest_rd( 3, 6, 4));
        printf("\n73:  %.10g", mytest_rd(-3, 6, 4));
        printf("\n74:  %.10g", mytest_rd( 3,-6, 4));
        printf("\n75:  %.10g", mytest_rd(-3,-6, 4));

        printf("\n76:  %.10g", mytest_rd( 1, 1, -4));
        printf("\n77:  %.10g", mytest_rd(-1, 1, -4));
        printf("\n78:  %.10g", mytest_rd( 1,-1, -4));
        printf("\n79:  %.10g", mytest_rd(-1,-1, -4));
        printf("\n80:  %.10g", mytest_rd( 0, 0, -4));
        printf("\n81:  %.10g", mytest_rd( 1, 0, -4));
        printf("\n82:  %.10g", mytest_rd(-1, 0, -4));
        printf("\n83:  %.10g", mytest_rd( 0, 1, -4));
        printf("\n84:  %.10g", mytest_rd( 0,-1, -4));
        printf("\n85:  %.10g", mytest_rd( 5, 5, -4));
        printf("\n86:  %.10g", mytest_rd(-5, 5, -4));
        printf("\n87:  %.10g", mytest_rd( 5,-5, -4));
        printf("\n88:  %.10g", mytest_rd(-5,-5, -4));
        printf("\n89:  %.10g", mytest_rd( 5, 0, -4));
        printf("\n90:  %.10g", mytest_rd(-5, 0, -4));
        printf("\n91:  %.10g", mytest_rd( 0, 5, -4));
        printf("\n92:  %.10g", mytest_rd( 0,-5, -4));
        printf("\n93:  %.10g", mytest_rd( 6, 3, -4));
        printf("\n94:  %.10g", mytest_rd(-6, 3, -4));
        printf("\n95:  %.10g", mytest_rd( 6,-3, -4));
        printf("\n96:  %.10g", mytest_rd(-6,-3, -4));
        printf("\n97:  %.10g", mytest_rd( 3, 6, -4));
        printf("\n98:  %.10g", mytest_rd(-3, 6, -4));
        printf("\n99:  %.10g", mytest_rd( 3,-6, -4));
        printf("\n100: %.10g", mytest_rd(-3,-6, -4));

        printf("\n101:  %.10g", mytest_rd(10,1,0));
        printf("\n102:  %.10g", mytest_rd(100,10,0));
        printf("\n103:  %.10g", mytest_rd(1000,100,0));
        printf("\n104:  %.10g", mytest_rd(10000,1000,0));
        printf("\n105:  %.10g", mytest_rd(100000,10000,0));
        printf("\n106:  %.10g", mytest_rd(1000000,100000,0));
        printf("\n107:  %.10g", mytest_rd(-10,10,0));
        printf("\n108:  %.10g", mytest_rd(-100,100,0));
        printf("\n109:  %.10g", mytest_rd(-1000,1000,0));
        printf("\n110:  %.10g", mytest_rd(-10000,10000,0));
        printf("\n111:  %.10g", mytest_rd(-100000,100000,0));
        printf("\n112:  %.10g", mytest_rd(-1000000,1000000,0));
        printf("\n113:  %.10g", mytest_rd(10,-10,0));
        printf("\n114:  %.10g", mytest_rd(100,-100,0));
        printf("\n115:  %.10g", mytest_rd(1000,-1000,0));
        printf("\n116:  %.10g", mytest_rd(10000,-10000,0));
        printf("\n117:  %.10g", mytest_rd(100000,-100000,0));
        printf("\n118:  %.10g", mytest_rd(1000000,-1000000,0));
        printf("\n119:  %.10g", mytest_rd(-1,-10,0));
        printf("\n120:  %.10g", mytest_rd(-10,-100,0));
        printf("\n121:  %.10g", mytest_rd(-100,-1000,0));
        printf("\n122:  %.10g", mytest_rd(-1000,-10000,0));
        printf("\n123:  %.10g", mytest_rd(-10000,-100000,0));
        printf("\n124:  %.10g", mytest_rd(-100000,-1000000,0));
        printf("\n125:  %.10g (INT_MAX: %d, INT_MIN %d)", mytest_rd(INT_MAX, INT_MIN, 0), INT_MAX, INT_MIN);
        printf("\n126:  %.10g (INT_MIN: %d, INT_MAX %d)", mytest_rd(INT_MIN, INT_MAX, 0), INT_MIN, INT_MAX);

        printf("\n127:  %.10g", mytest_rd(10,1,1));
        printf("\n128:  %.10g", mytest_rd(100,10,1));
        printf("\n129:  %.10g", mytest_rd(1000,100,1));
        printf("\n130:  %.10g", mytest_rd(10000,1000,1));
        printf("\n131:  %.10g", mytest_rd(100000,10000,1));
        printf("\n132:  %.10g", mytest_rd(1000000,100000,1));
        printf("\n133:  %.10g", mytest_rd(-10,10,1));
        printf("\n134:  %.10g", mytest_rd(-100,100,1));
        printf("\n135:  %.10g", mytest_rd(-1000,1000,1));
        printf("\n136:  %.10g", mytest_rd(-10000,10000,1));
        printf("\n137:  %.10g", mytest_rd(-100000,100000,1));
        printf("\n138:  %.10g", mytest_rd(-1000000,1000000,1));
        printf("\n139:  %.10g", mytest_rd(10,-10,1));
        printf("\n140:  %.10g", mytest_rd(100,-100,1));
        printf("\n141:  %.10g", mytest_rd(1000,-1000,1));
        printf("\n142:  %.10g", mytest_rd(10000,-10000,1));
        printf("\n143:  %.10g", mytest_rd(100000,-100000,1));
        printf("\n144:  %.10g", mytest_rd(1000000,-1000000,1));
        printf("\n145:  %.10g", mytest_rd(-1,-10,1));
        printf("\n146:  %.10g", mytest_rd(-10,-100,1));
        printf("\n147:  %.10g", mytest_rd(-100,-1000,1));
        printf("\n148:  %.10g", mytest_rd(-1000,-10000,1));
        printf("\n149:  %.10g", mytest_rd(-10000,-100000,1));
        printf("\n150:  %.10g", mytest_rd(-100000,-1000000,1));
        printf("\n151:  %.10g (INT_MAX: %d, INT_MIN %d)", mytest_rd(INT_MAX, INT_MIN, 1), INT_MAX, INT_MIN);
        printf("\n152:  %.10g (INT_MAX: %d, INT_MIN %d)", mytest_rd(INT_MIN, INT_MAX, 1), INT_MAX, INT_MIN);

        printf("\n153:  %.10g", mytest_rd(10,1,4));
        printf("\n154:  %.10g", mytest_rd(100,10,4));
        printf("\n155:  %.10g", mytest_rd(1000,100,4));
        printf("\n156:  %.10g", mytest_rd(10000,1000,4));
        printf("\n157:  %.10g", mytest_rd(100000,10000,4));
            printf("\n158:  %.10g", mytest_rd(1000000,100000,4));
        printf("\n159:  %.10g", mytest_rd(-10,10,4));
        printf("\n160:  %.10g", mytest_rd(-100,100,4));
        printf("\n161:  %.10g", mytest_rd(-1000,1000,4));
        printf("\n162:  %.10g", mytest_rd(-10000,10000,4));
        printf("\n163:  %.10g", mytest_rd(-100000,100000,4));
            printf("\n164:  %.10g", mytest_rd(-1000000,1000000,4));
        printf("\n165:  %.10g", mytest_rd(10,-10,4));
        printf("\n166:  %.10g", mytest_rd(100,-100,4));
        printf("\n167:  %.10g", mytest_rd(1000,-1000,4));
        printf("\n168:  %.10g", mytest_rd(10000,-10000,4));
        printf("\n169:  %.10g", mytest_rd(100000,-100000,4));
            printf("\n170:  %.10g", mytest_rd(1000000,-1000000,4));
        printf("\n171:  %.10g", mytest_rd(-1,-10,4));
        printf("\n172:  %.10g", mytest_rd(-10,-100,4));
        printf("\n173:  %.10g", mytest_rd(-100,-1000,4));
        printf("\n174:  %.10g", mytest_rd(-1000,-10000,4));
        printf("\n175:  %.10g", mytest_rd(-10000,-100000,4));
            printf("\n176:  %.10g", mytest_rd(-100000,-1000000,4));
        printf("\n177:  %.10g (INT_MAX: %d, INT_MIN %d)", mytest_rd(INT_MAX, INT_MIN, -1), INT_MAX, INT_MIN);
        printf("\n178:  %.10g (INT_MAX: %d, INT_MIN %d)", mytest_rd(INT_MIN, INT_MAX, -1), INT_MAX, INT_MIN);
    }

    if(test_prime_factors==1){
        printf("\nprime factors -------");

        // memory management bit ------------
        int element_count=0; 
        int * ec= &element_count;
        int * ptr;// = (int *) malloc(8*sizeof(int));

        ptr = show_prime_factors(-1, ec, ptr, pans);
        ptr = show_prime_factors(0, ec, ptr, pans);
        ptr = show_prime_factors(1, ec, ptr, pans);
        ptr = show_prime_factors(2, ec, ptr, pans);
        ptr = show_prime_factors(3, ec, ptr, pans);
        ptr = show_prime_factors(4, ec, ptr, pans);
        ptr = show_prime_factors(5, ec, ptr, pans);
        ptr = show_prime_factors(6, ec, ptr, pans);
        ptr = show_prime_factors(7, ec, ptr, pans);
        ptr = show_prime_factors(8, ec, ptr, pans);
        ptr = show_prime_factors(9, ec, ptr, pans);
        ptr = show_prime_factors(10, ec, ptr, pans);
        ptr = show_prime_factors(11, ec, ptr, pans);
        ptr = show_prime_factors(12, ec, ptr, pans);
        ptr = show_prime_factors(13, ec, ptr, pans);
        ptr = show_prime_factors(14, ec, ptr, pans);
        ptr = show_prime_factors(15, ec, ptr, pans);
        ptr = show_prime_factors(16, ec, ptr, pans);
        ptr = show_prime_factors(17, ec, ptr, pans);
        ptr = show_prime_factors(18, ec, ptr, pans);
        ptr = show_prime_factors(19, ec, ptr, pans);
        ptr = show_prime_factors(20, ec, ptr, pans);
        ptr = show_prime_factors(30, ec, ptr, pans);
        ptr = show_prime_factors(40, ec, ptr, pans);
        ptr = show_prime_factors(50, ec, ptr, pans);
        ptr = show_prime_factors(60, ec, ptr, pans);
        ptr = show_prime_factors(70, ec, ptr, pans);
        ptr = show_prime_factors(80, ec, ptr, pans);
        ptr = show_prime_factors(90, ec, ptr, pans);
        ptr = show_prime_factors(100, ec, ptr, pans);
        ptr = show_prime_factors(4, ec, ptr, pans);
        ptr = show_prime_factors(8, ec, ptr, pans);
        ptr = show_prime_factors(16, ec, ptr, pans);
        ptr = show_prime_factors(32, ec, ptr, pans);
        ptr = show_prime_factors(64, ec, ptr, pans);
        ptr = show_prime_factors(128, ec, ptr, pans);
        ptr = show_prime_factors(512, ec, ptr, pans);
        ptr = show_prime_factors(1024, ec, ptr, pans);
        ptr = show_prime_factors(2048, ec, ptr, pans);
        ptr = show_prime_factors(4096, ec, ptr, pans);
        ptr = show_prime_factors(8192, ec, ptr, pans);
        ptr = show_prime_factors(16384, ec, ptr, pans);
        ptr = show_prime_factors(32768, ec, ptr, pans);
        ptr = show_prime_factors(65536, ec, ptr, pans);
        ptr = show_prime_factors(131072, ec, ptr, pans);
        ptr = show_prime_factors(262144, ec, ptr, pans);
        ptr = show_prime_factors(524288, ec, ptr, pans);
        ptr = show_prime_factors(1048577, ec, ptr, pans);
        ptr = show_prime_factors(1200000, ec, ptr, pans);
      //ptr = show_prime_factors(1299827, ec, ptr, pans);
    // ptr = show_prime_factors(INT_MAX, ec, ptr, pans);
    // ptr = show_prime_factors(INT_MIN, ec, ptr, pans);
        free(ptr);

    }

    if(test_lcm==1){
        printf("\n\nlcm ------");
        //testing va_list etc out of scope
        printf("\n5.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 1, 1, 2) ));
        return 1;
        printf("\n1.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 0, 0) ));
        printf("\n2.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 0, 1) ));
        printf("\n3.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 1, 0) ));
        printf("\n4.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 1, 1) ));
        printf("\n5.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 1, 1, 2) ));
   //printf("\n6.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 2, 1, 2, 3) ));
        printf("\n6.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 3, 1, 3, 2) ));
        printf("\n6.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 3, 3, 1, 2) ));
        printf("\n6.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 3, 3, 2, 1) ));
        printf("\n7.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 3, 2, 3, 4) ));
  //printf("\n8.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 4, 2, 3, 4) ));
        printf("\n9.  %lld", mytest_lcm(gjlib_int_array_init(myarray, 4, 2, 3, 4, 5) ));
        printf("\n10.  %lld",mytest_lcm(gjlib_int_array_init(myarray, 3, 2, 3, 7) ));
        printf("\n11.  %lld",mytest_lcm(gjlib_int_array_init(myarray, 3, 2, 4, 8) ));
        printf("\n12.  %lld",mytest_lcm(gjlib_int_array_init(myarray, 3, 3, 6, 9) ));
        printf("\n13.  %lld",mytest_lcm(gjlib_int_array_init(myarray, 3, 4, 16, 64) ));
        printf("\n14.  %lld",mytest_lcm(gjlib_int_array_init(myarray, 3, 7, 49, 349) ));
        printf("\n15.  %lld",mytest_lcm(gjlib_int_array_init(myarray, 3, 64, 2048, 1024) ));
        printf("\n15.  %lld",mytest_lcm(gjlib_int_array_init(myarray, 3, 2048, 64, 1024) ));
        printf("\n15.  %lld",mytest_lcm(gjlib_int_array_init(myarray, 3, 1024, 2048, 64 ) ));
        printf("\n15.  %lld",mytest_lcm(gjlib_int_array_init(myarray, 3, 2048, 1024, 64) ));
        printf("\n16.  %lld",mytest_lcm(gjlib_int_array_init(myarray, 2, 1000000, 1000) ));
        printf("\n17.  %lld",mytest_lcm(gjlib_int_array_init(myarray, 3, 1000000, 100, 11) ));
        //printf("\n18.  %lld",mytest_lcm(gjlib_int_array_init(myarray, 2, INT_MAX, INT_MIN) ));
        // sort unnecessary
    }

    if(test_hcf==1){
        printf("\n\nhcf --------");
        // printf("\n1.  %d",hcf(gjlib_int_array_init(myarray, 4, 5, 15, 30) ));
        // printf("\n1.  %d",hcf(gjlib_int_array_init(myarray, 2, 5, 30, 15) ));
        printf("\n1.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, 5, 15, 30) ));
        printf("\n2.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, 5, 30, 15) ));
        printf("\n3.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, 15, 5, 30) ));
        printf("\n4.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, 15, 30, 5) ));
        printf("\n5.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, 30, 5, 15) ));
        printf("\n6.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, 30, 15, 5) ));
        printf("\n7.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, 21, 35, 7) ));
        printf("\n8.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, 12, 24, 48)));
        printf("\n9.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, 9, 27, 126)));
        printf("\n10.  %d",mytest_hcf(gjlib_int_array_init(myarray, 4, INT_MIN+1, INT_MIN+1, INT_MAX-1, INT_MIN+1) ));
        printf("\n11.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, -5,  15, 30) ));
        printf("\n12.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3,  5, -15, 30) ));
        printf("\n13.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3,  5,  15,-30) ));
        printf("\n14.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, -5, 30, 15) ));
        printf("\n15.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, -15, 5, 30) ));
        printf("\n16.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, -15, 30, 5) ));
        printf("\n17.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, -30, 5, 15) ));
        printf("\n18.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, -30, 15, 5) ));
        printf("\n19.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, -21, 35, 7) ));
        printf("\n20.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, -12, 24, 48)));
        printf("\n21.  %d",mytest_hcf(gjlib_int_array_init(myarray, 3, -9, 27, 126)));
        printf("\n22.  %d",mytest_hcf(gjlib_int_array_init(myarray, 2, INT_MAX-1, INT_MIN+1) ));
    }

    if( test_sq == 1){
        //printf("\n.  %d", gjlib_sq( 0,-1));
        // printf("\n.  %d", gjlib_sq(-2,-2));
        printf("\n\ngjlib_sq --------------\n");
        printf("\n1.  %d", gjlib_sq( 0, 0));
        printf("\n2.  %d", gjlib_sq( 0, 1));
        printf("\n3.  %d", gjlib_sq( 1, 0));
        printf("\n4.  %d", gjlib_sq(-1, 0));
        printf("\n5.  %d", gjlib_sq(-1, 1));
        printf("\n6.  %d", gjlib_sq( 1, 1));
        printf("\n7.  %d", gjlib_sq(-2, 2));
        printf("\n8.  %d", gjlib_sq( 2, 2));
        printf("\n9.  %d", gjlib_sq( 1, 2));
        printf("\n10.  %d", gjlib_sq( 1, 3));
        printf("\n11.  %d", gjlib_sq( 2, 5));
        printf("\n12.  %d", gjlib_sq( 5,10));
        printf("\n13.  %d", gjlib_sq( 1, sqrt(INT_MAX)));
        //printf("\n14.  %d", gjlib_sq( INT_MIN, sqrt(INT_MAX)));
    }

    if( test_notSq == 1){
        printf("\n\ngjlib_notSq --------------\n");
        int i=1;
        show_not_square(i++, 0,  1,pans);
        show_not_square(i++, 1,  0,pans);
        show_not_square(i++,-1,  0,pans);
        show_not_square(i++,-1,  1,pans);
        show_not_square(i++, 1,  1,pans);
        show_not_square(i++,-2,  2,pans);
        show_not_square(i++, 2,  2,pans);
        show_not_square(i++, 1,  2,pans);
        show_not_square(i++, 1,  3,pans);
        show_not_square(i++, 2,  5,pans);
        show_not_square(i++, 5, 10,pans);
        show_not_square(i++, 5,100,pans);
        show_not_square(i++, 5,100,pans);
        show_not_square(i++, 5,100,pans);
        show_not_square(i++, -50,100,pans);
        show_not_square(i++, -50,100,pans);
        show_not_square(i++, -50,-100,pans);
        show_not_square(i++, -50,-100,pans);
        show_not_square(i++, 5,100,pans);
        show_not_square(i++, 5,100,pans);
        show_not_square(i++, 5,100,pans);
        show_not_square(i++, 5,100,pans);
        show_not_square(i++, 5,100,pans);
        show_not_square(i++, 5,100,pans);
        show_not_square(i++, 5,100,pans);
        show_not_square(i++, 1, sqrt(INT_MAX),pans);
    }

    if( test_isSquare == 1){
        printf("\n\ngjlib_isSquare --------------\n");
        int i=1;
        printf("%s\n", show_is_square(i++,-1, pans));
        printf("%s\n", show_is_square(i++,0, pans));
        printf("%s\n", show_is_square(i++,1, pans));
        printf("%s\n", show_is_square(i++,2, pans));
        printf("%s\n", show_is_square(i++,3, pans));
        printf("%s\n", show_is_square(i++,4, pans));
        printf("%s\n", show_is_square(i++,-4, pans));
        printf("%s\n", show_is_square(i++,5, pans));
        printf("%s\n", show_is_square(i++,6, pans));
        printf("%s\n", show_is_square(i++,7, pans));
        printf("%s\n", show_is_square(i++,8, pans));
        printf("%s\n", show_is_square(i++,9, pans));
        printf("%s\n", show_is_square(i++,-9, pans));
        printf("%s\n", show_is_square(i++,10, pans));
        printf("%s\n", show_is_square(i++,-10, pans));
        printf("%s\n", show_is_square(i++,11, pans));
        printf("%s\n", show_is_square(i++,12, pans));
        printf("%s\n", show_is_square(i++,13, pans));
        printf("%s\n", show_is_square(i++,14, pans));
        printf("%s\n", show_is_square(i++,15, pans));
        printf("%s\n", show_is_square(i++,16, pans));
        printf("%s\n", show_is_square(i++,17, pans));
        printf("%s\n", show_is_square(i++,18, pans));
        printf("%s\n", show_is_square(i++,19, pans));
        printf("%s\n", show_is_square(i++,20, pans));
        printf("%s\n", show_is_square(i++,25, pans));
        printf("%s\n", show_is_square(i++,26, pans));
        printf("%s\n", show_is_square(i++,35, pans));
        printf("%s\n", show_is_square(i++,36, pans));
        printf("%s\n", show_is_square(i++,37, pans));
        printf("%s\n", show_is_square(i++,48, pans));
        printf("%s\n", show_is_square(i++,49, pans));
        printf("%s\n", show_is_square(i++,50, pans));
        printf("%s\n", show_is_square(i++,51, pans));
        printf("%s\n", show_is_square(i++,53, pans));
        printf("%s\n", show_is_square(i++,64, pans));
        printf("%s\n", show_is_square(i++,65, pans));
        printf("%s\n", show_is_square(i++,168, pans));
        printf("%s\n", show_is_square(i++,169, pans));
        printf("%s\n", show_is_square(i++,170, pans));
        printf("%s\n", show_is_square(i++,INT_MAX, pans));
        printf("%s\n", show_is_square(i++,INT_MIN, pans));
    }
    
    if( test_isInt == 1){
        printf("\n\ngjlib_isInt --------------\n");
        printf("%s\n", show_is_int(1,-1.0, pans));
        printf("%s\n", show_is_int(2,-1.1, pans));
        printf("%s\n", show_is_int(3,-1, pans));
        printf("%s\n", show_is_int(4,0, pans));
        printf("%s\n", show_is_int(5,0.0, pans));
        printf("%s\n", show_is_int(6,1, pans));
        printf("%s\n", show_is_int(7,1.1, pans));
        printf("%s\n", show_is_int(8,2, pans));
        printf("%s\n", show_is_int(9,2.0, pans));
        printf("%s\n", show_is_int(10,2.2, pans));
        printf("%s\n", show_is_int(11,10, pans));
        printf("%s\n", show_is_int(12,10.1, pans));
        printf("%s\n", show_is_int(13,10.01, pans));
        printf("%s\n", show_is_int(14,10.001, pans));
        printf("%s\n", show_is_int(15,10.0001, pans));
        printf("%s\n", show_is_int(16,10.00001, pans));
        printf("%s\n", show_is_int(17,10.000001, pans));
        printf("%s\n", show_is_int(18,10.0000001, pans));
        printf("%s\n", show_is_int(19,10.00000001, pans));
        printf("%s\n", show_is_int(20,10.000000001, pans));
        printf("%s\n", show_is_int(21,10.0000000001, pans));
        printf("%s\n", show_is_int(22,10.00000000001, pans));
        printf("%s\n", show_is_int(23,10.000000000001, pans));
        printf("%s\n", show_is_int(24,10.0000000000001, pans));
        printf("%s\n", show_is_int(25,10.00000000000001, pans));
        printf("%s\n", show_is_int(26,10.000000000000001, pans));
        printf("%s\n", show_is_int(27,INT_MAX, pans));
        printf("%s\n", show_is_int(28,INT_MAX - 0.1, pans));
        printf("%s\n", show_is_int(29,INT_MIN, pans));
        printf("%s\n", show_is_int(30,INT_MIN + 0.1, pans));
    }

    if( test_int_choose == 1){
        printf("\n\ngjlib_int_choose --------------\n");
        printf("\n1.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 1, 1) ));
        printf("\n2.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2, -1, -1) ));
        printf("\n3.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2,  1, -1) ));
        printf("\n4.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2, -1,  1) ));
        printf("\n5.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2,  1,  1) ));
        printf("\n6.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2,  0,  0) ));
        printf("\n7.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2,  0,  1) ));
        printf("\n8.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2,  0, -1) ));
        printf("\n9.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2,  1,  0) ));
        printf("\n10.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2, -1,  0) ));
        printf("\n11.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2,  INT_MIN, INT_MIN) ));
        printf("\n12.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2,  INT_MAX, INT_MAX) ));
        printf("\n13.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2,  INT_MIN, INT_MAX) ));
        printf("\n14.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 2,  INT_MAX, INT_MIN) ));
        printf("\n15.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 5, 10, 11, 12, 13, 14 ) ));
        printf("\n16.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 5, 100, 200, 300, 400, 500 ) ));
        printf("\n17.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 5, INT_MIN, -1, 0, 1, INT_MAX ) ));
        //printf("\n18.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 5, 10, 10.1, 10.2, 10.3, 10.4 ) ));
        printf("\n19.  %d", gjlib_int_choose(gjlib_int_array_init(myarray, 15, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 8192, 16384, 32768, 65536  ) ));
    }

    if( test_shrink == 1){
        printf("\n\ngjlib_shrink --------------\n");
        // int x=2;
        // int y = 2;
        // printf("\n.  shrink %d by %d: %f", x, y, gjlib_shrink(x, y));
        printf("\n 1.  shrink  %d by  %d: %.10g",  0,  0, gjlib_shrink( 0,  0));
        printf("\n 2.  shrink %d by %d: %.10g", -1, -1, gjlib_shrink(-1, -1 ));
        printf("\n 3.  shrink %d by  %d: %.10g", -1,  1, gjlib_shrink(-1,  1 ));
        printf("\n 4.  shrink  %d by %d: %.10g",  1, -1, gjlib_shrink( 1, -1));
        printf("\n 5.  shrink  %d by  %d: %.10g",  1,  1, gjlib_shrink( 1,  1));
        printf("\n 6.  shrink  %d by %d: %.10g",  0, -1, gjlib_shrink( 0, -1 ));
        printf("\n 7.  shrink  %d by  %d: %.10g",  0,  1, gjlib_shrink( 0,  1 ));
        printf("\n 8.  shrink %d by  %d: %.10g", -1,  0, gjlib_shrink(-1,  0 ));
        printf("\n 9.  shrink  %d by  %d: %.10g",  1,  0, gjlib_shrink( 1,  0 ));
        printf("\n10.  shrink  %f by  %d: %.10g",  0.55,  0, gjlib_shrink( 0.55,  0));
        printf("\n11.  shrink %f by %d: %.10g", -1.55, -1, gjlib_shrink(-1.55, -1 ));
        printf("\n12.  shrink %f by  %d: %.10g", -1.55,  1, gjlib_shrink(-1.55,  1 ));
        printf("\n13.  shrink  %f by %d: %.10g",  1.55, -1, gjlib_shrink( 1.55, -1));
        printf("\n14.  shrink  %f by  %d: %.10g",  1.55,  1, gjlib_shrink( 1.55,  1));
        printf("\n15.  shrink  %f by %d: %.10g",  0.55, -1, gjlib_shrink( 0.55, -1 ));
        printf("\n16.  shrink  %f by  %d: %.10g",  0.55,  1, gjlib_shrink( 0.55,  1 ));
        printf("\n17.  shrink %f by  %d: %.10g", -1.55,  0, gjlib_shrink(-1.55,  0 ));
        printf("\n18.  shrink  %f by  %d: %.10g",  1.55,  0, gjlib_shrink( 1.55,  0 ));
        printf("\n19.  shrink %f by  %d: %.10g",  1.12345,  1 , gjlib_shrink( 1.12345, 1  ));
        printf("\n20.  shrink %f by %d: %.10g",  1.12345, -1 , gjlib_shrink( 1.12345, -1  ));
        printf("\n21.  shrink %f by  %d: %.10g",  2.12345,  2 , gjlib_shrink( 2.12345, 2  ));
        printf("\n22.  shrink %f by %d: %.10g",  2.12345, -2 , gjlib_shrink( 2.12345, -2  ));
        printf("\n23.  shrink %f by  %d: %.10g",  3.12345,  3 , gjlib_shrink( 3.12345, 3  ));
        printf("\n24.  shrink %f by %d: %.10g",  3.12345, -3 , gjlib_shrink( 3.12345, -3  ));
        printf("\n25.  shrink %f by  %d: %.10g",  4.12345,  4 , gjlib_shrink( 4.12345, 4  ));
        printf("\n26.  shrink %f by %d: %.10g",  4.12345, -4 , gjlib_shrink( 4.12345, -4  ));
        printf("\n27.  shrink %f by  %d: %.10g",  5.12345,  5 , gjlib_shrink( 5.12345, 5  ));
        printf("\n28.  shrink %f by %d: %.10g",  5.12345, -5 , gjlib_shrink( 5.12345, -5  ));
        printf("\n29.  shrink %f by  %d: %.10g",  11.12345, 0 , gjlib_shrink( 11.12345, 0  ));
        printf("\n30.  shrink %f by %d: %.10g",  3.1415927, 5 , gjlib_shrink( 3.1415927, 5  ));
        printf("\n31.  shrink %f by %d: %.10g",  (double)INT_MAX, 7 , gjlib_shrink( (double)INT_MAX, 7 ));
        printf("\n32.  shrink %f by %d: %.10g",  (double)INT_MIN, 7 , gjlib_shrink( (double)INT_MIN, 7 ));
    }

    if( test_int_not ==1){
        printf("\n\n gjlib_int_not--------------\n");
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(-1,1) not 0: %d", gjlib_int_not(0,-1,1, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
        printf("\nNot'ing - ri(4,6) not 5: %d", gjlib_int_not(5, 4,6, & mytest_ri));
    }

    if( test_significant_figures ==1){
        printf("\n\n Significant figures ---------------\n");
        //printf("\n.  %.10g to %d significant figures: %.10g",  0.0, 0, gjlib_significant_figures( 0.0, 0));
        //printf("\n.  %.10g to %d significant figures: %.10g",  1.0, 0, gjlib_significant_figures( 1.0, 0));
        //printf("\n.  %.10g to %d significant figures: %.10g",  0.0,-1, gjlib_significant_figures( 0.0,-1));
        //printf("\n.  %.10g to %d significant figures: %.10g", -1.0, 0, gjlib_significant_figures(-1.0, 0));
        //printf("\n.  %.10g to %d significant figures: %.10g", -1.0,-1, gjlib_significant_figures(-1.0,-1));
        //printf("\n.  %.10g to %d significant figures: %.10g", 12345.12345, -1, gjlib_significant_figures(12345.12345,-1));
        //printf("\n.  %.10g to %d significant figures: %.10g", 12345.12345, 0, gjlib_significant_figures(12345.12345,0));

        printf("\n1.  %.10g to %d significant figures: %.10g",  0.0, 1, gjlib_significant_figures( 0.0, 1));
        printf("\n2.  %.10g to %d significant figures: %.10g",  1.0, 1, gjlib_significant_figures( 1.0, 1));
        printf("\n3.  %.10g to %d significant figures: %.10g", 1.1, 1, gjlib_significant_figures(1.1,1));
        printf("\n4.  %.10g to %d significant figures: %.10g", 11.0, 1, gjlib_significant_figures(11.0,1));
        printf("\n5.  %.10g to %d significant figures: %.10g", 111.0, 2, gjlib_significant_figures(111.0,2));
        printf("\n6.  %.10g to %d significant figures: %.10g", 1111.0, 3, gjlib_significant_figures(1111.0,3));
        printf("\n7.  %.10g to %d significant figures: %.10g", 11.1, 1, gjlib_significant_figures(11.1,1));
        printf("\n8.  %.10g to %d significant figures: %.10g", 11.11, 2, gjlib_significant_figures(11.11,2));
        printf("\n9.  %.10g to %d significant figures: %.10g", 11.111, 3, gjlib_significant_figures(11.111,3));
        printf("\n10.  %.10g to %d significant figures: %.10g", 11.1111, 4, gjlib_significant_figures(11.1111,4));
        printf("\n11.  %.10g to %d significant figures: %.10g", 0.1, 1, gjlib_significant_figures(0.1,1));
        printf("\n12.  %.10g to %d significant figures: %.10g", 0.01, 1, gjlib_significant_figures(0.01,1));
        printf("\n13.  %.10g to %d significant figures: %.10g", 0.001, 1, gjlib_significant_figures(0.001,1));
        printf("\n14.  %.10g to %d significant figures: %.10g", 0.0001, 1, gjlib_significant_figures(0.0001,1));

        printf("\n15.  %.10g to %d significant figures: %.10g",  -1.0, 1, gjlib_significant_figures(-1.0, 1));
        printf("\n16.  %.10g to %d significant figures: %.10g",  -1.1, 1, gjlib_significant_figures(-1.1,1));
        printf("\n17.  %.10g to %d significant figures: %.10g",  -11.0, 1, gjlib_significant_figures(-11.0,1));
        printf("\n18.  %.10g to %d significant figures: %.10g", -111.0, 2, gjlib_significant_figures(-111.0,2));
        printf("\n19.  %.10g to %d significant figures: %.10g", -1111.0, 3, gjlib_significant_figures(-1111.0,3));
        printf("\n20.  %.10g to %d significant figures: %.10g", -11.1, 1, gjlib_significant_figures(-11.1,1));
        printf("\n21.  %.10g to %d significant figures: %.10g", -11.11, 2, gjlib_significant_figures(-11.11,2));
        printf("\n22.  %.10g to %d significant figures: %.10g", -11.111, 3, gjlib_significant_figures(-11.111,3));
        printf("\n23.  %.10g to %d significant figures: %.10g", -11.1111, 4, gjlib_significant_figures(-11.1111,4));
        printf("\n24.  %.10g to %d significant figures: %.10g", -0.1, 1, gjlib_significant_figures(-0.1,1));
        printf("\n25.  %.10g to %d significant figures: %.10g", -0.01, 1, gjlib_significant_figures(-0.01,1));
        printf("\n26.  %.10g to %d significant figures: %.10g", -0.001, 1, gjlib_significant_figures(-0.001,1));
        printf("\n27.  %.10g to %d significant figures: %.10g", -0.0001, 1, gjlib_significant_figures(-0.0001,1));

        printf("\n28.  %.10g to %d significant figures: %.10g", 12345.12345, 1, gjlib_significant_figures(12345.12345,1));
        printf("\n29.  %.10g to %d significant figures: %.10g", 12345.12345, 2, gjlib_significant_figures(12345.12345,2));
        printf("\n30.  %.10g to %d significant figures: %.10g", 12345.12345, 3, gjlib_significant_figures(12345.12345,3));
        printf("\n31.  %.10g to %d significant figures: %.10g", 12345.12345, 4, gjlib_significant_figures(12345.12345,4));
        printf("\n32.  %.10g to %d significant figures: %.10g", 12345.12345, 5, gjlib_significant_figures(12345.12345,5));
        printf("\n33.  %.10g to %d significant figures: %.10g", 12345.12345, 6, gjlib_significant_figures(12345.12345,6));
        printf("\n34.  %.10g to %d significant figures: %.10g", 12345.12345, 7, gjlib_significant_figures(12345.12345,7));
        printf("\n35.  %.10g to %d significant figures: %.10g", 12345.12345, 8, gjlib_significant_figures(12345.12345,8));
        printf("\n36.  %.10g to %d significant figures: %.10g", 12345.12345, 9, gjlib_significant_figures(12345.12345,9));
        printf("\n37.  %.10g to %d significant figures: %.10g", 12345.12345, 10, gjlib_significant_figures(12345.12345,10));
        printf("\n38.  %.10g to %d significant figures: %.10g", 123.123, 8, gjlib_significant_figures(123.123,8));

        printf("\n39.  %.10g to %d significant figures: %.10g", -12345.12345, 1, gjlib_significant_figures(-12345.12345,1));
        printf("\n40.  %.10g to %d significant figures: %.10g", -12345.12345, 2, gjlib_significant_figures(-12345.12345,2));
        printf("\n41.  %.10g to %d significant figures: %.10g", -12345.12345, 3, gjlib_significant_figures(-12345.12345,3));
        printf("\n42.  %.10g to %d significant figures: %.10g", -12345.12345, 4, gjlib_significant_figures(-12345.12345,4));
        printf("\n43.  %.10g to %d significant figures: %.10g", -12345.12345, 5, gjlib_significant_figures(-12345.12345,5));
        printf("\n44.  %.10g to %d significant figures: %.10g", -12345.12345, 6, gjlib_significant_figures(-12345.12345,6));
        printf("\n45.  %.10g to %d significant figures: %.10g", -12345.12345, 7, gjlib_significant_figures(-12345.12345,7));
        printf("\n46.  %.10g to %d significant figures: %.10g", -12345.12345, 8, gjlib_significant_figures(-12345.12345,8));
        printf("\n47.  %.10g to %d significant figures: %.10g", -12345.12345, 9, gjlib_significant_figures(-12345.12345,9));
        printf("\n48.  %.10g to %d significant figures: %.10g", -12345.12345, 10, gjlib_significant_figures(-12345.12345,10));
        printf("\n49.  %.10g to %d significant figures: %.10g", -123.123, 8, gjlib_significant_figures(-123.123,8));
        printf("\n50.  %.10g to %d significant figures: %.10g", (double)INT_MAX, 7, gjlib_significant_figures((double)INT_MAX, 7));
        printf("\n15.  %.10g to %d significant figures: %.10g", (double)INT_MIN, 7, gjlib_significant_figures((double)INT_MIN,7));
    }

    char * tmpArray;
    if(test_to_sub==1){
        printf("\n\nto_sub ------------");
        printf("\nabcdefghijklmnopqrstuvwxyzABCDEFDGHIJKLMNOPQRSTUVWXYZ1234567890()=\\/*+-\n%s", mytest_to_sub("abcdefghijklmnopqrstuvwxyzABCDEFDGHIJKLMNOPQRSTUVWXYZ1234567890()=\\/*+-", tmpArray));
               /* "ₐ♭꜀ᑯₑբ₉ₕᵢⱼₖₗₘₙₒₚ૧ᵣₛₜᵤᵥwₓᵧ₂ₐ₈CDₑբGₕᵢⱼₖₗₘₙₒₚQᵣₛₜᵤᵥwₓᵧZ₀₁₂₃₄₅₆₇₈₉₊₋₌₍₎" */
        //printf("\n\nᵃᵇᶜᵈᵉᶠᵍʰⁱʲᵏˡᵐⁿᵒᵖqʳˢᵗᵘᵛʷˣʸᶻᴬᴮCᴰᴱFᴰᴳᴴᴵᴶᴷᴸᴹᴺᴼᴾQᴿSᵀᵁⱽᵂXYZ¹²³⁴⁵⁶⁷⁸⁹⁰⁽⁾₌ᐠᐟ*⁺⁻\n%s", mytest_to_sub("ᵃᵇᶜᵈᵉᶠᵍʰⁱʲᵏˡᵐⁿᵒᵖqʳˢᵗᵘᵛʷˣʸᶻᴬᴮCᴰᴱFᴰᴳᴴᴵᴶᴷᴸᴹᴺᴼᴾQᴿSᵀᵁⱽᵂXYZ¹²³⁴⁵⁶⁷⁸⁹⁰⁽⁾₌ᐠᐟ*⁺⁻", tmpArray));
        //printf("\n\nₐbcdₑfghᵢⱼklmnₒpqᵣstᵤᵥwₓyzABCDEFDGHIJKLMNOPQRSTUVWXYZ₁₂₃₄₅₆₇₈₉₀₍₎₌\\/*₊₋\n%s", mytest_to_sub("ₐbcdₑfghᵢⱼklmnₒpqᵣstᵤᵥwₓyzABCDEFDGHIJKLMNOPQRSTUVWXYZ₁₂₃₄₅₆₇₈₉₀₍₎₌\\/*₊₋", tmpArray));
    }

    char * tmpArse;
    if(test_to_super==1){
        printf("\n\nto_super ------------");
        printf("\nabcdefghijklmnopqrstuvwxyzABCDEFDGHIJKLMNOPQRSTUVWXYZ1234567890()=\\/*+-\n%s", mytest_to_super("abcdefghijklmnopqrstuvwxyzABCDEFDGHIJKLMNOPQRSTUVWXYZ1234567890()=\\/*+-", tmpArse));
               /*"ᵃᵇᶜᵈᵉᶠᵍʰᶦʲᵏˡᵐⁿᵒᵖ۹ʳˢᵗᵘᵛʷˣʸᶻᴬᴮᶜᴰᴱᶠᴳᴴᴵᴶᴷᴸᴹᴺᴼᴾQᴿˢᵀᵁⱽᵂˣʸᶻ⁰¹²³⁴⁵⁶⁷⁸⁹⁺⁻⁼⁽⁾" */
        //printf("\n\nᵃᵇᶜᵈᵉᶠᵍʰⁱʲᵏˡᵐⁿᵒᵖqʳˢᵗᵘᵛʷˣʸᶻᴬᴮCᴰᴱFᴰᴳᴴᴵᴶᴷᴸᴹᴺᴼᴾQᴿSᵀᵁⱽᵂXYZ¹²³⁴⁵⁶⁷⁸⁹⁰⁽⁾₌ᐠᐟ*⁺⁻\n%s", mytest_to_super("ᵃᵇᶜᵈᵉᶠᵍʰⁱʲᵏˡᵐⁿᵒᵖqʳˢᵗᵘᵛʷˣʸᶻᴬᴮCᴰᴱFᴰᴳᴴᴵᴶᴷᴸᴹᴺᴼᴾQᴿSᵀᵁⱽᵂXYZ¹²³⁴⁵⁶⁷⁸⁹⁰⁽⁾₌ᐠᐟ*⁺⁻", tmpArse));
        //printf("\n\nₐbcdₑfghᵢⱼklmnₒpqᵣstᵤᵥwₓyzABCDEFDGHIJKLMNOPQRSTUVWXYZ₁₂₃₄₅₆₇₈₉₀₍₎₌\\/*₊₋\n%s", mytest_to_super("ₐbcdₑfghᵢⱼklmnₒpqᵣstᵤᵥwₓyzABCDEFDGHIJKLMNOPQRSTUVWXYZ₁₂₃₄₅₆₇₈₉₀₍₎₌\\/*₊₋", tmpArray));
    }

    char * another;
    if(test_to_standard_form==1){
        printf("\n\nto_standard_form ------------\n");
       //printf("\n66. -555555 = %s", mytest_to_standard_form(-555555, another));
    //return 1;
        printf("\n1.  111.11 = %s", mytest_to_standard_form(111.11, another));
        printf("\n2.  0.11111 = %s", mytest_to_standard_form(0.11111, another));
        printf("\n2a.  -0.11111 = %s", mytest_to_standard_form(-0.11111, another));
        printf("\n3.  0 = %s", mytest_to_standard_form(0, another));        
        printf("\n4.  1 = %s", mytest_to_standard_form(1, another));
        printf("\n5.  -1 = %s", mytest_to_standard_form(-1, another));
        printf("\n6.  0.00012345 = %s", mytest_to_standard_form(0.00012345, another));
        printf("\n7.  0.0012345 = %s", mytest_to_standard_form(0.0012345, another));
        printf("\n8.  0.012345 = %s", mytest_to_standard_form(0.012345, another));
        printf("\n9.  0.12345 = %s", mytest_to_standard_form(0.12345, another));
        printf("\n10.  1.2345 = %s", mytest_to_standard_form(1.2345, another));
        printf("\n11.  12.345 = %s", mytest_to_standard_form(12.345, another));
        printf("\n12.  123.45 = %s", mytest_to_standard_form(123.45, another));
        printf("\n13.  1234.5 = %s", mytest_to_standard_form(1234.5, another));
        printf("\n14.  12345.0 = %s", mytest_to_standard_form(12345.0, another));
        printf("\n15.  -111.11 = %s", mytest_to_standard_form(-111.11, another));
        printf("\n16.  -0.11111 = %s", mytest_to_standard_form(-0.11111, another));
        printf("\n17.  -0.00012345 = %s", mytest_to_standard_form(-0.00012345, another));
        printf("\n18.  -0.0012345 = %s", mytest_to_standard_form(-0.0012345, another));
        printf("\n19.  -0.012345 = %s", mytest_to_standard_form(-0.012345, another));
        printf("\n20.  -0.12345 = %s", mytest_to_standard_form(-0.12345, another));
        printf("\n21.  -1.2345 = %s", mytest_to_standard_form(-1.2345, another));
        printf("\n22.  -12.345 = %s", mytest_to_standard_form(-12.345, another));
        printf("\n23.  -123.45 = %s", mytest_to_standard_form(-123.45, another));
        printf("\n24.  -1234.5 = %s", mytest_to_standard_form(-1234.5, another));
        printf("\n25.  -12345.0 = %s", mytest_to_standard_form(-12345.0, another));
        printf("\n26.  INT_MAX = %s", mytest_to_standard_form((double)INT_MAX, another));
        printf("\n27.  INT_MIN = %s", mytest_to_standard_form((double)INT_MIN, another));
        printf("\n28.  9.9 = %s", mytest_to_standard_form(9.9, another));
        printf("\n29.  -9.9 = %s", mytest_to_standard_form(-9.9, another));
        printf("\n30.  10 = %s", mytest_to_standard_form(10, another));
        printf("\n31.  10.0 = %s", mytest_to_standard_form(10.0, another));
        printf("\n32.  -10  = %s", mytest_to_standard_form(-10, another));
        printf("\n33.  -10.0  = %s", mytest_to_standard_form(-10.0, another));
        printf("\n34.  10.01  = %s", mytest_to_standard_form(10.01, another));
        printf("\n35.  -10.01  = %s", mytest_to_standard_form(-10.01, another));
        printf("\n36.  11  = %s", mytest_to_standard_form(11, another));
        printf("\n37.  11.0  = %s", mytest_to_standard_form(11.0, another));
        printf("\n38.  -11  = %s", mytest_to_standard_form(-11, another));
        printf("\n39.  -11.0  = %s", mytest_to_standard_form(-11.0, another));
        printf("\n40.  11.01  = %s", mytest_to_standard_form(11.01, another));
        printf("\n41.  -11.01  = %s", mytest_to_standard_form(-11.01, another));
        printf("\n42.  0.9= %s", mytest_to_standard_form(0.9, another));
        printf("\n43.  0.09= %s", mytest_to_standard_form(0.09, another));
        printf("\n44.  0.009= %s", mytest_to_standard_form(0.009, another));
        printf("\n45.  0.0009= %s", mytest_to_standard_form(0.0009, another));
        printf("\n46.  0.00009= %s", mytest_to_standard_form(0.00009, another));
        printf("\n47.  -0.9= %s", mytest_to_standard_form(-0.9, another));
        printf("\n48.  -0.09= %s", mytest_to_standard_form(-0.09, another));
        printf("\n49.  -0.009= %s", mytest_to_standard_form(-0.009, another));
        printf("\n50.  -0.0009= %s", mytest_to_standard_form(-0.0009, another));
        printf("\n51.  -0.00009= %s", mytest_to_standard_form(-0.00009, another));
        printf("\n52. 5 = %s", mytest_to_standard_form(5, another));
        printf("\n53. 55 = %s", mytest_to_standard_form(55, another));
        printf("\n54. 555 = %s", mytest_to_standard_form(555, another));
        printf("\n55. 5555 = %s", mytest_to_standard_form(5555, another));
        printf("\n56. 55555 = %s", mytest_to_standard_form(55555, another));
        printf("\n57. 555555 = %s", mytest_to_standard_form(555555, another));
        printf("\n58. 5555555 = %s", mytest_to_standard_form(5555555, another));
        printf("\n59. 55555555 = %s", mytest_to_standard_form(55555555, another));
        printf("\n60. 555555555 = %s", mytest_to_standard_form(555555555, another));
        printf("\n61. -5 = %s", mytest_to_standard_form(-5, another));
        printf("\n62. -55 = %s", mytest_to_standard_form(-55, another));
        printf("\n63. -555 = %s", mytest_to_standard_form(-555, another));
        printf("\n64. -5555 = %s", mytest_to_standard_form(-5555, another));
        printf("\n65. -55555 = %s", mytest_to_standard_form(-55555, another));
        printf("\n66. -555555 = %s", mytest_to_standard_form(-555555, another));
        printf("\n67. -5555555 = %s", mytest_to_standard_form(-5555555, another));
        printf("\n68. -55555555 = %s", mytest_to_standard_form(-55555555, another));
        printf("\n69. -555555555 = %s", mytest_to_standard_form(-555555555, another));
        printf("\n70.  0.5 = %s", mytest_to_standard_form(0.5, another));
        printf("\n71.  0.55 = %s", mytest_to_standard_form(0.55, another));
        printf("\n72.  0.555 = %s", mytest_to_standard_form(0.555, another));
        printf("\n73.  0.5555 = %s", mytest_to_standard_form(0.5555, another));
        printf("\n74.  0.55555 = %s", mytest_to_standard_form(0.55555, another));
        printf("\n75.  0.555555 = %s", mytest_to_standard_form(0.555555, another));
        printf("\n76.  0.5555555 = %s", mytest_to_standard_form(0.5555555, another));
        printf("\n77.  0.55555555 = %s", mytest_to_standard_form(0.55555556, another));
        printf("\n78.  0.555555555 = %s", mytest_to_standard_form(0.555555555, another));
        printf("\n79. -0.5 = %s", mytest_to_standard_form(-0.5, another));
        printf("\n80. -0.55 = %s", mytest_to_standard_form(-0.55, another));
        printf("\n81. -0.555 = %s", mytest_to_standard_form(-0.555, another));
        printf("\n82. -0.5555 = %s", mytest_to_standard_form(-0.5555, another));
        printf("\n83. -0.55555 = %s", mytest_to_standard_form(-0.55555, another));
        printf("\n84. -0.555555 = %s", mytest_to_standard_form(-0.555555, another));
        printf("\n85. -0.5555555 = %s", mytest_to_standard_form(-0.5555555, another));
        printf("\n86. -0.55555555 = %s", mytest_to_standard_form(-0.55555555, another));
        printf("\n87. -0.555555555 = %s", mytest_to_standard_form(-0.555555555, another));
    }
    printf("\n\nend\n");
}

char * show_is_prime(int i, int x, char * rtn){
    memset(rtn, 0, sizeof rtn);
    printf("%d.  is_prime (%d) = %s\n",i, x, mytest_boolOut(mytest_is_prime(x), rtn));
    return rtn;
}

char * show_not_square(int i, int x, int y, char * rtn){
    memset(rtn, 0, sizeof rtn);
    int rslt = gjlib_notSq(x,y);
    printf("\n%d.  not square (%d, %d) = %d (%s)",i, x, y, rslt, mytest_boolOut(rslt, rtn));
    return rtn;
}

char * show_is_int(int i, double x, char * rtn){
    printf("%d.  is_int (%f) = ",i, x);
    return mytest_boolOut(gjlib_isInt(x), rtn);
}

char * show_is_square(int i, int x, char * rtn){
    printf("%d.  is_square (%d) = ",i, x);
    return mytest_boolOut(gjlib_isSquare(x), rtn);
}

int * show_prime_factors(int val, int *element_count, int * rtn, char * pans){
    //printf("\n zero");
    rtn = mytest_prime_factors(val, rtn, element_count);
    //printf("\n five");
    printf("\nprime factors (%d) = %s", val, gjlib_int_array_implode(gjlib_int_array_reverse(rtn), pans));
    return rtn;
}

