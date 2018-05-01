#include "Kinematics.h"


double kinematics::longVelocity() const
{
    return (carDesc->getRadius() / 2.0) * (angularVL + angularVR);
}

double kinematics::rotationalVelocity() const
{
    return (carDesc->getRadius() / carDesc->getDistLR()) * (angularVL - angularVR);
}

double kinematics::dX() const
{
    return u1*std::cos(theta);

}

double kinematics::dY() const
{
    return u1 * std::sin(theta);
}

double kinematics::dTheta() const
{
    return (double)(u1 / carDesc->getLength())* std::tan(phie) ;
}

double kinematics::dPhie() const
{
    return u2;
}

double kinematics::toDegree(const double &rad) const
{
    return rad * (180.0 / PI);
}

CarDescription *kinematics::getCarDesc() const
{
    return carDesc;
}

void kinematics::setCarDesc(CarDescription *value)
{
    carDesc = value;
}

double kinematics::getAngularVL() const
{
    return angularVL;
}

void kinematics::setAngularVL(double value)
{
    angularVL = value;
}

double kinematics::getAngularVR() const
{
    return angularVR;
}

void kinematics::setAngularVR(double value)
{
    angularVR = value;
}

double kinematics::getTheta() const
{
    return theta;
}

void kinematics::setTheta(double value)
{
    theta = value;
}

double kinematics::getU1() const
{
    return u1;
}

void kinematics::setU1(double value)
{
    u1 = value;
}

double kinematics::getU2() const
{
    return u2;
}

void kinematics::setU2(double value)
{
    u2 = value;
}

double kinematics::getPhie() const
{
    return phie;
}

void kinematics::setPhie(double value)
{
    phie = value;
}
