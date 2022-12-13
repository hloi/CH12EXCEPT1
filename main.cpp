#include <iostream>
#include <stdexcept>
#include <cmath>
#include <fstream>
#include "OpenFileException.h"
using namespace std;

//double calculateBMI() {
//    double weight, height;
//    double bmi;
//    cout << "enter height: " << endl;
//    cin >> height;
////    if (height == 0) {
////        throw runtime_error("divided by zero");
////    }
//    cout << "enter weight: " << endl;
//    cin >> weight;
//    if (weight > 300 || weight < 0) {
//        throw range_error("incorrect weight");
//    }
//    bmi = (weight/pow(height,2))*703.0;
//    cout << bmi << endl;
//    return bmi;
//}

//int main() {
//
//
//    char quit = 'a';
//
//    while (quit != 'q') {
//
//        try {
//            std::cin.exceptions(std::ios_base::failbit);
//            calculateBMI();
//        } catch (const std::ios_base::failure &f) {
//            cin.clear();
//            cin.ignore();
//            cout << "number conversion error " << f.what() << endl;
//        } catch (range_error& re) {
//            cout << "range error: " << re.what() << endl;
//        } catch (runtime_error &re) {
//            cout << "runtime error: " << re.what() << endl;
//        } catch (exception& e) {
//            cout << "unknown excpetion: " << e.what() << endl;
//        }
//        catch (...) {
//            cout << "catch all exception: " << endl;
//        }
//        cout << "enter another value: " << endl;
//        cin >> quit;
//
//    }
//
//
//    return 0;
//}

ifstream openfile(string file) {
    ifstream f;
    string line;
    f.open(file);
    if (!f.is_open()) {
        throw OpenFileExeption("file not found");
    }
    f.exceptions(ifstream::failbit | ifstream::badbit);
    while (!f.eof()) {
        getline(f, line);
        cout << line << endl;
    }
    f.close();
}

// test1 {
/  TS_ASSERT_THROW_ANYTHING(openfile("test2.txt"));
int main() {
    try {
        openfile("test1.txt");
    } catch (OpenFileExeption& e) {
        cout << e.what() << endl;
    } catch (ifstream::failure e) {
        cout << "eof exception" << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "catch all exception" << endl;
    }
    return 0;
}