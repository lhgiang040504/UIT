#include <bits/stdc++.h>
using namespace std;

class Electricity {
protected:
    
    float efficiency;
public:
    Electricity(float eff = 0.0) :
    efficiency(eff) {}

    virtual void Input() { cin >> efficiency; }

    virtual float CalculatePower(WeatherCondition* w) { return 0.0; }

    virtual void setAccumulate(float redundant) { return; }
};

class Hydro : public Electricity {
private:
    int num_Units;
    bool accumulation;
    float accumulate;
public:
    Hydro(float eff = 0.0, int n = 0, bool acc = false, float a = 0.0)
        : Electricity(eff), num_Units(n), accumulation(acc), accumulate(a) {}

    void Input() override {
        Electricity::Input();
        cin >> num_Units >> accumulation;
    }

    void setAccumulate(float redundant) override {
        accumulate += redundant;
        if (accumulate > efficiency * num_Units)
            accumulate = efficiency * num_Units;
    }

    float CalculatePower(WeatherCondition* w) override {
        return efficiency * num_Units + (accumulation ? 1.0 : 0.0);
    }
};
class Thermoel : public Electricity {
private:
    float coal;
public:
    Thermoel(float eff = 0.0, float c = 0) :
    Electricity(eff), coal(c) {}

    void Input() override {
        Electricity::Input();
        cin >> coal;
    }

    float CalculatePower(WeatherCondition* w) override { return efficiency * coal; }
};
class Windel : public Electricity {
private:
    int num_Turbines;
    float maxSpeed;

public:
    Windel(float eff = 0.0, int n = 0, float m = 0.0) :
    Electricity(eff), num_Turbines(n), maxSpeed(m) {}

    void Input() override {
        Electricity::Input();
        cin >> num_Turbines >> maxSpeed;
    }

    float CalculatePower(WeatherCondition* w) override {
        float windPower = efficiency * num_Turbines * w->getSpeed() / maxSpeed;
        return windPower;
    }
};
class Solar : public Electricity {
private:
    float acreage;
public:
    Solar(float eff = 0.0, float a = 0) :
    Electricity(eff), acreage(a) {}

    void Input() override {
        Electricity::Input();
        cin >> acreage;
    }

    float CalculatePower(WeatherCondition* w) override {
        if (w->getCloudy() || w->getHour() >= 18 || w->getHour() <= 6)
            efficiency = 0 * efficiency;
        else if (w->getHour() >= 11 && w->getHour() <= 13) 
            efficiency = 1 * efficiency; 
        else {
            if (w->getHour() > 6 && w->getHour() < 11)
                efficiency = (w->getHour() - 6) * 20 * efficiency / 100.0;
            else 
                efficiency = (100 - (w->getHour() - 13) * 20) * efficiency / 100.0;
        }
        return efficiency * acreage;
    }

};

class WeatherCondition {
private:
    int hour;
    float speedWind;
    bool Cloudy;
    float Consume;
public:
    WeatherCondition(int hour = 0, int speed = 0.0, bool cloud = false, float consume = 0.0) :
    hour(hour), speedWind(speed), Cloudy(cloud), Consume(consume) {}

    void Input() {    cin >> hour >> speedWind >> Cloudy >> Consume;    }

    float getSpeed() { return speedWind; }
    bool getCloudy() { return Cloudy; }
    int getHour() { return hour; }
    float getConsume() { return Consume; }

};

int main() {
    int num_Electricity;
    vector<Electricity*> manage(num_Electricity);
// Keep track each type of electric
    for (int i = 0; i < num_Electricity; i++) {
        int type;
        cin >> type;
        if (type == 1)      manage[i] = new Hydro();
        else if (type == 2) manage[i] = new Thermoel();
        else if (type == 3) manage[i] = new Windel();
        else if (type == 4) manage[i] = new Solar();
            
        manage[i]->Input();
    }

    int hours;
    vector<WeatherCondition*> track;
    cin >> hours;
    track.reserve(hours);

// Keep track of each condition
    for (int i = 0; i < hours; i++) {
        track.push_back(new WeatherCondition());
        track[i]->Input();
    }

// Calculate revenue
    float totalRevenue = 0.0;
    vector<float> CS;
    CS.push_back(0.0);
    
    for (int i = 0; i < hours; i++) {
        float currentPowerDemand = track[i]->getConsume();
        float activeSourcesCapacity = 0.0;

        for (int j = 0; j < num_Electricity; j++) {
            float power = manage[j]->CalculatePower(track[i]);
            activeSourcesCapacity += power;
        }
        CS.push_back(activeSourcesCapacity);
        float temp = abs(CS[i] - CS[i + 1]) / (CS[i] > CS[i + 1] ? CS[i] : CS[i + 1]);
        
        if (temp > 20.0) {
            for (Electricity* source : manage) {
                if (dynamic_cast<Hydro*>(source) == nullptr && dynamic_cast<Thermoel*>(source) == nullptr) {
                    source->setAccumulate(0.0);
                }
            }
        }

        if (activeSourcesCapacity <= 0.8 * currentPowerDemand && activeSourcesCapacity > 0.5 * currentPowerDemand) {
            totalRevenue += currentPowerDemand * 1000 * 2500;
        } else if (activeSourcesCapacity <= 0.5 * currentPowerDemand) {
            totalRevenue += currentPowerDemand * 1000 * 2000;
        } else if (activeSourcesCapacity > currentPowerDemand) {
            float redundant = activeSourcesCapacity - currentPowerDemand;
            for (Electricity* source : manage) {
                source->setAccumulate(redundant);
            }
            totalRevenue += currentPowerDemand * 1000 * 3000;
        } else totalRevenue += currentPowerDemand * 1000 * 3000;
    }

    cout << totalRevenue << endl;

    // Clean up
    for (Electricity* source : manage) {
        delete source;
    }
    for (WeatherCondition* condition : track) {
        delete condition;
    }

    return 0;
}