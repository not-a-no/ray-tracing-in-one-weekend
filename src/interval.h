//
// Created by Nan Ma on 8/14/26.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_INTERVAL_H
#define RAY_TRACING_IN_ONE_WEEKEND_INTERVAL_H

class interval {
public:
    double min, max;

    interval(): min(+infinity), max(-infinity) {}  // Default interval is empty

    interval(double min, double max): min(min), max(max) {}

    double size() const {
        return max - min;
    }

    bool contains(double x) const {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const {
        return min < x && x < max;
    }

    static const interval empty, universe;
};

const interval interval:: empty = interval(+infinity, -infinity);
const interval interval:: universe = interval(-infinity, infinity);

#endif //RAY_TRACING_IN_ONE_WEEKEND_INTERVAL_H
