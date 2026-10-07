#ifndef ADAMSMETHOD_H
#define ADAMSMETHOD_H

#include <vector>
#include <functional>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

class AdamsSolver {
private:
    double x0;   
    double y0;         
    double h;     
    double xEnd;    

    vector<double> xValues;
    vector<double> yValues;
    vector<double> fValues; 

    function<double(double, double)> f;

    void initializeFirstPoints();
    double predictor(int i);
    double corrector(int i);
    double adamsBashforth2(int i);   
    double adamsBashforth3(int i);
    double adamsBashforth4(int i);
    double adamsMoulton2(int i);
    double adamsMoulton3(int i);
    double adamsMoulton4(int i);

public:
    AdamsSolver(function<double(double, double)> func,
        double x0, double y0, double h, double xEnd);

    void solve(int order = 4);

    vector<double> getXValues() const { return xValues; }
    vector<double> getYValues() const { return yValues; }

    void printResults() const;
    void printResultsToFile(const string& filename) const;

    static double calculateError(const vector<double>& exact,
        const vector<double>& computed);
};

#endif 