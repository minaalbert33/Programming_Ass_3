#include<bits/stdc++.h>
#include"bmplib.cpp"
using namespace std;

// Photos in form of 2d-arrays
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char newImage[SIZE][SIZE];

void load_image ();
void load_image2();
void save_image (unsigned char [][SIZE]);

// Mina
void invert_image ();
void rotate_image ();
void rotate_90 ();

// Seif 
void merge();
void lightenDarken();

// Ziad 
void doBlackandWhiteforImage ();
void doMirrorupforImage ();
void doMirrorleftforImage ();
void doMirrorrightforImage ();
void doMirrordownforImage();
void Mirror();

main(){
    load_image();
    cout << "Ahlan ya user ya habibi\n";
    string choice;
    cout << "1- Black & White Filter\n2- Invert Image\n3- merge filter\n5- Rotate Image\n";
    cout << "6- Darken and Lighten image\n11- Mirror 1/2 Image\n";
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
    }else if(choice == "11"){
        Mirror();
        save_image(image);
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

