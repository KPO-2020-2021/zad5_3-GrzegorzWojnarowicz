#include "scene.h"
#include "../inc/scene.h"

scene::scene() {
    GNU.ZmienTrybRys(PzG::TR_3D);
    this->XRange[0] = 0;
    this->XRange[1] = 0;
    this->YRange[0] = 0;
    this->YRange[1] = 0;

    this->chosenIndex = 0;

    vector3D initialPosDrone0 = vector3D(0,0,HALF_OF_DRONE_HEIGHT);
    vector3D initialPosDrone1 = vector3D(10,10,HALF_OF_DRONE_HEIGHT);
    vector3D initialPositionOfCone = vector3D(40,40,HALF_OF_DRONE_HEIGHT);
    vector3D initialPosWedge = vector3D(80,40,HALF_OF_DRONE_HEIGHT);
    vector3D initialPosPrism = vector3D(80,80,HALF_OF_DRONE_HEIGHT);
    Matrix3x3 initialOrientation = Matrix3x3();


    std::shared_ptr<Drone> dron1 = std::make_shared<Drone>("../data/drone0_droneBody.txt", "../data/drone0_rotor0.txt",
                                                           "../data/drone0_rotor1.txt", "../data/drone0_rotor2.txt",
                                                           "../data/drone0_rotor3.txt", initialPosDrone0, initialOrientation);

    std::shared_ptr<Drone> dron2 = std::make_shared<Drone>("../data/drone1_droneBody.txt", "../data/drone1_rotor0.txt",
                                                           "../data/drone1_rotor1.txt", "../data/drone1_rotor2.txt",
                                                           "../data/drone1_rotor3.txt", initialPosDrone1, initialOrientation);
    this->drone.push_back(dron1);

    this->drone.push_back(dron2);

    this->Objects.push_back(dron1);
    this->Objects.push_back(dron2);


    this->Objects.push_back(std::make_shared<Cone>("../data/coneModel.txt", "../data/coneBlock.txt",
                                            initialOrientation, initialPositionOfCone));
    this->Objects.push_back(std::make_shared<Cone>("../data/coneModel.txt", "../data/coneBlock.txt",
                                            initialOrientation, initialPositionOfCone));
    this->Objects.push_back(std::make_shared<Cone>("../data/coneModel.txt", "../data/coneBlock.txt",
                                            initialOrientation, initialPositionOfCone));
    this->Objects.push_back(std::make_shared<Prism>("../data/prismModel.txt", "../data/prismBlock.txt",
                                             initialOrientation, initialPosPrism));
    this->Objects.push_back(std::make_shared<Wedge>("../data/wedgeModel.txt", "../data/wedgeBlockk.txt",
                                           initialOrientation, initialPosWedge));

}

