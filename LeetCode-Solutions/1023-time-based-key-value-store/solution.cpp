#define deb(x) cout <<#x<<": "<<x<<'\n';
class TimeMap {
public:
//variables:
    unordered_map<string,map<int,string>>timeMap;
//constructor
    TimeMap() {
     timeMap = unordered_map<string,map<int,string>>();
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key][timestamp] = value;
    }
    string get(string key, int timestamp) {
        auto it = timeMap[key].lower_bound(timestamp);
        if(it == timeMap[key].begin() && it->first > timestamp || timeMap[key].size() == 0){
            return "";
        }
        if(it == timeMap[key].end() || it->first > timestamp) --it;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
