// Fourhas4letters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <algorithm>



int main()
{
    int value;
    int terminated13 = 0;
    int terminated18 = 0;
    std::string binaryStr;
    for (int i = 1; i <= 1000000; i++) {  // TODO: Check for 0, which would be 0000...00000 and therefore would incorrectly count the letters
        value = i;
        while (true) {
            //std::cout << value << std::endl;
            binaryStr = std::bitset<33>(value).to_string();  // Converts int (expressed as a raw array of bits in memory [bitset type]) to a binary string
            value = (std::count(binaryStr.begin(), binaryStr.end(), '0') - binaryStr.find('1', 0)) * 4
                + std::count(binaryStr.begin(), binaryStr.end(), '1') * 3; // Counts the number of 'one's and 'zero's excluding those preceding the first '1'
            if (value == 13) {
                //std::cout << "13 (Terminated!)" << std::endl;
                terminated13++;
                break;
            }
            else if (value == 18) {
                //std::cout << "18 (Terminated!)" << std::endl;
                terminated18++;
                break;
            }
        }
    }
    std::cout << "13: " << terminated13 << std::endl;
    std::cout << "18: " << terminated18 << std::endl;
    return 0;
}

