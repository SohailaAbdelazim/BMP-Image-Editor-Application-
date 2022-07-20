
// Last Modification Date: 22/04/2022
// Author1 : Basmala Mohamed Sayed Gad
// Author2 : Sohaila Abdelazim Khalifa
// Author3 : Hend Ahmed Kamal Abd El-Aziem
// Teaching Assistant: Afaf Abdelmonem
/* Purpose: The purpose of this program is to develop different filters that work on RGB images,
you can load an image and apply some changes to image and then save it again.
The 12 filters were done to invert a picture , creating version of its black and white,
merging 2 different images, flipping and rotating images , Darken and Lighten Image by 50% , Detect the edges in an Image ,
Enlarge or shrink Image, Mirroring the Image , Shuffle or blur  Image.*/


#include "bmplib.cpp"
#include <iostream>
#include <cstring>

using namespace std;

unsigned char RGBImage[SIZE][SIZE][RGB];
unsigned char RGBImage2[SIZE][SIZE][RGB];
unsigned char newRGBImage[SIZE][SIZE][RGB];

void loadImage();
void saveImage();
void blackAndWhiteRGBImage();
void invertRGBImage();
void mergeRGBImage();
void FlipImage_Vert();
void FlipImage_Horz();
void DarkRGBImage();
void LightRGBImage();
void RotateImage_90();
void RotateImage_180();
void RotateImage_270();
void detectRGBImageEdges();
void EnlargeRGB(string quarter);
void shrinkRGBImage();
void mirrorRGB_left();
void mirrorRGB_right();
void mirrorRGB_up();
void mirrorRGB_down();
void ShuffleRGB(string order);
void BlurRGBImage();


