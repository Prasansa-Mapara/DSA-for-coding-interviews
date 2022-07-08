class Logger {
public:
    unordered_map<string, int> hash;

    Logger() {
    }
    
    bool shouldPrintMessage(int time, string msg) {
        if(hash.find(msg)==hash.end()){
            hash[msg]=time;
            return 1;
        }
        else{
            if(time>=hash[msg]+10){
                hash[msg]=time;
                return 1;
            }
            else{
                return 0;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */