//
// Created by liuye on 2023/12/7.
//


#ifndef AIRLINETICKET_H
#define AIRLINETICKET_H
#include <string>

export class AirlineTicket
{
public:
    AirlineTicket();
    ~AirlineTicket();

    double calculatePriceInDollars();

    std::string getPassengerName();
    void setPassengerName(std::string name);

    int getNumberOfMiles();
    void setNumberOfMiles(int miles);

    bool hasEliteSuperRewardsStatus();
    void setHasEliteSuperRewardsStatus(bool status);

private:
    std::string m_passengerName;
    int m_numberOfMiles;
    bool m_hasEliteSuperRewardsStatus;
};

#endif
