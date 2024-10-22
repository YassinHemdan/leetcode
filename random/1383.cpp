class Solution {
public:
struct Employee{
    long long speed = 0;
    long long efficiency = 0;

    Employee(long long speed, long long efficiency) : speed(speed), efficiency(efficiency){}
    bool operator<(Employee const& other) {
        return efficiency < other.efficiency;
    }
    void print(){
        cout << "efficiency = " << this->efficiency << " speed = " << this->speed << "\n";
    }
};

int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<Employee> employees;

    for(int i=0 ; i<n ; ++i) // o(n)
        employees.push_back(Employee(speed[i], efficiency[i]));

    sort(employees.rbegin(), employees.rend()); // o(nlogn)

    priority_queue<long long> speeds;
    long long maxPerformance = 0;
    long long MOD = 1e9 + 7;
    long long totalSpeeds = 0;
    for(const Employee& employee : employees){
        if(k <= 0){
            totalSpeeds -= -speeds.top();
            speeds.pop();
        }
        --k;
        totalSpeeds += employee.speed;
        maxPerformance = max(maxPerformance, totalSpeeds * employee.efficiency);
        speeds.push(-employee.speed);
    }

    return maxPerformance % MOD;
}
};
