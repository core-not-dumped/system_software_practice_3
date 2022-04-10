//CHANGE COPYRIGHT HEADER WHEN YOU WRITE CODE (SUTDENT NAME, VERSION DATE MUST BE CHANGED)

/* ******************************************************************************************************************
 * Copyright (c) 2021 [2017313107], Seungtae-Lee, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : ppm.cc
 * - File Type : c++ source code
 * - File Version(Last Update Date) : 1.1 (Sep. 21, 2021.)
 * - Date : Sep. 21, 2021.
 * - Description : Version 1.0 is provided skeleton code for SSE2034-41(SKKU, 2021) class HW4.
 *                 This file has definition of ppm_process. In version 1.0 process_ppm() is not implemented.
 *                 After version 1.0, process_ppm() must be implemented.
 * ****************************************************************************************************************/

//DO NOT MODIFY PROVIDED PARTS! IF THESE PARTS ARE MODIFIED, YOU WILL GET LOW GRADE!
//WITHOUT MARKED PART! DO NOT MODIFY ANY CODE!

//Do Not Include Any Other Header Without Below
#include "ppm.h"
#include <fstream>
#include <cmath>
#include <iostream>
using namespace std;

/***********************************************************************************************************
 * TIPS & REFERENCES for HW4
 *
 * (1) pbm, pgm, ppm file format description : refer to HW4 PDF file
 *
 * (2) RGB to GRAY Scale formula : 0.299 * R + 0.587 * G + 0.114 * B (Round To UINT8(unsigned char) value)
 *     Ex 1) R : 120, G : 60, B : 35 -> Gray : 75.09 -> 75
 *     Ex 2) If Gray Value is 60.9 -> 61
 *
 * (3) W/B Bitmap Value : if gray > max_val/2 -> 0, else 1
 *     Ex) R : 120, G : 60, B :35 -> Gray : 75 -> W/B 1
 *
 * (4) Color Inversion formula : max_val - R, max_val - G, max_val - B
 *     Ex) R : 120, G : 60, B : 35 -> R : 135, G : 195, B : 220
 *
 * (5) All output files must be loaded in ppm image viewer.
 *     Viewer Site URL : https://www.kylepaulsen.com/stuff/NetpbmViewer/
 *
 * ********************************************************************************************************/

PROCESS_RESULT process_ppm(char *in_file_name, char *out_pbm_name, char *out_pgm_name, char *out_ppm_name) {

    //WRITE YOUR CODE Between /*****************************/ lines.
    /**************************************************************************************************/
    ifstream inStream;
    ofstream outStream_pbm, outStream_pgm, outStream_ppm;
    
    inStream.open(in_file_name);
    if(inStream.fail())             return INPUT_ERROR;
    
    outStream_pbm.open(out_pbm_name);
    if(outStream_pbm.fail())        return OUTPUT_ERROR;

    outStream_pgm.open(out_pgm_name);
    if(outStream_pgm.fail())        return OUTPUT_ERROR;

    outStream_ppm.open(out_ppm_name);
    if(outStream_ppm.fail())        return OUTPUT_ERROR;
    
    char t1,t2;
    inStream.get(t1);
    inStream.get(t2);
    if(t1 != 'P' || t2 != '3')      return INPUT_ERROR;
    outStream_pbm << "P1" << endl;
    outStream_pgm << "P2" << endl;
    outStream_ppm << "P3" << endl;

    int H, V;
    inStream >> H >> V;
    outStream_pbm << H << " " << V << endl;
    outStream_pgm << H << " " << V << endl;
    outStream_ppm << H << " " << V << endl;

    int max_value;
    inStream >> max_value;
    outStream_pgm << max_value << endl;
    outStream_ppm << max_value << endl;

    int i, j;
    for(i=0;i<V;i++)
    {
        int R, G, B;
        for(j=0;j<H;j++)
        {
            inStream >> R >> G >> B;

            if(inStream.eof())                                      return INPUT_ERROR;
            if(max_value < R || max_value < G || max_value < B)     return INPUT_ERROR;

            int gray = round(R*0.299 + G*0.589 + B*0.114);
            outStream_pbm << gray << " ";

            if(gray < max_value/2)      outStream_pgm << "1 ";
            else                        outStream_pgm << "0 ";

            outStream_ppm << max_value - R << " " << max_value - G << " " << max_value - B << " ";
        }
        outStream_pbm << endl;
        outStream_pgm << endl;
        outStream_ppm << endl;
    }


    inStream.close();
    outStream_pbm.close();
    outStream_pgm.close();
    outStream_ppm.close();

    return SUCCESS;
    /**************************************************************************************************/
}


