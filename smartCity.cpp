#include <iostream>
#include <string>
using namespace std;

// Base class for the City data
class City {
protected:
    string cityName;
    float totalPopulation;
    float totalShop;
    float totalEntrepreneur;

public:
    void getCityInfo() {
        cout << "Enter city name: " << endl;
        getline(cin, cityName);
        cout << "Enter city population: " << endl;
        cin >> totalPopulation;
        cout << "Enter total shops: " << endl;
        cin >> totalShop;
        cout << "Enter total Entrepreneurship: " << endl;
        cin >> totalEntrepreneur;
    }
};

// Hospital-related data and calculations
class Hospital : public virtual City {
protected:
    float numberOfHospital, capacityOfHospital;
    float numberOfDoctor;
    float doctorPerPopulation, populationPerHospital;

public:
    void getHospitalInfo() {
        cout << "Hospital Information" << endl;
        cout << "====================================================" << endl;
        cout << "Enter total number of hospitals in the city: " << endl;
        cin >> numberOfHospital;
        cout << "Enter total capacity of hospitals in the city: " << endl;
        cin >> capacityOfHospital;
        cout << "Enter total number of doctors in the city: " << endl;
        cin >> numberOfDoctor;
    }

    void calculateHospitalData() {
        // Calculate doctor per population and population per hospital
        if (totalPopulation > 0) {
            doctorPerPopulation = (numberOfDoctor / totalPopulation) * 100;  // Percentage of doctors per population
        } else {
            doctorPerPopulation = 0;
        }

        if (numberOfHospital > 0) {
            populationPerHospital = totalPopulation / numberOfHospital;  // Average population per hospital
        } else {
            populationPerHospital = 0;
        }
    }
};

// Internet user-related data and calculations
class InternetUser : public virtual City {
protected:
    float totalInternetUser;
    float internetUserRate;

public:
    void getInternetUserInfo() {
        cout << "Internet User Information" << endl;
        cout << "====================================================" << endl;
        cout << "Enter total number of internet users: " << endl;
        cin >> totalInternetUser;
    }

    void calculateInternetUserData() {
        if (totalPopulation > 0) {
            internetUserRate = (totalInternetUser / totalPopulation) * 100;  // Percentage of internet users
        } else {
            internetUserRate = 0;
        }
    }
};

// Online order-related data and calculations
class OnlineOrder : public virtual City {
protected:
    float totalOnlineShop, onlineShoppingRate, totalOnlineOrder, onlineOrderRate;

public:
    void getOnlineOrderInfo() {
        cout << "Online Order Information" << endl;
        cout << "====================================================" << endl;
        cout << "Enter total number of online shops: " << endl;
        cin >> totalOnlineShop;
        cout << "Enter total number of online orders: " << endl;
        cin >> totalOnlineOrder;
    }

    void calculateOnlineOrderData() {
        if (totalShop > 0) {
            onlineShoppingRate = (totalOnlineShop / totalShop) * 100;  // Percentage of online shops
        } else {
            onlineShoppingRate = 0;
        }

        if (totalPopulation > 0) {
            onlineOrderRate = (totalOnlineOrder / totalPopulation) * 100;  // Percentage of online orders
        } else {
            onlineOrderRate = 0;
        }
    }
};

// Entrepreneurship-related data and calculations
class Entrepreneurship : public virtual City {
protected:
    float onlineEntrepreneur;
    float onlineEntrepreneurRate;

public:
    void getEntrepreneurInfo() {
        cout << "Entrepreneur Information" << endl;
        cout << "====================================================" << endl;
        cout << "Enter total number of online entrepreneurs: " << endl;
        cin >> onlineEntrepreneur;
    }

    void calculateEntrepreneurData() {
        if (totalEntrepreneur > 0) {
            onlineEntrepreneurRate = (onlineEntrepreneur / totalEntrepreneur) * 100;  // Percentage of online entrepreneurs
        } else {
            onlineEntrepreneurRate = 0;
        }
    }
};

// Final Result class to calculate the smart rate of the city
class Result : public Hospital, public InternetUser, public OnlineOrder, public Entrepreneurship {
protected:
    float smartRate;

public:
    void calculateSmartCityRate() {
        // Calculate the Smart Rate using available metrics
        smartRate = (doctorPerPopulation + populationPerHospital + internetUserRate + onlineShoppingRate + onlineOrderRate + onlineEntrepreneurRate) / 5;
    }

    void showResult() {
        cout << "*******************************************************" << endl;
        cout << "*                                                     *" << endl;
        cout << "*                                                     *" << endl;
        cout << "*                                                     *" << endl;
        cout << "* SMART RATE OF " << cityName << " IS " << smartRate << "%  *" << endl;
        cout << "*                                                     *" << endl;
        cout << "*                                                     *" << endl;
        cout << "*                                                     *" << endl;
        cout << "*******************************************************" << endl;
    }
};

int main() {
    Result r;
    cout << "SMART CITY DETECTOR" << endl;
    cout << "=======================================" << endl;

    r.getCityInfo();
    r.getHospitalInfo();
    r.calculateHospitalData();
    r.getInternetUserInfo();
    r.calculateInternetUserData();
    r.getOnlineOrderInfo();
    r.calculateOnlineOrderData();
    r.getEntrepreneurInfo();
    r.calculateEntrepreneurData();

    r.calculateSmartCityRate();
    r.showResult();

    return 0;
}
