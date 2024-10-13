#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<image.h>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include <vector>
#include "functions.h"

Image readImage(char fname[]){
    Mat image = imread(fname);
    if(image.empty()){
        cout<<"Image file not found"<<endl;
        cin.get();
    }
    Image img(image.rows, image.cols, image.channel());

    for(int i = 0; i < image.rows; i++){
        for(int j =0; j < image.cols; j++){
            Vec3b intensity = image.at<Vec3b>(i,j);
            img.setPixelVal3(i, j, 0, intensity.val[0]);
            img.setPixelVal3(i, j, 1, intensity.val[1]);
            img.setPixelVal3(i, j, 2, intensity.val[2]);
        }
    }
    imshow("window name", img);
    waitKey(0);
    graySCALE(img);
    cout<<"number of channels: " <<image.channels()<<endl;
    return img;
}


