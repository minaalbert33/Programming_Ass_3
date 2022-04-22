// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: CS112-203-2nd – 17 -20210143-20210169-20210417-A3-Part1.cpp
// Last Modification Date: 22/04/2022
// Author1 and ID and Group: Mina Albert Saeed  20210417
// Author2 and ID and Group: Ziad Ahmed Mohamed 20210143
// Author3 and ID and Group: Seif Elden Mahmoud Helmy 20210169
// Teaching Assistant: Eng/ Hager Ali
// Purpose: 12 Filters on Images (Grayscale && RGB)

#include<bits/stdc++.h>
#include"bmplib.cpp"
#include "bmplib.h"
using namespace std;

// Photos in form of 2d-arrays
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char newImage[SIZE][SIZE];
char arr_a[SIZE][SIZE];
char arr_b[SIZE][SIZE];

// photos in form of 3d-arrays (RGB)
unsigned char image_rgb[SIZE][SIZE][RGB];
unsigned char image2_rgb[SIZE][SIZE][RGB];
unsigned char newImage_rgb[SIZE][SIZE][RGB];
unsigned char Newimage_rgb2[SIZE][SIZE][RGB];
char gx_r[SIZE][SIZE][RGB];
char gy_r[SIZE][SIZE][RGB];
char gx_b[SIZE][SIZE][RGB];
char gy_b[SIZE][SIZE][RGB];
char gx_g[SIZE][SIZE][RGB];
char gy_g[SIZE][SIZE][RGB];

// Saving Images Function (grayscale && RGB)
void load_image();
void load_image2();
void save_image(unsigned char [][SIZE]);
void load_image_rgb();
void load_image2_rgb();
void save_image_rgb(unsigned char[][SIZE][RGB]);
void save_image_RGB2();


// Mina's Functions' PROTOTYPES
void invert_image();
void invert_image_rgb();
void rotate_90();
void rotate_90_rgb();
void enlarge();
void enlarge_rgb();
void shuffle();
void shuffle_rgb();

// Seif's Functions' PROTOTYPES
void merge();
void merge_rgb();
void lightenDarken();
void lightenDarken_rgb();
void shrink();
void shrink_rgb();
void blur();
void blur_rgb();


// Ziad's Functions' PROTOTYPES
void doBlackandWhiteforImage ();
void doMirrorupforImage ();
void doMirrorleftforImage ();
void doMirrorrightforImage ();
void doMirrordownforImage();
void Mirror();
void doFlip();
void doFlipHorizontal();
void doFlipVertical();
void detect_image();
void Flip_RGB();
void FlipHorizontal_RGB();
void FlipVertical_RGB();
void Mirror_RGB();
void MirrorupforImage_RGB();
void MirrordownforImage_RGB();
void MirrorrightforImage_RGB();
void MirrorleftforImage_RGB();
void BlackandWhiteforImage_RGB();
void detect_rgb();

