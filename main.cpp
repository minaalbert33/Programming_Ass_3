// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: xxxxxx.cpp
// Last Modification Date: 4/3/2022
// Author1 and ID and Group: 20210143
// Teaching Assistant: Hager Ali
// Purpose:..........
#include <iostream>
#include <bits/stdc++.h>
#include "bmplib.cpp"
unsigned char image[SIZE][SIZE];
void loadImage ();
void saveImage ();
void doBlackandWhiteforImage ();
void doMirrorupforImage ();
void doMirrorleftforImage ();
void doMirrorrightforImage ();
void doMirrordownforImage();
void Mirror();
int main()
{
    char Option ;
    cout << " Ahlan ya user ya habibi \uF04A " << endl;
    loadImage();
    cout << "Please select a filter to apply or 0 to exit:\n1- Black & White Filter\na- Mirror 1/2 Image";
    cin >> Option ;
    if (Option=='1')
    {
        doBlackandWhiteforImage();
        saveImage();
    }
    else if (Option=='a')
    {
        Mirror();
        saveImage();
    }
    else if (Option=='0')
        return 0;
    else
        cout << "Invalid input " << endl;
}

void loadImage () {
    char imageFileName[300];
    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
void saveImage () {
    char imageFileName[300];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
void doBlackandWhiteforImage() {
    long avg = 0 ;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++){
            avg+=image[i][j];
        }
    }
    avg/=(SIZE*SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image[i][j] > avg)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}
void  doMirrorupforImage ()
{
    for (int i = SIZE; i >=0 ; i--)
    {
        for (int j = 0; j <SIZE ; j++) {
            image[i][j]=image[SIZE-i][j];
        }
    }
}
void doMirrorleftforImage ()
{
    for (int i = SIZE; i >=0 ; i--)
    {
        for (int j = 0; j <SIZE ; j++)
        {
            image[i][j]=image[i][SIZE-j];
        }
    }
}
void doMirrorrightforImage ()
{
    for (int i = 0; i <SIZE; i++)
    {
        for (int j = SIZE; j >=0 ; j--)
        {
            image[i][j]=image[i][SIZE-j];
        }
    }
}
void doMirrordownforImage()
{
    for (int i = 0; i <SIZE; i++) {
        for (int j = SIZE; j >= 0; j--) {
            image[i][j] = image[SIZE - i][j];
        }
    }
}
void Mirror(){
    int Mirror_opt;
    cout << " Enter an option for Mirror: 1(upper),2(down),3(right),4(left)" << endl;
    cin >> Mirror_opt;
    if (Mirror_opt==1)
        doMirrorupforImage();
    else if (Mirror_opt==2)
        doMirrordownforImage();
    else if (Mirror_opt==3)
        doMirrorrightforImage();
    else if (Mirror_opt==4)
        doMirrorleftforImage();
    else
        cout << " Invalid input " << endl;
}
