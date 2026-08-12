//
// Created by Nan Ma on 8/12/26.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_HITTABLE_LIST_H
#define RAY_TRACING_IN_ONE_WEEKEND_HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;

class hittable_list : public hittable {
public:
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() = default;
    hittable_list(const shared_ptr<hittable>& object) { add(object); }

    void clear() { objects.clear(); }

    void add(const shared_ptr<hittable>& object) {
        objects.push_back(object);
    }

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override{
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_tmax;

        for (const auto& object : objects) {
            if (object->hit(r, ray_tmin, closest_so_far, temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }
        return hit_anything;
    }
};

#endif //RAY_TRACING_IN_ONE_WEEKEND_HITTABLE_LIST_H