int main() {
    // Asking the user which to process a Grayscale image or RGB image
    string choice1;
    cout << "Ahlan ya user ya habibi\n1- Grayscale images\n2- RGB images" << endl;
    cout << "Enter 1 or 2, please: ";
    cin >> choice1;
    // Looping till getting a right input.
    while (choice1 != "1" && choice1 != "2") {
        cout << "--------------------------" << endl;
        cout << "Sorry, Invalid Choice!" << endl;
        cout << "--------------------------" << endl;
        cout << "Enter 1 or 2, please: ";
        cin >> choice1;
    }
    if (choice1 == "1") {
        load_image();
        string choice;
        cout << "1- Black & White Filter\n2- Invert Image\n3- Merge filter\n4- Flip Filter\n5- Rotate Image\n";
        cout << "6- Darken and Lighten image\n7- Detect Image Edges filter\n8- Enlarge Filter\n9- Shrink Filter";
        cout << "\na- Mirror 1/2 Image\nb- Shuffle Filter\nc- Blur Filter\n";
        cout << "Please, select a filter to apply or 0 to exit:";
        cin >> choice;
        if (choice == "0") {
            return 0;
        }
        else if (choice == "1") {
            doBlackandWhiteforImage();
            save_image(image);
        }
        else if (choice == "2") {
            invert_image();
            save_image(image);
        }
        else if (choice == "3") {
            load_image2();
            merge();
            save_image(newImage);
        }
        else if(choice == "4"){
            doFlip();
            save_image(newImage);
        }
        else if (choice == "5") {
            int degree;
            cout << "Enter the degree you want to rotate by: ";
            cin >> degree;
            if (degree == 90) {
                rotate_90();
                save_image(image);
            }
            else if (degree == 180) {
                rotate_90();
                rotate_90();
                save_image(image);
            }
            else {
                rotate_90();
                rotate_90();
                rotate_90();
                save_image(image);
            }
        }
        else if (choice == "6") {
            lightenDarken();
            save_image(newImage);
        }
        else if(choice == "7"){
            detect_image();
            save_image(image);
        }
        else if (choice == "8") {
            enlarge();
            save_image(newImage);
        }
        else if (choice == "9") {
            shrink();
            save_image(newImage);
        }
        else if (choice == "a") {
            Mirror();
            save_image(image);
        }
        else if (choice == "b") {
            shuffle();
            save_image(newImage);
        }
        else if (choice == "c") {
            blur();
            save_image(newImage);
        }
        
    }
    else if (choice1 == "2") {
        string choice;
        load_image_rgb();
        cout << "1- Black & White Filter\n2- Invert Image\n3- Merge filter\n4- Flip Filter\n5- Rotate Image\n";
        cout << "6- Darken and Lighten image\n7- Detect Image Edges filter\n8- Enlarge Filter\n9- Shrink Filter";
        cout << "\na- Mirror 1/2 Image\nb- Shuffle Filter\nc- Blur Filter\n";
        cout << "Please, select a filter to apply or 0 to exit:";
        cin >> choice;
        if (choice == "0") {
            return 0;
        }
        else if (choice == "1") {
            BlackandWhiteforImage_RGB();
            save_image(image);
        }
        else if (choice == "2") {
            invert_image_rgb();
            save_image_rgb(image_rgb);
        }
        else if (choice == "3") {
            load_image2_rgb();
            merge_rgb();
            save_image_rgb(newImage_rgb);
        }else if (choice == "4") {
            Flip_RGB();
            save_image_rgb(newImage_rgb);
        }
        else if (choice == "5") {
            int degree;
            cout << "Enter the degree you want to rotate by: ";
            cin >> degree;
            if (degree == 90) {
                rotate_90_rgb();
                save_image_rgb(image_rgb);
            }
            else if (degree == 180) {
                rotate_90_rgb();
                rotate_90_rgb();
                save_image_rgb(image_rgb);
            }
            else {
                rotate_90_rgb();
                rotate_90_rgb();
                rotate_90_rgb();
                save_image_rgb(image_rgb);
            }
        }
        else if (choice == "6") {
            lightenDarken_rgb();
            save_image_rgb(newImage_rgb);
        }else if(choice == "7"){
            detect_rgb();
            save_image_rgb(newImage_rgb);
        }
        else if (choice == "8") {
            enlarge_rgb();
            save_image_rgb(newImage_rgb);
        }
        else if (choice == "9") {
            shrink_rgb();
            save_image_rgb(newImage_rgb);
        }
        else if (choice == "a") {
            Mirror_RGB();
            save_image_rgb(image_rgb);
        }
        else if (choice == "b") {
            shuffle_rgb();
            save_image_rgb(newImage_rgb);
        }
        else if (choice == "c") {
            blur_rgb();
            save_image_rgb(newImage_rgb);
        }

    }
}

// function to load image from user.
void load_image() {
    char file_name[100];

    // Get gray scale image file name
    cout << "Please, Enter file name of the image to process: ";
    cin >> file_name;

    // Add to it .bmp extension and load image
    strcat(file_name , ".bmp");
    readGSBMP(file_name , image);
}
void load_image_rgb() {
    char file_name[100];

    // Get gray scale image file name
    cout << "Please, Enter file name of the image to process: ";
    cin >> file_name;

    // Add to it .bmp extension and load image
    strcat(file_name , ".bmp");
    readRGBBMP(file_name , image_rgb);
}

// Inverting image(gray)
void invert_image() {
    // Applying Bitwise NOT on the pixel to get the opposite value.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = ~image[i][j];
        }
    }
}

// Inverting image(rgb)
void invert_image_rgb() {
    // Applying Bitwise NOT on the pixel to get the opposite value.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                image_rgb[i][j][k] = ~image_rgb[i][j][k];
            }
        }
    }
}