scene::scene(double _XRange[2], double _YRange[2], double _ZRange[2]) {

    this->XRange[0] = _XRange[0];
    this->XRange[1] = _XRange[1];
    this->YRange[0] = _YRange[0];
    this->YRange[1] = _YRange[1];
    this->ZRange[0] = _ZRange[0];
    this->ZRange[1] = _ZRange[1];

    this->chosenIndex = 0;

    vector3D initialPosDrone0 = vector3D(20,20,HALF_OF_DRONE_HEIGHT);
    vector3D initialPosDrone1 = vector3D(180,180,HALF_OF_DRONE_HEIGHT);
    vector3D initialPositionOfCone = vector3D(70,40,HALF_OF_DRONE_HEIGHT);
    vector3D initialPositionOfCone2 = vector3D(120,80,HALF_OF_DRONE_HEIGHT);
    vector3D initialPositionOfCone3 = vector3D(30,160,HALF_OF_DRONE_HEIGHT);
    vector3D initialPosWedge = vector3D(65,10,HALF_OF_DRONE_HEIGHT);
    vector3D initialPosPrism = vector3D(90,130,HALF_OF_DRONE_HEIGHT);
    Matrix3x3 initialOrientation = Matrix3x3();


    std::shared_ptr<Drone> dron1 = std::make_shared<Drone>("../data/drone0_droneBody.txt", "../data/drone0_rotor0.txt",
                                                           "../data/drone0_rotor1.txt", "../data/drone0_rotor2.txt",
                                                           "../data/drone0_rotor3.txt", initialPosDrone0, initialOrientation);

    std::shared_ptr<Drone> dron2 = std::make_shared<Drone>("../data/drone1_droneBody.txt", "../data/drone1_rotor0.txt",
                                                           "../data/drone1_rotor1.txt", "../data/drone1_rotor2.txt",
                                                           "../data/drone1_rotor3.txt", initialPosDrone1, initialOrientation);
    this->drone.push_back(dron1);

    this->drone.push_back(dron2);

    this->Objects.push_back(dron1);
    this->Objects.push_back(dron2);

    this->Objects.push_back(std::make_shared<Cone>("../data/coneModel.txt", "../data/coneBlock.txt",
                                            initialOrientation, initialPositionOfCone));

    this->Objects.push_back(std::make_shared<Cone>("../data/coneModel.txt", "../data/coneBlock1.txt",
                                            initialOrientation, initialPositionOfCone2));
    this->Objects.push_back(std::make_shared<Cone>("../data/coneModel.txt", "../data/coneBlock2.txt",
                                            initialOrientation, initialPositionOfCone3));
    this->Objects.push_back(std::make_shared<Prism>("../data/prismModel.txt", "../data/prismBlock.txt",
                                             initialOrientation, initialPosPrism));
    this->Objects.push_back(std::make_shared<Wedge>("../data/wedgeModel.txt", "../data/wedgeBlock.txt",
                                           initialOrientation, initialPosWedge));


    GNU.UstawRotacjeXZ(80,70);


    for(int h = 0; h < NUMBER_OF_DRONES; ++h){
        /* rotors file*/
        for( int i = 0; i < NUMBER_OF_ROTORS; ++i){
            GNU.DodajNazwePliku(this->drone[h]->getRotor(i).getFileNameOfBlock().c_str())
                    .ZmienSposobRys(PzG::SR_Ciagly)
                    .ZmienSzerokosc(1)
                    .ZmienKolor(CHOSEN_DRONE_COLOR);
        }
        /* drone body file */
        GNU.DodajNazwePliku(this->drone[h]->getdroneBody().getFileNameOfBlock().c_str())
                .ZmienSposobRys(PzG::SR_Ciagly)
                .ZmienSzerokosc(1)
                .ZmienKolor(CHOSEN_DRONE_COLOR);
    }

    /*cone files*/
    for(int i = 0; i < this->Objects.size(); ++i){
        GNU.DodajNazwePliku(this->Objects[i]->getFileNameOfBlock().c_str())
                .ZmienSposobRys(PzG::SR_Ciagly)
                .ZmienSzerokosc(1)
                .ZmienKolor(CHOSEN_DRONE_COLOR);
    }
    /*route and board files*/
    GNU.DodajNazwePliku(this->routeFileName.c_str())
            .ZmienSposobRys(PzG::SR_Ciagly)
            .ZmienSzerokosc(1)
            .ZmienKolor(CHOSEN_DRONE_COLOR);

    GNU.DodajNazwePliku(this->boardFileName.c_str())
            .ZmienSposobRys(PzG::SR_Ciagly)
            .ZmienSzerokosc(1)
            .ZmienKolor(1);

    GNU.ZmienTrybRys(PzG::TR_3D);
    GNU.UstawZakresX((this->XRange[0]),(this->XRange[1]));
    GNU.UstawZakresY((this->YRange[0]),(this->YRange[1]));
    GNU.UstawZakresZ((this->ZRange[0]),(this->ZRange[1]));
}

void scene::drawScene(){
    std::ofstream os;

/* Drawing drones*/
    Hex rotor;
    Cuboid droneBody;
    for(int f = 0; f < NUMBER_OF_DRONES; ++f){
//        this->drone[f].calculatePosition();
        /* Draw body of drone[f]*/
        os.open(this->drone[f]->getdroneBody().getFileNameOfBlock());
        if(!os) {
            throw std::invalid_argument("openingdroneBodyFile\n");
        }
        droneBody = this->drone[f]->getdroneBody();
        os << droneBody;

        os.close();

        /* Draw rotors of drone[f]*/
        for(int h = 0; h < NUMBER_OF_ROTORS; ++h){
            os.open(this->drone[f]->getRotor(h).getFileNameOfBlock());
            if(!os) {
                throw std::invalid_argument("openingRotorFile\n");
            }
            rotor = this->drone[f]->getRotor(h);
            os << rotor;
            os.close();
        }
    }

    /* Drawing obstacles*/
    for(int i = NUMBER_OF_DRONES; i < this->Objects.size(); ++i){
        this->Objects[i]->calculatePosition();
        os.open(this->Objects[i]->getFileNameOfBlock());
        if(!os) {
            throw std::invalid_argument("error");
        }
        os << *(Objects[i]);
        os.close();
    }

    /* Drawing simple background */
    os.open(this->boardFileName);
    if(!os){
        throw std::exception();
    }
    for(int k = 0; k <= 200; k+= 10){
        for(int l = 0; l <= 200; l += 10){
        os << l << " " << k+10 << " 0\n";
        os << l << " " << k << " 0\n";
            if(l <200){
                os << "#\n\n";
            }
        }
        os << 0 << " " << k << " 0\n#\n\n";
    }
    os.close();

    GNU.Inicjalizuj();
    GNU.Rysuj();
}


