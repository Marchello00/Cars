#ifndef CARS_BASE_H
#define CARS_BASE_H

class CBase {
protected:
    int max_speed;
    int acceleration;
    int weight;
    int lives;
    int armor;
    int ammo;
public:
    const int car_type;

    CBase(int car_type) :
            car_type(car_type), max_speed(0),
            weight(0), lives(0), armor(0),
            ammo(0) {}

    void set_max_speed(int val) {
        max_speed = val;
    }

    void set_acceleration(int val) {
        acceleration = val;
    }

    void set_weight(int val) {
        weight = val;
    }

    void set_lives(int val) {
        lives = val;
    }

    void set_armor(int val) {
        armor = val;
    }

    void set_ammo(int val) {
        armor = val;
    }
};

class CPart : CBase {
public:
    const int part_type;
    virtual void get_cost() = 0;
};

class CCar : CBase {

};

#endif //CARS_BASE_H
