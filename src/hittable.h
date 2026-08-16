//
// Created by Nan Ma on 8/10/26.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_HITTABLE_H
#define RAY_TRACING_IN_ONE_WEEKEND_HITTABLE_H

#include "ray.h"
#include "vec3.h"

class hit_record {
public:
    point3 p;
    vec3 normal;
    double t = 0.0;
    bool front_face = false;

    void set_face_normal(const ray& r, const vec3& outward_normal) {
        // Sets the hit record normal vector.
        // NOTE: the parameter 'outward_normal' is assumed to have unit length.

        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
public:
    virtual ~hittable() = default;
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif //RAY_TRACING_IN_ONE_WEEKEND_HITTABLE_H
