#include <unordered_map>
#include <string>
#include <vector>
#include <utility>
#include <numeric>

class UndergroundSystem {
private:
    /**
     * A map where each key is the name of a station and each value is a map which associates each destination station with the times it took to travel to that station.
     */
    std::unordered_map<std::string, std::unordered_map<std::string, std::vector<int>>> travelingTimes;

    /**
     * A map which associates each customer id with the station that customer is currently checked in at and the check in time.
     */
    std::unordered_map<int, std::pair<std::string, int>> checkIns;
public:
    UndergroundSystem() {

    }
    
    /**
     * Checks in a customer at a station.
     */
    void checkIn(int id, std::string stationName, int t) {
        this->checkOut(id, stationName, t);
        this->checkIns.insert(std::make_pair(id, std::make_pair(stationName, t)));
    }
    
    /**
     * Checks out a customer at a station
     */
    void checkOut(int id, std::string stationName, int t) {
        auto entry = this->checkIns.find(id);

        if (entry != this->checkIns.end()) {
            auto [station, time] = entry->second;
            this->travelingTimes[station][stationName].push_back(t - time);
            this->checkIns.erase(id);
        }
    }
    
    /**
     * Gets the average traveling time between 2 stations
     */
    double getAverageTime(std::string startStation, std::string endStation) {
        auto &times = this->travelingTimes[startStation][endStation];
        
        return (double) std::accumulate(times.cbegin(), times.cend(), 0) / times.size();
    }
};

int main() {
    UndergroundSystem undergroundSystem;
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);  // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12
    undergroundSystem.checkOut(27, "Waterloo", 20);  // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10
    undergroundSystem.checkOut(32, "Cambridge", 22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14
    undergroundSystem.getAverageTime("Paradise", "Cambridge"); // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
    undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11
    undergroundSystem.checkIn(10, "Leyton", 24);
    undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 11.00000
    undergroundSystem.checkOut(10, "Waterloo", 38);  // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
    undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12
}