int scene::getIndex() {
    return this->chosenIndex;
}

void scene::setIndex(int index) {
    switch (index) {
        case 0:
            this->chosenIndex = 0;
            break;
        case 1:
            this->chosenIndex = 1;
            break;
        default:
            throw std::invalid_argument("index out of range :(");
    }
}


void scene::animateDroneTranslation(double angleOfFlight, double lengthOfFlight) {
    vector3D targetPosFromDroneCenter;
    vector3D unitTargetPos;
    vector3D animateVector;
    Matrix3x3 targetOrient = Matrix3x3(angleOfFlight, 'z');

    /*animate rotation*/
    animateRotation(angleOfFlight, 'z'),

    /* create vector of proper length but only x cord*/
    targetPosFromDroneCenter = vector3D(lengthOfFlight,0,0);

    /* draw route */
//    writeRouteToFile(targetPosFromDroneCenter);
    /* rotating this vector by orientation of drone*/
    targetPosFromDroneCenter = drone[chosenIndex]->getdroneBody().getOrientation() * targetPosFromDroneCenter;
    vector3D unitTarget = targetPosFromDroneCenter;
    unitTarget = unitTarget/targetPosFromDroneCenter.getLength();
    unitTarget = unitTarget * 20;

    while (!isRouteSafe(targetPosFromDroneCenter)){
        std::cout <<"Collision !!!!\nsearching for new route\n";
        writeRouteToFile(targetPosFromDroneCenter);
        targetPosFromDroneCenter = targetPosFromDroneCenter + unitTarget;
        drawScene();
        usleep(ANIMATION_SPEED* 100);
    }


    /* draw route */
    writeRouteToFile(targetPosFromDroneCenter);

    /*translate upwards */
    animateUpwardsMovement('u');

    /* creating auxiliary vectors */
    unitTargetPos = targetPosFromDroneCenter / targetPosFromDroneCenter.getLength();
    unitTargetPos = unitTargetPos * 2;
    animateVector = unitTargetPos;
    while(animateVector.getLength() < targetPosFromDroneCenter.getLength()){
        animateVector = animateVector + unitTargetPos;
        drone[chosenIndex]->translateDrone(unitTargetPos);
        drone[chosenIndex]->calculatePosition();
        /* animating rotation of rotors */
        /* 10 * 6
         * = 60 -> hexes after rotation of 60 degree doesn't change */
        for(int i = 0; i < (60/RESOLUTION); ++i){
            drone[chosenIndex]->rotateRotors(Matrix3x3(RESOLUTION, 'z'),Matrix3x3(-RESOLUTION, 'z'), i);
            drawScene();
        }

    }
    animateVector = animateVector * -1;
    drone[chosenIndex]->translateDrone(animateVector);
    /* translate drone by this vec*/
    drone[chosenIndex]->translateDrone(targetPosFromDroneCenter);
    drone[chosenIndex]->calculatePosition();
    drawScene();

    /*translate downwards */
    animateUpwardsMovement('d');

    /* delete route*/
    deleteRouteFromFile();
}

