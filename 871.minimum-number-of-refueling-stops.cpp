/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 *
 * https://leetcode.com/problems/minimum-number-of-refueling-stops/description/
 *
 * algorithms
 * Hard (31.47%)
 * Likes:    883
 * Dislikes: 18
 * Total Accepted:    21.5K
 * Total Submissions: 67.9K
 * Testcase Example:  '1\n1\n[]'
 *
 * A car travels from a starting position to a destination which is target
 * miles east of the starting position.
 * 
 * Along the way, there are gas stations.  Each station[i] represents a gas
 * station that is station[i][0] miles east of the starting position, and has
 * station[i][1] liters of gas.
 * 
 * The car starts with an infinite tank of gas, which initially has startFuel
 * liters of fuel in it.  It uses 1 liter of gas per 1 mile that it drives.
 * 
 * When the car reaches a gas station, it may stop and refuel, transferring all
 * the gas from the station into the car.
 * 
 * What is the least number of refueling stops the car must make in order to
 * reach its destination?  If it cannot reach the destination, return -1.
 * 
 * Note that if the car reaches a gas station with 0 fuel left, the car can
 * still refuel there.  If the car reaches the destination with 0 fuel left, it
 * is still considered to have arrived.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: target = 1, startFuel = 1, stations = []
 * Output: 0
 * Explanation: We can reach the target without refueling.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: target = 100, startFuel = 1, stations = [[10,100]]
 * Output: -1
 * Explanation: We can't reach the target (or even the first gas station).
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: target = 100, startFuel = 10, stations =
 * [[10,60],[20,30],[30,30],[60,40]]
 * Output: 2
 * Explanation: 
 * We start with 10 liters of fuel.
 * We drive to position 10, expending 10 liters of fuel.  We refuel from 0
 * liters to 60 liters of gas.
 * Then, we drive from position 10 to position 60 (expending 50 liters of
 * fuel),
 * and refuel from 10 liters to 50 liters of gas.  We then drive to and reach
 * the target.
 * We made 2 refueling stops along the way, so we return 2.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= target, startFuel, stations[i][1] <= 10^9
 * 0 <= stations.length <= 500
 * 0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] <
 * target
 * 
 * 
 * 
 * 
 * 
 */
#include "lc.hpp"

// @lc code=start
/**
 * This problem is similar to frog jump?
 * 
 * 1. 
 * Use BFS, the neighbors of each state/stop is the stations or the target that 
 * it can reach.
 * In the end, if the loop ends, it means it cannot reach the target.
 * 
 * To verify if a state has been visited, we should use the location, and
 * remaining fuel.
 * 
 * 2.
 * Like frog jump, use dynamic 
 */

struct state_t{
    int loc;
    int fuel;
    int level;
    state_t(const int loc, const int fuel, int level): loc(loc), fuel(fuel), level(level) {}
    bool operator==(const state_t &other) const {
        return this->loc == other.loc && this->fuel == other.fuel;
    }
};

namespace std {
    template<> struct hash<state_t> {
    public:
        size_t operator()(const state_t &s) const {
            return str_hash(std::to_string(s.loc) + ","+std::to_string(s.fuel));
        }
    private:
        std::hash<std::string> str_hash;
    };
}

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int N = stations.size();
        vector<long> dp (N+1, 0);
        dp[0] = startFuel;

        for (int i = 0; i < N; i++) {
            for (int t = i; t >= 0; t--) {
                if (dp[t] >= stations[i][0]) {
                    dp[t+1] = max(dp[t+1], dp[t] + (long)stations[i][1]);
                }
            }
        }
        for (int i = 0; i <= N; i++) {
            if (dp[i] >= target) return i;
        }
        return -1;
    }

    int minRefuelStopsBFS(int target, int startFuel, vector<vector<int>>& stations) {
        map<int, int> map_stations;
        for (auto &st : stations) {
            map_stations[st[0]] = st[1];
        }

        queue<state_t> q;
        state_t start(0, startFuel, 0);
        unordered_set<state_t> visited;
        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            state_t s = q.front();
            q.pop();

            if (s.loc == target) {
                return s.level;
            }

            int max_reach = -1;
            int station_fuel = 0;
            if (s.loc == 0) {
                max_reach = s.fuel;
            } else {
                station_fuel = map_stations[s.loc];
                max_reach = s.loc + s.fuel + station_fuel;
            }

            auto map_it = map_stations.upper_bound(s.loc);
            while (map_it != map_stations.end()) {
                if (map_it->first <= max_reach) {
                    state_t ns(map_it->first, 
                            s.fuel + station_fuel - (map_it ->first - s.loc),
                            s.level + 1);
                    if (visited.find(ns) == visited.end()) {
                        visited.insert(ns);
                        q.push(ns);
                    }
                } else {
                    break;
                }
                map_it = next(map_it);
            }
            if (max_reach >= target) {
                return s.level;
            }
        }
        return -1;
    }
};
// @lc code=end

