// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: CS112-203-2nd – 17 -20210143-20210169-20210417-A3-Part1.cpp
// Last Modification Date: 04/07/2022
// Author1 and ID and Group: Mina Albert Saeed  20210417
// Author2 and ID and Group: Ziad Ahmed Mohamed 20210143
// Author3 and ID and Group: Seif Elden Mahmoud Helmy 20210169
// Teaching Assistant: Eng/ Hager Ali
// Purpose: 6 Filters on Images

#include<bits/stdc++.h>
#include"bmplib.cpp"
#include "bmplib.h"
using namespace std;

// Photos in form of 2d-arrays
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char newImage[SIZE][SIZE];

// photos in form of 3d-arrays
unsigned char image_rgb[SIZE][SIZE][RGB];
unsigned char image2_rgb[SIZE][SIZE][RGB];
unsigned char newImage_rgb[SIZE][SIZE][RGB];

void load_image ();
void load_image2();
void save_image (unsigned char [][SIZE]);


void load_image_rgb();
void load_image2_rgb();
void save_image_rgb();

// Mina
void invert_image ();
void rotate_image ();
void rotate_90 ();

// Seif
void merge();
void lightenDarken();
void shrink();
void blur();
void merge_rgb();
void lightenDarken_rgb();
void shrink_rgb();
void blur_rgb();
// Ziad
void doBlackandWhiteforImage ();
void doMirrorupforImage ();
void doMirrorleftforImage ();
void doMirrorrightforImage ();
void doMirrordownforImage();
void Mirror();

int main(){
    int choice1;
    cout << "Ahlan ya user ya habibi\n1- Grayscale images\n2- RGB images" << endl;
    cin >> choice1;
    if(choice1 == 1){
        load_image();
    string choice;
    cout << "1- Black & White Filter\n2- Invert Image\n3- merge filter\n5- Rotate Image\n";
    cout << "6- Darken and Lighten image\n9- shrink image\n11- Mirror 1/2 Image\nc- blur\n";
    cout << "Please, select a filter to apply or 0 to exit:";
    cin >> choice;
    if(choice == "0"){
        return 0;
    }else if(choice == "1"){
        doBlackandWhiteforImage();
        save_image(image);
    }else if(choice == "2"){
        invert_image();
        save_image(image);
    }else if(choice == "3"){
        load_image2();
        merge();
        save_image(newImage);
    }else if(choice == "5"){
        int degree;
        cout << "Enter the degree you want to rotate by: ";
        cin >> degree;
        if(degree == 90){
            rotate_90();
            save_image(image);
        }else if(degree == 180){
            rotate_90();
            rotate_90();
            save_image(image);
        }else{
            rotate_90();
            rotate_90();
            rotate_90();
            save_image(image);
        }
    }else if(choice == "6"){
        lightenDarken();
        save_image(newImage);
    }else if(choice == "9"){
        shrink();
        save_image(newImage);
    }
    else if(choice == "11"){
        Mirror();
        save_image(image);
    }
    else if(choice == "c"){
        blur();
        save_image(newImage);
    }
}
    else if(choice1 == 2){
        string choice;
        load_image_rgb();
        cout << "1- Black & White Filter\n2- Invert Image\n3- merge filter\n5- Rotate Image\n";
        cout << "6- Darken and Lighten image\n9- shrink image\n11- Mirror 1/2 Image\nc- blur\n";
        cout << "Please, select a filter to apply or 0 to exit:";
        cin >> choice;
        if(choice == "0"){
            return 0;
        }else if(choice == "1"){
            doBlackandWhiteforImage();
            save_image(image);
        }else if(choice == "2"){
            invert_image();
            save_image(image);
        }else if(choice == "3"){
            load_image2_rgb();
            merge_rgb();
            save_image_rgb();
        }else if(choice == "5"){
            int degree;
            cout << "Enter the degree you want to rotate by: ";
            cin >> degree;
            if(degree == 90){
                rotate_90();
                save_image(image);
            }else if(degree == 180){
                rotate_90();
                rotate_90();
                save_image(image);
            }else{
                rotate_90();
                rotate_90();
                rotate_90();
                save_image(image);
            }
        }else if(choice == "6"){
            lightenDarken_rgb();
            save_image_rgb();
        }else if(choice == "9"){
            shrink_rgb();
            save_image_rgb();
        }
        else if(choice == "11"){
            Mirror();
            save_image(image);
        }
        else if(choice == "c"){
            blur_rgb();
            save_image_rgb();
        }

    }
}