void scene::animateUpwardsMovement(char direction) {
    vector3D targetPosFromDroneCenter;
    vector3D unitTargetPos;
    vector3D animateVector;
    /* create vector upwards/downwards */
    if(direction == 'u'){
        targetPosFromDroneCenter = vector3D(0,0,ALTITUDE_OF_FLIGHT);
    }else if(direction == 'd'){
        targetPosFromDroneCenter = vector3D(0,0,-ALTITUDE_OF_FLIGHT);
    }else{
        throw std::invalid_argument("unknown direction");
    }

    /* creating auxiliary vectors */
    unitTargetPos = targetPosFromDroneCenter / targetPosFromDroneCenter.getLength();
    unitTargetPos = unitTargetPos * 2;
    animateVector = unitTargetPos;
    while(animateVector.getLength() < targetPosFromDroneCenter.getLength()){
        animateVector = animateVector + unitTargetPos;
        drone[chosenIndex]->translateDrone(unitTargetPos);
        drone[chosenIndex]->calculatePosition();
        /* animating rotation of rotors */

        for(int i = 0; i < (60/RESOLUTION); ++i){
            drone[chosenIndex]->rotateRotors(Matrix3x3(RESOLUTION, 'z'),Matrix3x3(-RESOLUTION, 'z'), i);
            
            drawScene();
        }

    }
    animateVector = animateVector * -1;
    drone[chosenIndex]->translateDrone(animateVector);
    /* translate drone by this vector */
    drone[chosenIndex]->translateDrone(targetPosFromDroneCenter);
    drone[chosenIndex]->calculatePosition();
    drawScene();
}

void scene::writeRouteToFile(vector3D &translation) {
    vector3D upWard = vector3D(0,0, ALTITUDE_OF_FLIGHT);
    vector3D pos;
    std::ofstream os;
    os.open(this->routeFileName);
    if(!os){
        throw std::exception();
    }
    /*Starting point */
    os << this->drone[this->chosenIndex]->getdroneBody().getPosition();

    /*upward position */
    pos = this->drone[this->chosenIndex]->getdroneBody().getPosition() ;
    pos = pos + upWard;
    os << pos;
    /*translated position */
    pos = pos + translation;
    os << pos;
    /* downward position*/
    pos = pos - upWard;
    os << pos;
    os.close();
}

void scene::deleteRouteFromFile() {
    std::ofstream os;
    os.open(this->routeFileName);
    if(!os){
        throw std::exception();
    }

    os.close();
}

void scene::changeDronesColors() {
    if(this->chosenIndex == 0){
        for(int i = 0; i < NUMBER_OF_ROTORS; ++ i){
            GNU.DodajNazwePliku(this->drone[0]->getRotor(i).getFileNameOfBlock().c_str())
                    .ZmienSposobRys(PzG::SR_Ciagly)
                    .ZmienSzerokosc(1)
                    .ZmienKolor(CHOSEN_DRONE_COLOR);
        }
        GNU.DodajNazwePliku(this->drone[0]->getdroneBody().getFileNameOfBlock().c_str())
                .ZmienSposobRys(PzG::SR_Ciagly)
                .ZmienSzerokosc(1)
                .ZmienKolor(CHOSEN_DRONE_COLOR);

        for(int i = 0; i < NUMBER_OF_ROTORS; ++ i){
            GNU.DodajNazwePliku(this->drone[1]->getRotor(i).getFileNameOfBlock().c_str())
                    .ZmienSposobRys(PzG::SR_Ciagly)
                    .ZmienSzerokosc(1)
                    .ZmienKolor(NOT_CHOSEN_DRONE_COLOR);
        }
        GNU.DodajNazwePliku(this->drone[1]->getdroneBody().getFileNameOfBlock().c_str())
                .ZmienSposobRys(PzG::SR_Ciagly)
                .ZmienSzerokosc(1)
                .ZmienKolor(NOT_CHOSEN_DRONE_COLOR);
    }else if(this->chosenIndex = 1){
        for(int i = 0; i < NUMBER_OF_ROTORS; ++ i){
            GNU.DodajNazwePliku(this->drone[1]->getRotor(i).getFileNameOfBlock().c_str())
                    .ZmienSposobRys(PzG::SR_Ciagly)
                    .ZmienSzerokosc(1)
                    .ZmienKolor(CHOSEN_DRONE_COLOR);
        }
        GNU.DodajNazwePliku(this->drone[1]->getdroneBody().getFileNameOfBlock().c_str())
                .ZmienSposobRys(PzG::SR_Ciagly)
                .ZmienSzerokosc(1)
                .ZmienKolor(CHOSEN_DRONE_COLOR);

        for(int i = 0; i < NUMBER_OF_ROTORS; ++ i){
            GNU.DodajNazwePliku(this->drone[0]->getRotor(i).getFileNameOfBlock().c_str())
                    .ZmienSposobRys(PzG::SR_Ciagly)
                    .ZmienSzerokosc(1)
                    .ZmienKolor(NOT_CHOSEN_DRONE_COLOR);
        }
        GNU.DodajNazwePliku(this->drone[0]->getdroneBody().getFileNameOfBlock().c_str())
                .ZmienSposobRys(PzG::SR_Ciagly)
                .ZmienSzerokosc(1)
                .ZmienKolor(NOT_CHOSEN_DRONE_COLOR);
    }else{
        throw std::invalid_argument("out of index");
    }
}

