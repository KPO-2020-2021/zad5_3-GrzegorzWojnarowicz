#include "Drone.h"

Drone::Drone() {
    Matrix3x3 initMat = Matrix3x3();
    vector3D initVec = vector3D(0,0,1);
    vector3D transInZ = vector3D(0,0,1);

    this->droneBody = Cuboid("../data/cuboidModel.txt", "../data/droneBody.txt", initMat, initVec);

    initVec = (this->droneBody)[3] + transInZ;
    this->rotors[0] = Hex("../data/HexModel.txt",
                                     "../data/rotor0.txt", initMat, initVec);
    this->rotors[0].readModelVerticesPosition();

    initVec = (this->droneBody)[2] + transInZ;
    this->rotors[1] = Hex("../data/HexModel.txt",
                                     "../data/rotor1.txt", initMat, initVec);

    initVec = (this->droneBody)[6] + transInZ;
    this->rotors[2] = Hex("../data/HexModel.txt",
                                     "../data/rotor2.txt", initMat, initVec);

    initVec = (this->droneBody)[7] + transInZ;
    this->rotors[3] = Hex("../data/HexModel.txt",
                                     "../data/rotor3.txt", initMat, initVec);
    this->scaleX = 1;
    this->scaleY = 1;
    this->scaleZ = 1;
    this -> positionOfCenterOfMass = this->droneBody.getPosition();
}

Drone::Drone(std::string fileNameOfdroneBody, std::string fileNameOfRotor0,
             std::string fileNameOfRotor1, std::string fileNameOfRotor2,
             std::string fileNameOfRotor3, vector3D initialTranslation, Matrix3x3 initialOrientation) {

    Matrix3x3 initMat = initialOrientation;;
    vector3D transInZ = vector3D(0,0,1);
    vector3D initVec = initialTranslation;

    this->droneBody = Cuboid("../data/cuboidModel.txt", fileNameOfdroneBody, initMat, initVec);
    this->droneBody.readModelVerticesPosition();

    initVec = (this->droneBody)[3] + transInZ;
    initVec = initVec + initialTranslation;
    this->rotors[0] = Hex("../data/HexModel.txt",
                                     fileNameOfRotor0, initMat, initVec);

    initVec = (this->droneBody)[2] + transInZ;
    initVec = initVec + initialTranslation;
    this->rotors[1] = Hex("../data/HexModel.txt",
                                     fileNameOfRotor1, initMat, initVec);

    initVec = (this->droneBody)[6] + transInZ;
    initVec = initVec + initialTranslation;
    this->rotors[2] = Hex("../data/HexModel.txt",
                                     fileNameOfRotor2, initMat, initVec);

    initVec = (this->droneBody)[7] + transInZ;
    initVec = initVec + initialTranslation;
    this->rotors[3] = Hex("../data/HexModel.txt",
                                     fileNameOfRotor3, initMat, initVec);

    calculatePosition();
    this->scaleX = 1;
    this->scaleY = 1;
    this->scaleZ = 1;
    this -> positionOfCenterOfMass = this->droneBody.getPosition();
}

const Hex &Drone::operator[](int index) const {
    switch (index) {
        case 0:
            return this->rotors[0];
        case 1:
            return this->rotors[1];;
        case 2:
            return this->rotors[2];
        case 3:
            return this->rotors[3];
        default:
            throw std::invalid_argument("index out of range");
    }
}


Hex &Drone::operator[](int index) {
    switch (index) {
        case 0:
            return this->rotors[0];
        case 1:
            return this->rotors[1];;
        case 2:
            return this->rotors[2];
        case 3:
            return this->rotors[3];
        default:
            throw std::invalid_argument("index out of range");
    }
}
Cuboid Drone::getdroneBody() {
    return this->droneBody;
}

void Drone::calculatePosition() {
    this->droneBody.calculateActualPosition();
    for(int i = 0 ; i < NUMBER_OF_ROTORS; ++i){
        this->rotors[i].calculateActualPosition(this->droneBody.getPosition());
    }
    this -> positionOfCenterOfMass = this->droneBody.getPosition();
}

void Drone::rotateDrone(Matrix3x3 rotMatrix) {

    Matrix3x3 orient;

/*rotating drone body has to happen before rotating rotors*/
    orient = (this->droneBody.getOrientation());
    orient = rotMatrix * orient;
    this->droneBody.setOrientation(orient);


    /*rotate rotors*/
    for(int i = 0; i < NUMBER_OF_ROTORS; ++i){
        orient = this->rotors[i].getOrientation();
        orient = rotMatrix * orient;
        this->rotors[i].setOrientation(orient);
    }

}

void Drone::translateDrone(vector3D vec) {
    vector3D pos = (this->droneBody.getPosition());
    pos = pos + vec;
    this->droneBody.setPosition(pos);
    for(int i = 0; i < NUMBER_OF_ROTORS; ++i){
        pos = (this->rotors[i].getPosition());
        pos = pos + vec;
        this->rotors[i].setPosition(pos);
    }
}


void Drone::rotateRotors(const Matrix3x3 &rotLeft, const Matrix3x3 &rotRight, const int &numberOfRotation) {
    vector3D pos;
    vector3D droneBodyCenterCords = this->droneBody.getPosition();
    Matrix3x3 matrixToAnimateLeft = Matrix3x3();
    Matrix3x3 matrixToAnimateRight = Matrix3x3();

    /* creating proper matrix */
    for(int i = 0; i <numberOfRotation; ++i){
        matrixToAnimateLeft = rotLeft * matrixToAnimateLeft;
        matrixToAnimateRight = rotRight * matrixToAnimateRight;
    }



    /*rotating by this matrix and going back to proper position */
    for(int r = 0; r < NUMBER_OF_ROTORS; ++r){
        this->rotors[r].readModelVerticesPosition();
    /* rotate rotor in his center of mass */
        if(r%2 == 0){
            this->rotors[r].rotationByMatrix(matrixToAnimateRight);
        }else{
            this->rotors[r].rotationByMatrix(matrixToAnimateLeft);
        }
        /*translate to drone body coord system */
        pos = this->rotors[r].getPosition();
        pos = pos - droneBodyCenterCords;
        this->rotors[r].translationByVector(pos);
        /* rotate by orientation*/
        this->rotors[r].rotationByMatrix(this->rotors[r].getOrientation());
        /*translate rotors back to main coord system*/
        this->rotors[r].translationByVector(this->droneBody.getPosition());
    }
}

Hex Drone::getRotor(int index) {
    switch (index) {
        case 0:
            return this->rotors[0];
        case 1:
            return this->rotors[1];;
        case 2:
            return this->rotors[2];
        case 3:
            return this->rotors[3];
        default:
            throw std::invalid_argument("index out of range");
    }
}

std::string Drone::getType() {
    return std::string("Drone");
}
