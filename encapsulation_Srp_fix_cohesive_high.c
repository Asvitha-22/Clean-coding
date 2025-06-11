#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ---------------- Alert Interface ----------------
class IAlertService {
public:
    virtual void sendAlert(const std::string& message) = 0;
    virtual ~IAlertService() {}
};

class ConsoleAlertService : public IAlertService {
public:
    void sendAlert(const std::string& message) override {
        cout << message << endl;
    }
};

// ---------------- Sensor Data ----------------
struct SensorData {
    float temperature;
    float dimensionVariation;
    int operationMinutes;
    int selfTestCode;
};

// ---------------- Individual Checkers ----------------
class TemperatureChecker {
    IAlertService* alert;
public:
    TemperatureChecker(IAlertService* a) : alert(a) {}
    void check(float temp) {
        if (temp > 35.0f) {
            alert->sendAlert("ALERT: High temperature detected (Environment)");
        }
    }
};

class DimensionChecker {
    IAlertService* alert;
public:
    DimensionChecker(IAlertService* a) : alert(a) {}
    void check(float variation) {
        if (variation > 0.05f) {
            alert->sendAlert("ALERT: Part-dimension variation too high (Machine)");
        }
    }
};

class OperationTimeChecker {
    IAlertService* alert;
public:
    OperationTimeChecker(IAlertService* a) : alert(a) {}
    void check(int minutes) {
        if (minutes > 360) {
            alert->sendAlert("ALERT: Continuous operation exceeded 6 hours (Machine)");
        }
    }
};

class SelfTestChecker {
    IAlertService* alert;
public:
    SelfTestChecker(IAlertService* a) : alert(a) {}
    void check(int code) {
        switch (code) {
            case 0xFF:
                alert->sendAlert("Self-test OK");
                break;
            case 0x00:
                alert->sendAlert("ALERT: No data from machine (Environment)");
                break;
            case 0x01:
                alert->sendAlert("ALERT: Controller board failure (Machine)");
                break;
            case 0x02:
                alert->sendAlert("ALERT: Configuration data corrupted (Machine)");
                break;
            default:
                alert->sendAlert("ALERT: Unknown self-test code (Machine)");
        }
    }
};

// ---------------- Main ----------------
int main() {
    ConsoleAlertService alert;

    TemperatureChecker tempChecker(&alert);
    DimensionChecker dimChecker(&alert);
    OperationTimeChecker opChecker(&alert);
    SelfTestChecker selfTestChecker(&alert);

    ifstream infile("cnc_data.txt");
    if (!infile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    SensorData data;
    while (infile >> data.temperature >> data.dimensionVariation >> data.operationMinutes >> hex >> data.selfTestCode) {
        tempChecker.check(data.temperature);
        dimChecker.check(data.dimensionVariation);
        opChecker.check(data.operationMinutes);
        selfTestChecker.check(data.selfTestCode);
        cout << "---" << endl;
    }

    infile.close();
    return 0;
}