void scene::animateRotation(double targetAngle, char axis) {

    if(axis != 'x' && axis != 'y' && axis != 'z'){
        throw std::invalid_argument("unknown axis");
    }
    /* create single degree rotation matrix */
    Matrix3x3 targetMatrix = Matrix3x3(targetAngle, axis);
    Matrix3x3 reverseAnimateMatrix = Matrix3x3();
    Matrix3x3 unitMatrixMinus = Matrix3x3(-2, axis);
    Matrix3x3 unitMatrixPlus = Matrix3x3(2, axis);

    double animateDegree = 0;

    /* animation */

    while(fabs(animateDegree) < targetAngle){

        if(targetAngle < 0){
            animateDegree -= 2;
            reverseAnimateMatrix = unitMatrixPlus * reverseAnimateMatrix;
        }else{
            animateDegree += 2;
            reverseAnimateMatrix = unitMatrixMinus * reverseAnimateMatrix;
            drone[chosenIndex]->rotateDrone(unitMatrixPlus);
        }
        drone[chosenIndex]->calculatePosition();

        /* animating rotation of rotors */
        for(int i = 0; i < (60/RESOLUTION); ++i){
            drone[chosenIndex]->rotateRotors(Matrix3x3(RESOLUTION, 'z'),Matrix3x3(-RESOLUTION, 'z'), i);

            drawScene();
        }

    }
    drone[chosenIndex]->rotateDrone(reverseAnimateMatrix);
    drone[chosenIndex]->calculatePosition();;
    drone[chosenIndex]->rotateDrone(targetMatrix);
    /* translate drone by this vector*/
    drone[chosenIndex]->calculatePosition();
    drawScene();
}

void scene::makeCircleWithDrone(double radius) {


    int numberOfAngles = 20;
    int angleOfCurve = 180 - (180 * numberOfAngles - 360 )/ numberOfAngles;

    vector3D centerOfCircle = this->drone[this->chosenIndex]->getdroneBody().getPosition();
    /* switch z coord to max altitude*/
    centerOfCircle[2] = ALTITUDE_OF_FLIGHT;
    /*translate upwards */
    animateUpwardsMovement('u');
    /*translate by radius */
    vector3D radiusVec = vector3D(radius, 0 ,0);
    Matrix3x3 unitRotation = Matrix3x3(-angleOfCurve, 'z');
    Matrix3x3 rot90 = Matrix3x3(90, 'z');
    animateSimpleDroneTranslation(0,radiusVec);

    vector3D targetPosition = vector3D(0,10,0);
    targetPosition = this->drone[this->chosenIndex]->getdroneBody().getOrientation() * targetPosition;
    targetPosition = rot90 * targetPosition;


    /* calculate vector from centre of circle to drone */

    vector3D distance = this->drone[this->chosenIndex]->getdroneBody().getPosition();
    distance = distance - centerOfCircle;
    for(int i = 0; i < numberOfAngles; i ++){
            animateSimpleDroneTranslation(-angleOfCurve, targetPosition);
            targetPosition = unitRotation * targetPosition;
           

    }

    radiusVec = radiusVec * -1;
    animateSimpleDroneTranslation(0,radiusVec);

    /*translate downwards */
    animateUpwardsMovement('d');
    this->drone[this->chosenIndex]->calculatePosition();


}