int main()
{
    string nFilter;
    cout << "Ahlan ya user ya habibi :)" << "\n";
    loadImage();

    while (true)
    {
        cout << "Please select a filter number to apply, s to save or 0 to exit:" << "\n";
        cout << "1- Black & White Filter" << "\n" << "2- Invert Filter" << "\n"
             << "3- Merge Filter" << "\n" << "4- Flip Image" << "\n"
             << "5- Darken and Lighten Image" << "\n" << "6- Rotate Image" << "\n"
             << "7- Detect Image Edges" << "\n" << "8- Enlarge Image" << "\n"
             << "9- Shrink Image" << "\n" <<"a- Mirror 1/2 Image" << "\n"
             << "b- Shuffle Image" << "\n" << "c- Blur Image" << "\n"
             << "s- Save the image to a file" << "\n" << "0- Exit" << "\n";
        cin >> nFilter;

        // make sure that user enter one character.
        while (nFilter.length() > 1)
        {
            cout << "Please enter one choice: " << "\n";
            cin >> nFilter;
        }

        if (nFilter == "1")
        {
            blackAndWhiteRGBImage();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nFilter == "2")
        {
            invertRGBImage();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nFilter == "3")
        {
            mergeRGBImage();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nFilter == "4")
        {
            string flipType;
            cout << "Flip (h)orizontally or (v)ertically ?" << "\n";
            cin >> flipType;

            while (flipType.length() > 1)
            {
                cout << "Please enter one choice: " << "\n";
                cin >> flipType;
            }

            while ((tolower(flipType[0]) != 'h') and (tolower(flipType[0]) != 'v'))
            {
                cout << "Please enter valid choice: " << "\n";
                cin >> flipType;
            }

            if (tolower(flipType[0]) == 'h')
            {
                FlipImage_Horz();
                cout << "Process is done !" << "\n" << "\n";
            }
            else if (tolower(flipType[0]) == 'v')
            {
                FlipImage_Vert();
                cout << "Process is done !" << "\n" << "\n";
            }

        }
        else if (nFilter == "5")
        {
            string choice;
            cout << "Do you want to (d)arken or (l)ighten the image?\n";
            cin >> choice;

            while (choice.length() > 1)
            {
                cout << "Please enter one choice: " << "\n";
                cin >> choice;
            }

            while ((tolower(choice[0]) != 'd') and (tolower(choice[0]) != 'l'))
            {
                cout << "Please enter valid choice: " << "\n";
                cin >> choice;
            }

            if (tolower(choice[0]) == 'd')
            {
                DarkRGBImage();
                cout << "Process is done !" << "\n" << "\n";
            }
            else if (tolower(choice[0]) == 'l')
            {
                LightRGBImage();
                cout << "Process is done !" << "\n" << "\n";
            }
        }
        else if (nFilter == "6")
        {
            string rotationDegree;
            cout << "Rotate (90), (180) or (270) degrees?" << "\n";
            cin >> rotationDegree;

            while ((rotationDegree != "90") and (rotationDegree != "180") and (rotationDegree != "270"))
            {
                cout << "Please enter valid choice: " << "\n";
                cin >> rotationDegree;
            }

            if (rotationDegree == "90")
            {
                RotateImage_90();
                cout << "Process is done !" << "\n" << "\n";
            }
            else if (rotationDegree == "180")
            {
                RotateImage_180();
                cout << "Process is done !" << "\n" << "\n";
            }
            else if (rotationDegree == "270")
            {
                RotateImage_270();
                cout << "Process is done !" << "\n" << "\n";
            }
        }
        else if (nFilter == "7")
        {
            detectRGBImageEdges();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nFilter == "8")
        {
            string nQuarter;
            cout << "Which quarter to enlarge 1, 2, 3 or 4?" << "\n";
            cin >> nQuarter;

            while (nQuarter.length() > 1)
            {
                cout << "Please enter one choice: " << "\n";
                cin >> nQuarter;
            }

            while ((nQuarter != "1") and (nQuarter != "2") and (nQuarter != "3") and (nQuarter != "4"))
            {
                cout << "Please enter valid choice: " << "\n";
                cin >> nQuarter;
            }

            EnlargeRGB(nQuarter);
            cout << "Process is done !" << "\n" << "\n";

        }
        else if (nFilter == "9")
        {
            shrinkRGBImage();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (tolower(nFilter[0]) == 'a')
        {
            string mirrorType;
            cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?" << "\n";
            cin >> mirrorType;

            while (mirrorType.length() > 1)
            {
                cout << "Please enter one choice: " << "\n";
                cin >> mirrorType;
            }

            while ((tolower(mirrorType[0]) != 'l') and (tolower(mirrorType[0]) != 'r') and (tolower(mirrorType[0]) != 'u') and (tolower(mirrorType[0]) != 'd'))
            {
                cout << "Please enter valid choice: " << "\n";
                cin >> mirrorType;
            }

            if (tolower(mirrorType[0]) == 'l')
            {
                mirrorRGB_left();
                cout << "Process is done !" << "\n" << "\n";
            }
            else if (tolower(mirrorType[0]) == 'r')
            {
                mirrorRGB_right();
                cout << "Process is done !" << "\n" << "\n";
            }
            else if (tolower(mirrorType[0]) == 'u')
            {
                mirrorRGB_up();
                cout << "Process is done !" << "\n" << "\n";
            }
            else if (tolower(mirrorType[0]) == 'd')
            {
                mirrorRGB_down();
                cout << "Process is done !" << "\n" << "\n";
            }
        }
        else if (tolower(nFilter[0]) == 'b')
        {
            string quartersOrder;
            cout << "New order of quarters ?" << "\n";
            cin >> quartersOrder;

            while (quartersOrder.length() > 4)
            {
                cout << "Please enter only 4 numbers: " << "\n";
                cin >> quartersOrder;
            }

            ShuffleRGB(quartersOrder);
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (tolower(nFilter[0]) == 'c')
        {
            BlurRGBImage();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (tolower(nFilter[0]) == 's')
        {
            saveImage();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nFilter == "0")
        {
            cout << "Thank you for using this program :)" << "\n";
            break;
        }
        else
        {
            cout << "Please enter valid choice: " << "\n";
            cin >> nFilter;
        }
    }
    return 0;
}


void loadImage(){
    char ImageFileName[100];
    // getting file name of the image
    cout << "Please enter file name of the image to process (without extension): "<<endl;
    cin >> ImageFileName;

    // completing image file path
    strcat(ImageFileName,".bmp");

    // defense if user enter not existing image file name.
    while (readRGBBMP(ImageFileName,RGBImage) == 1)
    {
        cout << "Please enter existing image file name: " << "\n";
        cin >> ImageFileName;
    }
}

void saveImage () {
    char imageFileName[100];

    // getting the new image name to be saved
    cout << "Please enter target file name: " << "\n";
    cin >> imageFileName;

    // completing the image file path
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, RGBImage);
}

void blackAndWhiteRGBImage()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            int grayAverage = 0;

            // convert and reassignment every RGB pixel to its gray degree using this 3 equations.
            grayAverage += (RGBImage[i][j][0] * 0.3);
            grayAverage += (RGBImage[i][j][1] * 0.59);
            grayAverage += (RGBImage[i][j][2] * 0.11);

            RGBImage[i][j][0] = grayAverage;
            RGBImage[i][j][1] = grayAverage;
            RGBImage[i][j][2] = grayAverage;

            // compare every pixel with 127 to determine if this pixel will be black or white.
            if ( RGBImage[i][j][0] > 127)
            {
                RGBImage[i][j][0] = 255;
                RGBImage[i][j][1] = 255;
                RGBImage[i][j][2] = 255;
            } else
            {
                RGBImage[i][j][0] = 0;
                RGBImage[i][j][1] = 0;
                RGBImage[i][j][2] = 0;
            }
        }
    }
}

