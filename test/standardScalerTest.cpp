#include <iostream>
#include "../preprocessing/standardScaler.h"
#include "../io/csvLoader.h"


int main() {
//    EigenMatrix X = load_csv("X_train.csv");
    EigenMatrix X{3,3};
    X << 1, -1, 2,
         2, 0, 0,
         0, 1, -1;
    Cosan::standardScaler ss1{};
    ss1.fit(X);
    std::cout << ss1.mean << '\n' << std::endl;
    std::cout << ss1.std << '\n' << std::endl;
    std::cout << ss1.transform(X) << '\n' << std::endl;

    Cosan::standardScaler ss2{};
    std::cout << ss2.standardize(X) << std::endl;
}