void scene::animateSimpleDroneTranslation(double angleOfFlight, vector3D targetVec) {
    vector3D targetPosFromDroneCenter;
    vector3D unitTargetPos;
    vector3D animateVector = vector3D();
    Matrix3x3 targetOrient = Matrix3x3(angleOfFlight, 'z');

    /*animate rotation*/
    animateRotation(angleOfFlight, 'z');


    /* creating auxiliary vectors */
    unitTargetPos = targetVec / targetVec.getLength();
    unitTargetPos = unitTargetPos * 2;
    animateVector = unitTargetPos;
    while(animateVector.getLength() < targetVec.getLength()){
        animateVector = animateVector + unitTargetPos;
        drone[chosenIndex]->translateDrone(unitTargetPos);
        drone[chosenIndex]->calculatePosition();
        /* animating rotation of rotors */
        
        for(int i = 0; i < (60/RESOLUTION); ++i){
            drone[chosenIndex]->rotateRotors(Matrix3x3(RESOLUTION, 'z'),Matrix3x3(-RESOLUTION, 'z'), i);
            drawScene();
        }

    }
    animateVector = animateVector * -1;
    drone[chosenIndex]->translateDrone(animateVector);
    /* translate drone by this vec*/
    drone[chosenIndex]->translateDrone(targetVec);
    drone[chosenIndex]->calculatePosition();
    drawScene();

}

std::vector<std::shared_ptr<Object>>& scene::getObjects() {
    return this->Objects;
}

void scene::eraseObjectFromList(int index) {

    if(index == 1 || index == 0){
        throw std::invalid_argument("You cant delete drones... they are too expensive");
    }
    std::ofstream os;
    os.open(this->Objects[index]->getFileNameOfBlock());
    if(!os) {
        throw std::invalid_argument("error");
    }
    os.close();


    this->Objects.erase(this->Objects.begin() + index);
    drawScene();
}

void scene::addObjectToList(Matrix3x3 initialOrientation,
                            vector3D initialPosition, char objType, double scale) {

    std::string filenameOfBlock;
    std::string filenameOfModel;
    switch (objType) {
        case WEDGE:
            filenameOfModel = std::string("../data/wedgeModel.txt");
            filenameOfBlock = std::string("../data/wedgeBlock") + std::to_string(this->Objects[0]->getTotal())
                    + std::string(".txt");
            this->Objects.push_back(std::make_shared<Wedge>(filenameOfModel, filenameOfBlock,
                                                   initialOrientation, initialPosition));
            break;
        case CONE:
            filenameOfModel = std::string("../data/coneModel.txt");
            filenameOfBlock = std::string("../data/coneBlock") + std::to_string(this->Objects[0]->getTotal())
                              + std::string(".txt");
            this->Objects.push_back(std::make_shared<Cone>(filenameOfModel, filenameOfBlock,
                                                   initialOrientation, initialPosition));
            break;
        case PRISM:
            filenameOfModel = std::string("../data/prismModel.txt");
            filenameOfBlock = std::string("../data/prismBlock") + std::to_string(this->Objects[0]->getTotal())
                              + std::string(".txt");
            this->Objects.push_back(std::make_shared<Prism>(filenameOfModel, filenameOfBlock,
                                                   initialOrientation, initialPosition));
            break;
        default:
            throw std::invalid_argument("unknown obsticles");

    }
    GNU.DodajNazwePliku(filenameOfBlock.c_str())
            .ZmienSposobRys(PzG::SR_Ciagly)
            .ZmienSzerokosc(1)
            .ZmienKolor(CHOSEN_DRONE_COLOR);
    this->Objects.back()->calculatePosition();
    drawScene();
}

void scene::moveObjectFromList(int index, vector3D pos) {
    this->Objects[index]->setPosition(pos);
    this->Objects[index]->calculatePosition();
}

void scene::rotateObjectFromList(int index, Matrix3x3 orient) {
    this->Objects[index]->setOrientation(orient);
    this->Objects[index]->calculatePosition();
}

std::shared_ptr<Drone> scene::getDrone(int index) {
    switch (index) {
        case 0:
            return this->drone[0];
        case 1:
            return this->drone[1];
        default:
            throw std::invalid_argument("index out of range");
    }
}

bool scene::isRouteSafe(vector3D &translation) {
    int counter = 0;
    vector3D initDronePos = this->drone[this->chosenIndex]->getdroneBody().getPosition();
    initDronePos = initDronePos + translation;


    for(int i = 0; i < this->Objects.size(); ++i){
        if(abs(initDronePos[0] - this->Objects[i]->getPosition()[0]) <
        (DRONE_RADIUS + OBSTACLES_SIZE *  this->Objects[i]->getScaleX())  &&
                abs(initDronePos[1] - this->Objects[i]->getPosition()[1])
                < (DRONE_RADIUS + OBSTACLES_SIZE *  this->Objects[i]->getScaleY())){

            return false;
        }
    }

    return true;
}