void invertRGBImage()
{
    for ( int i = 0; i < SIZE; i++)
    {
        for ( int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k)
            {
                // subtract the pixel from 255 to convert it to its invert.
                RGBImage[i][j][k] = (255 - RGBImage[i][j][k]);
            }
        }
    }
}

void mergeRGBImage () {
    //loading the second image file name .
    char imageFileName2[100];
    cout << "Please enter name of image file to merge with: \n";
    cin >> imageFileName2;
    // Add to it .bmp extension and load image
    strcat(imageFileName2, ".bmp");
    readRGBBMP(imageFileName2, RGBImage2);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB ; ++k) {
                // making a newimage and adding to it both of the 2 images , dividing by 2 to take an average so that both appear.
                newRGBImage[i][j][k] = (RGBImage[i][j][k] + RGBImage2[i][j][k]) / 2 ;

            }
        }
    }

    // to make sure that save function will save correct image.
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                RGBImage[i][j][k] = newRGBImage[i][j][k];
            }
        }
    }
}

void FlipImage_Vert() {
    int k = 0;
    int temp;
    // Flip Image Vertically
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (k = 0; k < RGB; k++) {
                temp = RGBImage[i][j][k];
                RGBImage[i][j][k] = RGBImage[j][i][k];
                RGBImage[j][i][k] = temp;
            }
        }
    }
    for (int i =0; i<SIZE; i++){
        for (int j =0; j <(SIZE/2); j++){
            for(k = 0; k < RGB; k++) {
                temp = RGBImage[i][j][k];
                RGBImage[i][j][k] = RGBImage[i][SIZE - 1 - j][k];
                RGBImage[i][SIZE - 1 - j][k] = temp;
            }
        }
    }
}

void FlipImage_Horz(){
    // Flip Image Horizontally
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k = 0; k < RGB; k++) {
                int temp = RGBImage[i][j][k];
                RGBImage[i][j][k] = RGBImage[j][i][k];
                RGBImage[j][i][k] = temp;
            }
        }
    }
    for (int i =0; i<(SIZE/2); i++){
        for (int j =0; j <SIZE; j++){
            for (int k = 0; k < RGB; k++) {
                int temp = RGBImage[i][j][k];
                RGBImage[i][j][k] = RGBImage[SIZE - 1 - i][j][k];
                RGBImage[SIZE - 1 - i][j][k] = temp;
            }
        }
    }
}

void DarkRGBImage(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB ; ++k) {
                // multiplying each pixel by 0.5 to max it to 50% of the pixels.
                newRGBImage[i][j][k] = (RGBImage[i][j][k] * 0.5);
            }
        }
    }

    // to make sure that save function will save correct image.
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                RGBImage[i][j][k] = newRGBImage[i][j][k];
            }
        }
    }
}

void LightRGBImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB ; ++k) {
                if ((RGBImage[i][j][k] * 1.5) > 255) {
                    newRGBImage[i][j][k] = 255;
                }
                else {    // multiplying each pixel by 1.5 to minimize it to 50% of the pixels.
                    newRGBImage[i][j][k] = (RGBImage[i][j][k] * 1.5);
                }

            }
        }
    }

    // to make sure that save function will save correct image.
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                RGBImage[i][j][k] = newRGBImage[i][j][k];
            }
        }
    }
}

void RotateImage_90() {
    // Rotating by 90 degree clockwise
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k = 0; k < RGB; k++) {
                int temp = RGBImage[i][j][k];
                RGBImage[i][j][k] = RGBImage[j][i][k];
                RGBImage[j][i][k] = temp;
            }
        }
    }
    for (int i = 0; i < (SIZE/2); i++) {
        for ( int j =i; j < (SIZE-i-1); j++) {
            for(int k = 0; k < RGB; k++) {
                int temp = RGBImage[i][j][k];
                RGBImage[i][j][k] = RGBImage[SIZE - 1 - j][i][k];
                RGBImage[SIZE - 1 - j][i][k] = RGBImage[SIZE - 1 - i][SIZE - 1 - j][k];
                RGBImage[SIZE - 1 - i][SIZE - 1 - j][k] = RGBImage[j][SIZE - 1 - i][k];
                RGBImage[j][SIZE - 1 - i][k] = temp;
            }
        }
    }
}

