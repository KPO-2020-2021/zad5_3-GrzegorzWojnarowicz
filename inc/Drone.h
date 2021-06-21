#pragma once
#include "Cuboid.h"
#include "Hex.h"
#include "Vector3D.h"
#include "Object.h"

class Drone :public Object{
protected:
    Cuboid droneBody;
    Hex rotors[NUMBER_OF_ROTORS];
public:
    /*! left up rotor ->0, right up->1, right down ->2, left down -> 3 */
    Drone();
    Drone(std::string fileNameOfdroneBody, std::string fileNameOfRotor0,
          std::string fileNameOfRotor1, std::string fileNameOfRotor2,
          std::string fileNameOfRotor3, vector3D initialTranslation, Matrix3x3 initialOrientation);
//    void unitRotationOfRotors();
    Hex getRotor(int index);
    const Hex & operator[](int index) const;
    Hex & operator[](int index);
    Cuboid getdroneBody();
    /*! calculate actual position od every drone component */
    void calculatePosition();
    /*! multiply every drone element orientation by matrix */
    void rotateDrone(Matrix3x3 rotMatrix);
    /*! add vector to every drone component position*/
    void translateDrone(vector3D vec);
    /*! rotate rotors by given matrices once */
    void rotateRotors(const Matrix3x3 &rotLeft,const Matrix3x3 &rotRight, const int &numberOfRotation);
    std::string getType() override;
};


