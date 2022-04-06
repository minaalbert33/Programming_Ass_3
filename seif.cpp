#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char newImage[SIZE][SIZE];
void loadImage();
void loadImage2();
void saveImage();
void merge();
void lightenDarken();


int main() {
    int choice;
    char  imageFileName1[100];
    cout << "Ahlan ya user ya habibi " << endl;
    cout << "Please enter file name of the image to process: " ;
    cin >> imageFileName1;
    strcat(imageFileName1,".bmp");
    readGSBMP(imageFileName1,image);
    cout <<"Please select a filter to apply or 0 to exit" << endl;
    cout << "3- merge filter \n6- Darken and Lighten image" << endl;
    cin >> choice;
    if(choice == 3){
        loadImage2();
        merge();
        saveImage();
    }
    else if(choice == 6){
        lightenDarken();
        saveImage();

    }
}

void loadImage2(){
    char  imageFileName2[100];
    cout << "Enter the second source file name: ";
    cin >> imageFileName2;
    strcat(imageFileName2,".bmp");
    readGSBMP(imageFileName2,image2);
}
void saveImage(){
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat(imageFileName,".bmp");
    writeGSBMP(imageFileName,newImage);
}
void merge(){
    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            newImage[i][j] = (image[i][j] + image2[i][j])/2;

        }
    }
}
void lightenDarken(){
    int ch;
    cout << "Do you want to darken or lighten the image ?" << endl;
    cout << "1-Darken\n2-Lighten" << endl;
    cin >> ch;
    if(ch == 1){
        for(int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                newImage[i][j] = image[i][j]/2;

            }
        }
    }
    else if(ch == 2){
        for(int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                newImage[i][j] = 200;
                newImage[i][j] = (newImage[i][j]+image[i][j])/2;
            }

        }
    }
} 
