/* Copyright (c) 2012 Eliot Eshelman
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/


#include "simplexnoise.h"
#include "simplextextures.h"
#include <iostream>

int main() {
    int iterations = 5;

    std::cout << "Generating " << iterations*iterations*iterations*iterations << " iterations." << std::endl;

    for(int h=0; h < iterations; ++h) {
        for(int i=0; i < iterations; ++i) {
            for(int j=0; j < iterations; ++j) {
                for(int k=0; k < iterations; ++k) {
                    std::cout << octave_noise_4d(3, 0.5, 1, h, i, j, k) << std::endl;
                    std::cout << marble_noise_4d(3, 0.5, 1, h, i, j, k) << std::endl;
                }
            }
        }
    }

    return 0;
}
