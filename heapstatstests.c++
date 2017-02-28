/*
 * Copyright (c) 2015 the original author or authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string>
#include <sstream>
#include <iostream>

#include "heapstatshashtable.h"

HeapStatsHashtable *heapStats;

const char* test_class_name_1 = "java.lang.Object";
const char* test_class_name_2 = "java.lang.long.longer.String";

void setup() {
    heapStats = new HeapStatsHashtable();
}

void teardown() {
    if (heapStats != NULL) {
        delete heapStats;    
    }
}

bool verify(std::string test, std::string expected, std::string actual) {
    bool result = false;
    if(expected.compare(actual) == 0) {
        result = true;
    } else {
        std::cout << "ERROR - " << test << " has failed.\n";
        std::cout << "Expected:\n" << expected << "\n";
        std::cout << "Actual:\n" << actual << "\n";
        std::cout << "\n";
    }
    return result;
}

bool testSingleRecordAndPrint() {
    setup();
    HeapStatsHashtable tHeapStats = *heapStats;
    std::stringstream ss;
    
    tHeapStats.recordObject(test_class_name_1, 24);
    tHeapStats.print(ss);
    
    const std::string expected ("| Instance Count | Total Bytes | Class Name       |\n"
                                "| 1              | 24          | java.lang.Object |\n");
    
    bool result = verify ("testSingleRecordAndPrint", expected.c_str(), ss.str().c_str());
    teardown();
    return result;
}

bool testMultiRecordAndPrint() {
    setup();
    HeapStatsHashtable tHeapStats = *heapStats;
    std::stringstream ss;
    
    tHeapStats.recordObject(test_class_name_1, 24);
    tHeapStats.recordObject(test_class_name_2, 36);
    tHeapStats.print(ss);
    
    const std::string expected ("| Instance Count | Total Bytes | Class Name                   |\n"
                                "| 1              | 36          | java.lang.long.longer.String |\n"
                                "| 1              | 24          | java.lang.Object             |\n");
    
    bool result = verify ("testMultiRecordAndPrint", expected.c_str(), ss.str().c_str());
    teardown();
    return result;
}

bool testDuplicateRecordAndPrint() {
    setup();
    HeapStatsHashtable tHeapStats = *heapStats;
    std::stringstream ss;
    
    tHeapStats.recordObject(test_class_name_1, 24);
    tHeapStats.recordObject(test_class_name_1, 26);
    tHeapStats.recordObject(test_class_name_2, 32);
    tHeapStats.print(ss);
    
    const std::string expected ("| Instance Count | Total Bytes | Class Name                   |\n"
                                "| 2              | 50          | java.lang.Object             |\n"
                                "| 1              | 32          | java.lang.long.longer.String |\n");
    
    bool result = verify ("testDuplicateRecordAndPrint", expected.c_str(), ss.str().c_str());
    teardown();
    return result;
}

bool testSortAndPrint() {
    setup();
    HeapStatsHashtable tHeapStats = *heapStats;
    std::stringstream ss;

    tHeapStats.recordObject(test_class_name_2, 937072);
    tHeapStats.recordObject(test_class_name_1, 96);
    tHeapStats.print(ss);

    const std::string expected ("| Instance Count | Total Bytes | Class Name                   |\n"
                                "| 1              | 937072      | java.lang.long.longer.String |\n"
                                "| 1              | 96          | java.lang.Object             |\n");

    bool result = verify ("testSortAndPrint", expected.c_str(), ss.str().c_str());
    teardown();
    return result;
}

int main() {
    bool result = testSingleRecordAndPrint() && testMultiRecordAndPrint() && testDuplicateRecordAndPrint() && testSortAndPrint();
    if (result) {    	
        fprintf(stdout, "SUCCESS\n");
        exit(EXIT_SUCCESS);
    }
    else { 
        fprintf(stdout, "FAILURE\n");
        exit(EXIT_FAILURE);
    }	
}