// function to load image from user.
void load_image () {
    char file_name[100];

   // Get gray scale image file name
    cout << "Please, Enter file name of the image to process: ";
    cin >> file_name;

   // Add to it .bmp extension and load image
    strcat (file_name, ".bmp");
    readGSBMP(file_name, image);
}
void load_image_rgb() {
    char file_name[100];

    // Get gray scale image file name
    cout << "Please, Enter file name of the image to process: ";
    cin >> file_name;

    // Add to it .bmp extension and load image
    strcat (file_name, ".bmp");
    readRGBBMP(file_name, image_rgb);
}

// Inverting image
void invert_image (){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            image[i][j] = ~image[i][j];
        }
    }
}

// Saving Image to the desired file.
void save_image (unsigned char image_name[][SIZE]) {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> file_name;

    // Add to it .bmp extension and load image
    strcat (file_name, ".bmp");
    writeGSBMP(file_name, image_name);
}
void save_image_rgb () {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> file_name;

    // Add to it .bmp extension and load image
    strcat (file_name, ".bmp");
    writeRGBBMP(file_name, newImage_rgb);
}

// Function to rotate image 90 degrees.
void rotate_90 (){
    for(int i = 0; i < SIZE; i++){
        for(int j = i; j < SIZE; j++){
            swap(image[i][j], image[j][i]);
        }
    }

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < (SIZE/2); j++){
            swap(image[i][j], image[i][SIZE-1-j]);
        }
    }
}

// Function to load image2.
void load_image2(){
    char  imageFileName2[100];
    cout << "Enter the second source file name: ";
    cin >> imageFileName2;
    strcat(imageFileName2,".bmp");
    readGSBMP(imageFileName2,image2);
}
void load_image2_rgb(){
    char  imageFileName2[100];
    cout << "Enter the second source file name: ";
    cin >> imageFileName2;
    strcat(imageFileName2,".bmp");
    readRGBBMP(imageFileName2,image2_rgb);
}

// Merging two photos together.
void merge(){
    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            newImage[i][j] = (image[i][j] + image2[i][j])/2;

        }
    }
}