// Saving Image to the desired file.
void save_image(unsigned char image_name[][SIZE]) {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> file_name;

    // Add to it .bmp extension and load image
    strcat(file_name , ".bmp");
    writeGSBMP(file_name , image_name);
}
void save_image_rgb(unsigned char rgb_image[][SIZE][RGB]) {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> file_name;

    // Add to it .bmp extension and load image
    strcat(file_name , ".bmp");
    writeRGBBMP(file_name , rgb_image);
}

// Function to rotate image 90 degrees(gray).
void rotate_90() {

    // Transposing our matrix (making the rows columns and the columns rows).
    for (int i = 0; i < SIZE; i++) {
        for (int j = i; j < SIZE; j++) {
            swap(image[i][j] , image[j][i]);
        }
    }

    // Swapping the columns
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < (SIZE / 2); j++) {
            swap(image[i][j] , image[i][SIZE - 1 - j]);
        }
    }
}

// Function to rotate image 90 degrees(rgb).
void rotate_90_rgb() {

    // Transposing our matrix (making the rows columns and the columns rows).
    for (int i = 0; i < SIZE; i++) {
        for (int j = i; j < SIZE; j++) {
            for (int k = 0; k < RGB;k++) {
                swap(image_rgb[i][j][k] , image_rgb[j][i][k]);
            }
        }
    }

    // Swapping the columns
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < (SIZE / 2); j++) {
            for (int k = 0; k < RGB; k++) {
                swap(image_rgb[i][j][k] , image_rgb[i][SIZE - 1 - j][k]);
            }
        }
    }
}


// Function to load image2.
void load_image2() {
    char  imageFileName2[100];
    cout << "Enter the second source file name: ";
    cin >> imageFileName2;
    strcat(imageFileName2 , ".bmp");
    readGSBMP(imageFileName2 , image2);
}
void load_image2_rgb() {
    char  imageFileName2[100];
    cout << "Enter the second source file name: ";
    cin >> imageFileName2;
    strcat(imageFileName2 , ".bmp");
    readRGBBMP(imageFileName2 , image2_rgb);
}

// Merging two photos together.
void merge() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            //getting the avg for all pixels in the first image and second image
            newImage[i][j] = (image[i][j] + image2[i][j]) / 2;
        }
    }
}
void merge_rgb() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // adding third index to get RGB
            for (int k = 0; k < RGB;k++) {
                //getting the avg for all pixels in the first image and second image
                newImage_rgb[i][j][k] = (image_rgb[i][j][k] + image2_rgb[i][j][k]) / 2;
            }
        }
    }

}

