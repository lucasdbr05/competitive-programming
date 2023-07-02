#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double g = 9.80665;
    double pi = 3.14159;
    double h;
    cin >> h;

    int p1, p2;
    cin >> p1 >> p2;

    int n;
    cin >> n;

    while (n)
    {
        double alpha, v, vx, vy, a_rad, time_total, ts, td, H, v_aux;
        cin >> alpha >> v;
        a_rad = (alpha * 2 * pi) / 360;
        vy = v * sin(a_rad);
        vx = v * cos(a_rad);

        ts = vy / g;
        H = (vy * vy) / (2 * g) + h;
        v_aux = sqrt(2 * g * H);
        td = v_aux / g;

        time_total = ts + td;

        double space;
        space = vx * time_total;
        string result;
        if ((space >= p1) && (space <= p2))
        {
            result = "DUCK";
        }
        else
        {
            result = "NUCK";
        }

        cout << fixed << setprecision(5) << space << " -> " << result << endl;
        n -= 1;
        space = 0;
    }

    return 0;
}
