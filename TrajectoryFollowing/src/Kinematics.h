/*
 * Kinematics.h
 *
 *  Created on: May 1, 2018
 *      Author: Administrator
 */

#ifndef KINEMATICS_H_
#define KINEMATICS_H_
#include "cardescription.h"
#include <cmath>

class kinematics{
    const double PI = 22.0 / 7;
public:
    double angularVL;
    double angularVR;
    double u1, u2 ;
    double theta , phie ;
    virtual double longVelocity() const;
    virtual double rotationalVelocity() const;
    virtual double dX() const;
    virtual double dY() const;
    virtual double dTheta() const;
    virtual double dPhie() const;
    virtual double toDegree(const double& rad) const;
    CarDescription  *getCarDesc() const;
    void setCarDesc(CarDescription *value);

    double getAngularVL() const;
    void setAngularVL(double value);

    double getAngularVR() const;
    void setAngularVR(double value);

    double getTheta() const;
    void setTheta(double value);

    double getU1() const;
    void setU1(double value);

    double getU2() const;
    void setU2(double value);

    double getPhie() const;
    void setPhie(double value);

private:
    CarDescription *carDesc;

protected:
};

#endif // KINEMATICMODEL_H