// Function to either lighten or darken an image.
void lightenDarken() {
    int ch;
    cout << "Do you want to darken or lighten the image ?" << endl;
    cout << "1-Darken\n2-Lighten: " << endl;
    cin >> ch;
    if (ch == 1) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // divide the total pixels in the image by 2 to dark it
                newImage[i][j] = image[i][j] / 2;
            }
        }
    }
    else if (ch == 2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // get the image grayed by 200 and merge it with the real image
                newImage[i][j] = 200;
                newImage[i][j] = (newImage[i][j] + image[i][j]) / 2;
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
                    // get the image grayed by 200 and merge it with the real image.
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
                    // divide the total pixels in the image by 2 to dark it.
                    newImage_rgb[i][j][k] = image_rgb[i][j][k]/2;
                }
            }
        }
    }
}
void shrink() {
    string dim;
    cout << "Shrink to (1/2), (1/3) or (1/4)?" << endl;
    cin >> dim;
    if (dim == "1/2") {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // getting the avg of matrix 4 * 4 and divide every pixel by 2 to get the photo shrinked by 1/2
                newImage[i / 2][j / 2] = (image[i][j] + image[i + 1][j] + image[i][j + 1] + image[i + 1][j + 1]) / 4;
            }
        }
    }
    else if (dim == "1/3") {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // getting the avg of matrix 4 * 4 and divide every pixel by 3 to get the photo shrinked by 1/3
                newImage[i / 3][j / 3] = (image[i][j] + image[i + 1][j] + image[i][j + 1] + image[i + 1][j + 1]) / 4;
            }
        }

    }
    else {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // getting the avg of matrix 4 * 4 and divide every pixel by 4 to get the photo shrinked by 1/4
                newImage[i / 4][j / 4] = (image[i][j] + image[i + 1][j] + image[i][j + 1] + image[i + 1][j + 1]) / 4;
            }
        }
    }
}
void shrink_rgb() {
    string dim;
    cout << "Shrink to (1/2), (1/3) or (1/4)?" << endl;
    cin >> dim;
    if (dim == "1/2") {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // adding third index to get RGB
                for (int k = 0; k < RGB;k++) {
                    // getting the avg of matrix 4 * 4 and divide every pixel by 2 to get the photo shrinked by 1/2
                    newImage_rgb[i / 2][j / 2][k] = (image_rgb[i][j][k] + image_rgb[i + 1][j][k] + image_rgb[i][j + 1][k] + image_rgb[i + 1][j + 1][k]) / 4;
                }
            }
        }
    }
    else if (dim == "1/3") {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB;k++) {
                    // getting the avg of matrix 4 * 4 and divide every pixel by 3 to get the photo shrinked by 1/3

                    newImage_rgb[i / 3][j / 3][k] = (image_rgb[i][j][k] + image_rgb[i + 1][j][k] + image_rgb[i][j + 1][k] + image_rgb[i + 1][j + 1][k]) / 4;
                }
            }
        }

    }
    else {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB;k++) {
                    // getting the avg of matrix 4 * 4 and divide every pixel by 4 to get the photo shrinked by 1/4

                    newImage_rgb[i / 4][j / 4][k] = (image_rgb[i][j][k] + image_rgb[i + 1][j][k] + image_rgb[i][j + 1][k] + image_rgb[i + 1][j + 1][k]) / 4;
                }
            }
        }
    }
}
void blur() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // getting the avg for a matrix in the image with 5 rows and 5 cols to blur the image
            newImage[i][j]=(image[i][j]+image[i][j+1]+image[i][j+2]+image[i][j+3]
                            +image[i][j+4]+image[i+1][j]+image[i+1][j+1]+image[i+1][j+2]+image[i+1][j+3]
                            +image[i+1][j+4]+image[i+2][j]+image[i+2][j+1]+image[i+2][j+2]+image[i+2][j+3]
                            +image[i+2][j+4]+image[i+3][j]+image[i+3][j+1]+image[i+3][j+2]+image[i+3][j+3]
                            +image[i+4][j]+image[i+4][j+1]+image[i+4][j+2]+image[i+4][j+3]+image[i+4][j+4])/25;
        }
    }
}
void blur_rgb() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // adding third index to get RGB
            for (int k = 0; k < RGB;k++) {
                // getting the avg for a matrix in the image with 5 rows and 5 cols to blur the image
                newImage_rgb[i][j][k]=(image_rgb[i][j][k]+image_rgb[i][j+1][k]
                                       +image_rgb[i][j+2][k]+image_rgb[i][j+3][k]+image_rgb[i][j+4][k]
                                       +image_rgb[i+1][j][k]+image_rgb[i+1][j+1][k]+image_rgb[i+1][j+2][k]
                                       +image_rgb[i+1][j+3][k]+image_rgb[i+1][j+4][k]+image_rgb[i+2][j][k]
                                       +image_rgb[i+2][j+1][k]+image_rgb[i+2][j+2][k]+image_rgb[i+2][j+3][k]
                                       +image_rgb[i+2][j+4][k]+image_rgb[i+3][j][k]+image_rgb[i+3][j+1][k]
                                       +image_rgb[i+3][j+2][k]+image_rgb[i+3][j+3][k]+image_rgb[i+4][j][k]
                                       +image_rgb[i+4][j+1][k]+image_rgb[i+4][j+2][k]+image_rgb[i+4][j+3][k]
                                       +image_rgb[i+4][j+4][k])/25;
            }
        }
    }
}
void Mirror() {
    int Mirror_opt;
    cout << "Enter an option for Mirror: 1(upper),2(down),3(right),4(left): ";
    cin >> Mirror_opt;
    if (Mirror_opt == 1)
        doMirrorupforImage();
    else if (Mirror_opt == 2)
        doMirrordownforImage();
    else if (Mirror_opt == 3)
        doMirrorrightforImage();
    else if (Mirror_opt == 4)
        doMirrorleftforImage();
    else
        cout << " Invalid input " << endl;
}

