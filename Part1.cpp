// #include<iostream>
// #include<string>
// #include<cctype>
// #include<cstring>
// #include<vector>
// #include<map>
// #include<iomanip>
// #include<algorithm>
#include<bits/stdc++.h>
#include"bmplib.cpp"
using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

void load_image ();
void invert_image ();
void rotate_image ();
void save_image ();
void rotate_90 ();

main(){
    load_image();
    string choice;
    cout << "2- Invert Image\n5- Rotate Image\n";
    cout << "Please, select a filter to apply or 0 to exit:";
    cin >> choice;
    if(choice == "1")
        return 0;
    else if(choice == "2"){
        invert_image();
        save_image();
    }else{
        int degree;
        cout << "The Degrees you want to rotate the image: ";
        cin >> degree;
        if(degree == 90)
            rotate_90();
        else if(degree == 180){
            rotate_90();
            rotate_90();
        }else{
            rotate_90();
            rotate_90();
            rotate_90();
        }
        save_image();
    }
}


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

void save_image () {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> file_name;

    // Add to it .bmp extension and load image
    strcat (file_name, ".bmp");
    writeGSBMP(file_name, image);
}

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

