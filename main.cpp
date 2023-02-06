#include <iostream>
#include <vector>

using namespace std;

class Time {
public:
    Time() {
        day = 0;
        hour = 0;
        minute = 0;
    }

    Time(const int& d, const int& h, const int& m) {
        day = d;
        hour = h;
        minute = m;
    }

    int get_hour() const {
        return hour;
    }

    int get_day() const {
        return day;
    }

    int get_minute() const {
        return minute;
    }

private:
    int day = 0;
    int hour;
    int minute;
};

bool operator==(const Time& lhs, const Time& rhs) {
    if (lhs.get_day() == rhs.get_day() && lhs.get_hour() == rhs.get_hour() && lhs.get_minute() == rhs.get_minute()) return true;
    return false;
}

int operator-(const Time& t1, const Time& t2) {
    int hours1 = t1.get_hour();
    int hours2 = t2.get_hour();
    if (t1.get_day() != t2.get_day()) {
        hours2 += 24 * (t2.get_day() - t1.get_day());
    }
    int hour = hours2 - hours1;
    int minute = t2.get_minute() - t1.get_minute();
    return hour * 60 + minute;

}

ostream& operator<<(ostream& os, const Time& t) {
    os << "d" << t.get_day() << " " << t.get_hour() << ":" << t.get_minute();
    return os;
}

class Trip {
public:
    Trip (const Time& s) {
        start = s;
    }

    Trip (const Time& s, const Time& e) {
        start = s;
        end = e;
    }

    Time get_start() const {
        return start;
    }

    Time get_end() const {
        return end;
    }

private:
    Time start;
    Time end;
};

class Rocket {
public:
    Rocket(const int& idshnik) {
        id = idshnik;
    }

    void starting(const Time& t) {
        start = t;
        cout << "START: time = " << start << endl;
    }

    void ending(const Time& t) {
        result += (t - start);
        start = Time();
        cout << "END: time = " << t << "\tResult = " << t - start << endl;
    }

    int get_result() {
        return result;
    }

    int get_id() const {
        return id;
    }

private:
    int id;
    int result = 0;
    vector<Trip> trips;
};

int rocketid(const int& id, const vector<Rocket>& v) {
    for (unsigned int i = 0; i < v.size(); i++) {
        if (v[i].get_id() == id) return i;
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<Rocket> park;
    for (int i = 0; i < N; i++) {
        int day, hour, minute, id;
        char status;
        cin >> day >> hour >> minute >> id >> status;
        //cout << "Day: " << day << endl << "hour: " << hour << endl << "minute: " << minute << endl << "id: " << id << endl << "status: " << status << endl;
        if (rocketid(id, park) == -1) {
            park.push_back(Rocket(id));
        }
        if (status == 'A') {
            park[rocketid(id, park)].starting(Time(day, hour, minute));
        } else if (status == 'B') continue;
        else if (status == 'C' || status == 'S') {
            park[rocketid(id, park)].ending(Time(day, hour, minute));
        }
    }

    for (Rocket r : park) {
        cout << r.get_result() << " ";
    }

    return 0;
}