void Mirror_RGB(){
    int Mirror_opt;
    cout << "Enter an option for Mirror: 1(upper),2(down),3(right),4(left): ";
    cin >> Mirror_opt;
    if (Mirror_opt==1)
        MirrorupforImage_RGB();
    else if (Mirror_opt==2)
        MirrordownforImage_RGB();
    else if (Mirror_opt==3)
        MirrorrightforImage_RGB();
    else if (Mirror_opt==4)
        MirrorleftforImage_RGB();
    else
        cout << " Invalid input " << endl;
}
void MirrorupforImage_RGB(){
    for (int i = SIZE; i >=0 ; i--){
        for (int j = 0; j <SIZE ; j++) {
            for (int k = 0; k < RGB ; k++) {
                image_rgb[i][j][k]=image_rgb[SIZE-i][j][k];
            }
        }
    }
}
void  MirrordownforImage_RGB() {
    for (int i = 0; i <SIZE; i++) {
        for (int j = SIZE; j >= 0; j--){
            for (int k = 0; k < RGB ; k++)
            {
                image_rgb[i][j][k] = image_rgb[SIZE - i][j][k];
            }
        }
    }
}
void MirrorrightforImage_RGB(){
    for (int i = 0; i <SIZE; i++){
        for (int j = SIZE; j >=0 ; j--){
            for (int k = 0; k < RGB ; k++)
            {
                image_rgb[i][j][k]=image_rgb[i][SIZE-j][k];
            }

        }
    }
}
void MirrorleftforImage_RGB(){
    for (int i = SIZE; i >=0 ; i--){
        for (int j = 0; j <SIZE ; j++){
            for (int k = 0; k < RGB ; k++)
            {
                image_rgb[i][j][k]=image_rgb[i][SIZE-j][k];
            }
        }
    }

}

void BlackandWhiteforImage_RGB(){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int sum = 0;
            for (int k = 0; k < 3; k++)
            {
                sum += image_rgb[i][j][k];
            }
            sum = sum / 3;
            image[i][j] = sum;
        }
    }
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

void doFlip() {
    int choice;
    cout << "Enter a choice for flip 1 to horizontal flip and 2 to vertical flip " << endl ;
    cin >> choice;
    if (choice == 1) {
        doFlipHorizontal();
    } else if (choice == 2) {
        doFlipVertical();
    } else
        cout << "choice is out of limit " << endl;
}

void Flip_RGB(){
    int choice0;
    cout << " choose filter RGB for flip 1 for Horizontal 2 for Vertical " << endl;
    cin >> choice0 ;
    if (choice0==1){
        FlipHorizontal_RGB();
    }
    else if (choice0==2){
        FlipVertical_RGB();
    }
    else
        cout << "Invalid input " << endl;

}
void FlipHorizontal_RGB(){
    for (int i = 0; i < SIZE ; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB ; k++)
            {
                newImage_rgb[i][j][k]=image_rgb[i][SIZE-j-1][k];
            }
        }

    }

}
void FlipVertical_RGB(){
    for (int i = 0; i < SIZE ; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB ; k++)
            {
                newImage_rgb[i][j][k]=image_rgb[SIZE-i-1][j][k];
            }
        }

    }

}

void doFlipHorizontal(){
    for (int i = 0; i < SIZE ; i++) {
        for (int j = 0; j < SIZE; j++)
        {
            newImage[i][j]=image[i][SIZE-j-1];
        }
    }
}
void doFlipVertical(){
    for (int i = 0; i < SIZE ; i++)
    {
        for (int j = 0; j < SIZE ; j++)
        {
            newImage[i][j]=image[SIZE-i-1][j];
        }
    }
}
void detect_image(){
    for (int i = 1 ; i < SIZE - 1  ; i++)
    {
        for (int j = 1 ; j < SIZE - 1  ; j++ )
        {
          arr_a[i][j]=(image[i-1][j-1]*1)+(image[i][j-1]*2)+(image[i+1][j-1]*1)+(image[i-1][j+1]*-1)+(image[i][j+1]*-2)+(image[i+1][j+1]*-1);
        }
    }
    for (int i = 1 ; i < SIZE - 1 ; i++)
    {
        for (int j = 1 ; j < SIZE - 1 ; ++j )
        {
         arr_b[i][j]=(image[i-1][j-1]*-1)+(image[i-1][j]*-2)+(image[i-1][j+1]*-1)+(image[i+1][j-1]*1)+(image[i+1][j]*2)+(image[i+1][j+1]*1);
        }
    }
    for (int i = 1 ; i < SIZE - 1  ; i++)
    {
        for (int j = 1 ; j < SIZE - 1 ; j++ )
        {
         image[i][j]=sqrt(pow(arr_a[i][j],2)+ pow(arr_b[i][j],2));
        }
    }
    invert_image();
}

