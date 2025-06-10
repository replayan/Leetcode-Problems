class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(toDays(date1) - toDays(date2));
    }

private:
    // Convert a date string YYYY-MM-DD to the number of days since 1970-01-01
    int toDays(const string& date) {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

        // tm struct counts months from 0 (Jan) to 11 (Dec), and years since 1900
        tm t = {};
        t.tm_year = year - 1900;
        t.tm_mon = month - 1;
        t.tm_mday = day;

        time_t timeSinceEpoch = mktime(&t);
        return timeSinceEpoch / (60 * 60 * 24); // Convert seconds to days
    }
};
