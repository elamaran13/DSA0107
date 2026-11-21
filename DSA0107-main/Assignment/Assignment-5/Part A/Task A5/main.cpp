// Part A - Task A5: Design Recovery and Rethrowing
#include <iostream>
#include <stdexcept>

void auditAndLog(const std::exception& e) {
    std::cout << "[AUDIT LOG] Intercepted Exception: " << e.what() << "\n";
}

void processClaim(double claim, double maxCover) {
    if (claim > maxCover) {
        throw std::runtime_error("Claim exceeds policy limit!");
    }
}

void intermediateSettlement(double claim, double maxCover) {
    try {
        processClaim(claim, maxCover);
    } catch (const std::exception& e) {
        auditAndLog(e);
        // Rethrow the identical active exception to higher level handler
        throw;
    }
}

int main() {
    try {
        intermediateSettlement(60000, 50000);
    } catch (const std::exception& e) {
        std::cout << "[TOP LEVEL HANDLER] Final Disposition: " << e.what() << "\n";
    }
    return 0;
}
