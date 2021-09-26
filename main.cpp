


//===========================================//
//  Intro to creating simple graphical shapes//
//  with C++                                 //
//  Aim: to create Rectangle shape           //
//===========================================//
#include <windows.h>
#include <iostream>   
#include <stdio.h>
#include <conio.h> 
#include "resource.h"
#include <math.h>

using namespace std;
//=== class declarations ====================================

class   point
        {
   protected:  int   x;
               int   y;
               COLORREF RGB_color;
   public:     point()  {  x = 0;   y = 0; RGB_color=RGB(0,0,0); }
               point( int xval, int yval, int r,int g,int b );
               void  draw(HDC hdc);
               void  set_x( int xval );
               void  set_y( int yval );
               int   get_x();
               int   get_y();
			   void set_Colour(int r, int g, int b){
				   RGB_color=(r,g,b);
			   }
        };

class   line:   public point
        {
   protected:  int   length;
   public:     line()  {  x = 0;   y = 0; RGB_color=RGB(0,0,0);  length = 0;  }
               line( int xval, int yval, int r,int g,int b , int ilength);
               void  draw(HDC hDC);
               void  set_len( int ilength );
               int   get_len();
        };

class square:   public line
        {
   protected:  int width;
               COLORREF RGB_fill_color;
   public:     square()  {  x = 0;      y = 0; RGB_color=RGB(0,0,0);
                            length = 0; width = 0; RGB_fill_color=RGB(0,0,0); }
               square(  int xval,       int yval, int r, int g, int b,
                        int ilength,    int iwidth,
                        int fill_r, int fill_g, int fill_b  );
               void  draw(HDC hdc);
               void  set_width( int iwidth );
               int   get_width();
			   void set_RGB_Fill(int r, int g,int b){
				   RGB_fill_color=(r,g,b);
			   }
        };

//=== methods for point class ===============================
      point::point( int xval, int yval, int r, int g, int b )
                         {      x = xval;
                                y = yval;      
                                RGB_color =RGB(r,g,b);  }
                            
void  point::set_x( int xval )       {  x = xval;      }

void  point::set_y( int yval )       {  y = yval;      }

int   point::get_x()                 {  return( x );   }

int   point::get_y()                 {  return( y );   }

void  point::draw(HDC hDC)
      {  
         int i,j;      
         for( i= -2; i<3; i++ )
            for( j = -2; j<3; j++ )
               SetPixel(hDC, x+i, y+j,RGB_color);   
      }
                    
//=== methods for line class ================================
      line::line( int xval, int yval, int r, int g, int b, int ilength): point( xval, yval, r,g,b)
                                     {  set_len(ilength);  }
                                     
void  line::set_len( int ilength )   {  length = ilength;  }

int   line::get_len()                {  return( length );  }

void  line::draw(HDC hDC)
      {
       
		 HPEN pen=NULL;
		 if (pen)DeleteObject(pen); //delete previous created pen
		         
		 pen=CreatePen(PS_SOLID,1,RGB_color);  // Create a new pen
         SelectObject(hDC,pen); // select pen into context
         MoveToEx (hDC,x,y,NULL);
		 LineTo(hDC,x+length,y);

       }                         
           
//===================methods for square================================
square::square( int xval,       int yval, int r, int g, int b,
                      int ilength,    int iwidth,
                      int fill_r, int fill_g, int fill_b  )
                      : line( xval, yval, r, g, b, ilength)
                         {   set_width(iwidth);  
                             RGB_fill_color =RGB(fill_r, fill_g, fill_b);}
                                    
void  square::set_width( int iwidth )  {  width = iwidth;   }

int   square::get_width()              {  return( width );  }

void  square::draw(HDC hDC)
      {	 HPEN pen=NULL;
		
		 if (pen)DeleteObject(pen); //delete previous created pen
		 //if (pen2)DeleteObject(pen2); //delete previous created pen
         
		 pen=CreatePen(PS_SOLID,20,RGB_fill_color);  // Create a new pen
         SelectObject(hDC,pen); // select pen into context
         Rectangle(hDC, x, y, x+length, y+width);
      }





void main()
{
  

   HWND hWnd=GetForegroundWindow();
   HDC hDC=GetDC(hWnd);

   
	   	//                X, Y,          r,g,b               L,W,          fill
       square   square1( 100, 600,       0 , 255,0,        20, 50,      0,255,0 );
       square1.draw(hDC); 
   
       //                  X, Y,          r,g,b               L,W,          fill
       square   square2( 10, 80,       255, 45,0,        20, 100,      255,0,60 );
       square2.draw(hDC); 
   
         
   } //breakpoint here 

