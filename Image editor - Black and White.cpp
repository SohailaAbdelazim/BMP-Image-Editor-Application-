
// Last Modification Date: 22/04/2022
// Author1 : Sohaila Abdelazim Khalifa
// Author2 : Basmala Mohamed Sayed Gad
// Author3 : Hend Ahmed Kamal Abd El-Aziem
/* Purpose: The purpose of this program is to develop different filters that work on bitmap images,
you can load an image and apply some changes to image and then save it again.
The 12 filters were done to invert a picture , creating version of its black and white,
merging 2 different images, flipping and rotating images , Darken and Lighten Image by 50% , Detect the edges in an Image ,
Enlarge or shrink Image, Mirroring the Image , Shuffle or blur  Image.*/

#include "bmplib.cpp"
#include <iostream>
#include <cstring>

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char newImage[SIZE][SIZE];

void loadImage();
void saveImage();
void blackAndWhite();
void invertImage();
void mergeImage();
void FlipImage_Horz();
void FlipImage_Vert();
void darkenImage();
void lightenImage();
void RotateImage_90();
void RotateImage_180();
void RotateImage_270();
void detectImageEdges();
void Enlarge(string quarter);
void shrinkImage();
void mirror_left();
void mirror_right();
void mirror_up();
void mirror_down();
void Shuffle(string order);
void BlurImage();


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
            blackAndWhite();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nFilter == "2")
        {
            invertImage();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nFilter == "3")
        {
            mergeImage();
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
                darkenImage();
                cout << "Process is done !" << "\n" << "\n";
            }
            else if (tolower(choice[0]) == 'l')
            {
                lightenImage();
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
            detectImageEdges();
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

            Enlarge(nQuarter);

            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nFilter == "9")
        {
            shrinkImage();
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
                mirror_left();
                cout << "Process is done !" << "\n" << "\n";
            }
            else if (tolower(mirrorType[0]) == 'r')
            {
                mirror_right();
                cout << "Process is done !" << "\n" << "\n";
            }
            else if (tolower(mirrorType[0]) == 'u')
            {
                mirror_up();
                cout << "Process is done !" << "\n" << "\n";
            }
            else if (tolower(mirrorType[0]) == 'd')
            {
                mirror_down();
                cout << "Process is done !" << "\n" << "\n";
            }
        }
        else if (tolower(nFilter[0]) == 'b')
        {
            string newOrder;
            cout << "New order of quarters ?" << "\n";
            cin >> newOrder;

            while (newOrder.length() > 4)
            {
                cout << "Please enter only 4 numbers: " << "\n";
                cin >> newOrder;
            }

            Shuffle(newOrder);
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (tolower(nFilter[0]) == 'c')
        {
            BlurImage();
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
    cout << "Please enter file name of the image to process (without extension): " << endl;
    cin >> ImageFileName;

    // completing image file path
    strcat(ImageFileName,".bmp");

    // defense if user enter not existing image file name.
    while (readGSBMP(ImageFileName,image) == 1)
    {
        cout << "Please enter existing image file name: " << "\n";
        cin >> ImageFileName;
    }
}

void saveImage () {
    char imageFileName[100];

    // getting the new image name to be saved
    cout <<  "Please enter target file name: " << "\n";
    cin >> imageFileName;

    // completing the image file path
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void blackAndWhite()
{
    long average = 0;
    // this loop to calculate the average of all pixels.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            average += image[i][j];
        }
    }

    average /= (SIZE * SIZE);

    // this loop to compare every pixel with average to determine if this pixel will be black or white.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (image[i][j] > average)
            {
                image[i][j] = 255;
            }else
            {
                image[i][j] = 0;
            }
        }
    }
}

void invertImage()
{
    for ( int i = 0; i < SIZE; i++)
    {
        for ( int j = 0; j < SIZE; j++)
        {
            // subtract the pixel from 255 to convert it to its invert.
            image[i][j] = (255 - image[i][j]);
        }

    }
}

void mergeImage () {
    //loading the second image file name .
    char imageFileName2[100];
    cout << "Please enter name of image file to merge with: \n";
    cin >> imageFileName2;

    // Add to it .bmp extension and load image
    strcat(imageFileName2, ".bmp");

    while (readGSBMP(imageFileName2,image2) == 1)
    {
        cout << "Please enter existing image file name: " << "\n";
        cin >> imageFileName2;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // making a newImage and adding to it both of the 2 images, dividing by 2 to take an average so that both appear.
            newImage[i][j] = (image[i][j] + image2[i][j]) / 2 ;
        }
    }

    // to make sure that save function will save correct image.
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = newImage[i][j];
        }
    }
}

