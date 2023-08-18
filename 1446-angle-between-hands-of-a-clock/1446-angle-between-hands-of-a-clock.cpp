class Solution {
public:
    double angleClock(int hour, int minutes) {
        float h = (hour % 12 + (float)minutes / 60) * 30;
        float m = minutes * 6; // 360/60
        float angle = fabs(h - m);
        angle = (angle > 180) ? 360 - angle : angle;
        return angle;
    }
};
