/// The points lie on the same line iff any pair of them have the same slope
/// slope = dy / dx

typedef unsigned long long ull;

class Solution {
private:
    vector<vector<int>> pointSlopeData, slopeIndex;
    
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
    
    void init(vector<vector<int>>& points) {
        vector<ull> allHashs;
        for(int i = 0; i < points.size(); ++i) {
            for(int j = i+1; j < points.size(); ++j){
                allHashs.push_back(slope(points[i], points[j]));
            }
        }
        sort(allHashs.begin(), allHashs.end());
        allHashs.erase(unique(allHashs.begin(), allHashs.end()), allHashs.end());
        
        pointSlopeData = vector<vector<int>>(points.size(), vector<int>(allHashs.size(), 1));
        slopeIndex = vector<vector<int>>(points.size(), vector<int>(points.size()));
        
        for(int i = 0; i < points.size(); ++i) {
            for(int j = i+1; j < points.size(); ++j) {
                ull _slope = slope(points[i], points[j]);
                slopeIndex[i][j] = lower_bound(allHashs.begin(), allHashs.end(), _slope) - allHashs.begin();
            }
        }
    }
    
public:
    int maxPoints(vector<vector<int>>& points) {
        init(points);
        
        int maxP = 1;
        for(int i = 0; i < points.size(); ++i) {
            for(int j = i+1; j < points.size(); ++j) {
                maxP = max(maxP, ++pointSlopeData[i][slopeIndex[i][j]]);
            }
        }
        
        return maxP;
    }
};