void detect_rgb() {
        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                gx_r[i][j][0] = (image_rgb[i - 1][j - 1][0] * 1) + (image_rgb[i][j - 1][0] * 2) +
                                (image_rgb[i + 1][j - 1][0] * 1) + (image_rgb[i - 1][j + 1][0] * -1) +
                                (image_rgb[i][j + 1][0] * -2) + (image_rgb[i + 1][j + 1][0] * -1);
                gx_g[i][j][1] = (image_rgb[i - 1][j - 1][1] * 1) + (image_rgb[i][j - 1][1] * 2) +
                                (image_rgb[i + 1][j - 1][1] * 1) + (image_rgb[i - 1][j + 1][1] * -1) +
                                (image_rgb[i][j + 1][1] * -2) + (image_rgb[i + 1][j + 1][1] * -1);
                gx_b[i][j][2] = (image_rgb[i - 1][j - 1][2] * 1) + (image_rgb[i][j - 1][2] * 2) +
                                (image_rgb[i + 1][j - 1][2] * 1) + (image_rgb[i - 1][j + 1][2] * -1) +
                                (image_rgb[i][j + 1][2] * -2) + (image_rgb[i + 1][j + 1][2] * -1);

            }
        }
        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; ++j) {
                gy_r[i][j][0] = (image_rgb[i - 1][j - 1][0] * 1) + (image_rgb[i][j - 1][0] * 2) +
                                (image_rgb[i + 1][j - 1][0] * 1) + (image_rgb[i - 1][j + 1][0] * -1) +
                                (image_rgb[i][j + 1][0] * -2) + (image_rgb[i + 1][j + 1][0] * -1);
                gy_g[i][j][1] = (image_rgb[i - 1][j - 1][1] * 1) + (image_rgb[i][j - 1][1] * 2) +
                                (image_rgb[i + 1][j - 1][1] * 1) + (image_rgb[i - 1][j + 1][1] * -1) +
                                (image_rgb[i][j + 1][1] * -2) + (image_rgb[i + 1][j + 1][1] * -1);
                gy_b[i][j][2] = (image_rgb[i - 1][j - 1][2] * 1) + (image_rgb[i][j - 1][2] * 2) +
                                (image_rgb[i + 1][j - 1][2] * 1) + (image_rgb[i - 1][j + 1][2] * -1) +
                                (image_rgb[i][j + 1][2] * -2) + (image_rgb[i + 1][j + 1][2] * -1);
            }
        }
        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                newImage_rgb[i][j][0] = sqrt(pow(gx_r[i][j][0], 2) + pow(gy_r[i][j][0], 2));
                newImage_rgb[i][j][1] = sqrt(pow(gx_g[i][j][1], 2) + pow(gy_g[i][j][1], 2));
                newImage_rgb[i][j][2] = sqrt(pow(gx_b[i][j][2], 2) + pow(gy_b[i][j][2], 2));
            }
        }
        invert_image();
    }
void  doMirrorupforImage() {
    for (int i = SIZE; i >= 0; i--) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = image[SIZE - i][j];
        }
    }
}

void doMirrorleftforImage() {
    for (int i = SIZE; i >= 0; i--) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = image[i][SIZE - j];
        }
    }
}

void doMirrorrightforImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE; j >= 0; j--) {
            image[i][j] = image[i][SIZE - j];
        }
    }
}

void doMirrordownforImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE; j >= 0; j--) {
            image[i][j] = image[SIZE - i][j];
        }
    }
}

void doBlackandWhiteforImage() {
    long avg = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            avg += image[i][j];
        }
    }
    avg /= (SIZE * SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > avg)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}

// // Function to enlarge a selected quarter(gray).
void enlarge() {
    string quarter;
    cout << "Enter the number of the Quarter to enlarge(1,2,3,4): ";
    cin >> quarter;

    // Setting the start and the end of our two pointers to scan the desired quarter.
    int i_start = 0 , i_end = SIZE / 2 , j_start = 0 , j_end = SIZE / 2;
    if (quarter == "2") {
        j_start = SIZE / 2;
        j_end = SIZE;
    }
    else if (quarter == "3") {
        i_start = SIZE / 2;
        i_end = SIZE;
    }
    else {
        i_start = j_start = SIZE / 2;
        i_end = j_end = SIZE;
    }

    // Using two pointers approach to traverse the selected quarter.
    // i --> to traverse the rows, j --> to traverse the coulmns
    for (int i = i_start , new_i = 0; i < i_end; i++ , new_i += 2) {
        for (int j = j_start , new_j = 0; j < j_end; j++ , new_j += 2) {
            // Putting every pixel in our image four times in our new image in shape of 2x2 square.
            // Assuming that '$' represent the pixel
            // $$
            // $$
            newImage[new_i][new_j] = image[i][j];
            newImage[new_i + 1][new_j] = image[i][j];
            newImage[new_i][new_j + 1] = image[i][j];
            newImage[new_i + 1][new_j + 1] = image[i][j];
        }
    }
}

