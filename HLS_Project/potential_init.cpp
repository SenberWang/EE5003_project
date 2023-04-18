#include "potential_init.h"

void InitPotenMem(_potential_mem *PotenMemPE_0,
                  _potential_mem *PotenMemPE_1,
                  _potential_mem *PotenMemPE_2,
                  _potential_mem *PotenMemPE_3,
                  ap_uint<CLST_ID_WIDTH> ClstID)
{

    int idxRowPotenMem;
    int idxColPotenMem;
    int idxPotenMem;
    int idxFeMapPerPE;
    int idxSubFeMapPotenMem;

    /********************* conv layer 1 *************************/

    if (ClstID==0)
    {
        for (idxRowPotenMem=0; idxRowPotenMem<24; idxRowPotenMem++)
        {
            for (idxColPotenMem=0; idxColPotenMem<24; idxColPotenMem++)
            {
                idxPotenMem = idxRowPotenMem*24 + idxColPotenMem;

                PotenMemPE_0[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                PotenMemPE_0[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                PotenMemPE_0[idxPotenMem](45,42) = 0;                  //initialize feature map
                PotenMemPE_0[idxPotenMem](31,0) = 0;

                PotenMemPE_1[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                PotenMemPE_1[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                PotenMemPE_1[idxPotenMem](45,42) = 3;                  //initialize feature map
                PotenMemPE_1[idxPotenMem](31,0) = 0;

                PotenMemPE_2[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                PotenMemPE_2[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                PotenMemPE_2[idxPotenMem](45,42) = 6;                  //initialize feature map
                PotenMemPE_2[idxPotenMem](31,0) = 0;

                PotenMemPE_3[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                PotenMemPE_3[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                PotenMemPE_3[idxPotenMem](45,42) = 9;                  //initialize feature map
                PotenMemPE_3[idxPotenMem](31,0) = 0;
            }
        }


        for (idxRowPotenMem=0; idxRowPotenMem<24; idxRowPotenMem++)
        {
            for (idxColPotenMem=0; idxColPotenMem<24; idxColPotenMem++)
            {
                idxPotenMem = idxRowPotenMem*24 + idxColPotenMem + 576;

                PotenMemPE_0[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                PotenMemPE_0[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                PotenMemPE_0[idxPotenMem](45,42) = 1;                  //initialize feature map
                PotenMemPE_0[idxPotenMem](31,0) = 0;

                PotenMemPE_1[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                PotenMemPE_1[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                PotenMemPE_1[idxPotenMem](45,42) = 4;                  //initialize feature map
                PotenMemPE_1[idxPotenMem](31,0) = 0;

                PotenMemPE_2[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                PotenMemPE_2[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                PotenMemPE_2[idxPotenMem](45,42) = 7;                  //initialize feature map
                PotenMemPE_2[idxPotenMem](31,0) = 0;

                PotenMemPE_3[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                PotenMemPE_3[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                PotenMemPE_3[idxPotenMem](45,42) = 10;                  //initialize feature map
                PotenMemPE_3[idxPotenMem](31,0) = 0;
            }
        }


        for (idxRowPotenMem=0; idxRowPotenMem<24; idxRowPotenMem++)
        {
            for (idxColPotenMem=0; idxColPotenMem<24; idxColPotenMem++)
            {
                idxPotenMem = idxRowPotenMem*24 + idxColPotenMem + 1152;

                PotenMemPE_0[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                PotenMemPE_0[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                PotenMemPE_0[idxPotenMem](45,42) = 2;                  //initialize feature map
                PotenMemPE_0[idxPotenMem](31,0) = 0;

                PotenMemPE_1[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                PotenMemPE_1[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                PotenMemPE_1[idxPotenMem](45,42) = 5;                  //initialize feature map
                PotenMemPE_1[idxPotenMem](31,0) = 0;

                PotenMemPE_2[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                PotenMemPE_2[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                PotenMemPE_2[idxPotenMem](45,42) = 8;                  //initialize feature map
                PotenMemPE_2[idxPotenMem](31,0) = 0;

                PotenMemPE_3[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                PotenMemPE_3[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                PotenMemPE_3[idxPotenMem](45,42) = 11;                  //initialize feature map
                PotenMemPE_3[idxPotenMem](31,0) = 0;
            }
        }
    }

    /********************* pooling layer 1 *************************/

    if (ClstID==1)
    {
        for (idxRowPotenMem=0; idxRowPotenMem<12; idxRowPotenMem++)
        {
            for (idxColPotenMem=0; idxColPotenMem<12; idxColPotenMem++)
            {
                for (idxFeMapPerPE=0; idxFeMapPerPE<3; idxFeMapPerPE++)
                {
                    idxPotenMem = idxFeMapPerPE*144 + idxRowPotenMem*12 + idxColPotenMem;
                    PotenMemPE_0[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_0[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_0[idxPotenMem](45,42) = idxFeMapPerPE + 0*3;     //initialize feature map
                    PotenMemPE_0[idxPotenMem](31,0) = 0;

                    PotenMemPE_1[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_1[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_1[idxPotenMem](45,42) = idxFeMapPerPE + 1*3;     //initialize feature map
                    PotenMemPE_1[idxPotenMem](31,0) = 0;

                    PotenMemPE_2[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_2[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_2[idxPotenMem](45,42) = idxFeMapPerPE + 2*3;     //initialize feature map
                    PotenMemPE_2[idxPotenMem](31,0) = 0;

                    PotenMemPE_3[idxPotenMem](36,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_3[idxPotenMem](41,37) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_3[idxPotenMem](45,42) = idxFeMapPerPE + 3*3;     //initialize feature map
                    PotenMemPE_3[idxPotenMem](31,0) = 0;
                }
            }
        }
    }

    /********************* conv layer 2 *************************/

    if (ClstID==2)
    {
        for (idxRowPotenMem=0; idxRowPotenMem<8; idxRowPotenMem++)
        {
            for (idxColPotenMem=0; idxColPotenMem<8; idxColPotenMem++)
            {
                for (idxFeMapPerPE=0; idxFeMapPerPE<8; idxFeMapPerPE++)
                {
                    idxPotenMem = idxFeMapPerPE*64 + idxRowPotenMem*8 + idxColPotenMem;

                    PotenMemPE_0[idxPotenMem](35,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_0[idxPotenMem](39,36) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_0[idxPotenMem](46,40) = idxFeMapPerPE + 0*8;     //initialize feature map
                    PotenMemPE_0[idxPotenMem](31,0)  = 0;

                    PotenMemPE_1[idxPotenMem](35,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_1[idxPotenMem](39,36) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_1[idxPotenMem](46,40) = idxFeMapPerPE + 1*8;     //initialize feature map
                    PotenMemPE_1[idxPotenMem](31,0)  = 0;

                    PotenMemPE_2[idxPotenMem](35,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_2[idxPotenMem](39,36) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_2[idxPotenMem](46,40) = idxFeMapPerPE + 2*8;     //initialize feature map
                    PotenMemPE_2[idxPotenMem](31,0)  = 0;

                    PotenMemPE_3[idxPotenMem](35,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_3[idxPotenMem](39,36) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_3[idxPotenMem](46,40) = idxFeMapPerPE + 3*8;     //initialize feature map
                    PotenMemPE_3[idxPotenMem](31,0)  = 0;
                }
            }
        }
    }


    if (ClstID==3)
    {
        for (idxRowPotenMem=0; idxRowPotenMem<8; idxRowPotenMem++)
        {
            for (idxColPotenMem=0; idxColPotenMem<8; idxColPotenMem++)
            {
                for (idxFeMapPerPE=0; idxFeMapPerPE<8; idxFeMapPerPE++)
                {
                    idxPotenMem = idxFeMapPerPE*64 + idxRowPotenMem*8 + idxColPotenMem;

                    PotenMemPE_0[idxPotenMem](35,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_0[idxPotenMem](39,36) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_0[idxPotenMem](46,40) = idxFeMapPerPE + 0*8 + 32;     //initialize feature map
                    PotenMemPE_0[idxPotenMem](31,0)  = 0;

                    PotenMemPE_1[idxPotenMem](35,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_1[idxPotenMem](39,36) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_1[idxPotenMem](46,40) = idxFeMapPerPE + 1*8 + 32;     //initialize feature map
                    PotenMemPE_1[idxPotenMem](31,0)  = 0;

                    PotenMemPE_2[idxPotenMem](35,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_2[idxPotenMem](39,36) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_2[idxPotenMem](46,40) = idxFeMapPerPE + 2*8 + 32;     //initialize feature map
                    PotenMemPE_2[idxPotenMem](31,0)  = 0;

                    PotenMemPE_3[idxPotenMem](35,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_3[idxPotenMem](39,36) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_3[idxPotenMem](46,40) = idxFeMapPerPE + 3*8 + 32;     //initialize feature map
                    PotenMemPE_3[idxPotenMem](31,0)  = 0;
                }
            }
        }
    }

    /********************* pooling layer 2 *************************/

    if (ClstID==4)
    {
        for (idxSubFeMapPotenMem=0; idxSubFeMapPotenMem<16; idxSubFeMapPotenMem++)
        {
            for (idxRowPotenMem=0; idxRowPotenMem<4; idxRowPotenMem++)
            {
                for (idxColPotenMem=0; idxColPotenMem<4; idxColPotenMem++)
                {
                    idxPotenMem = idxSubFeMapPotenMem*16 + idxRowPotenMem*4 + idxColPotenMem;

                    PotenMemPE_0[idxPotenMem](35,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_0[idxPotenMem](39,36) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_0[idxPotenMem](46,40) = 0*16 + idxSubFeMapPotenMem;     //initialize feature map
                    PotenMemPE_0[idxPotenMem](31,0)  = 0;

                    PotenMemPE_1[idxPotenMem](35,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_1[idxPotenMem](39,36) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_1[idxPotenMem](46,40) = 1*16 + idxSubFeMapPotenMem;     //initialize feature map
                    PotenMemPE_1[idxPotenMem](31,0)  = 0;

                    PotenMemPE_2[idxPotenMem](35,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_2[idxPotenMem](39,36) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_2[idxPotenMem](46,40) = 2*16 + idxSubFeMapPotenMem;     //initialize feature map
                    PotenMemPE_2[idxPotenMem](31,0)  = 0;

                    PotenMemPE_3[idxPotenMem](35,32) = idxColPotenMem;     //initialize col number
                    PotenMemPE_3[idxPotenMem](39,36) = idxRowPotenMem;     //initialize row number
                    PotenMemPE_3[idxPotenMem](46,40) = 3*16 + idxSubFeMapPotenMem;     //initialize feature map
                    PotenMemPE_3[idxPotenMem](31,0)  = 0;
                }
            }
        }
    }


    /********************* output layer *************************/

    if (ClstID==5)
    {
        for(idxPotenMem=0;idxPotenMem<5;idxPotenMem++)
        {
            PotenMemPE_0[idxPotenMem](63, 32) = idxPotenMem;
            PotenMemPE_0[idxPotenMem](31, 0) = 0;

            PotenMemPE_1[idxPotenMem](63, 32) = idxPotenMem + 5;
            PotenMemPE_1[idxPotenMem](31, 0) = 0;
        }
        
    }

}
