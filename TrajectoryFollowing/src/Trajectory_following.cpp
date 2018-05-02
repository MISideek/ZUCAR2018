#include <iostream>
#include "PathGen.h"
#include <time.h>
#include "controller.h"
#include "Kinematics.h"
#include "Fernet.h"
using namespace std;
const int NUM_SECONDS = 1;

double dist_(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int calcColsestWayPoint(double x , double y , Eigen::VectorXd const &xVals, Eigen::VectorXd  const &yVals){
			double closest_len = 1000 ;
			int closest_waypoint = 0 ;
	for (int i = 0; i < xVals.rows() ; i++) {
			double map_x = xVals[i];
			double map_y = yVals[i];

			double dist = dist_(x, y, map_x, map_y);
			if (dist < closest_len) {
				closest_len = dist;
				closest_waypoint = i;
			}
		}



	return closest_waypoint;
}

double calc_d(double x , double y ,Eigen::VectorXd const &xVals, Eigen::VectorXd  const &yVals){
			double closest_len = 1000 ;
			int closest_waypoint = 0 ;
	for (int i = 0; i < xVals.rows() ; i++) {
			double map_x = xVals[i];
			double map_y = yVals[i];

			double dist = dist_(x, y, map_x, map_y);
			if (dist < closest_len) {
				closest_len = dist;
				closest_waypoint = i;
			}
		}



	return closest_len ;
}

double calcS (int closest_waypoint , Eigen::VectorXd xVals){
	return xVals[closest_waypoint] ;
}




int main() {
  /* Setup your example here, code that should run once
   */
    		int count = 1;
			double timeCounter = 0 ;
			clock_t thisTime = clock();
		    clock_t lastTime = thisTime;
			double x=0 ,z3 = 0 , z4 = 0 ,V1 = 0 , V2 = 0  ;
			double carX = 0 ;
			double carY = 0 ;
			double s = 0 , sdot =0 ;
			double d = 0 ;
			double k1 = 0 , k2 = 1 , k3 = 3 , k4 = 3 ;
			//double theta = 0;
			//double phie = 0 ;
			double dx = 0  ;
			double dy = 0 ;
			double dtheta = 0 ;
			double thetaErr = 0 ;
			int cwp = 0 ;
			double u1 = 5 ;
			double k = 0 ;
			double Tor = 0 ;
			kinematics carKin ;
			carKin.theta = 0 ;
			carKin.phie = 0 ;

			//map .............. defined by values
	        Eigen::VectorXd xVals(13) ;
		    Eigen::VectorXd yVals(13) ;
		    xVals << 0,1,2,3,4,5,6,7,8,9,10,11,12 ;
		    yVals << 0,1,2,3,4,4,4,4,4,3,2,1,0 ;

		    //generate the path
		    path p1(xVals , yVals) ;
		    //...................





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
	             //printf("%d\n", count);
	             cwp = calcColsestWayPoint(carX , carY ,xVals , yVals) ;
	             d = calc_d(carX , carY  ,xVals , yVals) ;
	             s = calcS (cwp , xVals) ;
	             k = p1.calcCurvature(s) ;
	             dx = carKin.dX() ;
	             dy = carKin.dY() ;
	             dtheta = carKin.dTheta() ;
	             carKin.theta = carKin.theta + dtheta ;
	             carX = carX + dx ;
	             carY = carY + dy ;
	           //  sdot =  dS( u1 ,  k , d ,  thetaErr ) ;
	             //thetaErr = thetaErr + dTheta(u1,1.2,carKin.phie,s,k);
	             //z3 = traj::RControl::calcZ3(d,s,thetaErr,k);
	             //z4 = traj::RControl::calcZ4(d,s,thetaErr,carKin.phie,1.2,k,Tor);
	             //V1 = traj::RControl::calcV1(u1 , k , d , thetaErr) ;
	          //   V2 = traj::RControl::controlSignal_V2(V1 , k2 , k3 , k4 , d , z3 , z4) ;
	             carKin.phie = carKin.phie + V2 ;
	             if(count == 13){
	            	 break;
	             }
	             //cout << "car x:" << carX << endl ;
	             //cout << "car y:" << carY << endl ;

	             count++;
	         }

  }

  return 0;
}