// Function to enlarge a selected quarter(rgb).
void enlarge_rgb() {
    string quarter;
    cout << "Enter the number of the Quarter to enlarge(1,2,3,4): ";
    cin >> quarter;

    // Setting the start and the end of our two pointers to scan the desired quarter.
    int i_start = 0 , i_end = SIZE / 2 , j_start = 0 , j_end = SIZE / 2;
    if (quarter == "2") {
        j_start = SIZE / 2;
        j_end = SIZE;
    }
    else if (quarter == "3") {
        i_start = SIZE / 2;
        i_end = SIZE;
    }
    else {
        i_start = j_start = SIZE / 2;
        i_end = j_end = SIZE;
    }

    // Using two pointers approach to traverse the selected quarter.
    // i --> to traverse the rows, j --> to traverse the coulmns.
    for (int i = i_start , new_i = 0; i < i_end; i++ , new_i += 2) {
        for (int j = j_start , new_j = 0; j < j_end; j++ , new_j += 2) {
            for (int k = 0; k < RGB; k++) {
                // Putting every pixel in our image four times in our new image in shape of 2x2 square.
                // Assuming that '$' represent the pixel.
                // $$
                // $$
                newImage_rgb[new_i][new_j][k] = image_rgb[i][j][k];
                newImage_rgb[new_i + 1][new_j][k] = image_rgb[i][j][k];
                newImage_rgb[new_i][new_j + 1][k] = image_rgb[i][j][k];
                newImage_rgb[new_i + 1][new_j + 1][k] = image_rgb[i][j][k];
            }
        }
    }
}

// Function to shuffle an image(gray).
void shuffle() {
    string shuffle_order;

    // Looping till the user enter a valid shuffle order.
    while (true) {
        // Getting the Wanted order of the quarters
        cout << "Enter the shuffle order like 1 2 3 4: ";
        getline(cin >> ws , shuffle_order);

        // Removing spaces from shuffle_order string
        shuffle_order.erase(remove(shuffle_order.begin() , shuffle_order.end() , ' ') , shuffle_order.end());

        // Checking the validity of the input using regex pattern.
        regex valid_order("[1-4]+[1-4]+[1-4]+[1-4]");
        bool is_valid_order = regex_match(shuffle_order , valid_order);
        if (!is_valid_order) {
            cout << "Not A valid shuffle order." << endl;
        }else{
            break;
        }
    }
    // Declaration of the start and the end of our pointers to scan the selected quarter.

    // j && k to traverse the quarter from the original image.
    // j --> to scan rows && k --> to scan columns.

    // new_j && new_k to traverse the quarter of the new image.
    // new_j --> to traverse the rows && new_k --> to traverse the columns.

    int j_start , j_end , k_start , k_end , new_j_start , new_k_start;

    // Looping through shuffle_order to get the quarters.
    // And setting the start and the end of every pointer.
    for (int i = 0; i < 4; i++) {

        // If the charcter is 1 then 
        // we want to scan quarter 1 form the original image.
        if (shuffle_order[i] == '1') {
            j_start = k_start = 0;
            k_end = j_end = SIZE / 2;
        }

            // If the charcter is 2 then we will
            // we want to scan quarter 2 form the original image.
        else if (shuffle_order[i] == '2') {
            j_start = 0; j_end = SIZE / 2; k_start = SIZE / 2; k_end = SIZE;

            // If the charcter is 3 then we will
            // we want to scan quarter 4 form the original image.
        }
        else if (shuffle_order[i] == '3') {
            j_start = SIZE / 2; j_end = SIZE;
            k_start = 0; k_end = SIZE / 2;

            // If the charcter is 4 then we will
            // we will load quarter 4 form the original image.
        }
        else {
            j_start = k_start = SIZE / 2; j_end = k_end = SIZE;
        }

        // Note that i starts from 0 not 1.
        // If i == 0, we will scan quarter 1 of new image.
        if (i == 0) {
            new_j_start = new_k_start = 0;
        }

            // If i == 1, we will scan quarter 2 of new image.
        else if (i == 1) {
            new_j_start = 0; new_k_start = SIZE / 2;
        }

            // If i == 2, we will scan quarter 3 of new image.
        else if (i == 2) {
            new_j_start = SIZE / 2; new_k_start = 0;
        }

            // If i == 3, we will scan quarter 4 of new image.
        else {
            new_j_start = SIZE / 2; new_k_start = SIZE / 2;
        }

        // This for loop will read from the original image by
        // two pointers : j && k
        // And write in the new image by:
        // two pointers: new_j && new_k
        for (int j = j_start , new_j = new_j_start; j < j_end; j++ , new_j++) {
            for (int k = k_start , new_k = new_k_start; k < k_end; k++ , new_k++) {
                newImage[new_j][new_k] = image[j][k];
            }
        }
    }
}

