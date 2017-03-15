//***************************************************************************************//
// Josh Joseph
// C++ In Object-Oriented Programming and Design
// Pesky Tourist
// 09-23-2015
// Professor Basawapatna

// ** DESCRIPTION **
// This program combine multiple photographs a sculpture into a single image 
// using median filter. The photos are cluttered with one tourist. 
// The final image shows the statue and background without the tourist.

// ** Algorithm **
// The program loads 9 images (200 * 225) and reads the pixel color values, and stores 
// them into a 3-dimensional array. Then, it stores RGB values at each (x,y) coorindate 
// of 9 pictures and stores them into 3 different singl dimensional arrays. 
// It then picks the middle value, i.e., the median value from three sorted arrays 
// which holds red, green and blue values. Finally, it writes those median values 
// to a new window (200 * 225) which is tourist free.
//***************************************************************************************//

#include <graphics.h> 
#include <stdio.h>

using namespace std;

void loadImage(int imageNumber); //function prototype for loadImage
void sort(int arr[], int n);     //function prototype for loadImage

// function main begins program execution
int main()
{
  int firstWindow= initwindow(200,225, "Load Pictures"); // firstWindow will be used to load all 9 images
  int finalWindow=initwindow(200,225,"Final Picture");   // finalWindow will be used to write fianl picture without the tourist

  int pic[200][225][9]; // stores all pixel values of 9 pictures
  int redPixel[9];      // stores red values of same coordinates for all 9 pictures
  int greenPixel[9];    // stores green values of same coordinates for all 9 pictures
  int bluePixel[9];     // stores blue values of same coordinates for all 9 pictures

   setcurrentwindow(firstWindow); //BGI function that selects the active window (firstWindow to load all the images)
 
  // triple for loop that loads 9 images one by one and loops thorugh all pixel values of the current image
  for (int picNum=0; picNum<9; picNum++)
  {
    loadImage(picNum); // loads images 
    
    for(int x=0; x<200; x++)
    {
      for (int y=0; y<225; y++)
      {
        pic[x][y][picNum]=getpixel(x,y); // stores all pixel values of 9 pictures 
      }
    }
  }

  setcurrentwindow(finalWindow); //switches the active window to fianlWindow to write picture without the tourist

  // triple for loop that loops through pixels at a particular coordinate of nine pictures
  for(int x=0; x<200; x++)
  {
    for (int y=0; y<225; y++)
    {
      for (int picNum=0; picNum<9; picNum++)
      {
        redPixel[picNum]=RED_VALUE(pic[x][y][picNum]);     // stores red value of that coordinate into redPixel array
        greenPixel[picNum]=GREEN_VALUE(pic[x][y][picNum]); // stores green value of that coordinate into greenPixel array
        bluePixel[picNum]=BLUE_VALUE(pic[x][y][picNum]);   // stores blue value of that coordinate into bluePixel array
      }

        sort(redPixel,9);   // sort redPixel array in ascending order
        sort(greenPixel,9); // sort greenPixel array in ascending order
        sort(bluePixel,9);  // sort bluePixel array in ascending order

        // writes pixels to the windows using COLOR function and median red, green, and blue values 
        putpixel(x,y,COLOR(redPixel[4], greenPixel[4], bluePixel[4]));
    }
  }
    getch(); // end function main
}

// this function takes that image number and loads it onto the current window
void loadImage(int imageNumber)
{
     char str[5];
     sprintf(str, "%i.jpg", imageNumber);
     readimagefile(str,0,0,200,225); // BGI function that loads the image onto the current window
}

// this function sort an int array in ascending order using insertion sort
void sort(int arr[], int n)
{
  int j, temp;

  for (int i = 1; i<n; i++)
  {
    j=i;
    temp = arr[i];

    // while (j!=0 and value of element at index j-1 is greater than value of the current element)
    while(j!=0 && arr[j-1]>temp)
    {
      arr[j]=arr[j-1]; // shift element at index j-1 to the right
      j--;             // decrement j by 1
    }

    arr [j]=temp;      // assign current element value to element at index j  
  }
}