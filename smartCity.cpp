#include<iostream>
#include<string>
using namespace std;

class City{
    protected:
    string cityName;
    float totalPopulation;
    float totalShop;
    //int totalTransport;
    float totalEntrepreneur;
    public:
    void getcity(){
        cout<<"Enter city name: "<<endl;
        getline(cin, cityName);
        cin.ignore();
        cout<<"Enter city population: "<<endl;
        cin>>totalPopulation;
        cout<<"Enter total shop: "<<endl;
        cin>>totalShop;
        cout<<"Enter total Entrepreneurship: "<<endl;
        cin>>totalEntrepreneur;


    }
    
};

class Hospital : public virtual City{
    protected:
    float numberOfHospital, capacityOfHospital;
    float numberOfDoctor;
    float doctorPerPopulation,  populationPerHospital;
    public:
    void getHospital(){
        cout<<"Hospital Information"<<endl;
        cout<<"===================================================="<<endl;
        cout<<"Enter total Number of Hospital in the city: "<<endl;
        cin>>numberOfHospital;

        cout<<"Enter total capacity of Hospital in the city: "<<endl;
        cin>>capacityOfHospital;

        cout<<"Enter total Number of doctor in the hospital: "<<endl;
        cin>>numberOfHospital;
        

    } 

    void calculationOfHospital(){
        doctorPerPopulation = ((numberOfDoctor/totalPopulation)*100)+50;
        populationPerHospital = ((numberOfHospital/totalPopulation)*100)+50;

    }

};

class InternetUser : public virtual City{
    protected:
    float totalInternetUser;
    float internetUserRate;
    public:
    void getInternetUser(){
        cout<<"Internet User Information"<<endl;
        cout<<"===================================================="<<endl;
        cout<<"Enter total number of internet user"<<endl;
        cin>>totalInternetUser;
    }
    void calculationOfInternetUser(){
        internetUserRate = (totalInternetUser/totalPopulation)*100;
    }

};

class OnlineOrder : public virtual City{
    protected:
    float totalOnlineShop, onlineShoppingRate, totalOnlineOrder, onlineOrderRate;
    public:
    void getOnlineOrder(){
        cout<<"Online Order Information"<<endl;
        cout<<"===================================================="<<endl;
        cout<<"Enter total number of online shop"<<endl;
        cin>>totalOnlineShop;
        cout<<"Enter total number of online order"<<endl;
        cin>>totalOnlineOrder;
    }
    void calculationOfOnlineOrder(){
        onlineShoppingRate = (totalOnlineShop/totalShop)*100;
        onlineOrderRate = (totalOnlineOrder/totalPopulation)*100;
    }

};
/*

class Trasport : public virtual City{
    protected:
    int totalOnlineTransport;
    int onlineTransportRate;
    public:
    void getTransport(){
        cout<<"Transportation Information"<<endl;
        cout<<"===================================================="<<endl;
        cout<<"Enter how many transport are available online"<<endl;
        cin>>totalOnlineTransport;
    }
    void calculationOfTransportation(){
        onlineTransportRate = (totalOnlineTransport/totalTransport)*100;
    }
};
*/

class Entrepreneurship : public virtual City{
    protected:
        float onlineEntrepreneur;
        float onlineEntrepreneurRate;
    public:
    void getEntrepreneur(){
        cout<<"Entrepreneur Information"<<endl;
        cout<<"===================================================="<<endl;
        cout<<"Enter total Online Entrepreneur"<<endl;
        cin>>onlineEntrepreneur;
    }
    void calculationOfEntrepreneur(){
        onlineEntrepreneurRate = (onlineEntrepreneur/totalEntrepreneur)*100;
    }

};






class Result : public Hospital, public InternetUser, public OnlineOrder, public Entrepreneurship{
protected:
    float smartRate;
    public:
    void SmartCityCalculation(){
        smartRate = (doctorPerPopulation+populationPerHospital+internetUserRate+onlineShoppingRate+onlineOrderRate+onlineEntrepreneurRate)/6;
    }
    void showResult(){
        cout<<"*******************************************************"<<endl;
        cout<<"*                                                     *"<<endl;
        cout<<"*                                                     *"<<endl;
        cout<<"*                                                     *"<<endl;
        cout<<"*SMART RATE OF "<<cityName<< "IS "<<smartRate<<"Percent\t*"<<endl;
        cout<<"*                                                     *"<<endl;
        cout<<"*                                                     *"<<endl;
        cout<<"*                                                     *"<<endl;
        cout<<"*******************************************************"<<endl;
    }
};

int main(){
    Result r;
    cout<<"SMART CITY DETECTOR"<<endl;
    cout<<"======================================="<<endl;
    r.getcity();
    r.getHospital();
    r.calculationOfHospital();
    r.getInternetUser();
    r.calculationOfInternetUser();
    r.getOnlineOrder();
    r.calculationOfOnlineOrder();
    //r.getTransport();
    //r.calculationOfTransportation();
    r.getEntrepreneur();
    r.calculationOfEntrepreneur();
    r.SmartCityCalculation();
    r.showResult();
    


    return 0;
}