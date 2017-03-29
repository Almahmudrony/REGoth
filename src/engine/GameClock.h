#pragma once

#include <string>

namespace Engine
{
    /**
     * Ingame clock
     */
    class GameClock
    {
    public:
        GameClock();

        /**
         * sets the clock to the default settings of a new game
         */
        void resetNewGame();

        /**
         * @return current day
         */
        int getDay() const;

        /**
        * @param newDay day to be set to
        */
        void setDay(int newDay);

        /**
         * updates the game time with the given real time
         */
        void update(float deltaRealTimeSeconds);

        /**
         * Converts time to hours/minutes (24h format)
         * @param hours
         * @param minutes
         */
        void getTimeOfDay(int& hours, int& minutes) const;

        /**
         * @return time elapsed in days since last midnight (0:00)
         */
        float getTimeOfDay() const;

        /**
         * @return Day + time of day as string
         */
        std::string getDateTimeFormatted() const;

        /**
         * Set time to hours/minutes (24h format)
         * hours + minutes / 60.0 may be greater than 24 or smaller than 0
         * and the day will be adjusted in this case
         * @param hours
         * @param minutes
         */
        void setTimeOfDay(int hours, int minutes);

        /**
         * sets the total time directly
         * @param t time in seconds
         */
        void setTotalSeconds(std::size_t t);

        /**
         * gets the total time
         * @return time in seconds
         */
        std::size_t getTotalSeconds();

        /**
         * sets the extra speed factor for test purposes
         */
        void setClockSpeedFactor(float factor);

        /**
         * gets the total ingame time to real time ratio
         */
        float totalSpeedUp() const;

        /**
         * @return time in days since "new game" started
         */
        float getTime();

        /**
         * @return time of day as string in hh:mm format
         */
        std::string getTimeOfDayFormatted() const;

        /**
         * helper function for conversion
         * @param hours
         * @param minutes
         * @return converts timespan in hours/minutes to days (float)
         */
        static float hmToDayTime(int hours, int minutes);

        /**
         * helper function for conversion
         * @param hours
         * @param minutes
         * @return converts timeOfDay in days (float) to hours/minutes
         */
        static void dayTimeTohm(float timeOfDay, int& hours, int& minutes);

        static constexpr unsigned int SECONDS_IN_A_DAY = 24 * 60 * 60;

        // Defines how much faster the ingame clock runs compared to the real time clock. Don't change this value
        static constexpr float GAMETIME_REALTIME_RATIO = 14.5;

    private:
        // Time elapsed since Day 0 00:00 in days
        float m_totalTimeInDays;

        // Time elapsed in the game since last 00:00 in days (interval [0,1[)
        float m_TimeOfDay2;

        // Number of full days elapsed in the game since "start new gothic game"
        int m_Day2;

        // define an extra speedup for the ingame clock
        float m_ClockSpeedFactor;
    };
}