void FlipImage_Vert() {
    // Flip Image Vertically
    // Storing in a new array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int temp = image[i][j];
            image[i][j] = image[j][i];
            image[j][i] = temp;
        }
    }
    for (int i =0; i<SIZE; i++){
        for (int j =0; j <(SIZE/2); j++){
            int temp = image[i][j];
            image[i][j] = image[i][SIZE-1-j];
            image[i][SIZE-1-j]= temp;
        }
    }
}

void FlipImage_Horz(){
    // Flip Image Horizontally
    // creating a new array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int temp = image[i][j];
            image[i][j] = image[j][i];
            image[j][i] = temp;
        }
    }
    for (int i =0; i<(SIZE/2); i++){
        for (int j =0; j <SIZE; j++){
            int temp = image[i][j];
            image[i][j] = image[SIZE-1-i][j];
            image[SIZE-1-i][j] = temp;
        }
    }
}

void darkenImage()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {  // multiplying each pixel by 0.5 to max it to 50% of the pixels.

            image[i][j] = (image[i][j] * 0.5);
        }
    }

}

void lightenImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((image[i][j] * 1.5) > 255 ){ // condition to check the boundries pixels if it gets over the 255.
                image[i][j] = 255;
            }
            else{
                // multiplying each pixel by 1.5 to minimize it to 50% of the pixels.
                image[i][j] = (image[i][j] * 1.5);
            }
        }
    }
}

void RotateImage_90() {
    // Rotating by 90 degree clockwise
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int temp = image[i][j];
            image[i][j] = image[j][i];
            image[j][i] = temp;
        }
    }
    for (int i = 0; i < (SIZE/2); i++) {
        for ( int j =i; j < (SIZE-i-1); j++) {
            int temp = image[i][j];
            image[i][j] = image [SIZE-1-j][i];
            image[SIZE-1-j][i] = image[SIZE-1-i][SIZE-1-j];
            image[SIZE-1-i][SIZE-1-j] = image[j][SIZE-1-i];
            image[j][SIZE-1-i] = temp;
        }
    }
}

void RotateImage_180(){
    // Rotating by 180 degree clockwise
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int temp = image[i][j];
            image[i][j] = image[j][i];
            image[j][i] = temp;
        }
    }
    for (int i = 0; i < (SIZE/2); i++) {
        for (int j= 0; j < SIZE; j++) {
            int temp = image[i][j];
            image[i][j] = image[SIZE-i-1][SIZE-j-1];
            image[SIZE-i-1][SIZE-j-1] = temp;
        }
    }
}

void RotateImage_270(){
    // Rotating by 270 degree clockwise
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int temp = image[i][j];
            image[i][j] = image[j][i];
            image[j][i] = temp;
        }
    }
    for (int i = 0; i < (SIZE/2); i++) {
        for ( int j =i; j < (SIZE-i-1); j++) {
            int temp = image[i][j];
            image[i][j] = image [SIZE-1-j][i];
            image[SIZE-1-j][i] = image[SIZE-1-i][SIZE-1-j];
            image[SIZE-1-i][SIZE-1-j] = image[j][SIZE-1-i];
            image[j][SIZE-1-i] = temp;
        }
    }
    for (int i =0; i<SIZE; i++){
        for (int j =0; j <(SIZE/2); j++){
            int temp = image[i][j];
            image[i][j] = image[i][SIZE-1-j];
            image[i][SIZE-1-j] = temp;
        }
    }
}

void detectImageEdges()
{
    blackAndWhite();

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            // check if all 4 sides of pixel are the same color to determine if this pixel is edge pixel or not.
            if ((image[i-1][j] == image[i][j+1]) and (image[i-1][j] == image[i][j-1]) and (image[i-1][j] == image[i+1][j]) and (image[i][j+1] == image[i][j-1]) and (image[i][j+1] == image[i+1][j]) and (image[i+1][j] == image[i][j-1]))
            {
                newImage[i][j] = 255;
            }else
            {
                newImage[i][j] = 0;
            }
        }
    }

    // restore newImage in image as saveImage function saving image not newImage.
    for (int i = 0; i <SIZE ; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] = newImage[i][j];
        }
    }
}

