/*
 * This file is part of the Kentside Minimal Test Harness
 *
 * Copyright (C) 2017 Helm Solutions Ltd (kentside@yandex.com)
 *
 * The Kentside Minimal Test Harness is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * The Kentside Minimal Test Harness is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Kentside Minimal Test Harness.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef _TEST_TESTREGISTRY_
#define _TEST_TESTREGISTRY_

#include <vector>

#include "test/test.h"

namespace test {

    class test_registry {
    public:
        static test_registry& instance() {
            if (_instance == 0) {
                _instance = new test_registry();
            }
            return *_instance;
        }

        void add_test(test* test) {
            _tests.push_back(test);
        }

        std::vector<test*>& get_tests() {
            return _tests;
        }

    private:
        test_registry() {
        }

        std::vector<test*> _tests;

        static test_registry* _instance;
    };
}

#endif

