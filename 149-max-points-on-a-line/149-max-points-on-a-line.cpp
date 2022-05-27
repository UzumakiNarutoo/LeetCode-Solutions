/// The points lie on the same line iff any pair of them have the same slope
/// slope = dy / dx

typedef unsigned long long ull;

class Solution {
private:
    vector<unordered_map<ull, int>> pointSlopeData;
    
    ull HashValue(const vector<int>& slope) {
        int dy = slope[0], dx = slope[1];
        
        bool dySign = dy < 0, dxSign = dx < 0;
        
        return ((abs(dy) * 100000ll + abs(dx)) * 10ll + dySign) * 10ll + dxSign; 
    }
    
    ull slope(const vector<int>& point1, const vector<int>& point2) {
        int x1 = point1[0], y1 = point1[1];
        int x2 = point2[0], y2 = point2[1];
        
        int dy = y1 - y2, dx = x1 - x2;
        int g = __gcd(dy, dx);
        
        return HashValue({dy/g, dx/g});
    }
    
public:
    int maxPoints(vector<vector<int>>& points) {
        pointSlopeData = vector<unordered_map<ull, int>>(points.size());
        
        int maxP = 0;
        for(int i = 0; i < points.size(); ++i) {
            for(int j = i+1; j < points.size(); ++j) {
                maxP = max(maxP, ++pointSlopeData[i][slope(points[i], points[j])]);
            }
        }
        
        return maxP + 1;
    }
};