void Enlarge(string quarter)
{
    if (quarter == "1")
    {
        // (i/2) and (j/2) to store every pixel in quarter 1 in 4 pixels in newImage.
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                newImage[i][j] = image[i/2][j/2];
            }
        }
    }
    else if (quarter == "2")
    {
        // (i/2) and ((SIZE/2)+(j/2)) to store every pixel in quarter 2 in 4 pixels in newImage.
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                newImage[i][j] = image[i/2][(SIZE/2)+(j/2)];
            }
        }
    }
    else if (quarter == "3")
    {
        // ((SIZE/2)+(i/2)) and (j/2) to store every pixel in quarter 3 in 4 pixels in newImage.
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                newImage[i][j] = image[(SIZE/2)+(i/2)][j/2];
            }
        }
    }
    else if (quarter == "4")
    {
        // ((SIZE/2)+(i/2)) and ((SIZE/2)+(j/2)) to store every pixel in quarter 4 in 4 pixels in newImage.
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                newImage[i][j] = image[(SIZE/2)+(i/2)][(SIZE/2)+(j/2)];
            }
        }

    }

    // make sure that save function will save correct image.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] = newImage[i][j];
        }
    }
}

void shrinkImage  () {
    string choice;
    cout << "Shrink to (1/2), (1/3) or (1/4)?\n";
    cin >> choice;

    int x=0 , y=0 ; // counters to help in shrinking.
    if ( choice == "1/2"){
        // taking an index of pixel and skipping no.of index by the increment accordingaly to the shrink size.
        for (int i = 0; i < SIZE; i+=2) {
            for (int j = 0; j < SIZE; j+=2) {
                newImage[x][y] = image[i][j] ;
                y++ ;

            }
            y = 0 ;
            x++;
        }
    }

    else if (choice == "1/3") {
        for (int i = 0; i < SIZE; i += 3) {
            for (int j = 0; j < SIZE; j += 3) {
                newImage[x][y] = image[i][j];
                y++;

            }
            y = 0;
            x++;
        }
    }

    else if (choice == "1/4"){
        for (int i = 0; i < SIZE; i+=4) {
            for (int j = 0; j < SIZE; j+=4) {
                newImage[x][y] = image[i][j] ;
                y++ ;
            }
            y = 0 ;
            x++;
        }
    }

    else {
        cout << "invalid operation\n";
    }

    // to make sure that save function will save correct image.
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = newImage[i][j];
        }
    }
}

void mirror_left()
{
    // start the loops form 0 to SIZE and column [SIZE-j] to access the first pixels left.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][SIZE-j] = image[i][j];
        }
    }
}

void mirror_right()
{
    // start the loops form SIZE to 0 and column [SIZE-j] to access the last pixels right.
    for (int i = SIZE; i > 0; i--)
    {
        for (int j = SIZE; j > 0; j--)
        {
            image[i][SIZE-j] = image[i][j];
        }
    }
}

void mirror_down()
{
    // start the loops form SIZE to 0 and row [SIZE-i] to access the last pixels down.
    for (int i = SIZE; i > 0; i--)
    {
        for (int j = SIZE; j > 0; j--)
        {
            image[SIZE-i][j] = image[i][j];
        }
    }
}

void mirror_up()
{
    // start the loops form 0 to SIZE and row [SIZE-i] to access the first pixels up.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[SIZE-i][j] = image[i][j];
        }
    }
}

void Shuffle(string order)
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
                newImage[row][col] = image[k][j];
            }
        }
    }

    // to make sure that save function will save correct image.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] = newImage[i][j];
        }
    }
}

void BlurImage  () {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // taking each index of pixel adding them and taking the average of them ny dividing by 9, refer to the matrix
            // 1  2  3
            // 4  5  6
            // 7  8  9
            newImage[i][j] = (    image[i][j] + image[i][j-1] + image[i][j+1]          // around the pixel e.g the middle.
                                  + image[i-1][j-1] + image[i-1][j] + image[i-1][j+1]   // above the pixel.
                                  + image[i+1][j-1] + image[i+1][j] + image[i+1][j+1]) /9  ; // under the pixel
        }
    }

    // to make sure that save function will save correct image.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] = newImage[i][j];
        }
    }
}
