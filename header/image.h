
/*
 The Image class provides methods for creating, manipulating, and accessing pixel values
 * in images. It supports both greyscale and color images, with separate methods and data 
 * members for each type. Greyscale images are represented using a 2D array of pixel values, 
 * while color images are represented using a 3D array to account for multiple channels.



*/
#ifndef IMAGE_H
#define IMAGE_H



class Image{
    public:
    Image();
    Image(int numRows, int numCols, int dpeth);
    ~Image();
    int getPixelVal(int row, int col);
    void setPixelVal(int row, int col, int value);
    int getPixelVal3(int row, int col, int depth);
    void setPixelVal3(int row, int col, int depth, int value);
    int rows;
    int cols;
    int depth;
    int **pixelVal;
    int ***pixelVal3;


};

#endif