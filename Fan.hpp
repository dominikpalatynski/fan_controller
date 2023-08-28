#pragma once

class Fan {
    int rpm = 0;
    const int maxRpm = 3000;
    const int minRpm = 1000;
    const int disabledRpm = 0;
public:
    Fan();
    Fan(const Fan&);
    Fan(Fan&&);
    virtual ~Fan() = default;
    void setSpeed(int newRpm);
    int getSpeed() const;
    bool disable();
    bool enable();
};