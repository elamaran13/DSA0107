// Task 10: Compare Expectations with Execution - Floating Point Decay Test
#include <iostream>
#include <iomanip>

int main() {
    std::cout << "--- Large-Scale Simulation: Integer vs Floating-Point ---\n";
    long long journeyCounts[] = {20000, 500000, 3000000};
    double fareRupees = 36.00;
    long long farePaise = 3600;

    for (long long N : journeyCounts) {
        long long intTotalPaise = N * farePaise;
        double doubleTotalRupees = 0.0;
        // Repeated accumulation to observe floating-point drift
        for (long long i = 0; i < N; ++i) {
            doubleTotalRupees += fareRupees;
        }

        double intConvertedToRupees = intTotalPaise / 100.0;
        double diff = doubleTotalRupees - intConvertedToRupees;

        std::cout << "Journeys: " << N << "\n"
                  << "  Integer Total: Rs " << std::fixed << std::setprecision(2) << intConvertedToRupees << "\n"
                  << "  Double Total : Rs " << doubleTotalRupees << "\n"
                  << "  Discrepancy  : Rs " << diff << "\n\n";
    }
    return 0;
}
