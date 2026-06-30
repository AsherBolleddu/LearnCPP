#include <iostream>
#include <string_view>

struct AdData
{
    int numAdsWatched {};
    double clickedAdsPercent {};
    double avgEarningsPerAd {};
};

template <typename T>
T getData(std::string_view prompt)
{
    std::cout << prompt;
    T data {};
    std::cin >> data;

    return data;
}

AdData getAdData()
{
    AdData temp {};
    std::cout << "How many ads were shown today? ";
    std::cin >> temp.numAdsWatched;
    std::cout << "What percentage of ads were clicked on by users? ";
    std::cin >> temp.clickedAdsPercent;
    std::cout << "What was the average earnings per click? ";
    std::cin >> temp.avgEarningsPerAd;

    return temp;
}

void printAdData(const AdData& adData)
{
    std::cout << "Number of ads watched: " << adData.numAdsWatched << '\n';
    std::cout << "Percentage of users that clicked on an ad: " << adData.clickedAdsPercent << '\n';
    std::cout << "Average earnings per clicked ad: " << adData.avgEarningsPerAd << '\n';
    std::cout << "Total earnings: $"
              << adData.numAdsWatched * (adData.clickedAdsPercent / 100) * adData.avgEarningsPerAd << '\n';
}

int main()
{
    // int numAdsWatched { getData<int>("How many ads were watched? ") };
    // double clickedAdsPercent { getData<double>("What percentage of users clicked on an ad? ") };
    // double avgEarningsPerAd { getData<double>("Whata are the average earnings per clicked ad? ") };

    // printAdData(AdData { numAdsWatched, clickedAdsPercent, avgEarningsPerAd });

    AdData adData { getAdData() };
    printAdData(adData);

    return 0;
}
