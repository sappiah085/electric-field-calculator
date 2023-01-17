#include <iostream>
#include <cmath>
using namespace std;

typedef struct{
    float charge;
    float xCoordinate;
    float yCoordinate;
} chargeVector;

typedef struct{
    float xCoordinate;
    float yCoordinate;
} eletricfieldVector;



eletricfieldVector CalculateField(chargeVector v, chargeVector point){
    const float K = 8987.5517923;
    eletricfieldVector eVector;
    float x = point.xCoordinate - v.xCoordinate;
    float y = point.yCoordinate - v.yCoordinate;
    float r = sqrt(x*x+y*y);
    float r3 = r*r*r;
    float value = K*v.charge*(1/r3);
    eVector.xCoordinate = x*value;
    eVector.yCoordinate = y* value;
    return eVector;
}

int main()
{
    cout<<"Note all charges are treated as nano(ie. 10^-6) so type whole numbers. eg: 2 * 10e-5 = 20"<<endl;
    float x,y;

    chargeVector chargeV, pointCharge;
    int numberOfCharges;
    cout<<"Enter number of charges: ";
    cin>>numberOfCharges;
    chargeVector chargeArray[numberOfCharges];
    cout<<endl;
    cout << "Enter the point P's charge: ";
    cin >> pointCharge.charge;

    cout << "Enter the point P's x-coordinate: ";
    cin >> pointCharge.xCoordinate;

    cout << "Enter the point P's y-coordinate: ";
    cin >> pointCharge.yCoordinate;

    cout << endl;
    for(int i =0 ; i<numberOfCharges; i++){
        cout<<"Enter the charge of q"<<i+1<<": ";
        cin>> chargeV.charge;

        cout<<"Enter the x-coordinate of q"<<i+1<<": ";;
        cin>> chargeV.xCoordinate;

        cout<<"Enter the y-coordinate of q"<<i+1<<": ";
        cin>> chargeV.yCoordinate;
        chargeArray[i] = chargeV;
        cout<< endl;
    }
    for( chargeVector eV: chargeArray ){

        x= x + CalculateField(eV, pointCharge).xCoordinate;
        y= y + CalculateField(eV, pointCharge).yCoordinate;

    }
    cout<<"The coordinate of resultant electric field is ("<<x<<" , "<<y<<" )"<<"N/C"<<  endl;
    cout << "The magnitude is : "<<sqrt(x*x+y*y)<<"N/C"<<endl;
    cout << "The force exerted on charge at the point P is : "<<sqrt((x*pointCharge.charge * 1e-6)*(x*pointCharge.charge * 1e-6)+(y*pointCharge.charge * 1e-6)*(y*pointCharge.charge  * 1e-6))<<"N";
    return 0;
}