void RotateImage_180(){
    // Rotating by 180 degree clockwise
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k = 0; k < RGB; k++) {
                int temp = RGBImage[i][j][k];
                RGBImage[i][j][k] = RGBImage[j][i][k];
                RGBImage[j][i][k] = temp;
            }
        }
    }
    for (int i = 0; i < (SIZE/2); i++) {
        for (int j= 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                int temp = RGBImage[i][j][k];
                RGBImage[i][j][k] = RGBImage[SIZE - i - 1][SIZE - j - 1][k];
                RGBImage[SIZE - i - 1][SIZE - j - 1][k] = temp;
            }
        }
    }
}

void RotateImage_270(){
    // Rotating by 270 degree clockwise
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k =0; k < RGB; k++) {
                int temp = RGBImage[i][j][k];
                RGBImage[i][j][k] = RGBImage[j][i][k];
                RGBImage[j][i][k] = temp;
            }
        }
    }
    for (int i = 0; i < (SIZE/2); i++) {
        for ( int j =i; j < (SIZE-i-1); j++) {
            for(int k =0; k < RGB; k++) {
                int temp = RGBImage[i][j][k];
                RGBImage[i][j][k] = RGBImage[SIZE - 1 - j][i][k];
                RGBImage[SIZE - 1 - j][i][k] = RGBImage[SIZE - 1 - i][SIZE - 1 - j][k];
                RGBImage[SIZE - 1 - i][SIZE - 1 - j][k] = RGBImage[j][SIZE - 1 - i][k];
                RGBImage[j][SIZE - 1 - i][k] = temp;
            }
        }
    }
    for (int i =0; i<SIZE; i++){
        for (int j =0; j <(SIZE/2); j++){
            for(int k =0; k < RGB; k++) {
                int temp = RGBImage[i][j][k];
                RGBImage[i][j][k] = RGBImage[i][SIZE - 1 - j][k];
                RGBImage[i][SIZE - 1 - j][k] = temp;
            }
        }
    }
}

void detectRGBImageEdges()
{
    blackAndWhiteRGBImage();

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                // check if all 4 sides of pixel are the same color to determine if this pixel is edge pixel or not.
                if ((RGBImage[i-1][j][k] == RGBImage[i][j+1][k]) and (RGBImage[i-1][j][k] == RGBImage[i][j-1][k]) and (RGBImage[i-1][j][k] == RGBImage[i+1][j][k]) and (RGBImage[i][j+1][k] == RGBImage[i][j-1][k]) and (RGBImage[i][j+1][k] == RGBImage[i+1][j][k]) and (RGBImage[i+1][j][k] == RGBImage[i][j-1][k]))
                {
                    newRGBImage[i][j][k] = 255;
                }else
                {
                    newRGBImage[i][j][k] = 0;
                }
            }
        }
    }

    // restore newRGBImage in RGBImage as saveRGBImage function saving RGBImage not newRGBImage.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                RGBImage[i][j][k] = newRGBImage[i][j][k];
            }
        }
    }
}

void EnlargeRGB(string quarter)
{
    if (quarter == "1")
    {
        // (i/2) and (j/2) to store every pixel in quarter 1 in 4 pixels in newRGBImage.
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; ++k)
                {
                    newRGBImage[i][j][k] = RGBImage[i/2][j/2][k];
                }
            }
        }
    }
    else if (quarter == "2")
    {
        // (i/2) and ((SIZE/2)+(j/2)) to store every pixel in quarter 2 in 4 pixels in newRGBImage.
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; ++k)
                {
                    newRGBImage[i][j][k] = RGBImage[i/2][(SIZE/2)+(j/2)][k];

                }
            }
        }
    }
    else if (quarter == "3")
    {
        // ((SIZE/2)+(i/2)) and (j/2) to store every pixel in quarter 3 in 4 pixels in newRGBImage.
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; ++k)
                {
                    newRGBImage[i][j][k] = RGBImage[(SIZE/2)+(i/2)][j/2][k];
                }
            }
        }
    }
    else if (quarter == "4")
    {
        // ((SIZE/2)+(i/2)) and ((SIZE/2)+(j/2)) to store every pixel in quarter 4 in 4 pixels in newRGBImage.
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; ++k)
                {
                    newRGBImage[i][j][k] = RGBImage[(SIZE/2)+(i/2)][(SIZE/2)+(j/2)][k];
                }
            }
        }

    }

    // make sure that save function will save correct image.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                RGBImage[i][j][k] = newRGBImage[i][j][k];
            }
        }
    }
}