// Function to shuffle an image(rgb).
void shuffle_rgb() {

    string shuffle_order;
    // Looping till the user enter a valid shuffle order.
    while (true) {
        // Getting the Wanted order of the quarters
        cout << "Enter the shuffle order like 1 2 3 4: ";
        getline(cin >> ws, shuffle_order);

        // Removing spaces from shuffle_order string
        shuffle_order.erase(remove(shuffle_order.begin(), shuffle_order.end(), ' '), shuffle_order.end());

        regex valid_order("[1-4]+[1-4]+[1-4]+[1-4]");
        bool is_valid_order = regex_match(shuffle_order, valid_order);
        if (!is_valid_order) {
            cout << "Not A valid shuffle order." << endl;
        } else {
            break;
        }
    }

    // Declaration of the start and the end of our pointers to scan the selected quarter.
    // j && k to traverse the quarter from the original image.
    // j --> to scan rows && k --> to scan columns.
    // new_j && new_k to traverse the quarter of the new image.
    // new_j --> to traverse the rows && new_k --> to traverse the columns.

    int j_start, j_end, k_start, k_end, new_j_start, new_k_start;

    // Looping through shuffle_order to get the quarters.
    // And setting the start and the end of every pointer.
    for (int i = 0; i < 4; i++) {

        // If the charcter is 1 then we will
        // we want to scan quarter 1 form the original image.
        if (shuffle_order[i] == '1') {
            j_start = k_start = 0;
            k_end = j_end = SIZE / 2;
        }

            // If the charcter is 2 then we will
            // we want to scan quarter 2 form the original image.
        else if (shuffle_order[i] == '2') {
            j_start = 0;
            j_end = SIZE / 2;
            k_start = SIZE / 2;
            k_end = SIZE;

            // If the charcter is 3 then we will
            // we want to scan quarter 4 form the original image.
        } else if (shuffle_order[i] == '3') {
            j_start = SIZE / 2;
            j_end = SIZE;
            k_start = 0;
            k_end = SIZE / 2;

            // If the charcter is 4 then we will
            // we will load quarter 4 form the original image.
        } else {
            j_start = k_start = SIZE / 2;
            j_end = k_end = SIZE;
        }

        // Note that i starts from 0 not 1.
        // If i == 0, we will scan quarter 1 of new image.
        if (i == 0) {
            new_j_start = new_k_start = 0;
        }

            // If i == 1, we will scan quarter 2 of new image.
        else if (i == 1) {
            new_j_start = 0;
            new_k_start = SIZE / 2;
        }

            // If i == 2, we will scan quarter 3 of new image.
        else if (i == 2) {
            new_j_start = SIZE / 2;
            new_k_start = 0;
        }

            // If i == 3, we will scan quarter 4 of new image.
        else {
            new_j_start = SIZE / 2;
            new_k_start = SIZE / 2;
        }

        // This for loop will read from the original image by
        // two pointers : j && k
        // And write in the new image by:
        // two pointers: new_j && new_k
        for (int j = j_start, new_j = new_j_start; j < j_end; j++, new_j++) {
            for (int k = k_start, new_k = new_k_start; k < k_end; k++, new_k++) {
                for (int l = 0; l < RGB; l++) {
                    newImage_rgb[new_j][new_k][l] = image_rgb[j][k][l];
                }
            }
        }
    }
}
