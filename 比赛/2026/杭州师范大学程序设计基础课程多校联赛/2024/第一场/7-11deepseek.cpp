#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

double n, J, v_j, H, v_h;

double T1(double a) {
    if (a <= J) {
        return J / v_j;
    } else {
        if (a <= 2 * J) {
            return (2 * a - J) / v_j;
        } else {
            return (a + J) / v_j;
        }
    }
}

double T2(double a) {
    if (a >= H) {
        return (n - H) / v_h;
    } else {
        double a0 = 2 * H - n;
        if (a >= a0) {
            return (n + H - 2 * a) / v_h;
        } else {
            return (2 * n - H - a) / v_h;
        }
    }
}

double t(double a) {
    if (a == 0.0) {
        return T2(0.0);
    } else if (a == n) {
        return T1(n);
    } else {
        return max(T1(a), T2(a));
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> J >> v_j >> H >> v_h;
        vector<double> points;
        points.push_back(0.0);
        points.push_back(n);
        points.push_back(J);
        points.push_back(H);
        points.push_back(2 * J);
        points.push_back(2 * H - n);

        vector<double> valid_points;
        for (double p : points) {
            if (p >= 0.0 && p <= n) {
                valid_points.push_back(p);
            }
        }
        sort(valid_points.begin(), valid_points.end());
        valid_points.erase(unique(valid_points.begin(), valid_points.end()), valid_points.end());

        vector<double> candidates = valid_points;
        for (int i = 0; i < valid_points.size() - 1; i++) {
            double a1 = valid_points[i];
            double a2 = valid_points[i+1];
            double mid = (a1 + a2) / 2.0;

            double c1, d1;
            if (mid <= J) {
                c1 = 0.0;
                d1 = J / v_j;
            } else {
                if (mid <= 2 * J) {
                    c1 = 2.0 / v_j;
                    d1 = -J / v_j;
                } else {
                    c1 = 1.0 / v_j;
                    d1 = J / v_j;
                }
            }

            double c2, d2;
            if (mid >= H) {
                c2 = 0.0;
                d2 = (n - H) / v_h;
            } else {
                double a0 = 2 * H - n;
                if (mid >= a0) {
                    c2 = -2.0 / v_h;
                    d2 = (n + H) / v_h;
                } else {
                    c2 = -1.0 / v_h;
                    d2 = (2 * n - H) / v_h;
                }
            }

            if (fabs(c1 - c2) > 1e-9) {
                double a_sol = (d2 - d1) / (c1 - c2);
                if (a_sol > a1 && a_sol < a2) {
                    candidates.push_back(a_sol);
                }
            }
        }

        double best_time = 1e18;
        for (double a : candidates) {
            double time_val = t(a);
            if (time_val < best_time) {
                best_time = time_val;
            }
        }
        cout << fixed << setprecision(5) << best_time << endl;
    }
    return 0;
}