void shrinkRGBImage() {
    string choice;
    cout << "Shrink to (1/2), (1/3) or (1/4)?\n";
    cin >> choice;
    int x=0 , y=0 , z=0;
    // taking an index of pixel and skipping no.of index by the increment accordingaly to the shrink size.
    if ( choice == "1/2"){
        for (int i = 0; i < SIZE; i+=2) {
            for (int j = 0; j < SIZE; j+=2) {
                for (int k = 0; k < RGB; k++) {
                    newRGBImage[x][y][z] = RGBImage[i][j][k] ;
                    z++;
                }
                z = 0 ;
                y++;
            }
            y = 0 ;
            x++;
        }
    }
    else if ( choice == "1/3"){
        for (int i = 0; i < SIZE; i+=3) {
            for (int j = 0; j < SIZE; j+=3) {
                for (int k = 0; k < RGB; k++) {
                    newRGBImage[x][y][z] = RGBImage[i][j][k] ;
                    z++;
                }
                z = 0 ;
                y++;
            }
            y = 0 ;
            x++;
        }
    }
    else if ( choice == "1/4"){
        for (int i = 0; i < SIZE; i+=4) {
            for (int j = 0; j < SIZE; j+=4) {
                for (int k = 0; k < RGB ; k++) {
                    newRGBImage[x][y][z] = RGBImage[i][j][k] ;
                    z++;
                }
                z = 0 ;
                y++;
            }
            y = 0 ;
            x++;
        }
    }

    // to make sure that save function will save correct image.
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                RGBImage[i][j][k] = newRGBImage[i][j][k];
            }
        }
    }
}

void mirrorRGB_left()
{
    // start the first and second loops form 0 to SIZE and column [SIZE-j] to access the first pixels left.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                RGBImage[i][SIZE-j][k] = RGBImage[i][j][k];
            }
        }
    }
}

void mirrorRGB_right()
{
    // start the first and second loops form SIZE to 0 and column [SIZE-j] to access the last pixels right.
    for (int i = SIZE; i > 0; i--)
    {
        for (int j = SIZE; j > 0; j--)
        {
            for (int k = 0; k < RGB; ++k)
            {
                RGBImage[i][SIZE-j][k] = RGBImage[i][j][k];
            }
        }
    }
}

void mirrorRGB_up()
{
    // start the first and second loops form 0 to SIZE and row [SIZE-i] to access the first pixels up.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                RGBImage[SIZE-i][j][k] = RGBImage[i][j][k];
            }
        }
    }
}

void mirrorRGB_down()
{
    // start the first and second loops form SIZE to 0 and row [SIZE-i] to access the last pixels down.
    for (int i = SIZE; i > 0; i--)
    {
        for (int j = SIZE; j > 0; j--)
        {
            for (int k = 0; k < RGB; ++k)
            {
                RGBImage[SIZE-i][j][k] = RGBImage[i][j][k];
            }
        }
    }
}

void ShuffleRGB(string order)
{
    int row , col , newRow , newCol;

    for (int i = 0; i < order.length(); ++i)
    {
        // row represents row in old quarter and newRow represents row in new quarter.
        row = i < 2 ? 0 : SIZE/2;
        newRow = order[i] < '3' ? 0 : SIZE/2;

        for (int k = newRow; k < (newRow + (SIZE/2)); ++k, ++row)
        {
            // col represents column in old quarter and newCol represents column in new quarter.
            col = (i%2) == 0 ? 0 : SIZE/2;
            newCol = ((order[i] - '0')%2) == 1 ? 0 : SIZE/2;

            for (int j = newCol; j < (newCol + (SIZE/2)); ++j, ++col)
            {
                for (int l = 0; l < RGB; ++l)
                {
                    newRGBImage[row][col][l] = RGBImage[k][j][l];
                }
            }
        }
    }

    // to make sure that save function will save correct image.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                RGBImage[i][j][k] = newRGBImage[i][j][k];

            }
        }
    }
}


void BlurRGBImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB ; k++) { // taking each index of pixel adding them and taking the average of them ny dividing by 9, k is constant as its the RGB
                newRGBImage[i][j][k] = (    RGBImage[i][j][k] + RGBImage[i][j-1][k] + RGBImage[i][j+1][k] // around the pixel e.g the middle.
                                            + RGBImage[i-1][j-1][k] + RGBImage[i-1][j][k] + RGBImage[i-1][j+1][k]   // above the pixel.
                                            + RGBImage[i+1][j-1][k] + RGBImage[i+1][j][k] + RGBImage[i+1][j+1][k]) /9  ; // under the pixel.
            }
        }
    }

    // to make sure that save function will save correct image.
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                RGBImage[i][j][k] = newRGBImage[i][j][k];
            }
        }
    }
}
