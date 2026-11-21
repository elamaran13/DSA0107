// Q5: Overloading Increment, Comparison, and Subscript Operators (Track Timer)
#include <iostream>
#include <string>
#include <vector>

class Playlist {
private:
    std::vector<std::string> tracks;
public:
    void addTrack(const std::string& title) { tracks.push_back(title); }

    // Overload subscript operator []
    std::string& operator[](size_t index) {
        return tracks.at(index); // Bounds checked
    }

    const std::string& operator[](size_t index) const {
        return tracks.at(index);
    }

    size_t size() const { return tracks.size(); }
};

class TrackTimer {
private:
    int seconds;
public:
    TrackTimer(int s = 0) : seconds(s) {}

    // Prefix ++
    TrackTimer& operator++() {
        ++seconds;
        return *this;
    }

    // Postfix ++
    TrackTimer operator++(int) {
        TrackTimer old = *this;
        ++seconds;
        return old;
    }

    bool operator<(const TrackTimer& other) const {
        return this->seconds < other.seconds;
    }

    int getSeconds() const { return seconds; }
};

int main() {
    Playlist list;
    list.addTrack("Track 1 - Prelude");
    list.addTrack("Track 2 - Fugue");
    list.addTrack("Track 3 - Allegro");

    std::cout << "Track at index 1: " << list[1] << "\n";
    list[1] = "Track 2 - Scherzo"; // Modified via l-value []
    std::cout << "Modified track at index 1: " << list[1] << "\n";

    TrackTimer t(10);
    TrackTimer post = t++;
    TrackTimer pre = ++t;
    std::cout << "t: " << t.getSeconds() << " | post: " << post.getSeconds() << " | pre: " << pre.getSeconds() << "\n";

    return 0;
}
