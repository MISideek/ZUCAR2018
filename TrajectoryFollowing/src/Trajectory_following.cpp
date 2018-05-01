#include <iostream>
#include "PathGen.h"
#include <time.h>
using namespace std;
const int NUM_SECONDS = 1;

int main() {
  /* Setup your example here, code that should run once
   */
    		int count = 1;
			double timeCounter = 0 ;
			clock_t thisTime = clock();
		    clock_t lastTime = thisTime;
			double x = 0 ;
			//map .............. defined by values
	        Eigen::VectorXd xVals(13) ;
		    Eigen::VectorXd yVals(13) ;
		    xVals << 0,1,2,3,4,5,6,7,8,9,10,11,12 ;
		    yVals << 0,1,2,3,4,4,4,4,4,3,2,1,0 ;
		    path p1(xVals , yVals) ;


		    for(int i = 0 ; i < 120 ; i++){

		    	cout <<  x <<","<< p1(x) << endl ;
		    	 x = x+0.1 ;
		    }
		    //std::cout << p1(2.5) << endl ;
		    //std::cout << p1.getfirstdriv(2.0) << endl ;
		    cout << "point at 2.0 is  "<< p1(2.5) << endl ;
		    cout << "the 1st driv at 2.0 is :: "<< p1.getfirstdriv(2.0) << endl ;
		    cout << "the driv at 2.0 is :: "<< p1.getSecDriv(2.0) << endl ;
		    cout << "third is ?" << p1.getThirdDriv(2.0) << endl ;
		    cout << "torsion is :: "<< p1.calcTorsion(2.0) << endl ;


		    std::cout << "curvature is:: " <<p1.calcCurvature(2.0) << endl ;

  /* Code in this loop will run repeatedly
   */
  for (;;) {
	  thisTime = clock();

	         timeCounter += (double)(thisTime - lastTime);

	         lastTime = thisTime;
	         //code run every second
	         if(timeCounter > (double)(NUM_SECONDS * CLOCKS_PER_SEC))
	         {
	             timeCounter -= (double)(NUM_SECONDS * CLOCKS_PER_SEC);
	             printf("%d\n", count);

	             count++;
	         }

  }

  return 0;
}
