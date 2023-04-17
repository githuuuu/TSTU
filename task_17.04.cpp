#include <iostream>
using namespace std;
int main(){
    int x1, x2, x3, y1, y2, y3, x0, y0;
    int a, b, c;
    cout << "enter x and y for the first point" << endl;
    cin >> x1;
    cin >> y1;
    cout << "enter x and y for the second point" << endl;
    cin >> x2;
    cin >> y2;
    cout << "enter x and y for the third point" << endl;
    cin >> x3;
    cin >> y3;
    if (((x1 - x3) * (y2 - y3)) - ((x2 - x3) * (y1 - y3)) != 0) {
        cout << "triangle exists" << endl;
        cout << "enter x and y for a new point" << endl;
        cin >> x0;
        cin >> y0;
        a = ((x1 - x0) * (y2 - y1)) - ((x2 - x1)) * ((y1 - y0));
        b = ((x2 - x0) * (y3 - y2)) - ((x3 - x2)) * ((y2 - y0));
        c = ((x3 - x0) * (y1 - y3)) - ((x1 - x3)) * ((y3 - y0));
        if ((a < 0 && b < 0 && c < 0) || (a > 0 && b > 0 && c > 0)) cout << "new point is inside the triangle"<< endl;
        if (a == 0 || b == 0 || c == 0) cout << "new point is on one of the sides of the triangle";
        else cout << "new point is outside the triangle";
    }
    else cout << "triangle does not exist";
}
