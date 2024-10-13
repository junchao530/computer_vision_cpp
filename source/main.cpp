/*

Main function to make calls to the image and the type of processing. 

*/

//include "0functions.hpp"
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

typedef void (*FuncCall)(Image &im);
typedef void (*FuncCall1)(Image &im,Image &im1);

//Structure of standard image processing techniques to be called
typedef struct{
    std::string argValue;
    std::string PrintValue;
    FuncCall filter;
    FuncCall1 filters;
}imageProcess;

//list of image processing techniques 
imageProcess lists[] = {
    //processing techniques requiring 2 images
     {"erosion",                 "Doing image erosion\n",                        Erosion,               NULL},      
     {"histogramEquilization",   "Doing histogram equilization on image\n",      histogramEqualization, NULL},    
     {"linearContrast",          "Applying linear contrast operation on image\n",linearContrast,        NULL},    
     {"sobelFilter",             "Applying sobel filter on image\n",             sobelFilter,           NULL},    
     {"prewittFilter",           "Applying prewitt filter on image\n",           prewittFilter,         NULL},    
     {"gaussFilter",             "Applying gauss filter on image\n",             gaussFilter,           NULL},    
     {"smoothingFilter",         "Applying smoothing filter on image\n",         smoothingFilter,       NULL},    
     {"robertFilter",            "Applying robert filter on image\n",            robertFilter,          NULL},    
     {"laplacienConvo",          "Applying laplacien convolution on image\n",    laplacienConvo,        NULL},    
     {"sharpen",                 "Sharpening image\n",                           Sharpen,               NULL},    
     {"edgeDetect",              "Doing edge detection on image\n",              edgeDetect,            NULL},    
     {"Hflip",                   "flip image horizontally\n",                    Hflip,                 NULL},    
     {"Vflip",                   "flip image vertically\n",                      Vflip,                 NULL},    
     {"Rrotate",                 "Rotate image clockwise\n",                     Rrotate,               NULL},    
     {"Lrotate",                 "Rotate image anti-clockwise\n",                Lrotate,               NULL},       
     {"luminance",               "Image luminance: \n",                          Luminance,             NULL},
    //Processing techniques requiring 1 images
     {"and",                     "Image1 AND Image2: \n",                        NULL,                  logicAnd},
     {"nand",                    "Image1 NAND Image2: \n",                       NULL,                  logicNand},
     {"or",                      "Image1 OR Image2: \n",                         NULL,                  logicOr},
     {"xor",                     "Image1 XOR Imag        e2: \n",                        NULL,                  logicXor},
     {"sub",                     "Substract Image1 from Image2: \n",             NULL,                  Subtraction},
     {"add",                     "add Image1 to Image2: \n",                     NULL,                  Addition},
     {"merge",                   "merge Image1 to Image2: \n",                   NULL,                  Merge},
};

void printHelp()
{
    printf("Instructions:\n"
    "- You must enter 3, 4, or 5 arguement (including the program name)\n"
    "- E.g. To apply not operation on an immage: ./app not images/img.png\n"
    "- To do operations to two images E.g. Add: ./app images/img1.png add images/img2.png\n"
    "- See README for more info!\n");
    
}

int main(int argc, char **argv){
    if(argc ==3 ){
        image ImageIn = readImage(argv[2]);
        int count = 0;
        while(count <= 18){ 
            if(argv[1] == lists[count].argValue){
                cout<<lists[count].PrintValue<<endl;
                return 0;
            }count++;
        }
    }else if(argc == 4){
            Image imageIn1 = readImage(argv[1]);
            Image imageIn2 = readImage(argv[3]);
            int count      = 17;
            while(count <= 24){
                if(argv[2] == lists[count].argValue){
                    cout<<lists[count].PrintValue<<endl;
                    lists[count].filters(imageIn1, imageIn2);
                    return 0;
            }count++;
        }
    }
    else{
        Image imageIn = readImage(argv[2]);

        if(strcmp(argv[1]), "linearcontrastSaturation" == 0){
            int smin = (int)atof(argv[3]);
            int smax = (int)atof(argv[4]);
            linearContrastSaturaton(imageIn, smin, smax);
    }else
    //list of additional features as they take extra parameters
    if(strcmp(argv[1], "brightness") == 0){
        int level = (int)atof(argv[3]);
        brightNESS(imageIn, level);
    }else
    if(strcmp(argv[1], "filtering")== 0){
        double r = (int)atof(argv[3]);
        double g = (int)atof(argv[4]);
        double b = (int)atof(argv[5]);
    }
    if(strcmp(argv[1], "mult") == 0){
        double factor = atof(argv[3]);
    }else
    if(strcmp(argv[1], "scalingNN") == 0){
        printf("scaling Imang \n");
        double xscale = atof(argv[3]);
        double yscale = atof(argv[4]);
        scalingNN(imageIn, xscale, yscale);
    }else{
        printHelp();
    }
    
}
}