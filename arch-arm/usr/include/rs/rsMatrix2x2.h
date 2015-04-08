/*
 * Copyright (C) 2011-2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_RS_MATRIX_2x2_H
#define ANDROID_RS_MATRIX_2x2_H

#include "rsType.h"


// ---------------------------------------------------------------------------
namespace android {
namespace renderscript {

struct Matrix2x2 : public rs_matrix2x2 {
    inline float get(uint32_t x, uint32_t y) const {
        return m[x*2 + y];
    }

    inline void set(uint32_t x, uint32_t y, float v) {
        m[x*2 + y] = v;
    }

    void loadIdentity();
    void load(const float *);
    void load(const rs_matrix2x2 *);

    void loadMultiply(const rs_matrix2x2 *lhs, const rs_matrix2x2 *rhs);

    void transpose();

    void multiply(const rs_matrix2x2 *rhs) {
        Matrix2x2 tmp;
        tmp.loadMultiply(this, rhs);
        load(&tmp);
    }
};

}
}

#endif  // ANDROID_RS_MATRIX_2x2_H