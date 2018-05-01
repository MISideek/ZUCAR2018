#ifndef CARDESCRIPTION_H
#define CARDESCRIPTION_H


class CarDescription{
 private:
    double r;
    double lnth;
    double dLR;
public:

    double getRadius() const;
    void setRadius(double value);

    double getLength() const;
    void setLength(double value);

    double getDistLR() const;
    void setDistLR(double value);

protected:
};
#endif // CARDESCRIPTION_H
