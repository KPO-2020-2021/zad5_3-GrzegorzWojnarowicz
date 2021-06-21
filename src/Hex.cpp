#include "Hex.h"

Hex::Hex() {
    this -> fileNameOfModel = "../data/HexModel.txt";
    this -> fileNameOfBlock = "../data/data.txt";
    this -> orientation = Matrix3x3();
    this -> positionOfCenterOfMass = vector3D();
}

Hex::Hex(std::string fileNameOfModel, std::string fileNameOfBlock,
                               Matrix3x3 initialOrientation, vector3D initialPosition){
    this -> fileNameOfModel = fileNameOfModel;
    this -> fileNameOfBlock = fileNameOfBlock;
    this -> orientation = initialOrientation;
    this -> positionOfCenterOfMass = initialPosition;
}

std::ostream &operator<<(std::ostream &ost, Hex &hex) {
    ost << std::setprecision(10) << std::fixed;

    vector3D up = hex[11];
    up = up - hex[8];
    up = up/2;
    up = up + hex[8];
    vector3D down = hex[5];
    down = down - hex[2];
    down = down/2;
    down = down + hex[2];


    ost << up;
    ost << hex[6];
    ost << hex[0];
    ost << down << "#\n\n";

    ost << up;
    ost << hex[7];
    ost << hex[1];
    ost << down << "#\n\n";

    ost << up;
    ost << hex[8];
    ost << hex[2];
    ost << down << "#\n\n";

    ost << up;
    ost << hex[9];
    ost << hex[3];
    ost << down << "#\n\n";

    ost << up;
    ost << hex[10];
    ost << hex[4];
    ost << down << "#\n\n";

    ost << up;
    ost << hex[11];
    ost << hex[5];
    ost << down << "#\n\n";

    ost << up;
    ost << hex[6];
    ost << hex[0];
    ost << down << "#\n\n";
    return ost;
}

void Hex::readModelVerticesPosition() {
    std::string tmp;
    std::stringstream ss;
    int i = 0;
    std::ifstream is;
    is.open(this->fileNameOfModel);

        while(getline(is, tmp)){
            ss << tmp;
            ss >> this->vertices[i];
            i++;
            ss = std::stringstream();
        }
        is.close();
}

const vector3D &Hex::operator[](int index) const {
    switch (index) {
        case 0:
            return this->vertices[0];
        case 1:
            return this->vertices[1];;
        case 2:
            return this->vertices[2];
        case 3:
            return this->vertices[3];
        case 4:
            return this->vertices[4];
        case 5:
            return this->vertices[5];;
        case 6:
            return this->vertices[6];
        case 7:
            return this->vertices[7];
        case 8:
            return this->vertices[8];
        case 9:
            return this->vertices[9];
        case 10:
            return this->vertices[10];
        case 11:
            return this->vertices[11];
        default:
            throw std::invalid_argument("index out of range");
    }
}

vector3D &Hex::operator[](int index){
    switch (index) {
        case 0:
            return this->vertices[0];
        case 1:
            return this->vertices[1];;
        case 2:
            return this->vertices[2];
        case 3:
            return this->vertices[3];
        case 4:
            return this->vertices[4];
        case 5:
            return this->vertices[5];;
        case 6:
            return this->vertices[6];
        case 7:
            return this->vertices[7];
        case 8:
            return this->vertices[8];
        case 9:
            return this->vertices[9];
        case 10:
            return this->vertices[10];
        case 11:
            return this->vertices[11];
        default:
            throw std::invalid_argument("index out of range");
    }
}

void Hex::rotationByMatrix(Matrix3x3 rotMatrix) {
    for(int i = 0; i < VERTICES_NUMBER_OF_HEX; ++i){
        this->vertices[i] = rotMatrix * (this->vertices[i]);
    }
}

void Hex::translationByVector(vector3D vec) {
    for(int i = 0; i < VERTICES_NUMBER_OF_HEX; ++i){
        this->vertices[i] = vec + (this->vertices[i]);
    }
}

void Hex::calculateActualPosition(vector3D posOfdroneBody) {
    readModelVerticesPosition();

    /*translate to target position */
    for(int j = 0; j < VERTICES_NUMBER_OF_HEX; ++j){
        this->vertices[j] = this->positionOfCenterOfMass + (this->vertices[j]);
    }

    /*translate vertices to drone body cord system */
    for(int i = 0; i < VERTICES_NUMBER_OF_HEX; ++i){
        this->vertices[i] = this->vertices[i] - posOfdroneBody;
    }
    /* rotate vertices in proper cord system */
    for(int i = 0; i < VERTICES_NUMBER_OF_HEX; ++i){

        this->vertices[i] = this->orientation * (this->vertices[i]);
    }
    /*translate vertices back to main cord system */
    for(int i = 0; i < VERTICES_NUMBER_OF_HEX; ++i){
        this->vertices[i] = this->vertices[i] + posOfdroneBody;
    }
}