// Function to either lighten or darken an image.
void lightenDarken(){
    int ch;
    cout << "Do you want to darken or lighten the image ?" << endl;
    cout << "1-Darken\n2-Lighten: " << endl;
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

void Mirror(){
    int Mirror_opt;
    cout << "Enter an option for Mirror: 1(upper),2(down),3(right),4(left): ";
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

void  doMirrorupforImage (){
    for (int i = SIZE; i >=0 ; i--){
        for (int j = 0; j <SIZE ; j++) {
            image[i][j]=image[SIZE-i][j];
        }
    }
}

void doMirrorleftforImage (){
    for (int i = SIZE; i >=0 ; i--){
        for (int j = 0; j <SIZE ; j++){
            image[i][j]=image[i][SIZE-j];
        }
    }
}

void doMirrorrightforImage (){
    for (int i = 0; i <SIZE; i++){
        for (int j = SIZE; j >=0 ; j--){
            image[i][j]=image[i][SIZE-j];
        }
    }
}

void doMirrordownforImage(){
    for (int i = 0; i <SIZE; i++) {
        for (int j = SIZE; j >= 0; j--){
            image[i][j] = image[SIZE - i][j];
        }
    }
}

void doBlackandWhiteforImage(){
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
void shrink(){
    string dim;
    cout << "Shrink to (1/2), (1/3) or (1/4)?" << endl;
    cin >> dim;
    if(dim == "1/2"){
        for (int i = 0; i <SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
        newImage[i/2][j/2] = (image[i][j] + image[i+1][j] + image[i][j+1] + image[i+1][j+1]) / 4;}
        }
    }
    else if(dim == "1/3"){
        for (int i = 0; i <SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                newImage[i/3][j/3] = (image[i][j] + image[i+1][j] + image[i][j+1] + image[i+1][j+1]) / 4;}
        }

    }
    else{
        for (int i = 0; i <SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                newImage[i/4][j/4] = (image[i][j] + image[i+1][j] + image[i][j+1] + image[i+1][j+1]) / 4;}
        }
    }

}
void blur(){
    for (int i = 0; i <SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            newImage[i][j]=(image[i][j]+image[i][j+1]+image[i][j+2]+image[i+1][j]+image[i+1][j+1]+image[i+1][j+2]+image[i+2][j]+image[i+2][j+1]+image[i+2][j+2])/9;
            }
    }
}
void merge_rgb(){
    for (int i = 0; i <SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k = 0 ; k < RGB;k++){
                newImage_rgb[i][j][k] = (image_rgb[i][j][k] + image2_rgb[i][j][k])/2;

            }

    }
}

}
void lightenDarken_rgb(){
    int ch;
    cout << "Do you want to darken or lighten the image ?" << endl;
    cout << "1-Darken\n2-Lighten: " << endl;
    cin >> ch;
    if(ch == 2){
    for (int i = 0; i <SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k = 0 ; k < RGB;k++){
                newImage_rgb[i][j][k] = 200;
                newImage_rgb[i][j][k] = (newImage_rgb[i][j][k]+image_rgb[i][j][k])/2;


            }

        }
    }
    }
    else if(ch == 1){
        for (int i = 0; i <SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for(int k = 0 ; k < RGB;k++){
                    newImage_rgb[i][j][k] = image_rgb[i][j][k]/2;



                }

            }
        }

    }


}
void shrink_rgb(){

    string dim;
    cout << "Shrink to (1/2), (1/3) or (1/4)?" << endl;
    cin >> dim;
    if(dim == "1/2"){
        for (int i = 0; i <SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for(int k = 0 ; k < RGB;k++){
                    newImage_rgb[i/2][j/2][k] = (image_rgb[i][j][k] + image_rgb[i+1][j][k] + image_rgb[i][j+1][k] +image_rgb[i+1][j+1][k])/4;



                }

            }
        }

    }
    else if(dim == "1/3"){
        for (int i = 0; i <SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for(int k = 0 ; k < RGB;k++){
                    newImage_rgb[i/3][j/3][k] = (image_rgb[i][j][k] + image_rgb[i+1][j][k] + image_rgb[i][j+1][k] +image_rgb[i+1][j+1][k])/4;



                }

            }
        }


    }
    else{
        for (int i = 0; i <SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for(int k = 0 ; k < RGB;k++){
                    newImage_rgb[i/4][j/4][k] = (image_rgb[i][j][k] + image_rgb[i+1][j][k] + image_rgb[i][j+1][k] +image_rgb[i+1][j+1][k])/4;


                }

            }
        }

    }

}
void blur_rgb(){
    for (int i = 0; i <SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k = 0 ; k < RGB;k++){
                newImage_rgb[i][j][k]= (image_rgb[i][j][k]+image_rgb[i][j+1][k]+image_rgb[i][j+2][k]+image_rgb[i+1][j][k]+image_rgb[i+1][j+1][k]+image_rgb[i+1][j+2][k]+image_rgb[i+2][j][k]+image_rgb[i+2][j+1][k]+image_rgb[i+2][j+2][k])/9;


            }

        }
    }

}



